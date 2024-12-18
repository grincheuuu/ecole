/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:25:42 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/03 01:25:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
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
    t_list *last = ft_lstlast(list);
    if (last)
        printf("Dernier element de la liste : %s\n", (char *)last->content);
    else
        printf("La liste est vide.\n");
    while (list != NULL)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
*/