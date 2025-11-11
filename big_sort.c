/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:32:21 by ibettenc          #+#    #+#             */
/*   Updated: 2025/11/03 14:50:50 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cheapest_rotate_to_top(t_stack **a, int top, int bot, int size)
{
	int	cost_top;
	int	cost_bot;

	cost_top = top;
	cost_bot = size - bot - 1;
	if (cost_top <= cost_bot)
	{
		while (top-- > 0)
			ra(a);
	}
	else
	{
		while (cost_bot-- > 0)
			rra(a);
	}
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int min, int max)
{
	int	top;
	int	bot;
	int	mid;
	int	size;

	mid = min + (max - min) / 2;
	while (1)
	{
		top = find_top(*a, min, max);
		if (top == -1)
			break ;
		bot = find_bottom(*a, min, max);
		size = stack_size(*a);
		cheapest_rotate_to_top(a, top, bot, size);
		pb(a, b);
		if ((*b)->index < mid)
			rb(b);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;
	int	idx;

	while (*b)
	{
		idx = find_max_index(*b);
		pos = find_position(*b, idx);
		size = stack_size(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (pos++ < size)
				rrb(b);
		pa(a, b);
	}
}

static void	push_all_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	min;
	int	max;
	int	chunks;

	min = 0;
	if (size <= 50)
		chunks = 2;
	else if (size <= 100)
		chunks = 5;
	else if (size <= 500)
		chunks = 10;
	else if (size > 500)
		chunks = 17;
	i = 0;
	while (i < chunks)
	{
		min = size * i / chunks;
		max = size * (i + 1) / chunks - 1;
		if (i == chunks - 1)
			max = size -1;
		push_chunks_to_b(a, b, min, max);
		i++;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	push_all_chunks_to_b(a, b, size);
	push_back_to_a(a, b);
}
