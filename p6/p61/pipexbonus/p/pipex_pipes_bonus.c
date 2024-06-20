/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/16 19:53:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

t_pointer	*ft_pointer_init(t_listp *listp)
{
	t_pointer	*pointerA;

	pointerA = (t_pointer *)malloc(sizeof(t_pointer));
	if (pointerA == NULL)
		return (NULL);
	pointerA->first = listp;
	pointerA->end = listp;
	return (pointerA);
}

void	ft_pipeline(int argc, char **argv, char **env, int i)
{
	int	j;
	t_listp	*listp;
	t_pointer	*pointerA;

	j = 0;
	listp = ft_lstnew();
	pointerA = ft_pointer_init(listp);
	while (i < argc - 1)
	{
		if (i == argc - 2)
		{
			ft_last(argc, argv, env, listp, pointerA);
		}
		else if (i == 2)
		{
			ft_un(argv, env, listp);
		}
		else
		{
			ft_mid(argv[i], env, listp, pointerA);
		}
		i++;
	}
	while (j < argc - 3)
	{
		wait(NULL);
	}
}

void	ft_un(char **argv, char **env, t_listp *listp)
{
	char	**patch;
	int		t;
	int		file_fd;
	int		pipe_fd[2];

	t = 0;
	patch = NULL;
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((listp->pid = fork()), "pid");
	file_fd = 0;
	if (listp->pid == 0)
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
		listp->file_fd = pipe_fd[0];
//		close(pipe_fd[0]);
	}
	exit(EXIT_FAILURE);
}

void	ft_mid(char *argv, char **env, t_listp *listp, t_pointer *pointerA)
{
	char	**patch;
	int		t;
	int		pipe_fd[2];

	t = 0;
	patch = NULL;
	ft_error(pipe(pipe_fd), "pipe_fd");
	listp = ft_maillon(listp, pointerA);
	ft_error((listp->pid = fork()), "pid");
	if (listp->pid == 0)
	{
		dup2(listp->file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(listp->file_fd);
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
		close(listp->file_fd);
		close(pipe_fd[1]);
		listp->file_fd = pipe_fd[0];
//		close(pipe_fd[0]);
		write (1, "C", 1);
	}
	exit(EXIT_FAILURE);
}

void	ft_last(int argc, char **argv, char **env, t_listp *listp, t_pointer *pointerA)
{
	char	**patch;
	int		file_fdfinal;
	int		t;
	char		c;

	t = 0;
	patch = NULL;
	c = 0;
	listp = ft_maillon(listp, pointerA);
	ft_error((listp->pid = fork()), "pid");
	if (listp->pid == 0)
	{
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
