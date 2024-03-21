/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:09:30 by nromito           #+#    #+#             */
/*   Updated: 2024/03/19 17:54:37 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
    t_stack	*first;
    t_stack	*last;
    t_stack *head;

    if (stack == NULL || (*stack)->next == NULL)
        return ;
    first = (*stack);
    last = ft_stack_last(*stack);
    head = last;
    (*stack) = first->next;
    first->next = NULL;
    head->next = first;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
