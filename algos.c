/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:08:16 by nromito           #+#    #+#             */
/*   Updated: 2024/03/22 16:35:18 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

bool	is_to_push(t_stack **stack_a, int j, t_stack *to_check, int size)
{
	t_stack	*node;
	int		check;

	node = *stack_a;
	check = 0;
	ft_index(*stack_a);
	while (node != NULL)
	{
		if (node->index == to_check->index || node->n > j)
		{
			check = 1;
			node = node->next;
		}
		else
		{
			if (node->index <= size / 2)
				check = first_half_push(node, to_check, size, check);
			else if (node->index > size / 2)
				check = second_half_push(node, to_check, size, check);
			node = node->next;
		}
	}
	return (check);
}

int	first_half_push(t_stack *node, t_stack *to_check, int size, int check)
{
	if (to_check->index <= size / 2)
	{
		if (to_check->index < node->index)
			check = 1;
		else
			check = 0;
	}
	else if (to_check->index > size / 2)
	{
		if (size + 1 - to_check->index <= node->index)
			check = 1;
		else
			check = 0;
	}
	return (check);
}

int	second_half_push(t_stack *node, t_stack *to_check, int size, int check)
{
	if (to_check->index >= size / 2)
	{
		if (size + 1 - to_check->index < size + 1 - node->index)
			check = 1;
		else
			check = 0;
	}
	else if (to_check->index < size / 2)
	{
		if (to_check->index <= size + 1 - node->index)
			check = 1;
		else
			check = 0;
	}
	return (check);
}
