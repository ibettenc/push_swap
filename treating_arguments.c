/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treating_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/31 13:22:02 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate(t_stack **a, char *str, int *value)
{
	if (is_digit(str) == -1)
		return (-1);
	if (check_int_range(str) == -1)
		return (-1);
	*value = ft_atoi(str);
	if (is_double(*a, *value) == -1)
		return (-1);
	return (0);
}

static void	handle_error(t_stack **a)
{
	write (2, "Error\n", 6);
	free_stack(*a);
	*a = NULL;
}

int	treating_int(int ac, char **av, t_stack **a)
{
	int	i;
	int	value;

	i = 1;
	while (i < ac)
	{
		if (validate(a, av[i], &value) == -1)
		{
			handle_error(a);
			return (-1);
		}
		push_node_back(a, value);
		i++;
	}
	return (0);
}

int	convert(t_stack **a, char *av)
{
	char	**numbers;
	int		i;
	int		value;

	numbers = ft_split(av, ' ');
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	i = 0;
	while (numbers[i])
	{
		if (validate(a, numbers[i], &value) == -1)
		{
			free_split(numbers);
			handle_error(a);
			return (-1);
		}
		push_node_back(a, value);
		i++;
	}
	free_split(numbers);
	return (0);
}

int	treating_argv(t_stack **a, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		return (convert(a, av[1]));
	return (treating_int(ac, av, a));
}
