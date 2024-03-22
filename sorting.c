/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:11 by nromito           #+#    #+#             */
/*   Updated: 2024/03/22 17:06:20 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, int size)
{
	if (size >= 1 && size <= 3)
		sort_three(stack_a, size);
	else
		sort_all(stack_a, size);
}

void	sort_all(t_stack **stack_a, int size)
{
	t_stack	*stack_b;
	int		*arr;
	int		j;

	arr = create_arr((*stack_a), size);
	if (arr == NULL)
		ft_error(1);
	j = target_choice(arr, size);
	stack_b = NULL;
	while (size > 2)
	{
		first_sorting(stack_a, &stack_b, j, size);
		size = ft_stack_size((*stack_a));
		free(arr);
		arr = create_arr((*stack_a), size);
		j = target_choice(arr, size);
	}
	free(arr);
	sort_two(stack_a);
	second_sorting(stack_b, stack_a);
	stack_b = NULL;
}

void	first_sorting(t_stack **stack_a, t_stack **stack_b, int j, int size)
{
	t_stack	*node;

	node = NULL;
	node = *stack_a;
	ft_index(*stack_a);
	while (node != NULL)
	{
		if (node->n <= j)
		{
			if (is_to_push(stack_a, j, node, size) == 1)
			{
				move_to_b(stack_a, stack_b, node->index, size);
				size--;
				ft_index(*stack_a);
				node = *stack_a;
			}
			else
				node = node->next;
		}
		else
			node = node->next;
	}
}

void	second_sorting(t_stack *stack_b, t_stack **stack_a)
{
	int		size;
	t_stack	*node;

	node = stack_b;
	size = ft_stack_size(stack_b);
	ft_index(stack_b);
	while (size > size / 2)
	{
		node = get_max(stack_b);
		move_to_a(&stack_b, stack_a, node->index, size);
		ft_index(stack_b);
		size--;
	}
	half_2(stack_b, stack_a, node, size);
}

void	half_2(t_stack *stack_b, t_stack **stack_a, t_stack *node, int size)
{
	t_stack	*second_max;

	second_max = NULL;
	while (stack_b)
	{
		node = get_max(stack_b);
		second_max = get_second_max(stack_b, node);
		if (node->index - second_max->index > 1)
		{
			move_to_a(&stack_b, stack_a, second_max->index, size);
			size--;
			ft_index(stack_b);
		}
		move_to_a(&stack_b, stack_a, node->index, size);
		size--;
		ft_index(stack_b);
	}
}
