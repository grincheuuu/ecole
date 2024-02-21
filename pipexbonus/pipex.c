/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:53:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/20 16:12:21 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_result(char **result, char *temp)
{
	char	**testpatch;
	int		len;
	int		t;
	int		i;

	len = 0;
	i = 0;
	t = 0;
	while (result[t] != NULL)
		t++;
	testpatch = malloc((t + 1) * sizeof(char *));
	if (testpatch == NULL)
		return (NULL);
	while (i < t)
	{
		len = ft_strlen(result[i]) + ft_strlen(temp);
		testpatch[i] = ft_strjoin(result[i], temp);
		i++;
	}
	testpatch[i] = NULL;
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
	int		t;

	i = 0;
	t = 0;
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

void	ft_childun(int pipe_fd[], char **argv, char **env)
{
	char	**patch;
	char	**thor;
	char	**com;
	int		t;
	int		file_fd;

	t = 0;
	file_fd = 0;
	patch = NULL;
	thor = NULL;
	com = NULL;
	ft_error((file_fd = open(argv[1], O_RDONLY, 0777)), "file_fd");
	if (dup2(file_fd, STDIN_FILENO) == -1)
		perror("dup1");
	close(file_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	patch = ft_testpath(ft_path(env), argv[2]);
	while (patch[t] != NULL)
	{
		thor = ft_split(patch[t], ' ');
		com = ft_split(argv[2], ' ');
		free(patch[t]);
		if (access(thor[0], F_OK | X_OK) == 0)
			ft_error(execve(thor[0], com, env), "execve");
		ft_fre(thor);
		ft_fre(com);
		t++;
	}
	free(patch);
	perror("childun");
	exit(EXIT_FAILURE);
}

void	ft_childdeux(int pipe_fd[], char **argv, char **env)
{
	char	**patch;
	char	**thor;
	char	**com;
	int		t;
	int		file_fdfinal;

	t = 0;
	file_fdfinal = 0;
	thor = NULL;
	patch = NULL;
	com = NULL;
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		perror("pipe_fd");
	close(pipe_fd[0]);
	file_fdfinal = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	ft_error(file_fdfinal, "file_fdfinal");
	if (dup2(file_fdfinal, STDOUT_FILENO) != 0)
		perror("dup22222");
	close(file_fdfinal);
	patch = ft_testpath(ft_path(env), argv[3]);
	while (patch[t] != NULL)
	{
		thor = ft_split(patch[t], ' ');
		free(patch[t]);
		com = ft_split(argv[3], ' ');
		if ((access(thor[0], F_OK | X_OK) == 0))
			ft_error(execve(thor[0], com, env), "execve");
		ft_fre(thor);
		ft_fre(com);
		t++;
	}
	free(patch);
	perror("childeux");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	a_pid;
	pid_t	b_pid;
	int		pipe_fd[2];

	if (argc == 5)
	{
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
	perror("argv erreur");
	exit(EXIT_FAILURE);
}
