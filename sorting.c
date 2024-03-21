/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:11 by nromito           #+#    #+#             */
/*   Updated: 2024/03/20 20:15:31 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, int size)
{
	if (size >= 1 && size <= 3)
		sort_three(stack_a, size);
	// else if (size >= 4 && size <= 5)
	// 	sort_five(stack_a, size);
	else
		sort_all(stack_a, size);
}

void sort_all(t_stack **stack_a, int size)
{
	t_stack *stack_b;
	int 	*arr;
	int		j;

	arr = create_arr((*stack_a), size);
	if (arr == NULL)
		ft_error(1);
	j = target_choice(arr, size);
	stack_b = NULL;
	// stack_b = create_stack_b(size);
	while (size > 2)
	{
		first_sorting(stack_a, &stack_b, j, size);
		size = ft_stack_size((*stack_a));
		free(arr);
		arr = create_arr((*stack_a), size);
		j = target_choice(arr, size);
	}
	sort_two(stack_a);
//	sort_three(stack_a, size);
	second_sorting(stack_b, stack_a);
	// move_to_a(&stack_b, stack_a, size);
	free(arr);
	// free_stack(stack_b);
}

int target_choice(int *arr, int size)
{
	if (size == 2)
		return (arr[0]);
//	if (size <= 50)
//		return (arr[size / 3]);
	if (size <= 100)
		return (arr[size / 4]);
	// else if (size <= 200)
	// 	return (arr[size / 6]);
	// else if (size <= 300)
	// 	return (arr[size / 8]);
	else if (size <= 400)
		return (arr[size / 6]);
	else
		return (arr[size / 10]);
}

void	first_sorting(t_stack **stack_a, t_stack **stack_b, int j, int size)
{
	t_stack *node;

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
	t_stack *node;
	t_stack *second_max;
	int size;
	
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

t_stack *get_second_max(t_stack *stack_b, t_stack *node)
{
	t_stack *second_max;
	
	second_max = NULL;
	while (stack_b != NULL)
	{
		if (node->n + stack_b->n > second_max->n)
			second_max = stack_b;
		stack_b = stack_b->next;
	}
	return (second_max);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;
	
	max = stack;
	while (stack != NULL)
	{
		if (stack->n > max->n)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
