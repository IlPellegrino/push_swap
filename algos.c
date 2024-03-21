/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:08:16 by nromito           #+#    #+#             */
/*   Updated: 2024/03/20 20:06:17 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*reset_stack(t_stack **stack_a, t_stack **head)
// {
// 	*stack_a = *head;
// 	ft_index(stack_a);
// 	return (*stack_a);
// }

bool	is_to_push(t_stack **stack_a, int j, t_stack *to_check, int size) //riguardare condizioni per avere true come risultato
{
	t_stack *node;
	int	check;
	
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
			if (node->index <= size / 2) // prima meta' dello stack a GAY!!
			{
				if (to_check->index <= size / 2) // tmp nella prima meta'
				{
					if (to_check->index < node->index)
						check = 1;
					else
						check = 0;
				}
				else if (to_check->index > size / 2) //tmp nella seconda meta'
				{	
					if (size + 1 - to_check->index <= node->index)
						check = 1;
					else
						check = 0;
				}
			}
			else if (node->index > size / 2)
			{
				if (to_check->index >= size / 2) //tmp nella seconda meta'
				{	
					if (size + 1 - to_check->index < size + 1 - node->index)
						check = 1;
					else
						check = 0;
				}
				else if (to_check->index < size / 2) // tmp nella prima meta'
				{
					if (to_check->index <= size + 1 - node->index)
						check = 1;
					else
						check = 0;
				}
			}
			node = node->next;
			if (node == NULL)
				return (check);
		}
	}
	return(check);
}

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



// bool	calculate_big_b(t_stack *stack_b)
// {
// 	t_stack *tmp;
// 	int	check;
// 	int size;

// 	size = ft_stack_size(stack_b);
// 	check = 1;
// 	to_check->index = stack_b->index;
// 	while(stack_b->prev != NULL)
// 		stack_b = stack_b->prev;
// 	while (stack_b != NULL)
// 	{
// 		if (stack_b == tmp)
// 			stack_b = stack_b->next;
// 		else 
// 		{
// 			if (stack_b->index <= size / 2) // prima meta' dello stack a
// 			{
// 				if (tmp->index <= size / 2) // tmp nella prima meta'
// 				{	
// 					if (tmp->index < stack_b->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 				else if (tmp->index > size / 2) //tmp nella seconda meta'
// 				{	
// 					if (size + 1 - tmp->index < stack_b->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 			}
// 			else if (stack_b->index > size / 2)
// 			{
// 				if (tmp->index <= size / 2) // tmp nella prima meta'
// 				{	
// 					if (tmp->index < size + 1 - stack_b->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 				else if (tmp->index > size / 2) //tmp nella seconda meta'
// 				{	
// 					if (size + 1 - tmp->index < size + 1 - stack_b->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 			}
// 			stack_b = stack_b->next;
// 		}
// 	}
// 	return(check);
// }


// bool	calculate_big_a(t_stack *stack_a, int lis_max)
// {
// 	t_stack *tmp;
// 	int	check;

// 	int size = ft_stack_size(stack_a);
// 	check = 1;
// 	tmp->index = stack_a->index;
// 	stack_a = reset_stack(stack_a);
// 	while (stack_a != NULL)
// 	{
// 		if (stack_a == tmp || stack_a->n < lis_max)
// 			stack_a = stack_a->next;
// 		else 
// 		{
// 			if (stack_a->index <= size / 2) // prima meta' dello stack a
// 			{
// 				if (tmp->index <= size / 2) // tmp nella prima meta'
// 				{	
// 					if (tmp->index < stack_a->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 				else if (tmp->index > size / 2) //tmp nella seconda meta'
// 				{	
// 					if (size + 1 - tmp->index < stack_a->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 			}
// 			else if (stack_a->index > size / 2)
// 			{
// 				if (tmp->index <= size / 2) // tmp nella prima meta'
// 				{	
// 					if (tmp->index < size + 1 - stack_a->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 				else if (tmp->index > size / 2) //tmp nella seconda meta'
// 				{	
// 					if (size + 1 - tmp->index < size + 1 - stack_a->index)
// 						check = 1;
// 					else
// 						return (0);
// 				}
// 			}
// 			stack_a = stack_a->next;
// 		}
// 	}
// 	return(check);
// }
