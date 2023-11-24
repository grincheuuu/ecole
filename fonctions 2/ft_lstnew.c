/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:03:25 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 12:33:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	int	data;
	t_list	*new_node;

	data = 42;
	new_node = ft_lstnew(&data);
	return (0);
}*/

le contenu : Le contenu avec lequel le nœud doit être créé.
Valeur de retour Le nouveau noeud
Fonctions externes. malloc
Description Alloue (avec malloc(3)) et renvoie un nouveau noeud.
La variable membre "content" est initialisée avec la valeur du paramètre "content".
la valeur du paramètre "content". La variable
'next' est initialisée à NULL.

La fonction lstnew alloue de la mémoire pour un nouveau maillon et initialise ses champs avec les valeurs spécifiées. Le maillon est généralement défini comme une structure, et le champ content est utilisé pour stocker les données, tandis que le champ next est utilisé pour pointer vers le maillon suivant dans la liste chaînée.

Cette fonction lstnew crée un nouveau maillon (nœud) de la liste chaînée en allouant de la mémoire pour une structure t_list. Elle initialise le champ content avec les données spécifiées (passées en argument) et le champ next à NULL, car il s'agit du premier maillon de la liste (ou le dernier si la liste ne contient qu'un maillon).

L'instruction new_node->content = content; signifie que vous assignez la valeur de la variable content au champ content de la structure new_node. Voici comment cela fonctionne en détail :

    new_node est un pointeur vers une structure t_list. C'est le nouveau maillon que vous êtes en train de créer.

    -> est un opérateur de pointeur en C qui est utilisé pour accéder aux champs d'une structure (ou d'un pointeur vers une structure). Dans ce cas, il est utilisé pour accéder au champ content de la structure new_node.

    content est la variable que vous avez passée en argument à la fonction lstnew. C'est la donnée que vous souhaitez stocker dans le maillon.

En résumé, l'instruction new_node->content = content; copie la valeur de la variable content dans le champ content de la structure new_node. Cela permet d'associer les données spécifiées (passées en argument) au maillon que vous êtes en train de créer, de sorte que le maillon contienne ces données.

L'instruction new_node->next = NULL; signifie que vous attribuez la valeur NULL au champ next de la structure new_node. Voici ce que cela implique :

    new_node est un pointeur vers une structure t_list. C'est le maillon que vous êtes en train de créer.

    -> est un opérateur de pointeur en C qui est utilisé pour accéder aux champs d'une structure (ou d'un pointeur vers une structure). Dans ce cas, il est utilisé pour accéder au champ next de la structure new_node.

    NULL est une valeur spéciale en C qui représente un pointeur nul, c'est-à-dire un pointeur qui ne pointe vers aucune adresse mémoire valide.

L'instruction new_node->next = NULL; signifie que vous initialisez le champ next de new_node pour qu'il pointe vers aucune adresse mémoire. En d'autres termes, vous indiquez que le maillon que vous êtes en train de créer n'a pas de maillon suivant dans la liste chaînée, ce qui signifie qu'il est actuellement le dernier maillon de la liste.

