/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/27 16:43:25 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_un(t_pointer_cmd **pointerB, t_pointer **pointera, t_file_fd *t_file,
		t_listp **listp)
{
	char	**patch;
	char	**argv;
	int		status;

	ft_initialize(&status, &patch, &argv);
	if ((*listp)->pid == 0)
	{
		argv = ft_child_un_deux(pointerB, pointera, t_file, listp);
		if (!(argv == NULL || argv[0] == NULL))
		{
			if (ft_arg_buildin(argv) == 0)
			{
				ft_build_pipe(argv, status, pointera, t_file);
				ft_clean_final(listp, pointera, pointerB, t_file);
				ft_clean_argv_pipe(argv, status);
			}
			ft_exe_child(pointera, argv, patch);
		}
		if (ft_fre_listp(listp, argv) == 1)
			ft_close_exit_success(pointera, pointerB, t_file, argv);
		ft_clean_all(patch, listp, pointerB, pointera);
		ft_quit_pipe(argv, t_file);
	}
	else
		*listp = ft_parent_un(listp);
}

char	**ft_child_un_deux(t_pointer_cmd **pointerB, t_pointer **pointera,
		t_file_fd *t_file, t_listp **listp)
{
	char	**argv;

	argv = NULL;
	ft_signaux_pipeline(1);
	close((*listp)->pipe_fd[0]);
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
	ft_generate_infile(pointerB, t_file, pointera, listp);
	if (ft_generate_outfile(pointerB, t_file, pointera, listp) == 0)
		dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
	close((*listp)->pipe_fd[1]);
	argv = ft_generate_argv(pointerB, t_file->t);
	return (argv);
}

void	ft_mid(t_pointer_cmd **pointerB, t_pointer **pointera,
		t_file_fd *t_file, t_listp **listp)
{
	char	**patch;
	char	**argv;
	int		status;

	ft_initialize(&status, &patch, &argv);
	if ((*listp)->pid == 0)
	{
		argv = ft_child_mid_deux(pointerB, pointera, t_file, listp);
		if (!(argv == NULL || argv[0] == NULL))
		{
			if (ft_arg_buildin(argv) == 0)
			{
				ft_build_pipe(argv, status, pointera, t_file);
				ft_clean_final(listp, pointera, pointerB, t_file);
				ft_clean_argv_pipe(argv, status);
			}
			ft_exe_child(pointera, argv, patch);
		}
		if (ft_fre_listp(listp, argv) == 1)
			ft_close_exit_success(pointera, pointerB, t_file, argv);
		ft_clean_all(patch, listp, pointerB, pointera);
		ft_quit_pipe(argv, t_file);
	}
	else
		ft_parents_mid(listp);
}

char	**ft_child_mid_deux(t_pointer_cmd **pointerB, t_pointer **pointera,
		t_file_fd *t_file, t_listp **listp)
{
	char	**argv;

	argv = NULL;
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
	ft_signaux_pipeline(1);
	if (ft_generate_infile(pointerB, t_file, pointera, listp) == 0)
		dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
	close((*listp)->before->pipe_fd[0]);
	close((*listp)->pipe_fd[0]);
	if (ft_generate_outfile(pointerB, t_file, pointera, listp) == 0)
		dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
	close((*listp)->pipe_fd[1]);
	argv = ft_generate_argv(pointerB, t_file->t);
	return (argv);
}

void	ft_last(t_pointer_cmd **pointerB, t_pointer **pointera,
		t_file_fd *t_file, t_listp **listp)
{
	char	**patch;
	char	**argv;
	int		status;

	ft_initialize_final(&status, &patch, &argv, listp);
	if ((*listp)->pid == 0)
	{
		argv = ft_child_last_deux(pointerB, pointera, t_file, listp);
		if (!(argv == NULL || argv[0] == NULL))
		{
			if (ft_arg_buildin(argv) == 0)
			{
				ft_build_pipe(argv, status, pointera, t_file);
				ft_clean_final(listp, pointera, pointerB, t_file);
				ft_clean_argv_pipe(argv, status);
			}
			ft_exe_child(pointera, argv, patch);
		}
		if (ft_fre_listp(listp, argv) == 1)
			ft_close_exit_success(pointera, pointerB, t_file, argv);
		ft_clean_all(patch, listp, pointerB, pointera);
		ft_quit_pipe(argv, t_file);
	}
	else
		ft_parent_last(listp);
}
