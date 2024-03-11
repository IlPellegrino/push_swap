/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:11 by nromito           #+#    #+#             */
/*   Updated: 2024/03/11 17:10:19 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *stack_a)
{
	if (stack_a->size == 2)
	{
		if (stack_a->content > stack_a->next->content)
			sa(stack_a);
	}
	else if (stack_a->size == 3)
	{
		
	}
	else if (stack_a->size == 4)
	{
		
	}
	else if (stack_a->size == 5)
	{
		
	}
}

t_stack	*create_stack(char **argv)
{
	t_stack *tmp;
	int 	i;
	int 	num;
	
	num = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		num = ft_atoi(argv[i]);
		tmp = ft_lstnew(num);
		ft_lstadd_back(&argv, tmp);
		i++;
	}
	return (tmp);
}

t_stack	*ft_argc_check(char **argv)
{
	t_stack *tmp;
	char 	**matrix;
	int 	i;
	int 	num;
	
	i = 0;
	num = 0;
	matrix = ft_split(argv[1], ' ');
	while (matrix[i] != NULL)
	{
		num = ft_atoi(matrix[i]);
		tmp = ft_lstnew(num);
		ft_lstadd_back(&matrix, tmp);
		i++;
	}
	free_matrix(matrix);
	return (tmp);
}
void	sort_big(t_stack *stack_a)
{
	if (stack_a->size > 5 && stack_a->size <= 100)
	{
		// sort_100(stack_a);
	}
	else if (stack_a->size > 100 && stack_a->size <= 500)
	{
		// sort_500(stack_a);
	}
}
