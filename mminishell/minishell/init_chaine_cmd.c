/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chaine_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:02:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/10 18:42:46 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_node_cmd(t_lexing *node)
{
	if (node->cmd != NULL)
		free(node->cmd);
	free(node);
}

void	ft_lstclear_node(t_lexing **chaine)
{
	t_lexing	*current;
	t_lexing	*second;

	if (*chaine == NULL)
		return ;
	current = *chaine;
	while (current != NULL)
	{
		second = current->next;
		ft_free_node_cmd(current);
		current = second;
	}
	*chaine = NULL;
}

void	ft_printlist_cmd(t_pointer_cmd *pointerB)
{
	t_lexing	*temp;
	int			i;

	temp = NULL;
	i = 0;
	if (pointerB == NULL)
	{
		write(1, "NULL", 4);
		return ;
	}
	temp = pointerB->first;
	while (temp->next)
	{
		printf("cmd : %s\n", temp->cmd);
		printf("type : %d\n", temp->special_token);
		temp = temp->next;
		i++;
		printf("\n");
	}
}

void	ft_lstadd_back_cmd(t_cmd **chaine, t_cmd *new)
{
	t_cmd	*temp;

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
