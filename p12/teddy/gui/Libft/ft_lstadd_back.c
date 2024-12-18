/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:21:30 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/03 14:21:30 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = ft_lstlast(*lst);
		pos->next = new;
	}
}
/*
int main()
{
	t_list *list = NULL;
	char *str1 = "Premier element";
	char *str2 = "Deuxieme element";
	char *str3 = "Troisieme element";

	ft_lstadd_back(&list, ft_lstnew(str1));
	ft_lstadd_back(&list, ft_lstnew(str2));
	ft_lstadd_back(&list, ft_lstnew(str3));

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