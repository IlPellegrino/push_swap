/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:12:25 by nromito           #+#    #+#             */
/*   Updated: 2024/03/11 17:24:35 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc < 2 || !argv[1][0])
		ft_error (0);
	if (argc == 2)
		stack_a = ft_argc_check(argv[1]);
	else
		stack_a = create_stack(argv);
	stack_a->size = ft_lstsize(stack_a);
	if (!stack_a)
		ft_error_free(stack_a);
	// if (is_sorted(stack_a))
	// {
	// 	free_stack(stack_a);
	// 	return (0);
	// }
	if (stack_a->size <= 5)
		sort_small(stack_a);
	else
		sort_big(stack_a);
	free_stack(stack_a);
	return (0);
}
