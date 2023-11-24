/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:32:12 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 12:46:41 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

lst : L'adresse d'un pointeur sur le premier lien d'une liste.
d'une liste.
new : L'adresse d'un pointeur sur le nœud à ajouter à la liste.
ajouté à la liste.
Valeur de retour Aucune
Fonctions externes. Aucune
Description Ajoute le nœud "new" au début de la liste.

La fonction ft_lstadd_front a pour but d'ajouter un nouveau maillon (new) au début d'une liste chaînée représentée par un pointeur **lst. Voici comment cette fonction fonctionne :

    t_list **lst est un pointeur vers un pointeur de structure t_list. Cela signifie que lst est un pointeur qui pointe vers le premier maillon de la liste chaînée, et en utilisant **lst, nous pouvons accéder à la liste elle-même (c'est-à-dire, le pointeur qui pointe vers le premier maillon).

    t_list *new est le nouveau maillon que vous souhaitez ajouter au début de la liste.

La fonction ft_lstadd_front fait les opérations suivantes :

    Elle vérifie d'abord si le maillon new que vous souhaitez ajouter n'est pas NULL, car il n'aurait pas de sens d'ajouter un maillon nul à la liste.

    Ensuite, elle met à jour le champ next du nouveau maillon (new->next) pour qu'il pointe vers le maillon actuellement en tête de la liste, c'est-à-dire le maillon sur lequel pointe *lst. Cela signifie que le nouveau maillon devient le nouveau premier maillon de la liste, et il pointe vers l'ancien premier maillon.

    Enfin, elle met à jour le pointeur *lst pour qu'il pointe maintenant vers le nouveau maillon (*lst = new). Cela signifie que le pointeur qui pointe vers le premier maillon de la liste est mis à jour pour pointer vers le nouveau maillon que vous venez d'ajouter. Ainsi, le nouveau maillon devient le premier maillon de la liste.
