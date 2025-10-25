/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 18:11:32 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ra(t_stack **a)
{
    t_stack *first;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return;
    first = *a;
    *a = first->next;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_printf("ra\n");
}

void    rb(t_stack **b)
{
    t_stack *first;
    t_stack *last;
    
    if (!b || !*b || !(*b)->next)
        return;
    first = *b;
    *b = first->next;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_printf("rb\n");
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    ft_printf("rr\n");
}
