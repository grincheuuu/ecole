/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:34:56 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 14:04:26 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

Paramètres lst : Le début de la liste.
Valeur de retour La longueur de la liste
Fonctions externes. Aucune
Description Compte le nombre de nœuds dans une liste.

La fonction ft_lstsize a pour but de compter le nombre de maillons (éléments) dans une liste chaînée. Voici comment cette fonction fonctionne :

    t_list *lst est un pointeur vers le premier maillon de la liste chaînée que vous souhaitez parcourir.

La fonction ft_lstsize fait les opérations suivantes :

    Elle initialise une variable count à 0. Cette variable servira à compter le nombre de maillons dans la liste.

    Ensuite, elle entre dans une boucle while qui parcourt la liste chaînée. Tant que lst n'est pas NULL (c'est-à-dire, tant qu'il y a un maillon à parcourir), la boucle continue.

    À chaque itération de la boucle, elle incrémente la variable count de 1 pour compter le maillon actuel.

    Ensuite, elle met à jour le pointeur lst pour pointer vers le maillon suivant de la liste, en utilisant lst = lst->next.

    La boucle continue à parcourir les maillons de la liste jusqu'à ce que lst atteigne la fin de la liste, c'est-à-dire jusqu'à ce que lst soit NULL.

    Finalement, elle retourne la valeur de la variable count, qui représente le nombre de maillons dans la liste chaînée.
