/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:12:25 by nromito           #+#    #+#             */
/*   Updated: 2024/03/22 19:42:51 by nromito          ###   ########.fr       */
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
			ft_error(1);
		}
		tmp = ft_stack_new(num);
		ft_stack_add_front(&stack, tmp);
	}
	free_matrix(matrix);
	return (stack);
}

void	check_duplicates(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				ft_error(0);
			j++;
		}
		i++;
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
	free_stack(&stack_a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		size;

	stack_a = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		stack_a = ft_argv_check(argv);
		if (is_sorted(stack_a))
			return (0);
	}
	else
	{
		stack_a = create_stack(argv);
		if (is_sorted(stack_a))
			return (0);
	}
	check_duplicates(argc, argv);
	size = ft_stack_size(stack_a);
	if (!stack_a)
		ft_error_free(&stack_a);
	if (size >= 1 && size <= 500)
		sorting(&stack_a, size);
	free_stack(&stack_a);
}
