/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:07:12 by nromito           #+#    #+#             */
/*   Updated: 2024/03/20 11:13:47 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
    t_stack	*last;
    t_stack	*first;
    t_stack	*head;
    t_stack	*temp;

    if (stack == NULL || (*stack)->next == NULL)
        return ;
    last = ft_stack_last(*stack);
    first = *stack;
    head = *stack;
    while (head->next != last)
        head = head->next;
    temp = head->next;
    head->next = NULL;
    temp->next = first;
    *stack = temp;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
