/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:30:50 by nromito           #+#    #+#             */
/*   Updated: 2024/04/04 20:56:38 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **stack_a, t_stack **stack_b, int index, int size)
{
	ft_index(*stack_a);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack_a);
			index--;
		}
		pb(stack_a, stack_b);
	}
	else if (index > size / 2)
	{
		while (index < size)
		{
			rra(stack_a);
			index++;
		}
		pb(stack_a, stack_b);
	}
}

void	move_to_a(t_stack **stack_b, t_stack **stack_a, int index, int size)
{
	ft_index(*stack_b);
	if (index < size / 2)
	{
		while (index > 1)
		{
			rb(stack_b);
			index--;
		}
		if ((*stack_b)->n < (*stack_b)->next->n)
			sb(stack_b);
		else if (index == 1)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (index >= size / 2)
	{
		while (index < size)
		{
			if (size == 1 && index == 0)
				break;
			rrb(stack_b);
			index++;
		}
		pa(stack_a, stack_b);
	}
}
