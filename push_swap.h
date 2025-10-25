/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#             */
/*   Updated: 2025/10/25 19:42:53 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_stack
{
	int n_operation;
	int value;
	int index;
	struct s_stack *next;
}   t_stack;

void    free_stack(t_stack *head);
t_stack    *create_node(int n);
void push_back(t_stack **head, int value);
void free_split(char **numbers);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
int is_digit(char *av);
int n_numbers(char *av);
int is_double(t_stack *head, int value);
void    show_stack(t_stack *head);
int treating_int(int ac, char **av, t_stack **a);
int stack_size(t_stack *a);
int     find_top(t_stack *a, int min, int max);
int     find_bottom(t_stack *a, int min, int max);
int is_sorted(t_stack **x);
int	find_max_index(t_stack *b);
int	find_position(t_stack *b, int index);
void    sort_2(t_stack **a);
void    sort_3(t_stack **a);
void	assign_index(t_stack *a);
void    push_chunk_to_b(t_stack **a, t_stack **b, int min, int max);
void	big_sort(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);
