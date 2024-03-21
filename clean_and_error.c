/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:03:43 by nromito           #+#    #+#             */
/*   Updated: 2024/03/19 20:47:44 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error_code)
{
	if (error_code == 0)
		ft_putstr_fd("Error\n", 2);
	else if (error_code == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void ft_error_free(t_stack **stack)
{
	// free_stack(*stack);
	(void)stack;
}

void  free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// void free_stack(t_stack *stack)
// {
// 	t_stack *tmp;

// 	// while (stack)
// 	// {
// 	// 	tmp = stack;
// 	// 	stack = stack->next;
// 	// }
// }

