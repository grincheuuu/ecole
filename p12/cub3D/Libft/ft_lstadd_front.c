/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:00:58 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/03 01:00:58 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main()
{
	t_list *list = NULL;
	char *str1 = "Premier element";
	char *str2 = "Deuxieme element";
	char *str3 = "Troisieme element";

	ft_lstadd_front(&list, ft_lstnew(str1));
	ft_lstadd_front(&list, ft_lstnew(str2));
	ft_lstadd_front(&list, ft_lstnew(str3));

	t_list *current = list;
	while (current != NULL)
	{
		printf("element de la liste : %s\n", (char *)current->content);
		current = current->next;
	}
	while (list != NULL)
	{
		t_list *temp = list;
		list = list->next;
		free(temp);
	}

	return 0;
}
*/