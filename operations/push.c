/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/30 19:54:21 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*pif;

	if (!b || !*b)
		return ;
	pif = *b;
	*b = (*b)->next;
	pif->next = *a;
	*a = pif;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*pif;

	if (!a || !*a)
		return ;
	pif = *a;
	*a = (*a)->next;
	pif->next = *b;
	*b = pif;
	ft_printf("pb\n");
}
