/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:42:27 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/30 17:47:16 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_pointer *pointerA)
{
	pointerA->first = NULL;
	pointerA->end = NULL;
	pointerA->status = 0;
}

char	**ft_transform_env_list(t_pointer **pointera)
{
	t_list	*temp;
	char	**env_tab;
	int		i;

	i = 0;
	env_tab = NULL;
	temp = (*pointera)->first;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	env_tab = malloc((i + 1) * sizeof(char *));
	if (env_tab == NULL)
		return (NULL);
	temp = (*pointera)->first;
	i = 0;
	while (temp != NULL)
	{
		env_tab[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

int	ft_print_env(t_pointer **pointerA)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (*pointerA == NULL)
	{
		return (1);
	}
	temp = (*pointerA)->first;
	while (temp != NULL)
	{
		write(1, temp->str, ft_strlen(temp->str));
		write(1, "\n", 1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	ft_cd_moin(t_pointer **pointera)
{
	int		i;
	int		j;
	t_list	*temp;
	char	*old_pwd;

	j = 0;
	old_pwd = NULL;
	temp = (*pointera)->first;
	i = ft_search_var(*pointera, "OLDPWD=");
	if (i == 0)
		i = ft_search_var(*pointera, "PWD=");
	while (temp != NULL && j < i)
	{
		temp = temp->next;
		j++;
	}
	old_pwd = ft_strdup(temp->str + 7);
	ft_cd(old_pwd, pointera);
	free(old_pwd);
	ft_pwd();
	return (0);
}

void	ft_realize_oldpwd(char *old_pwd, t_pointer **pointera)
{
	char	**op;

	op = malloc(3 * sizeof(char *));
	if (old_pwd == NULL)
		return ;
	op[0] = ft_strdup("export");
	op[1] = ft_strjoin("OLDPWD=", old_pwd);
	op[2] = NULL;
	ft_export(op, pointera);
	ft_fre(op);
}

/*
void	ft_printlist(t_pointer *pointerA)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (pointerA == NULL)
	{
		write(1, "NULL", 4);
		return ;
	}
	temp = pointerA->first;
	while (temp != NULL)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
		i++;
	}
}*/
