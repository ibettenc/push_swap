/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:53:02 by ibettenc          #+#    #+#             */
/*   Updated: 2025/09/22 13:01:12 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstnew(void *content)
{
	stack	*new;

	new = malloc(sizeof(stack));
	if (!new)
		return (NULL);
	new->content = content;
	return (new);
}
