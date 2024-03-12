/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:36:27 by nromito           #+#    #+#             */
/*   Updated: 2024/03/12 19:16:46 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vsmall_sort(t_stack *stack_a)
{
	if (stack_a->size == 2 && stack_a->content > stack_a->next->content)
		sa(stack_a);
	else if (stack_a->content > stack_a->next->content 
				&& stack_a->content > stack_a->next->next->content)
	{
		ra(stack_a);
		if (stack_a->content > stack_a->next->content)
			sa(stack_a);
	}
	else if (stack_a->content > stack_a->next->content 
			&& stack_a->content < stack_a->next->next->content)
		sa(stack_a);
	else if (stack_a->content > stack_a->next->next->content 
			&& stack_a->content < stack_a->next->content)
		rra(stack_a);
	else if (stack_a->next->content > stack_a->next->next->content)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
}

void	small_sort(t_stack *stack_a)
{
	int	median;

	median = algo_median(stack_a);
	while (stack_a->next != NULL)
	{
		
	}
}
