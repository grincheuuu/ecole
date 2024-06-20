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

void	ft_un(int *pipe_fd, char **argv, char **env)
{
	char	**patch;
	int		t;
	int		pid;
	int		file_fd;

	t = 0;
	patch = NULL;
	ft_error((pid = fork()), "pid");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		ft_error((file_fd = open(argv[1], O_RDONLY | O_CREAT, 0644)), "file_fd");
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		patch = ft_testpath(ft_path(env), argv[2]);
		ft_exe(patch, t, argv[2], env);
		free(patch);
		write(2, "pb child1", 9);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipe_fd[1]);
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
	ft_error((pid = fork()), "pid");
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
	{	
		close(pipe_fd[1]);
	}
	exit(EXIT_FAILURE);
}

void	ft_last(int argc, char **argv, char **env, int *pipe_fd)
{
	char	**patch;
	int		file_fdfinal;
	int		t;
	int		pid;

	t = 0;
	patch = NULL;
	ft_error((pid = fork()), "pid");
	if (pid == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		file_fdfinal = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		ft_error(file_fdfinal, "file_fdfinal");
		dup2(file_fdfinal, STDOUT_FILENO);
		close(file_fdfinal);
		close(pipe_fd[1]);
		patch = ft_testpath(ft_path(env), argv[argc - 2]);
		ft_exe(patch, t, argv[argc - 2], env);
		free(patch);
		write(2, "pb last", 9);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}
