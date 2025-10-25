/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 19:42:16 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
    t_stack	*first;
    t_stack	*second;

    if (!*a || !a || !(*a)->next)
        return;
    first = *a;
    second = (*a)->next;
    
    first->next = second->next;
    second->next = first;
    *a = second;
    ft_printf("sa\n");
}

void	sb(t_stack **b)
{
    t_stack	*first;
    t_stack	*second;
    
    if (!b || !*b || !(*b)->next)
        return;
    first = *b;
    second = (*b)->next;

    first->next = second->next;
    second->next = first;
    *b = second;
    ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    ft_printf("ss\n");
}  
