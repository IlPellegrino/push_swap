/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:05:57 by nromito           #+#    #+#             */
/*   Updated: 2024/03/06 11:09:59 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	int	i;

	if (stack_from->size < 1)
		return ;
	i = stack_to->size;
	while (i > 0)
	{
		stack_to->array[i] = stack_to->array[i - 1];
		i--;
	}
	stack_to->array[0] = stack_from->array[0];
	stack_to->size++;
	i = 0;
	while (i < stack_from->size - 1)
	{
		stack_from->array[i] = stack_from->array[i + 1];
		i++;
	}
	stack_from->size--;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
