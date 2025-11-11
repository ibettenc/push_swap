/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/31 17:52:36 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *av)
{
	int	i;

	if (!av || !*av)
		return (-1);
	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (av[i] == '+' || av[i] == '-')
		{
			if (!ft_isdigit(av[i + 1]))
				return (-1);
			i++;
		}
		if (!ft_isdigit(av[i]))
			return (-1);
		while (ft_isdigit(av[i]))
			i++;
		if (av[i] && av[i] != ' ')
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

	val = ft_atol(str);
	if (val > 2147483647 || val < -2147483648)
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
