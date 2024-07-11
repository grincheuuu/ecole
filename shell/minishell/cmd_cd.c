/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:44:55 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/24 17:00:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *str, t_list *env_list, t_pointer *pointera, int argc)
{
	char	*var;
	int	i;

	var = NULL;
	i = 0;
	if (str == NULL && argc == 2)
	{
		ft_only_cd(pointera, "HOME=", argc);
		ft_pwd(env_list, pointera);
		printf("1\n");
		return ;
	}
	printf("%s1\n", str);
	if (chdir(str))
	{
		strerror(errno);
		ft_lstclear(&env_list);
    	free(pointera);
   		exit(EXIT_FAILURE);
	}
	else
	{
		ft_pwd(env_list, pointera);
		var = ft_strjoin("PWD=", str);
		if (ft_search_var(pointera, var) == 1)
			ft_export(var, env_list, pointera);
		free(var);
		return ;
	}
}

void	ft_only_cd(t_pointer *pointera, char *var, int argc)
{
	t_list	*temp;
	char	*zoz;
	int	i;

	i = 0;
	zoz = NULL;
	(void)argc;
	temp = pointera->first;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var)) == 0)
		{
			zoz = ft_strdup(temp->str + 5);
			ft_cd(zoz, pointera->first, pointera, argc);
			free (zoz);
			return ;
		}
		temp = temp->next;
		i++;
	}
	return ;
}
