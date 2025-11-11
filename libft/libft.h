/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:24:09 by ibettenc          #+#    #+#             */
/*   Updated: 2025/11/03 14:11:32 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
