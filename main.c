/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/11/03 14:31:58 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	assign_index(*a);
	if (stack_size(*a) == 2)
		sort_2(a);
	else if (stack_size(*a) == 3)
		sort_3(a);
	else if (stack_size(*a) == 4)
		sort_4(a, b);
	else if (stack_size(*a) == 5)
		sort_5(a, b);
	else
		big_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (treating_argv(&a, ac, av) == -1)
		return (-1);
	if (is_sorted(&a))
	{
		free_stack(a);
		return (0);
	}
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
