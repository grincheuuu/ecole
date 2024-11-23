/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:46:05 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/03 15:46:05 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		pos = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pos;
	}
}
/*
void my_del(void *content)
{
    free(content);
}

int main()
{
    t_list *list = ft_lstnew("Premier element");
    ft_lstadd_front(&list, ft_lstnew("Deuxieme element"));
    ft_lstadd_front(&list, ft_lstnew("Troisieme element"));
    printf("Contenu de la liste avant la suppression:\n");
    t_list *current = list;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    ft_lstclear(&list, my_del);
    if (list == NULL)
        printf("Tous les elements ont ete supprimes avec succes.\n");
    else
        printf("La suppression a echoue. La liste n'est pas vide.\n");
    return 0;
}
*/