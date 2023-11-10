/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:05:39 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 17:09:56 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*second;

	if (del == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		second = current->next;
		if (del != NULL)
			del(current->content);
		free(current);
		current = second;
	}
	*lst = NULL;
}
