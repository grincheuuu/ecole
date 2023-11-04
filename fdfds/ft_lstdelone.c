/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:29:42 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 17:31:13 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	if (lst->content != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
int	main(void)
{
	t_list	*node = ft_lstnew("heelo, World");

	ft_lstdelone(node, custom_del);
	return (0);
}*/
