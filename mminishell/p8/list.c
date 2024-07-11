/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:04:34 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/25 17:04:53 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_maillonlist(char **env)
{
	t_list	*new;
	t_list	*chaine;
	int		i;

	i = 0;
	new = NULL;
	chaine = NULL;
	while (env[i] != NULL)
	{
		new = ft_lstnew_bis(env[i]);
		if (new == NULL)
		{
			ft_lstclear_bis(&chaine);
			return (NULL);
		}
		ft_lstadd_back_bis(&chaine, new);
		i++;
	}
	return (chaine);
}
void	ft_lstclear_bis(t_list **chaine)
{
	t_list	*current;
	t_list	*second;

	if (*chaine == NULL)
		return ;
	current = *chaine;
	while (current != NULL)
	{
		second = current->next;
		free(current->str);
		free(current);
		current = second;
	}
	*chaine = NULL;
}

t_list	*ft_lstnew_bis(char *str)
{
	t_list	*new_node;
	char	*line;

	line = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	line = ft_strdup(str);
	new_node->str = line;
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->before = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_bis(t_list **chaine, t_list *new)
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
