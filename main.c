/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:12:25 by nromito           #+#    #+#             */
/*   Updated: 2024/03/19 20:46:56 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fare makefile
//fare algoritmo per numeri piccoli
//fare algoritmo per numeri medi e numeri grandi
//controllare le varie funzioni per gli errori e i free
//aggiungere tutte le funzioni all'header
//finiamolo entro la fine del mese! DAJE!

t_stack	*ft_argv_check(char **argv)
{
	t_stack *tmp;
	t_stack *stack;
	char 	**matrix;
	int 	i;
	int 	num;
	
	i = 0;
	num = 0;
	stack = NULL;
	matrix = ft_split(argv[1], ' ');
	while (matrix[i] != NULL)
		i++;
	i--;
	while (i >= 0)
	{
		num = ft_atoi(matrix[i]);
		tmp = ft_stack_new(num);
		ft_stack_add_front(&stack, tmp);
		i--;
	}
	free_matrix(matrix);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		size;
	
	stack_a = NULL;
	if (argc < 2 || !argv[1][0])
		ft_error (0);
	if (argc == 2)
		stack_a = ft_argv_check(argv);
	else
		stack_a = create_stack(argv);
	size = ft_stack_size(stack_a);
	if (!stack_a)
		ft_error_free(&stack_a);
	if (size >= 1 && size <= 500)
		sorting(&stack_a, size);
	// free_stack(stack_a);
	return (0);
}
