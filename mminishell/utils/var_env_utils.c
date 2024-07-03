/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:37:24 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/01 18:11:20 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_search_home(t_pointer *pointera, char *var)
{
	t_list	*temp;
	char	*home;

	home = NULL;
	temp = pointera->first;
	while (temp != NULL)
	{
		if (ft_strncmp(var, temp->str, 4) == 0)
		{
			home = ft_strdup(temp->str + 5);
			return (home);
		}
		temp = temp->next;
	}
	return (NULL);
}

char	*ft_search_env_var(t_pointer *pointera, char *var)
{
	t_list	*temp;
	char	*home;

	home = NULL;
	temp = pointera->first;
	while (temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var) - 1) == 0)
		{
			home = ft_strdup(temp->str + ft_strlen(var));
			return (home);
		}
		temp = temp->next;
	}
	return (NULL);
}

void	ft_shlvl(t_pointer **pointera)
{
	char	*var;
	char	*op;
	int		i;

	var = NULL;
	op = NULL;
	i = -1;
	i = ft_search_var(*pointera, "SHLVL=");
	if (i < 0)
		ft_export_plus(pointera);
	else
	{
		op = ft_export_moin(pointera, i);
		var = ft_strjoin("SHLVL=", op);
		free(op);
		ft_maillon_change(pointera, i, var);
		free(var);
	}
}
