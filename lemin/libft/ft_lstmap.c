/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:35:19 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 13:53:04 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	start = newlst;
	lst = lst->next;
	while (lst)
	{
		newlst->next = ft_lstnew(f(lst->content));
		if (newlst->next == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	return (start);
}
