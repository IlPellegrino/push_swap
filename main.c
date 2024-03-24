/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:12:25 by nromito           #+#    #+#             */
/*   Updated: 2024/03/24 16:20:40 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//NORMINETTATO OK

t_stack	*ft_argv_check(char **argv)
{
	t_stack	*tmp;
	t_stack	*stack;
	char	**matrix;
	int		i;
	int		num;

	i = 0;
	num = 0;
	stack = NULL;
	matrix = ft_split(argv[1], ' ');
	while (matrix[i] != NULL)
		i++;
	while (--i >= 0)
	{
		num = ft_atoi(matrix[i]);
		if (check_num(num, matrix[i]) == 0)
		{
			free_matrix(matrix);
			ft_error(stack, 1);
		}
		tmp = ft_stack_new(num);
		ft_stack_add_front(&stack, tmp);
	}
	free_matrix(matrix);
	return (stack);
}

void	check_duplicates(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->n == tmp2->n)
				ft_error(stack_a, 0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->n > stack_a->next->n)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		size;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (!argv[1][0])
		ft_error(stack_a, 0);
	if (argc == 2)
		stack_a = ft_argv_check(argv);
	else
		stack_a = create_stack(argv);
	check_duplicates(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	size = ft_stack_size(stack_a);
	if (!stack_a)
		ft_error_free(&stack_a);
	if (size >= 1 && size <= 500)
		sorting(&stack_a, size);
	free_stack(&stack_a);
}
