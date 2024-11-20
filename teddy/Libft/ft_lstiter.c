/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:39:03 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/06 01:39:03 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pos;

	if (!lst)
		return ;
	pos = lst;
	while (pos != NULL)
	{
		(*f)(pos->content);
		pos = pos->next;
	}
}
/*
void print_element(void *content)
{
    printf("%s\n", (char *)content);
}

int main()
{
    t_list *element1 = malloc(sizeof(t_list));
    element1->content = "Premier element";
    element1->next = NULL;

    t_list *element2 = malloc(sizeof(t_list));
    element2->content = "Deuxieme element";
    element2->next = NULL;

    t_list *element3 = malloc(sizeof(t_list));
    element3->content = "Troisieme element";
    element3->next = NULL;

    t_list *list = element1;
    element1->next = element2;
    element2->next = element3;

    ft_lstiter(list, &print_element);

    free(element1);
    free(element2);
    free(element3);

    return 0;
}
*/