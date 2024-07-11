/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/16 19:07:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_result(char **result, char *temp)
{
	char	**testpatch;
	int		t;
	int		i;

	i = 0;
	t = 0;
	testpatch = NULL;
	if (result == NULL)
	{
		free(temp);
		return (testpatch);
	}
	while (result[t] != NULL)
		t++;
	testpatch = ft_testpatch_suite(t, i, result, temp);
	ft_fre(result);
	free(temp);
	return (testpatch);
}

char	**ft_testpatch_suite(int t, int i, char **result, char *temp)
{
	char	**testpatch;

	testpatch = malloc((t + 1) * sizeof(char *));
	if (testpatch == NULL)
		return (NULL);
	while (i < t)
	{
		testpatch[i] = ft_strjoin(result[i], temp);
		i++;
	}
	testpatch[i] = NULL;
	return (testpatch);
}

char	**ft_testpath(char **result, char **argv)
{
	char	**testpatch;
	char	*temp;
	int		l;
	int		i;

	i = 0;
	l = 1 + ft_strlen(argv[0]);
	temp = malloc((l + 1) * sizeof(char));
	if (temp == NULL)
	{
		ft_fre(result);
		return (NULL);
	}
	temp[i] = '/';
	while (argv[0][i] != '\0')
	{
		temp[i + 1] = argv[0][i];
		i++;
	}
	temp[i + 1] = '\0';
	testpatch = ft_result(result, temp);
	return (testpatch);
}

void	ft_execve_error(int n, const char *str, char ***thor, char ***com)
{
	if (n == -1)
	{
		perror(str);
		ft_fre(*thor);
		ft_fre(*com);
		//		exit(EXIT_FAILURE);
	}
}

int	ft_pipex_start(t_pointer **pointera, t_pointer_cmd *pointerB, int status)
{
	if (ft_search_pipe(pointerB) == 1)
		return (ft_realize_cmd(&pointerB, pointera, status));
	else
	{
		status = ft_pipeline(pointerB, pointera, status);
	}
	return (status);
}

int	ft_realize_cmd(t_pointer_cmd **pointerB, t_pointer **pointera, int status)
{
	char		**argv;
	pid_t		a_pid;
	int			pipe_fd[2];
	t_file_fd	*t_file;

	t_file = ft_t_file_initialise(status);
	argv = ft_generate_argv(pointerB, t_file->t);
	if (ft_arg_buildin(argv) == 0)
	{
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
	ft_fre(argv);
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childun(pipe_fd, pointerB, t_file, pointera);
	else
	{
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
	waitpid(a_pid, &status, 0);
	if (access("text.tmp", F_OK) == 0)
		unlink("text.tmp");
	ft_restore_fd(t_file);
	free(t_file);
	return (status);
}

int	ft_exit(char **argv, t_file_fd *t_file, t_pointer **pointera,
		t_pointer_cmd **pointerB)
{
	int	status;
	int	i;

	status = 0;
	i = 1;
	if (argv[1] != NULL && argv[1][0] != 0 && argv[2] != NULL)
	{
		write(1, "exit\n", 5);
		while (argv[i++] != NULL)
		{
			if (ft_atol_test(argv[1]) != 0)
				break ;
			else
			{
				write(2, "minishell: exit: too many arguments\n", 36);
				return (1); // pas exit
			}
		}
	}
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
	status = ft_cmd_exit(argv, t_file->status);
	ft_clean_final(NULL, pointera, pointerB, t_file);
	ft_fre(argv);
	exit(status);
}

int	ft_analyse_arg_buildin(char **argv, t_pointer **pointera, t_file_fd *t_file)
{
	int	status;

	/*	struct sigaction    act;
		ft_bzero(&act, sizeof(act));
		act.sa_handler = SIG_IGN;
		sigaction(SIGPIPE, &act, NULL);
		status = 0;*/
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
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
	argv = ft_generate_argv(pointerB, 0);
	ft_generate_fd(pointerB, t_file, argv);
	if (!(argv == NULL || argv[0] == NULL))
	{
		env = ft_transform_env_list(pointera);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, 0, argv, env);
		ft_test_dir(argv[0]);
		ft_fre(env);
		ft_fre(argv);
		ft_fre(patch);
	}
	ft_lstclear_bis(&(*pointera)->first);
	free(*pointera);
	ft_lstclear_node(&(*pointerB)->first);
	free(*pointerB);
	free(t_file);
	exit(EXIT_FAILURE);
}

int	ft_search_pipe(t_pointer_cmd *pointerB)
{
	t_cmd	*temp;

	temp = pointerB->first;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "pipe", 4) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_signaux_annul(int n)
{
	struct sigaction	sa_ignore;
	struct sigaction	sa_default;

	if (n == 0)
	{
		ft_bzero(&sa_ignore, sizeof(sa_ignore));
		sa_ignore.sa_handler = SIG_IGN;
		sa_ignore.sa_flags = 0;
		sigemptyset(&sa_ignore.sa_mask);
		if (sigaction(SIGPIPE, &sa_ignore, NULL) == -1)
		{
			perror("sigaction");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_bzero(&sa_default, sizeof(sa_default));
		sa_default.sa_handler = SIG_DFL;
		sa_default.sa_flags = 0;
		sigemptyset(&sa_default.sa_mask);
		if (sigaction(SIGPIPE, &sa_default, NULL) == -1)
		{
			perror("sigaction");
			exit(EXIT_FAILURE);
		}
	}
}
