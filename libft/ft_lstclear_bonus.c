/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:59:53 by nromito           #+#    #+#             */
/*   Updated: 2024/03/11 17:34:19 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	if (!lst || !temp)
		return ;
	while (temp != NULL)
	{
		temp2 = temp->next;
		del(temp->content);
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
}
