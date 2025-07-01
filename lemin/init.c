/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:03 by gschwart          #+#    #+#             */
/*   Updated: 2025/06/30 18:05:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*ft_lstnew(void)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->before = NULL;
	new_node->next = NULL;
	new_node->count = 0;
	new_node->chemin = NULL;
	new_node->name = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **chaine, t_list *new)
{
	t_list	*temp;

	temp = *chaine;
	if (*chaine == NULL)
		*chaine = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->before = temp;
		new->next = NULL;
	}
}

void	ft_lstclear(t_list **chaine)
{
	t_list	*current;
	t_list	*second;

	if (*chaine == NULL)
		return ;
	current = *chaine;
	while (current != NULL)
	{
		second = current->next;
		free(current);
		current = second;
	}
	*chaine = NULL;
}

void	ft_affect(t_list *pile_a, t_pointer *pointera)
{
	t_list	*temp;

	temp = pile_a;
	if (pile_a == NULL)
		return ;
	pointera->first = pile_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	pointera->end = temp;
}

/*
void	ft_pointerend(t_pointer *pointerc)
{
	t_list	*temp;
	t_list	*late;

	late = NULL;
	temp = pointerc->first;
	if (pointerc->first == NULL)
		return ;
	while (temp->next != NULL)
	{
		late = temp;
		temp = temp->next;
	}
	pointerc->end = temp;
	pointerc->end->before = late;
}*/

t_pointer	*ft_pointera(int argc, char **argv, t_pointer *pointera)
{
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (NULL);
	pointera = malloc(sizeof(t_pointer));
	return (pointera);
}

void	ft_initialisation(t_pointer **pointerb,
		t_list **pile_a, t_list **pile_b, char ***arv)
{
	*pointerb = NULL;
	*pile_a = NULL;
	*pile_b = NULL;
	*arv = NULL;
}

void	ft_fre(char **patch)
{
	int	i;

	i = 0;
	while (patch[i] != NULL)
	{
		free(patch[i]);
		i++;
	}
	free(patch);
}
