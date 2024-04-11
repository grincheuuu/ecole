/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:21:53 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 17:10:07 by gschwart         ###   ########.fr       */
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
}
