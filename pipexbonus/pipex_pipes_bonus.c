/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/23 19:07:39 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_un(int file_fd, int *pipe_fd, char *argv, char **env)
{
	char	**patch;
	int		t;
	int		pid;

	t = 0;
	patch = NULL;
	ft_error((pid = fork()), "pid");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		free(patch);
		write(2, "pb child1", 9);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(-1, NULL, 0);
		close(file_fd);
	}
	exit(EXIT_FAILURE);
}

void	ft_family(char *argv, char **env, int *pipe_fd)
{
	char	**patch;
	int		t;
	int		pid;

	t = 0;
	patch = NULL;
	ft_error(pid = fork(), "pid");
	if (pid == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		free(patch);
		write(2, "pb child2", 9);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(-1, NULL, 0);
	exit(EXIT_FAILURE);
}

void	ft_last(int file_fdfinal, char *argv, char **env, int *pipe_fd)
{
	char	**patch;
	int		t;
	int		pid;

	t = 0;
	patch = NULL;
	ft_error(pid = fork(), "pid");
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(file_fdfinal, STDOUT_FILENO);
		close(file_fdfinal);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		free(patch);
		write(2, "pb last", 9);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(-1, NULL, 0);
		close(file_fdfinal);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	exit(EXIT_FAILURE);
}
