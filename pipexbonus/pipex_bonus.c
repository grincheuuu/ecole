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
	
	if (argc >= 5)
	{
/*		if (strncmp(argv[2], "here_doc", 8) == 0)
		{
			ft_error((file_fd = open(argv[1], O_RDONLY, 0777)), "HERE_DOC");
			 = ft_limiteur(file_fd, "LIMITEUR");
			write (STDIN_FILENO, fileun, ft_strlen(fileun));
			dup2(pipe_fd[1], STDOUT_FILENO);
			execve();
		}
		else
		{	ft_error((file_fd = open(argv[1], O_RDONLY, 0777)), "file_fd");
		}*/
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
	}
	return (0);
}
