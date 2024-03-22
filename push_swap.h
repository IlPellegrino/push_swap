/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:27 by nromito           #+#    #+#             */
/*   Updated: 2024/03/22 19:13:13 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	int				index;
	struct s_stack	*next;
}				t_stack;
//main.c
t_stack	*ft_argv_check(char **argv);
void	check_duplicates(int argc, char **argv);
//moves.c
void	move_to_b(t_stack **stack_a, t_stack **stack_b, int index, int size);
void	move_to_a(t_stack **stack_b, t_stack **stack_a, int index, int size);
//stack_utils.c
t_stack	*ft_stack_new(int n);
int		ft_stack_size(t_stack *stack_a);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_last(t_stack *stack);
//stack_ordinating.c
int		target_choice(int *arr, int size);
int		check_num(int num, char *argv);
t_stack	*create_stack(char **argv);
t_stack	*get_max(t_stack *stack_b);
t_stack	*get_second_max(t_stack *stack_b, t_stack *node);
//commands_swap.c
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
//commands_push.c
void	push(t_stack **stack_from, t_stack **stack_to);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//commands_r.c
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
//commands_rr.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
//clean_and_error.c
void	ft_error(int error_code);
void	ft_error_free(t_stack **stack_a);
void	free_matrix(char **matrix);
void	free_stack(t_stack **stack);
//algos.c
void	ft_index(t_stack *stack_a);
bool	is_to_push(t_stack **stack_a, int j, t_stack *to_check, int size);
int		first_half_push(t_stack *node, t_stack *to_check, int size, int check);
int		second_half_push(t_stack *node, t_stack *to_check, int size, int check);
//sorting.c
void	sorting(t_stack **stack_a, int size);
void	sort_all(t_stack **stack_a, int size);
void	first_sorting(t_stack **stack_a, t_stack **stack_b, int j, int size);
void	second_sorting(t_stack *stack_b, t_stack **stack_a);
void	half_2(t_stack *stack_b, t_stack **stack_a, t_stack *node, int size);
//sorting_2.c
int		*create_arr(t_stack *stack_a, int size);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a, int size);
void	sort_int_tab(int *arr, int size);

#endif