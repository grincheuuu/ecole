/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:53:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/15 15:36:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_result(char **result, char *temp)
{
	char	**testpatch;
	int		t;
	int		i;

	i = 0;
	t = 0;
	testpatch = NULL;
	if (result == NULL)
	{
		free(temp);
		return (testpatch);
	}
	while (result[t] != NULL)
		t++;
	testpatch = ft_testpatch_suite(t, i, result, temp);
	ft_fre(result);
	free(temp);
	return (testpatch);
}

char	**ft_testpath(char **result, char *argv)
{
	char	**testpatch;
	char	*temp;
	int		l;
	int		i;

	i = 0;
	l = 1 + ft_strlen(argv);
	temp = malloc((l + 1) * sizeof(char));
	if (temp == NULL)
	{
		ft_fre(result);
		return (NULL);
	}
	temp[i] = '/';
	while (argv[i] != '\0')
	{
		temp[i + 1] = argv[i];
		i++;
	}
	temp[i + 1] = '\0';
	testpatch = ft_result(result, temp);
	return (testpatch);
}

pid_t	ft_childun(int pipe_fd[], char **argv, char **env)
{
	pid_t	a_pid;
	char	**patch;
	int		t;
	int		file_fd;

	t = 0;
	patch = NULL;
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
	{
		ft_error(file_fd = open(argv[1], O_RDONLY, 0644), "file_fd");
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		patch = ft_testpath(ft_path(env), argv[2]);
		ft_exe(patch, t, argv[2], env);
		free(patch);
		write (2, "command not found 1", 19);
		exit(EXIT_FAILURE);
	}
	else
		close(pipe_fd[1]);
	return (a_pid);
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
	patch = ft_testpath(ft_path(env), argv[3]);
	ft_exe(patch, t, argv[3], env);
	free(patch);
	write(2, " command not found last", 23);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	a_pid;
	pid_t	b_pid;
	int		pipe_fd[2];
	int		status;

	if (argc == 5)
	{
		ft_error(pipe(pipe_fd), "pipe_fd");
		a_pid = ft_childun(pipe_fd, argv, env);
		ft_error((b_pid = fork()), "b_pid");
		if (b_pid == 0)
			ft_childdeux(pipe_fd, argv, env);
		else
			close(pipe_fd[0]);
		waitpid(a_pid, &status, 0);
		waitpid(b_pid, &status, 0);
		if (status != 0)
			exit(status >> 8);
		exit(EXIT_SUCCESS);
	}
	write (2, "arguments faux", 14);
	exit(EXIT_FAILURE);
}
