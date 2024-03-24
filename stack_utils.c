/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:35:07 by nromito           #+#    #+#             */
/*   Updated: 2024/03/24 15:51:21 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//NORMINETTATO OK

t_stack	*ft_stack_new(int n)
{
	t_stack	*newstack;

	newstack = malloc(sizeof(t_stack));
	if (newstack == NULL)
		return (NULL);
	newstack->n = n;
	newstack->next = NULL;
	return (newstack);
}

int	ft_stack_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_stack_last(*stack);
	last->next = new;
}
