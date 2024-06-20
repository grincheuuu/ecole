/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/20 14:24:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

t_pointer	*ft_pointer_init(t_listp *listp)
{
	t_pointer	*pointer;

	pointer = (t_pointer *)malloc(sizeof(t_pointer));
	if (pointer == NULL)
		return (NULL);
	pointer->first = listp;
	pointer->end = listp;
	return (pointer);
}

int	ft_pipeline(int argc, char **argv, char **env, int i)
{
	t_listp		*listp;
	t_pointer	*pointer;
	int			j;
	int			status;

	j = 0;
	listp = ft_lstnew();
	pointer = ft_pointer_init(listp);
	while (i < argc - 1)
	{
		ft_error(pipe(listp->pipe_fd), "pipe_fd");
		ft_error((listp->pid = fork()), "pid");
		if (i == argc - 2)
			j = ft_last(argc, argv, env, &listp);
		else if (i == 2)
			ft_un(argv, env, &listp, pointer);
		else
			ft_mid(argv[i], env, &listp, pointer);
		i++;
	}
	status = ft_wait(pointer);
	ft_clean_final(pointer, j);
	return (status >> 8);
}

void	ft_un(char **argv, char **env, t_listp **listp, t_pointer *pointer)
{
	char	**patch;
	int		t;
	int		file_fd;

	t = 0;
	patch = NULL;
	if ((*listp)->pid == 0)
	{
		file_fd = ft_file(argv[1]);
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
		dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
		close((*listp)->pipe_fd[0]);
		close((*listp)->pipe_fd[1]);
		ft_test_file_fd(argv[1], pointer);
		patch = ft_testpath(ft_path(env), argv[2]);
		ft_exe(patch, t, argv[2], env);
		ft_clean_all(patch, pointer);
		write (2, "command not found 1", 19);
		exit(EXIT_FAILURE);
	}
	else
		*listp = ft_parent_un(listp, pointer);
}

void	ft_mid(char *argv, char **env, t_listp **listp, t_pointer *pointer)
{
	char	**patch;
	int		t;

	t = 0;
	patch = NULL;
	if ((*listp)->pid == 0)
	{
		dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
		close((*listp)->before->pipe_fd[0]);
		dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
		close((*listp)->pipe_fd[1]);
		close((*listp)->pipe_fd[0]);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		ft_clean_all(patch, pointer);
		write (2, " command not found ", 19);
		exit(EXIT_FAILURE);
	}
	else
	{
		close((*listp)->before->pipe_fd[0]);
		close((*listp)->pipe_fd[1]);
		*listp = ft_maillon(*listp, pointer);
	}
}

int	ft_last(int argc, char **argv, char **env, t_listp **listp)
{
	char	**patch;
	int		file_fdfinal;
	int		t;

	t = 0;
	patch = NULL;
	close((*listp)->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
	if ((*listp)->pid == 0)
	{
		file_fdfinal = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (ft_error_deux(file_fdfinal, "file_fdfinal") == 1)
			return (1);
		dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
		close((*listp)->before->pipe_fd[0]);
		dup2(file_fdfinal, STDOUT_FILENO);
		close(file_fdfinal);
		patch = ft_testpath(ft_path(env), argv[argc - 2]);
		ft_exe(patch, t, argv[argc - 2], env);
		ft_free_last(patch);
		return (1);
	}
	else
		close((*listp)->before->pipe_fd[0]);
	return (0);
}
