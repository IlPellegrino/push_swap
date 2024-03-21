/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:36:27 by nromito           #+#    #+#             */
/*   Updated: 2024/03/20 16:14:47 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, int size)
{
	if (size == 2 && (*stack_a)->n > (*stack_a)->next->n)
		sa(stack_a);
	else if ((*stack_a)->n > (*stack_a)->next->n
				&& (*stack_a)->n > (*stack_a)->next->next->n)
	{
		ra(stack_a);
		if ((*stack_a)->n > (*stack_a)->next->n)
			sa(stack_a);
	}
	else if ((*stack_a)->n > (*stack_a)->next->n 
			&& (*stack_a)->n < (*stack_a)->next->next->n)
		sa(stack_a);
	else if ((*stack_a)->n > (*stack_a)->next->next->n 
			&& (*stack_a)->n < (*stack_a)->next->n)
		rra(stack_a);
	else if ((*stack_a)->next->n > (*stack_a)->next->next->n)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
}

// void	sort_five(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	if (size == 2 && (*stack_a)->n > (*stack_a)->next->n)
// 		sa(stack_a);
// 	else if ((*stack_a)->n > (*stack_a)->next->n
// 				&& (*stack_a)->n > (*stack_a)->next->next->n)
// 	{
// 		ra(stack_a);
// 		if ((*stack_a)->n > (*stack_a)->next->n)
// 			sa(stack_a);
// 	}
// 	else if ((*stack_a)->n > (*stack_a)->next->n 
// 			&& (*stack_a)->n < (*stack_a)->next->next->n)
// 		sa(stack_a);
// 	else if ((*stack_a)->n > (*stack_a)->next->next->n 
// 			&& (*stack_a)->n < (*stack_a)->next->n)
// 		rra(stack_a);
// 	else if ((*stack_a)->next->n > (*stack_a)->next->next->n)
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 		rra(stack_a);
// 	}
// }

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->n > (*stack_a)->next->n)
		sa(stack_a);
}
int *create_arr(t_stack *stack_a, int size)
{
	int i;
	int *arr;

	i = 0;
	arr = malloc(sizeof(int) * size + 1);
	if (!arr)
		return (NULL);
	while (stack_a != NULL)
	{
		arr[i] = stack_a->n;
		stack_a = stack_a->next;
		i++;
	}
	arr = sort_int_tab(arr);
	return (arr);
}

int	*sort_int_tab(int *arr)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (arr[i] != '\0')
	{
		j = 0;
		while (arr[j] != '\0')
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
