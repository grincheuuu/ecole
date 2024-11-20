/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:25:12 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/03 01:25:12 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*pos;

	i = 0;
	pos = lst;
	while (pos != NULL)
	{
		pos = pos->next;
		i++;
	}
	return (i);
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

	int size = ft_lstsize(list);
	printf("Taille de la liste : %d\n", size);

	while (list != NULL)
	{
		t_list *temp = list;
		list = list->next;
		free(temp);
	}

	return 0;
}
*/