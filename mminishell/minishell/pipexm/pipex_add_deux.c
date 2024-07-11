/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_add_deux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:59:15 by gschwart          #+#    #+#             */
/*   Updated: 2024/07/02 16:59:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_parents(int pipe_fd[])
{
	ft_signaux_pipeline(0);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}

int	ft_exit_arg_nb(char **argv)
{
	int	i;

	i = 1;
	while (argv[i++] != NULL)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (1);
	}
	return (0);
}

void	ft_end_child(char **argv, char **env, char **patch)
{
	int	status;

	status = 127;
	ft_test_dir(argv[0]);
	ft_fre(env);
	ft_fre(argv);
	if (patch != NULL)
		ft_fre(patch);
}

void	ft_execve_error(int n, const char *str, char ***thor, char ***com)
{
	(void)thor;
	(void)com;
	if (n == -1)
	{
		perror(str);
	}
}

void	ft_parent_last(t_listp **listp)
{
	ft_signaux_pipeline(0);
	close((*listp)->before->pipe_fd[0]);
}
