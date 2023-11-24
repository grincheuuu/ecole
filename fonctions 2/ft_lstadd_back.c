/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:24 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 14:27:11 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

lst : L'adresse d'un pointeur sur le premier lien d'une liste.
d'une liste.
new : L'adresse d'un pointeur sur le nœud à ajouter à la liste.
ajouté à la liste.
Valeur de retour Aucune
Fonctions externes. Aucune
Description Ajoute le nœud "new" à la fin de la liste.

La fonction ft_lstadd_back a pour but d'ajouter un nouveau maillon (new) à la fin d'une liste chaînée représentée par un pointeur **lst. Voici comment cette fonction fonctionne :

    t_list **lst est un pointeur vers un pointeur de structure t_list. Cela signifie que lst est un pointeur qui pointe vers le premier maillon de la liste chaînée, et en utilisant **lst, nous pouvons accéder à la liste elle-même.

    t_list *new est le nouveau maillon que vous souhaitez ajouter à la fin de la liste.

La fonction ft_lstadd_back fait les opérations suivantes :

    Elle commence par créer une variable temp et l'initialise avec la valeur de *lst. Cette variable temp sera utilisée pour parcourir la liste chaînée et trouver le dernier maillon.

    Ensuite, elle vérifie si le pointeur *lst (c'est-à-dire, la liste elle-même) est NULL. Si *lst est NULL, cela signifie que la liste est vide, et dans ce cas, elle met à jour *lst pour qu'il pointe vers le nouveau maillon new. Cela signifie que le nouveau maillon devient le premier maillon de la liste.

    Si *lst n'est pas NULL, cela signifie qu'il y a au moins un maillon dans la liste. Elle entre dans une boucle while qui parcourt la liste chaînée en utilisant la variable temp.

    À chaque itération de la boucle, elle met à jour temp pour qu'il pointe vers le maillon suivant de la liste en utilisant temp = temp->next. Cela permet de passer au maillon suivant.

    La boucle continue à parcourir les maillons de la liste jusqu'à ce qu'elle atteigne le dernier maillon, c'est-à-dire jusqu'à ce que temp->next soit NULL.

    Une fois la boucle terminée et que temp pointe vers le dernier maillon de la liste, elle met à jour le champ next de ce dernier maillon pour qu'il pointe vers le nouveau maillon new, ce qui ajoute le nouveau maillon à la fin de la liste.

