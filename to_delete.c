/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 19:44:51 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *head) // a supprimer
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d -> ", current->value);
		current = current->next;
	}
	ft_printf("NULL\n");
}
