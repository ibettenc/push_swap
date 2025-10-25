/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_and_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 19:47:04 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		a = a->next;
		count++;
	}
	return (count);
}

int	n_numbers(char *av) // a supprimer
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (av[i])
	{
		while (av[i] == ' ' || av[i] == '\t')
			i++;
		if (av[i] == '-' || av[i] == '+' || (av[i] >= '0' && av[i] <= '9'))
		{
			n++;
			if (av[i] == '-' || av[i] == '+')
				i++;
			while (av[i] >= '0' && av[i] <= '9')
				i++;
		}
		else if (av[i])
			return (-1);
	}
	return (n);
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
