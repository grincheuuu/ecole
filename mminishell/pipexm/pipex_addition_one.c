/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_addition_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:30:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/30 16:00:20 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_realize_cmd(t_pointer_cmd **pointerB, t_pointer **pointera, int status)
{
	char		**argv;
	pid_t		a_pid;
	int			pipe_fd[2];
	t_file_fd	*t_file;

	t_file = ft_t_file_initialise(status);
	argv = ft_generate_argv(pointerB, t_file->t);
	if (ft_arg_buildin(argv) == 0)
		return (ft_arg_build_go(argv, t_file, pointera, pointerB));
	ft_fre(argv);
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childun(pipe_fd, pointerB, t_file, pointera);
	else
		ft_parents(pipe_fd);
	waitpid(a_pid, &status, 0);
	ft_unlink(pointerB);
	ft_restore_fd(t_file);
	free(t_file);
	if (WEXITSTATUS(status))
		status = WEXITSTATUS(status);
	change_signal(0);
	return (status);
}

int	ft_arg_build_go(char **argv, t_file_fd *t_file, t_pointer **pointera,
		t_pointer_cmd **pointerB)
{
	int	status;

	status = 0;
	if (ft_generate_fd(pointerB, t_file, argv) == -1)
		return (1);
	if (ft_strncmp(argv[0], "exit", 5) == 0)
		status = ft_exit(argv, t_file, pointera, pointerB);
	else
		status = ft_analyse_arg_buildin(argv, pointera, t_file);
	ft_restore_fd(t_file);
	free(t_file);
	ft_fre(argv);
	return (status);
}

int	ft_exit(char **argv, t_file_fd *t_file, t_pointer **pointera,
		t_pointer_cmd **pointerB)
{
	int	status;

	status = 0;
	if (argv[1] != NULL && argv[1][0] != 0 && argv[2] != NULL)
	{
		write(1, "exit\n", 5);
		if (ft_atol_test(argv[1]) != 0)
		{
			close(t_file->stdin_fd);
			close(t_file->stdout_fd);
			ft_clean_final(NULL, pointera, pointerB, t_file);
			ft_fre(argv);
			exit(2);
		}
		if (ft_exit_arg_nb(argv) == 1)
			return (1);
	}
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
	status = ft_cmd_exit(argv, (*pointera)->status);
	ft_clean_final(NULL, pointera, pointerB, t_file);
	ft_fre(argv);
	exit(status);
}

int	ft_analyse_arg_buildin(char **argv, t_pointer **pointera, t_file_fd *t_file)
{
	int	status;

	status = 0;
	if (ft_strncmp(argv[0], "echo", 5) == 0)
		status = ft_echo(argv);
	else if (ft_strncmp(argv[0], "cd", 3) == 0)
		status = ft_realize_cd(argv, pointera);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		status = ft_pwd();
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		status = ft_export(argv, pointera);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		status = ft_unset(pointera, argv);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		status = ft_print_env(pointera);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		status = ft_cmd_exit(argv, t_file->status);
	else
	{
		write(2, "minishell: command not found: ", 30);
		ft_putstr_fd(argv[0], 2);
		write(2, "\n", 1);
		status = 1;
	}
	return (status);
}

void	ft_childun(int pipe_fd[], t_pointer_cmd **pointerB, t_file_fd *t_file,
		t_pointer **pointera)
{
	char	**patch;
	char	**argv;
	char	**env;

	patch = NULL;
	argv = NULL;
	ft_close_fd(pipe_fd, t_file);
	ft_signaux_pipeline(1);
	if (ft_generate_fd(pointerB, t_file, argv) == 0)
	{
		argv = ft_generate_argv(pointerB, 0);
		if (argv == NULL || argv[0] == NULL)
			ft_close_exit_success(pointera, pointerB, t_file, argv);
		if (!(argv == NULL || argv[0] == NULL))
		{
			env = ft_transform_env_list(pointera);
			patch = ft_testpath(ft_path(env), argv);
			ft_exe(patch, 0, argv, env);
			ft_end_child(argv, env, patch);
		}
		else if (argv != NULL && argv[0][0] == '\0')
			ft_fre(argv);
		free(t_file);
	}
	ft_close_exit_failure(pointera, pointerB, t_file);
}
