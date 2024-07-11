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
	char	*copy;

	temp = pointera->first;
	copy = NULL;
	while (temp != NULL)
	{
		copy = ft_strjoin("declare -x ", temp->str);
		free(temp->str);
		temp->str = ft_strdup(copy);
		free(copy);
		write (1, temp->str, ft_strlen(temp->str));
		write (1, "\n", 1);
		temp = temp->next;
	}
}

int	ft_export(char *str, t_list *env_list, t_pointer *pointera)
{
	char	**tab;
	t_list	*new;
	int	i;
	int	j;

	new = NULL;
	i = 0;
	j = 0;
	if (str == NULL)
	{
		ft_export_only(pointera);
		return (0);
	}
	tab = ft_split(str, ' ');
	while (tab[i] != NULL)
	{
		if (ft_test_var(tab[i], pointera, &tab) == 0)
		{
			new = ft_lstnew(tab[i]);
			if (new == NULL)
			{
				ft_lstclear(&env_list);
				ft_fre(tab);
				return (1); //status = 1
			}
			ft_lstadd_back(&env_list, new);
		}
		i++;
	}
	ft_fre(tab);
	return (0); // status=0
}

int	ft_test_var(char *var, t_pointer *pointera, char ***tab)
{
	int	i;
	int	t;

	i = 0;
	t = 1;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
	{
		ft_export_error(var, pointera->first, pointera, tab);
		return (1);
	}
	while (var[i] != '\0' && var[i] != '=')
	{
		if (ft_isalpha(var[i]) == 0 && ft_isdigit(var[i]) == 0 && var[i] != '_' && var[i] != '=')
		{
			ft_export_error(var, pointera->first, pointera, tab);
			return (1);
		}
		i++;
	}
	if (var[i] == '=')
		t = 0;
	while (var[i] != '\0')
	{
		if ((var[i] >= 0 && var[i] <= 31) && var[i] == 127)
		{
			ft_export_error(var, pointera->first, pointera, tab);
			return (1);
		}
		i++;
	}
	if (t == 0)
	{
		if (ft_search_var(pointera, var) == 0)
			return (0);
		if (ft_search_var(pointera, var) == 1)
			ft_maillon_change(pointera, i, var);
	}
	return (1);
}

int	ft_search_var(t_pointer *pointera, char *var)
{
	t_list	*temp;
	int	i;
	int	j;
	int	len_var;

	i = 0;
	j = 0;
	len_var = 1;
	temp = pointera->first;
	while (var[j++] != '=' && var[j++] != '\0')
		len_var += 1;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, len_var) == 0)
		{
			return (1);
		}
		temp = temp->next;
		i++;
	}
	return (0);
}

void	ft_maillon_change(t_pointer *pointera, int i, char *var)
{
	t_list	*temp;
	t_list	*new;
	int	j;

	j = 0;
	temp = pointera->first;
	while (j < i)
	{
		temp = temp->next;
		j++;
	}
	new = ft_lstnew(var);
	if (new == NULL)
	{
		ft_lstclear(&pointera->first);
		return ;
	}
	new->next = temp->next;
	new->before = temp->before;
	free(temp);
	if (pointera->first == NULL)
		pointera->first = new;
	if (pointera->end == NULL)
		pointera->end = new;
}

void	ft_export_error(char *var, t_list *env_list, t_pointer *pointera, char ***tab)
{
	int	i;

	i = 0;
	write (2, "bash: export: '", 16);
	ft_putstr_fd(var, 2);
	write (2, "': not a valid identifier\n", 27);
	ft_lstclear(&env_list);
	free(pointera);
	ft_fre(*tab);
	exit(EXIT_FAILURE);
}
