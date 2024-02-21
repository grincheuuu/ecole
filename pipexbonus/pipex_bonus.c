/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/21 17:28:48 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_child(int file_fd, char *argv, char **env)
{
	char	**patch;
	char	**thor;
	char	**com;
	int		t;
	int		pipe_fd[2];
	int		a_pid;
	
	t = 0;
	patch = NULL;
	thor = NULL;
	com = NULL;
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error(a_pid = fork(), "a_pid");
	if (a_pid == 0)
	{
		dup2(file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(file_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		patch = ft_testpath(ft_path(env), argv);
		while (patch[t] != NULL)
		{
			thor = ft_split(patch[t], ' ');
			com = ft_split(argv, ' ');
			free(patch[t]);
			if (access(thor[0], F_OK | X_OK) == 0)
				ft_error(execve(thor[0], com, env), "execve");
			ft_fre(thor);
			ft_fre(com);
			t++;
		}
		free(patch);
	}
	else
		file_fd = pipe_fd[0];
	perror("child ");
	exit(EXIT_FAILURE);
}

int	ft_childfinal(int file_fd, int file_fdfinal, char *argv, char **env)
{
	char	**patch;
	char	**thor;
	char	**com;
	int		t;
	int		a_pid;
	
	ft_error(a_pid = fork(), "a_pid");
	t = 0;
	thor = NULL;
	patch = NULL;
	com = NULL;
	if (a_pid == 0)
	{
		dup2(file_fdfinal, STDOUT_FILENO);
		dup2(file_fd, STDIN_FILENO);
		close(file_fdfinal);
		close(file_fd);
		patch = ft_testpath(ft_path(env), argv);
		while (patch[t] != NULL)
		{
			thor = ft_split(patch[t], ' ');
			free(patch[t]);
			com = ft_split(argv, ' ');
			if ((access(thor[0], F_OK | X_OK) == 0))
				ft_error(execve(thor[0], com, env), "execve");
			ft_fre(thor);
			ft_fre(com);
			t++;
		}
		free(patch);
	}
	perror("child ");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int	file_fd;
	int	file_fdfinal;
	int	i;
	
	if (argc > 5)
	{
		if (strncmp(argv[2], "here_doc", 8) == 0)
		{
			ft_error(file_fd = ft_limiteur(argv[2]), "here_doc");
		}
		else
		{	ft_error((file_fd = open(argv[1], O_RDONLY, 0777)), "file_fd1");
		}
	}
	i = argc - 2;
	file_fdfinal = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_error(file_fdfinal, "file_fdfinal");
	ft_error((file_fd = open(argv[1], O_RDONLY, 0777)), "file_fddebut");
	while (1 < i)
	{
		if (i == argc - 2)
		{
			ft_childfinal(file_fd, file_fdfinal, argv[i], env);
		}
		else
		{
			ft_child(file_fd, argv[argc - i], env);
		}
		i--;
	}
	return (0);
}
