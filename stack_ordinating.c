/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ordinating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:31:10 by nromito           #+#    #+#             */
/*   Updated: 2024/03/22 19:14:49 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//NORMINETTATO OK

t_stack	*create_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	int		size;
	int		num;

	new = NULL;
	stack = NULL;
	num = 0;
	size = 0;
	while (argv[size] != NULL)
		size++;
	while (--size > 0)
	{
		num = ft_atoi(argv[size]);
		if (check_num(num, argv[size]) == 0)
		{
			free_stack(&stack);
			ft_error(1);
		}
		new = ft_stack_new(num);
		ft_stack_add_front(&stack, new);
	}
	new = NULL;
	return (stack);
}

int	check_num(int num, char *argv)
{
	char	*s;

	s = ft_itoa(num);
	if (ft_strncmp(s, argv, ft_strlen(argv)) != 0)
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}

int	target_choice(int *arr, int size)
{
	if (size == 2)
		return (arr[0]);
	if (size <= 100)
		return (arr[size / 4]);
	else if (size <= 400)
		return (arr[size / 6]);
	else
		return (arr[size / 10]);
}

t_stack	*get_second_max(t_stack *stack_b, t_stack *node)
{
	t_stack	*second_max;

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
