/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 21:29:32 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	convert(t_stack **a, char *av)
{
	char	**numbers;
	int	i;
	int	value;

	i = 0;
	numbers = ft_split(av, ' ');
	if (!numbers)
	{
		write(2, "Error : ft_split\n", 17);
		return (-1);
	}
	while (numbers[i])
	{
		value = ft_atoi(numbers[i]);
		if (is_double(*a, value) == -1)
		{
			write(2, "Error : convert\ndouble numbers\n", 31);
			free_split(numbers);
			return (-1);	
		}
		push_back(a, value);
		i++;
	}
	free_split(numbers);
	return (0);
}

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int	index;

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
	else
		big_sort(a,b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	if (ac < 2)
	{
		write(2, "Error : no arguments\n", 21);
		return (-1);
	}
	if (ac == 2)
	{
		if (is_digit(av[1]) == -1)
		{
			write(2, "Error : is_digit\ndigits only\n", 28);
			return (-1);
		}
		convert(&a, av[1]);
	}
	if (ac > 2)
	{
		if (treating_int(ac, av, &a) == -1)
			return (-1);
	}
	show_stack(a); //
	if (is_sorted(&a))
		return (0);
	push_swap(&a, &b);
	ft_printf("---\n"); //
	show_stack(a); //
	free_stack(a);
	free_stack(b);
	return (0);
}

