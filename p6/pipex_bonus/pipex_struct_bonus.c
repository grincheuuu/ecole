/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:00:43 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/16 20:07:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_lstclear(t_listp **chaine)
{
	t_listp	*current;
	t_listp	*second;

	current = *chaine;
	if (*chaine == NULL)
		return ;
	while (current != NULL)
	{
		second = current->next;
		free(current);
		current = second;
	}
	*chaine = NULL;
}

t_listp	*ft_lstnew(void)
{
	t_listp	*new_node;

	new_node = (t_listp *)malloc(sizeof(t_listp));
	if (new_node == NULL)
		return (NULL);
	new_node->pid = 0;
	new_node->file_fd = 0;
	new_node->status = 0;
	new_node->next = NULL;
	new_node->before = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_listp **chaine, t_listp *new)
{
	t_listp	*temp;

	temp = *chaine;
	if (*chaine == NULL)
		*chaine = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->before = temp;
		new->next = NULL;
	}
}

t_listp	*ft_maillon(t_listp *listp, t_pointer *pointerA)
{
	t_listp	*new;

	new = NULL;
	new = ft_lstnew();
	if (new == NULL)
	{
		ft_lstclear(&pointerA->first);
		return (NULL);
	}
	ft_lstadd_back(&listp, new);
	pointerA->end = new;
	listp = listp->next;
	return (listp);
}
