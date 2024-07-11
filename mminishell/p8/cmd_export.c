/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:46:42 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/29 18:02:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_only(t_pointer *pointera)
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
}

int	ft_export(char **str, t_pointer **pointera)
{
	t_list	*new;
	int		i;
	int		status;

	new = NULL;
	i = 0;
	status = 0;
	if (str[1] == NULL)
	{
		ft_export_only(*pointera);
		return (0);
	}
	while (str[++i] != NULL)
	{
		if (ft_test_var(str[i], pointera) == 0)
		{
			new = ft_lstnew_bis(str[i]);
			if (new == NULL)
				return (1);
			ft_lstadd_back_bis_pointer(pointera, new);
		}
		else
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
			return (0);
		}
	}
	return (1);
}

int	ft_search_var(t_pointer *pointera, char *var)
{
	t_list	*temp;
	int		i;
	int		j;
	int		len_var;

	i = -1;
	j = 0;
	len_var = 1;
	temp = pointera->first;
	while (var[j++] != '\0' && var[j] != '=')
		len_var += 1;
	while (temp != NULL)
	{
		i++;
		if (ft_strncmp(var, temp->str, len_var) == 0)
			return (i);
		temp = temp->next;
	}
	return (-1);
}

void	ft_maillon_change(t_pointer **pointera, int i, char *var)
{
	t_list	*temp;
	t_list	*new;
	int		j;

	j = 0;
	temp = (*pointera)->first;
	while (temp != NULL && j < i)
	{
		temp = temp->next;
		j++;
	}
	new = ft_lstnew_bis(var);
//	if (new == NULL)
//		return ;
	if (temp->next != NULL)
		temp->next->before = new;
	else
		(*pointera)->end = new;
	if (temp->before != NULL)
		temp->before->next = new;
	else
		(*pointera)->first = new;
	new->next = temp->next;
	new->before = temp->before;
	free(temp->str);
	free(temp);
}

void	ft_export_error(char *var)
{
	write(2, "bash: export: '", 16);
	ft_putstr_fd(var, 2);
	write(2, "': not a valid identifier\n", 27);
}
