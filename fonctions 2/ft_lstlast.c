/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:40:58 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 12:44:33 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

lst : Le début de la liste.
Valeur de retour Dernier noeud de la liste
Fonctions externes. Aucune
Description Renvoie le dernier nœud de la liste

La fonction ft_lstlast a pour but de renvoyer un pointeur vers le dernier maillon d'une liste chaînée. Voici comment cette fonction fonctionne :

    t_list *lst est un pointeur vers le premier maillon de la liste chaînée que vous souhaitez parcourir.

La fonction ft_lstlast fait les opérations suivantes :

    Elle commence par vérifier si le pointeur lst est NULL (c'est-à-dire, s'il n'y a aucun maillon dans la liste). Si c'est le cas, elle retourne immédiatement NULL, car il n'y a pas de dernier maillon à renvoyer.

    Si lst n'est pas NULL, cela signifie qu'il y a au moins un maillon dans la liste. Elle entre ensuite dans une boucle while pour parcourir la liste.

    À chaque itération de la boucle, elle met à jour le pointeur lst pour qu'il pointe vers le maillon suivant dans la liste en utilisant lst = lst->next. Cela permet de passer au maillon suivant.

    La boucle continue à parcourir les maillons de la liste jusqu'à ce qu'elle atteigne le dernier maillon, c'est-à-dire jusqu'à ce que lst->next soit NULL.

    Finalement, une fois que la boucle a atteint le dernier maillon, elle retourne le pointeur lst, qui pointe maintenant vers le dernier maillon de la liste.
