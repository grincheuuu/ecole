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
#include <stdio.h>

void	ft_un(char **argv, char **env, t_listpipe *listp)
{
	char	**patch;
	int		t;
	int		pid;
	int		file_fd;
	int		pipe_fd[2];

	t = 0;
	patch = NULL;
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((pid = fork()), "pid");
	file_fd = 0;
	if (pid == 0)
	{
		ft_error((file_fd = open(argv[1], O_RDONLY, 0644)), "file_fd");
		dup2(file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(file_fd);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		patch = ft_testpath(ft_path(env), argv[2]);
		ft_exe(patch, t, argv[2], env);
		free(patch);
		write(2, "pb child1", 9);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipe_fd[1]);
//		wait(NULL);
		write (1, "1", 1);
		listp->file_fd = pipe_fd[0];
		close(pipe_fd[0]);
	}
	exit(EXIT_FAILURE);
}

void	ft_mid(char *argv, char **env, t_listpipe *listp)
{
	char	**patch;
	int		t;
	int		pid;
	int		pipe_fd[2];

	t = 0;
	patch = NULL;
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((pid = fork()), "pid");
	if (pid == 0)
	{
		dup2(listp->file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(file_fd);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		free(patch);
		write(2, "pb child2", 9);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(point_p->file_fd);
		close(pipe_fd[1]);
		listp->file_fd = pipe_fd[0];
		close(pipe_fd[0]);
		write (1, "C", 1);
	}
	exit(EXIT_FAILURE);
}

void	ft_last(int argc, char **argv, char **env, t_listpipe *listp)
{
	char	**patch;
	int		file_fdfinal;
	int		t;
	int		pid;
	char		c;

	t = 0;
	patch = NULL;
	c = 0;
	ft_error((pid = fork()), "pid");
	if (pid == 0)
	{
		write(1, "enfant", 6);
		c = file_fd + '0';
		write (1, &c, 1);
		if (dup2(listp->file_fd, STDIN_FILENO) != 0)
			perror("dupAA");
		close(listp->file_fd);
		file_fdfinal = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		ft_error(file_fdfinal, "file_fdfinal");
		if (dup2(file_fdfinal, STDOUT_FILENO) != 0)
			perror("dupqq");
		close(file_fdfinal);
		patch = ft_testpath(ft_path(env), argv[argc - 2]);
		ft_exe(patch, t, argv[argc - 2], env);
		free(patch);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(listp->file_fd);
		write (1, "B", 1);
	}
	exit(EXIT_FAILURE);
}
/*
int	main(int argc, char **argv, char **env)
{
	int	i;
	int	j;
	int	file_fd;
	char	c;
	
	i = 2;
	c = 0;
	j = 0;
	if (argc >= 5)
	{
		if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
			ft_heredoc(argv, env);
		else
		{
			while (i < argc - 1)
			{	
				if (i == argc - 2)
				{
					ft_last(argc, argv, env, file_fd);
				}
				else if (i == 2)
				{
					file_fd = ft_un(argv, env);
					write (1, "\n", 1);
					c = file_fd + '0';
					write (1, &c, 1);
					if(file_fd != 0)
						perror("file_fda");
				}
				else
				{
					file_fd = ft_mid(argv[i], env, file_fd);
					if (file_fd != 0)
						perror("file_fd1b");
				}
				i++;
			}
			while (j < argc - 3)
			{
				write(1, "4", 1);
				wait(NULL);
				write(1, "5", 1);					
				j++;
			}
		}
		exit(EXIT_SUCCESS);
	}
	write (2, "argc faux", 9);
	exit(EXIT_FAILURE);
}*/
