/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:05:39 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 17:09:56 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*second;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		second = current->next;
		if (del != NULL)
			del(current->content);
		free(current);
		current = second;
	}
	*lst = NULL;
}

lst : L'adresse d'un pointeur sur un nœud.
del : L'adresse de la fonction utilisée pour supprimer
le contenu du noeud.
Valeur de retour Aucune
Fonctions externes free
Description Supprime et libère le nœud donné et tous les successeurs de ce nœud, à l'aide de la fonction "del".
successeur de ce noeud, en utilisant la fonction "del" et free(3).
et free(3).
Enfin, le pointeur sur la liste doit être positionné à
NUL

La fonction ft_lstclear a pour but de supprimer tous les maillons d'une liste chaînée, en libérant la mémoire associée à chaque maillon et à ses données. Voici comment cette fonction fonctionne :

    t_list **lst est un pointeur vers un pointeur de structure t_list. Cela signifie que lst est un pointeur qui pointe vers le premier maillon de la liste chaînée, et en utilisant **lst, nous pouvons accéder à la liste elle-même.

    void (*del)(void *) est un pointeur de fonction vers une fonction qui sera utilisée pour libérer la mémoire associée aux données stockées dans chaque maillon. Cette fonction de libération est fournie en tant que pointeur de fonction et est appelée sur le champ content de chaque maillon avant que le maillon lui-même ne soit libéré.

La fonction ft_lstclear fait les opérations suivantes :

    Elle commence par vérifier si le pointeur lst ou *lst est NULL ou si la fonction de libération del est NULL. Si l'un des trois est NULL, cela signifie qu'aucune suppression n'est nécessaire, et la fonction se termine immédiatement sans aucune opération supplémentaire.

    Elle initialise deux pointeurs current et second. current est initialisé avec la valeur de *lst, c'est-à-dire le premier maillon de la liste. second est initialisé à NULL pour le moment.

    Ensuite, elle entre dans une boucle while qui parcourt la liste chaînée en utilisant le pointeur current.

    À chaque itération de la boucle, elle sauvegarde le pointeur current->next dans second. Cela permet de conserver un pointeur vers le maillon suivant de la liste avant de supprimer le maillon actuel.

    Elle vérifie si la fonction de libération del n'est pas NULL, puis elle appelle del(current->content) pour libérer la mémoire associée aux données stockées dans le maillon actuel.

    Ensuite, elle utilise la fonction free pour libérer la mémoire du maillon actuel en appelant free(current).

    Elle met à jour le pointeur current pour qu'il pointe vers le maillon suivant en utilisant current = second. Cela permet de passer au maillon suivant.

    La boucle continue à parcourir les maillons de la liste jusqu'à ce que current atteigne la fin de la liste, c'est-à-dire jusqu'à ce qu'il soit NULL.

    Finalement, elle met à jour *lst pour qu'il pointe vers NULL, indiquant que la liste chaînée est maintenant vide.
