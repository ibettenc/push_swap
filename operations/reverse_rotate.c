/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 19:41:35 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
    t_stack	*prev;
    t_stack	*last;

    if (!a || !*a || !(*a)->next)
        return;
    prev = NULL;
    last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
    t_stack	*prev;
    t_stack	*last;
    
    if (!b || !*b ||!(*b)->next)
        return;
    prev = NULL;
    last = *b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    ft_printf("rrr\n");
}
