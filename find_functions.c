/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:32:21 by ibettenc          #+#    #+#             */
/*   Updated: 2025/11/03 14:51:19 by ibettenc         ###   ########.fr       */
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
		a = a->next;
		pos++;
	}
	return (-1);
}

int	find_bottom(t_stack *a, int min, int max)
{
	int	pos;
	int	found;
	int	size;

	pos = 0;
	found = -1;
	size = stack_size(a);
	while (a)
	{
		if (a->index >= min && a->index <= max)
			found = pos;
		a = a->next;
		pos++;
	}
	if (found == -1)
		return (-1);
	return (size - found - 1);
}

int	find_max_index(t_stack *b)
{
	int	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

int	find_position(t_stack *b, int index)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == index)
			return (pos);
		pos++;
		b = b->next;
	}
	return (-1);
}

int	find_min_position(t_stack *a)
{
	int	pos;
	int	pos_min;
	int	min;

	pos = 0;
	pos_min = 0;
	min = a->index;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			pos_min = pos;
		}
		pos++;
		a = a->next;
	}
	return (pos_min);
}
