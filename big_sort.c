/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 20:22:37 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_top(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

int	find_bottom(t_stack *a, int min, int max)
{
	int	pos;
	int	found;
	int	size;
	int	i;

	pos = 0;
	found = -1;
	size = stack_size(a);
	i = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			found = i; // garde la derniere pos trouve
		i++;
		pos++;
		a = a->next;
	}
	if (found == -1)
		return (-1);
	return (size - found - 1); // distance depuis le bas
}

void	push_chunk_to_b(t_stack **a, t_stack **b, int min, int max)
{
	int	pos_top;
	int	pos_bottom;

	while (1)
	{
		pos_top = find_top(*a, min, max);
		pos_bottom = find_bottom(*a, min, max);
		if (pos_top == -1) // aucun élément du chunk restant
			break ;
		if (pos_top <= pos_bottom)
		{
			while (pos_top-- > 0)
				ra(a);
		}
		else
		{
			while (pos_bottom-- > 0)
				rra(a);
		}
		pb(a, b); // pousse l'élément trouvé vers B
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*b)
	{
		max_index = find_max_index(*b);
		pos = find_position(*b, max_index);
		size = stack_size(*b);
		if (pos <= size / 2) // si element qu'on veut remonter est dans la 1ere moitie
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	max;
	int	min;
	int	chunk_size;
	int	size;

	min = 0;
	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 25;
	if (size > 100 && size <= 500)
		chunk_size = 40;
	if (size > 500)
		chunk_size = 80;
	while (min < size)
	{
		max = min + chunk_size - 1;
		if (max >= size)
			max = size - 1;
		push_chunk_to_b(a, b, min, max);
		min = min + chunk_size;
	}
	push_to_a(a, b);
}
