/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/11/03 14:50:20 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	x;

	x = (*a)->next->next->value;
	if ((*a)->value > (*a)->next->value && (*a)->value > x)
	{
		ra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (x < (*a)->next->value && (*a)->value < x)
	{
		if ((*a)->next->value > x)
		{
			sa(a);
			ra(a);
		}
	}
	else
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		else
			rra(a);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_min_position(*a);
	if (pos <= 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < stack_size(*a))
			rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_min_position(*a);
	if (pos <= 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < stack_size(*a))
			rra(a);
	pb(a, b);
	pos = find_min_position(*a);
	if (pos <= 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < stack_size(*a))
			rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
