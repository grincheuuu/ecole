/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/01 15:44:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_childun(int pipe_fd[], char **argv, char **env)
{
	char	**patch;
	int		t;
	int		file_fd;

	t = 0;
	file_fd = 0;
	patch = NULL;
	file_fd = open(argv[1], O_RDONLY, 0644);
	ft_error(file_fd, "file_fd");
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	patch = ft_testpath(ft_path(env), argv[2]);
	ft_exe(patch, t, argv[2], env);
	free(patch);
	write (2, "pb child1", 9);
	exit(EXIT_FAILURE);
}

void	ft_childdeux(int pipe_fd[], char **argv, char **env)
{
	char	**patch;
	int		t;
	int		file_fdfinal;

	t = 0;
	file_fdfinal = 0;
	patch = NULL;
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	file_fdfinal = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	ft_error(file_fdfinal, "file_fdfinal");
	dup2(file_fdfinal, STDOUT_FILENO);
	close(file_fdfinal);
	close(pipe_fd[1]);
	patch = ft_testpath(ft_path(env), argv[3]);
	ft_exe(patch, t, argv[3], env);
	free(patch);
	write(2, "pb child2", 9);
	exit(EXIT_FAILURE);
}

void	ft_pipex_normal(char **argv, char **env)
{
	pid_t	a_pid;
	pid_t	b_pid;
	int		pipe_fd[2];

	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childun(pipe_fd, argv, env);
	else
		close(pipe_fd[1]);
	ft_error((b_pid = fork()), "b_pid");
	if (b_pid == 0)
		ft_childdeux(pipe_fd, argv, env);
	else
		close(pipe_fd[0]);
	waitpid(a_pid, NULL, 0);
	waitpid(b_pid, NULL, 0);
	exit(EXIT_SUCCESS);
}
