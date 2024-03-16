/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:21:53 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/08 16:06:23 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*ft_lstnew(int nb)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->nb = nb;
	new_node->before = NULL;
	new_node->next = NULL;
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

void	ft_affect(t_list *pile_a, t_pointer *pointerA)
{
	t_list	*temp;

	temp = pile_a;
	if (pile_a == NULL)
		return ;
	pointerA->first = pile_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	pointerA->end = temp;
}

void	ft_pointerEnd(t_pointer *pointerC)
{
	t_list	*temp;
	t_list	*late;

	late = NULL;
	temp = pointerC->first;
	if (pointerC->first == NULL)
		return ;
	while (temp->next != NULL)
	{
		late = temp;
		temp = temp->next;
	}
	pointerC->end = temp;
	pointerC->end->before = late;
}

t_list	*ft_maillonlist(int argc, char **argv)
{
	int	i;
	t_list	*new;
	t_list	*chaine;

	i = 1;
	new = NULL;
	chaine = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (new == NULL)
		{
			ft_lstclear(&chaine);
			return (NULL);
		}
		ft_lstadd_back(&chaine, new);
		i++;
	}
	return (chaine);
}
