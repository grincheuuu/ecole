/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:01:12 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/30 17:11:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	new_list = NULL;
	if (lst == NULL || f == NULL)
		return (0);
	new_list = NULL;
	while (lst != NULL)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

lst : L'adresse d'un pointeur sur un nœud.
f : L'adresse de la fonction utilisée pour itérer sur la
sur la liste.
Valeur de retour Aucune
Fonctions externes. Aucune
Description Itère la liste "lst" et applique la fonction
'f' sur le contenu de chaque nœud.

La fonction ft_lstmap a pour but de créer une nouvelle liste chaînée en appliquant une fonction f à chaque maillon de la liste chaînée originale lst. Cette nouvelle liste chaînée contient les résultats de l'application de f à chaque élément de la liste originale. Voici comment cette fonction fonctionne :

    t_list *lst est un pointeur vers le premier maillon de la liste chaînée d'origine que vous souhaitez parcourir.

    void *(*f)(void *) est un pointeur de fonction vers une fonction qui sera utilisée pour transformer les données de chaque maillon de la liste d'origine en de nouvelles données qui seront stockées dans la nouvelle liste.

    void (*del)(void *) est un pointeur de fonction vers une fonction de suppression qui sera utilisée pour libérer la mémoire associée aux données si une erreur se produit lors de la création de la nouvelle liste.

La fonction ft_lstmap fait les opérations suivantes :

    Elle commence par vérifier si la liste d'origine lst est NULL ou si la fonction f est NULL. Si l'une de ces conditions est vraie, la fonction retourne NULL pour indiquer qu'aucune nouvelle liste n'a été créée.

    Ensuite, elle initialise un pointeur new_list à NULL. Ce pointeur sera utilisé pour construire la nouvelle liste chaînée.

    Elle entre dans une boucle while qui parcourt la liste chaînée d'origine lst. Tant que lst n'est pas NULL, la boucle continue.

    À chaque itération de la boucle, elle crée un nouveau maillon new_elem en utilisant la fonction ft_lstnew et en passant les données transformées à partir de f(lst->content) comme contenu du nouveau maillon. Si la création du nouveau maillon échoue (c'est-à-dire si new_elem est NULL), la fonction supprime la nouvelle liste déjà créée en appelant ft_lstclear avec del, puis retourne NULL pour indiquer qu'une erreur s'est produite.

    Si la création du nouveau maillon new_elem réussit, elle ajoute ce maillon à la nouvelle liste chaînée en utilisant la fonction ft_lstadd_back. Le nouveau maillon est ajouté à la fin de la nouvelle liste.

    Ensuite, elle met à jour lst pour qu'il pointe vers le maillon suivant de la liste d'origine en utilisant lst = lst->next, ce qui permet de passer au maillon suivant.

    La boucle continue à parcourir la liste d'origine, en créant des nouveaux maillons et en les ajoutant à la nouvelle liste, jusqu'à ce que tous les maillons de la liste d'origine aient été traités.

    Finalement, elle retourne la nouvelle liste chaînée new_list qui contient les données transformées.
