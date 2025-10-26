/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/26 14:58:28 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *av)
{
	int	i;

	i = 0;
	if (!av || !*av)
		return (-1);

	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		if ((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))
			i++;
		if (!ft_isdigit(av[i]))
			return (-1);
		while (ft_isdigit(av[i]))
			i++;
		while (av[i] == ' ')
			i++;
		if (av[i] && av[i] != '+' && av[i] != '-' && !ft_isdigit(av[i])
			&& av[i] != ' ')
			return (-1);
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

int	check_int_range(char *str)
{
	long	val;

	val = ft_atol(str); // ft_atol retourne long pour éviter overflow
	if (val > INT_MAX || val < INT_MIN)
		return (-1);
	return (0);
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
			free_stack(*a);
			*a = NULL;
			return (-1);
		}
		value = ft_atoi(av[i]);
		if (is_double(*a, value) == -1)
		{
			write(2, "Error : is_double\ndouble numbers\n", 33);
			free_stack(*a);
			*a = NULL;
			return (-1);
		}
		push_back(a, value);
		i++;
	}
	return (0);
}

