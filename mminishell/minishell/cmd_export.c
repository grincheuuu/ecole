/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:46:42 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/10 16:19:37 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_only(t_pointer *pointera)
{
	t_list	*temp;

	temp = pointera->first;
	while (temp != NULL)
	{
		write(1, "declare -x ", 11);
		write(1, temp->str, ft_strlen(temp->str));
		write(1, "\n", 1);
		temp = temp->next;
	}
	return (0);
}

int	ft_export(char **str, t_pointer **pointera)
{
	t_list	*new;
	int		i;
	int		j;
	int		status;

	new = NULL;
	i = 0;
	status = 0;
	if (str[1] == NULL)
		return (ft_export_only(*pointera));
	while (str[++i] != NULL)
	{
		j = ft_test_var(str[i], pointera);
		if (j == 0)
		{
			new = ft_lstnew_bis(str[i]);
			if (new == NULL)
				return (1);
			ft_lstadd_back_bis_pointer(pointera, new);
		}
		else if (j != 3000)
			status = 1;
	}
	return (status);
}

void	ft_lstadd_back_bis_pointer(t_pointer **pointera, t_list *new)
{
	t_list	*temp;
	t_list	*chaine;

	chaine = (*pointera)->first;
	temp = chaine;
	if (chaine == NULL)
		chaine = new;
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

int	ft_test_var(char *var, t_pointer **pointera)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = -1;
	t = 1;
	if (var == NULL)
		return (2);
	if ((ft_isalpha(var[i]) == 0 && var[i] != '_'))
	{
		ft_export_error(var);
		return (1);
	}
	while (var[i] != '\0' && var[i] != '=')
	{
		if (ft_isalpha(var[i]) == 0 && ft_isdigit(var[i]) == 0 && var[i] != '_'
			&& var[i] != '=')
		{
			ft_export_error(var);
			return (1);
		}
		i++;
	}
	return (ft_test_var_deux(var, i, t, pointera));
}

int	ft_test_var_deux(char *var, int i, int t, t_pointer **pointera)
{
	if (var[i] == '=')
		t = 0;
	while (var[i] != '\0')
	{
		if ((var[i] >= 0 && var[i] <= 31) && var[i] == 127)
		{
			ft_export_error(var);
			return (1);
		}
		i++;
	}
	if (t == 0)
	{
		i = ft_search_var(*pointera, var);
		if (i < 0)
			return (0);
		if (i >= 0)
		{
			ft_maillon_change(pointera, i, var);
		}
	}
	return (3000);
}
