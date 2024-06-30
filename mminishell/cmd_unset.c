/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:35:12 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/01 14:37:02 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_pointer **pointera, char **var)
{
	t_list	*temp;
	int		status;
	int		t;

	status = 0;
	t = 1;
	temp = NULL;
	while (var[t] != NULL)
	{
		temp = (*pointera)->first;
		status = ft_unset_deux(var[t], temp, pointera);
		t++;
	}
	return (0);
}

int	ft_unset_deux(char *var, t_list *temp, t_pointer **pointera)
{
	int	j;
	int	status;

	j = 0;
	status = 0;
	if (ft_isalpha(var[j]) == 0 && var[j] != '_')
		return (status);
	while (var[j] != '\0')
	{
		if (ft_isalpha(var[j]) == 0 && ft_isdigit(var[j]) == 0 && var[j] != '_'
			&& var[j] != '=')
			return (status);
		if (var[j] == '=')
			return (status);
		j++;
	}
	ft_unset_trois(var, temp, pointera);
	return (status);
}

void	ft_unset_trois(char *var, t_list *temp, t_pointer **pointera)
{
	int	i;

	i = 0;
	while (temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var) - 1) == 0)
		{
			ft_free_maillon(pointera, i);
			break ;
		}
		temp = temp->next;
		i++;
	}
}

void	ft_free_maillon(t_pointer **pointera, int i)
{
	t_list	*temp;
	int		j;

	j = 0;
	temp = (*pointera)->first;
	while (temp != NULL && j < i)
	{
		temp = temp->next;
		j++;
	}
	if (temp == NULL)
		return ;
	if (temp->next != NULL)
		temp->next->before = temp->before;
	else
		(*pointera)->end = temp->before;
	if (temp->before != NULL)
		temp->before->next = temp->next;
	else
		(*pointera)->first = temp->next;
	free(temp->str);
	free(temp);
}

void	ft_lstclear_bis_pointera(t_pointer **pointera)
{
	t_list	*current;
	t_list	*second;
	t_list	*chaine;

	chaine = (*pointera)->first;
	if (chaine == NULL)
		return ;
	current = chaine;
	while (current != NULL)
	{
		second = current->next;
		free(current->str);
		free(current);
		current = second;
	}
	chaine = NULL;
}
