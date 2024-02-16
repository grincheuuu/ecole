/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:53:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/15 13:58:32 by gschwart         ###   ########.fr       */
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
	printf("aa%daa", t);
	testpatch = malloc((t + 1) * sizeof(char *));
	if (testpatch == NULL)
		return (NULL);
	while (i < t)
	{
		len = ft_strlen(result[i]) + ft_strlen(temp);
		printf("%s qqqqqqqqq %d", temp, i);
		testpatch[i] = ft_strjoin(result[i], temp);
		printf("%s iiiiiii", testpatch[i]);
		i++;
	}
	testpatch[i] = NULL;
	ft_malloc_error(testpatch, t);
	ft_fre(result);
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
	printf("%djjjjjj\n", l);
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
	printf("%dm,m,m,m,m,m,m,m\n", i);
	temp[i + 1] = '\0';
	testpatch = ft_result(result, temp);
	free(temp);
	printf("22222");
	return (testpatch);
}

void	ft_childun(int pipe_fd[], int file_fd, char **argv, char **env)
{
	char	**patch;
	char	**thor;
	int		t;

	t = 0;
	patch = NULL;
	thor = NULL;
	dup2(file_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	patch = ft_testpath(ft_path(env), argv[2]);
	printf("1111");
	if (patch == NULL)
		exit(EXIT_FAILURE);
	while (patch[t] != NULL)
	{
		printf("%s", patch[t]);
		thor = ft_split(patch[t], ' ');
		free(patch[t]);
		if ((access(thor[0], F_OK) == 0) && ((access(thor[0], X_OK) == 0)))
			execve(thor[0], &argv[2], env);
		ft_fre(thor);
		t++;
	}
	free(patch);
}

void	ft_childdeux(int pipe_fd[], char **argv, char **env, int file_fdfinal)
{
	char	**patch;
	char	**thor;
	int		t;

	t = 0;
	thor = NULL;
	ft_error(file_fdfinal, "file_fdfinal");
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	dup2(file_fdfinal, STDOUT_FILENO);
	patch = ft_testpath(ft_path(env), argv[3]);
	while (patch[t] != NULL)
	{
		thor = ft_split(patch[t], ' ');
		free(patch[t]);
		if ((access(thor[0], F_OK) == 0) && ((access(thor[0], X_OK) == 0)))
			execve(thor[0], &argv[3], env);
		ft_fre(thor);
		t++;
	}
	free(patch);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	a_pid;
	pid_t	b_pid;
	int		pipe_fd[2];
	int		file_fd;
	int		file_fdfinal;

	printf("1");
	if (argc == 5)
	{
		ft_error((file_fd = open(argv[1], O_RDONLY, 0777)), "file_fd");
		ft_error(pipe(pipe_fd), "pipe_fd");
		ft_error((a_pid = fork()), "a_pid");
		if (a_pid == 0)
			ft_childun(pipe_fd, file_fd, argv, env);
		close(file_fd);
		waitpid(a_pid, NULL, 0);
		file_fdfinal = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		ft_parents(pipe_fd, file_fdfinal, argv, env);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(file_fdfinal);
		waitpid(b_pid, NULL, 0);
		exit(EXIT_SUCCESS);
	}
	perror("argv erreur");
	exit(EXIT_FAILURE);
}
