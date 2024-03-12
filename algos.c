/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:08:16 by nromito           #+#    #+#             */
/*   Updated: 2024/03/12 19:08:43 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_median(t_stack *stack_a)
{
	int	*array;
	int	median;
	int	i;
	int	tot_arr;
	
	i = 0;
	array = malloc(sizeof(int *) * stack_a->size);
	while (stack_a->next != NULL)
	{
		array[i++] = stack_a->content;
		stack_a = stack_a->next;
	}
	i = -1;
	while (++i <= stack_a->size)
		tot_arr += array[i];
	median = tot_arr / stack_a->size;
	return (median);
}