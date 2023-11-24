/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:29:42 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 17:31:13 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	if (lst->content != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
int	main(void)
{
	t_list	*node = ft_lstnew("heelo, World");

	ft_lstdelone(node, custom_del);
	return (0);
}*/

lst : Le nœud à libérer.
del : L'adresse de la fonction utilisée pour supprimer
le contenu.
Valeur de retour Aucune
Fonctions externes. free
Description Prend en paramètre un nœud et libère la mémoire du contenu du nœud à l'aide de la fonction "del" donnée.
le contenu du nœud à l'aide de la fonction "del" fournie en
en tant que paramètre et libère le nœud. La mémoire de
'next' ne doit pas être libérée

La fonction ft_lstdelone a pour but de supprimer un maillon spécifique d'une liste chaînée, en libérant la mémoire associée au maillon. Voici comment cette fonction fonctionne :

    t_list *lst est un pointeur vers le maillon que vous souhaitez supprimer de la liste chaînée.

    void (*del)(void *) est un pointeur de fonction vers une fonction qui sera utilisée pour libérer la mémoire associée aux données stockées dans le maillon. Cette fonction de libération est fournie en tant que pointeur de fonction et est appelée sur le champ content du maillon avant que le maillon lui-même ne soit libéré.

La fonction ft_lstdelone fait les opérations suivantes :

    Elle commence par vérifier si le maillon lst que vous souhaitez supprimer est NULL ou si la fonction de libération del est NULL. Si l'un des deux est NULL, cela signifie que la suppression n'est pas nécessaire, et la fonction se termine immédiatement sans aucune opération supplémentaire.

    Ensuite, elle vérifie si le champ content du maillon lst n'est pas NULL. Si le champ content n'est pas NULL, cela signifie qu'il y a des données associées à ce maillon qui doivent être libérées. La fonction de libération del est appelée sur le champ content pour libérer la mémoire associée à ces données.

    Après la libération des données, elle utilise la fonction free pour libérer la mémoire associée au maillon lui-même, en appelant free(lst). Cela supprime le maillon de la mémoire.

Ainsi, la fonction ft_lstdelone supprime un maillon spécifique de la liste chaînée, en libérant la mémoire associée aux données stockées dans ce maillon, puis en libérant la mémoire du maillon lui-même. Elle est utile pour gérer la mémoire de manière appropriée lors de la suppression de maillons d'une liste chaînée.
