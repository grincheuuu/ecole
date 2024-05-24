/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_ajout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:59:35 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/16 15:59:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error_deux(int n, const char *str, t_file_fd *t_file)
{
	if (n == -1)
	{
		perror(str);
		free(t_file);
		return (1);
	}
	return (0);
}

void	ft_free_last(char **patch)
{
	free(patch);
	write (2, " command not found last", 23);
}

void	ft_absolut_path(char *argv, char **com, char **env)
{
	char	**pop;

	pop = ft_split(argv, ' ');
	if ((access(pop[0], F_OK | X_OK) == 0))
		execve(pop[0], com, env);
/*	if (ft_buildin(pop[0]) == 1)
		execve;*/
	ft_fre(pop);
}