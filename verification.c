/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 19:44:14 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *av)
{
	int	i;

	i = 0;
	if (!av || !*av)
		return (-1);

	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!(av[i] >= '0' && av[i] <= '9'))
		return (-1);
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack **x)
{
	t_stack	*pif;

	if (!x || !*x)
		return (1);
	pif = *x;
	while (pif->next)
	{
		if (pif->value > pif->next->value)
			return (0);
		pif = pif->next;
	}
	return (1);
}

int	is_double(t_stack *head, int value)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		if (current->value == value)
			return (-1);
		else
			current = current->next;
	}
	return (0);
}


int	treating_int(int ac, char **av, t_stack **a)
{
	int	i;
	int	value;

	i = 1;
	while (i < ac)
	{
		if (is_digit(av[i]) == -1)
		{
			write (2, "Error : is_digit\ndigit only\n", 28);
			return (-1);
		}
		value = ft_atoi(av[i]);
		if (is_double(*a, value) == -1)
		{
			write(2, "Error : is_double\ndouble numbers\n", 33);
			free_stack(*a);
			return (-1);
		}
		push_back(a, value);
		i++;
	}
	return (0);
}

