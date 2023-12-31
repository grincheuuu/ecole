/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:43:51 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 15:00:26 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(void *content)
{
	char *str = (char *)content;
	printf("%s\n", str);
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int	main(void)
{
	t_list	*myList = NULL;

	ft_lstiter(myList, &print_string);
	return (0);
}*/

lst : L'adresse d'un pointeur sur un nœud.
f : L'adresse de la fonction utilisée pour itérer sur la
sur la liste.
Valeur de retour Aucune
Fonctions externes. Aucune
Description Itère la liste "lst" et applique la fonction
'f' sur le contenu de chaque nœud.
