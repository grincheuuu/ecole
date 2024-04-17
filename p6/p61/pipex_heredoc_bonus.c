/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:17:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/03 19:04:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_gnl(char *str)
{
	char	*line;
	int		file_fd;

	line = NULL;
	file_fd = open("text.tmp", O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_error(file_fd, "TEXT.TMP");
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (ft_strncmp(line, str, ft_strlen(str)) == 0
			&& (ft_strlen(line) - 1 == ft_strlen(str)))
			break ;
		write (file_fd, line, ft_strlen(line));
		write (file_fd, "\n", 1);
		free(line);
	}
	free(line);
	close(file_fd);
}

void	ft_childunhere(int pipe_fd[], char **argv, char **env)
{
	char	**patch;
	int		t;
	int		file_fd;

	t = 0;
	file_fd = 0;
	patch = NULL;
	close(pipe_fd[0]);
	ft_gnl(argv[2]);
	file_fd = open("text.tmp", O_RDONLY, 0644);
	ft_error((file_fd = open("text.tmp", O_RDONLY, 0644)), "file_fd");
	if (dup2(file_fd, STDIN_FILENO) != 0)
		perror("dup2");
	close(file_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	patch = ft_testpath(ft_path(env), argv[3]);
	ft_exe(patch, t, argv[3], env);
	free(patch);
	write (2, "pb child1", 9);
	unlink("text.tmp");
	exit(EXIT_FAILURE);
}

void	ft_childdeuxhere(int pipe_fd[], char **argv, char **env)
{
	char	**patch;
	int		t;
	int		file_fdfinal;

	t = 0;
	file_fdfinal = 0;
	patch = NULL;
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	file_fdfinal = open(argv[5], O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_error(file_fdfinal, "file_fdfinal");
	dup2(file_fdfinal, STDOUT_FILENO);
	close(file_fdfinal);
	patch = ft_testpath(ft_path(env), argv[4]);
	ft_exe(patch, t, argv[4], env);
	free(patch);
	write(2, "pb child2", 9);
	exit(EXIT_FAILURE);
}

int	ft_heredoc(char **argv, char **env)
{
	pid_t	a_pid;
	pid_t	b_pid;
	int		pipe_fd[2];
	int		status;

	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childunhere(pipe_fd, argv, env);
	else
		close(pipe_fd[1]);
	ft_error((b_pid = fork()), "b_pid");
	if (b_pid == 0)
		ft_childdeuxhere(pipe_fd, argv, env);
	else
		close(pipe_fd[0]);
	waitpid(a_pid, &status, 0);
	waitpid(b_pid, &status, 0);
	unlink("text.tmp");
	if (status != 0)
		exit(status >> 8);
	exit(EXIT_SUCCESS);
}
