/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:35:07 by nromito           #+#    #+#             */
/*   Updated: 2024/03/19 20:50:56 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    t_stack *head;

    if (*stack == NULL)
    {
        *stack = new;
        return ;
    }
    last = ft_stack_last(*stack);
    head = last;
    last->next = new;
}


t_stack	*create_stack(char **argv)
{
	t_stack *stack;
	int 	size;
	int 	num;
	
	stack = NULL;
	num = 0;
	size = 0;
	while (argv[size] != NULL)
		size++;
	size--;
	while (size > 0)
	{
		num = ft_atoi(argv[size]);
		ft_stack_add_front(&stack, ft_stack_new(num));
		size--;
	}
	return (stack);
}

// t_stack *create_stack_b(int size)
// {
// 	t_stack *tmp;
// 	t_stack *stack;
// 	int 	i;
	
// 	i = 0;
// 	while (i < size)
// 	{
// 		tmp = ft_stack_new(0);
// 		ft_stack_add_front(&stack, tmp);
// 		i++;
// 	}
// 	return (stack);
// }

