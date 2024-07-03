/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_minishell_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:22:46 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:23:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_quit_pipe(char **argv, t_file_fd *t_file)
{
	ft_fre(argv);
	free(t_file);
	exit(127);
}

int	ft_build_pipe(char **argv, int status, t_pointer **pointera,
		t_file_fd *t_file)
{
	(void)status;
	ft_signaux_annul(0);
	if (ft_strncmp(argv[0], "exit", 5) == 0)
		status = ft_arg_exit(argv, (*pointera)->status);
	else
		status = ft_analyse_arg_buildin(argv, pointera, t_file);
	return (status);
}

void	ft_parents_mid(t_listp **listp)
{
	ft_signaux_pipeline(0);
	close((*listp)->before->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
	*listp = ft_maillon(*listp);
}

void	ft_exe_child(t_pointer **pointera, char **argv, char **patch)
{
	char	**env;

	env = ft_transform_env_list(pointera);
	patch = ft_testpath(ft_path(env), argv);
	ft_exe(patch, 0, argv, env);
	ft_test_dir(argv[0]);
	ft_fre(env);
	ft_fre(patch);
}

void	ft_initialize_final(int *status, char ***patch, char ***argv,
		t_listp **listp)
{
	*status = 0;
	*patch = NULL;
	*argv = NULL;
	close((*listp)->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
}
