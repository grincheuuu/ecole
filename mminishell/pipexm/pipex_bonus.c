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

int	ft_pipex_start(int argc, char **env, t_pointer **pointera, t_pointer_cmd *pointerB)
{
	int	i;
	int	j;
	int	status;

	i = 2;
	j = 0;
	status = 0;
	(void)argc;
	if (ft_search_pipe(pointerB) == 1)
		return (ft_realize_cmd(pointerB, env, pointera));
/*	else
	{
		if (argc == 6 && ft_strncmp_deux(argv, "here_doc", 8) == 0)
			status = ft_heredoc(argv, env);
		else
		{
			status = ft_pipeline(argc, pointerB, env, i);
		}
		if (status != 0)
			exit(status);
		return (0);
	}*/
	write (2, "arguments faux", 15);
	return (status);
}

int ft_realize_cmd(t_pointer_cmd *pointerB, char **env, t_pointer **pointera)
{
	char	*argv;
	pid_t	a_pid;
	int		pipe_fd[2];
	int		status;
	t_file_fd	*t_file;

	argv = NULL;
	t_file = NULL;
	status = 0;
	t_file = ft_realize_filefd(pointerB);
	if (t_file == NULL)
		return (1);
	argv = ft_create_argv(pointerB);
	printf("\nAA%sAA\n", argv);
	if (argv == NULL || *argv == '\0')
	{
		printf("BB");
		free(argv);
		free(t_file);
		return (0);
	}
	if (ft_analyse_arg_buildin(argv, pointera, pointerB, env) == 0)
	{
		free(argv);
		free(t_file);
		return (status);
	}
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childun(pipe_fd, argv, env, t_file);
	else
		close(pipe_fd[1]);
	waitpid(a_pid, &status, 0);
	if (access("text.tmp", F_OK) == 0)
		unlink("text.tmp");
	free(argv);
	free(t_file);
	printf("D");
	return (status);
}

int	ft_analyse_arg_buildin(char *argv, t_pointer **pointera, t_pointer_cmd *pointerB, char **env)
{
	int	argc;
	int	i;
	int	status;
	char	**track;

	argc = 2;
	status = 0;
	i = 0;
	track = NULL;
	if (ft_strncmp(argv, "echo", 4) == 0)
	{
		ft_echo(argv);
	}
	else if (ft_strncmp(argv, "cd", 2) == 0)
	{
		track = ft_split(argv, ' ');
		while (track[i] != NULL)
			i++;
		if (i <= 2)
			ft_cd(track[1], pointera);
		else
		{
			write (2, "bash: cd: too many arguments\n", 32);
			ft_fre(track);
			return (1); // exit
		}
		ft_fre(track);
	}
	else if (ft_strncmp(argv, "pwd", 3) == 0)
		ft_pwd(pointera);
	else if (ft_strncmp(argv, "export", 6) == 0)
	{
		i = 1;
		track = ft_split(argv, ' ');
		if (track[i] == NULL)
			status = ft_export(track[i], pointera);
		while (track[i] != NULL)
   		{
        	status = ft_export(track[i], pointera);
        	i++;
   		}
//		ft_print_env(pointera);
		ft_fre(track);
	}
	else if (ft_strncmp(argv, "unset", 5) == 0)
	{
		track = ft_split(argv, ' ');
		ft_unset(pointera, track);
		ft_fre(track);
	}
	else if (ft_strncmp(argv, "env", 3) == 0)
	{
		ft_print_env(pointera);
	}
	else if (ft_strncmp(argv, "exit", 4) == 0)
	{
		ft_cmd_exit(argv, pointera, pointerB, env);
	}
	else
		return (1);
	printf("ZZ");
	ft_print_env(pointera);
	return (status);
}

void	ft_childun(int pipe_fd[], char *argv, char **env, t_file_fd *t_file)
{
	char	**patch;

	patch = NULL;
	dprintf(2, "PP");
	dprintf(2, "%s", argv);
	close(pipe_fd[0]);
	dup2(t_file->file_fd, STDIN_FILENO);
	close(t_file->file_fd);
	if (t_file->file_fdfinal > 0)
		dup2(t_file->file_fdfinal, STDOUT_FILENO);
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	patch = ft_testpath(ft_path(env), argv);
	ft_exe(patch, 0, argv, env);
	free(patch);
	write (2, "pb child", 9);
	return ;
}

char	*ft_create_argv(t_pointer_cmd *pointerB)
{
	t_cmd	*temp;
	char	*argv;
	char	*copy;

	temp = pointerB->first;
	argv = NULL;
	copy = ft_strdup("");
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "word", 5) == 0)
		{
			argv = ft_strjoin(copy, temp->cmd);
			free(copy);
			copy = argv;
            argv = ft_strjoin(copy, " ");
            free(copy);
            copy = argv;
//			printf("\n9%s9\n", temp->cmd);
		}
		temp = temp->next;
	}
//	printf("%s", argv);
	return (argv);
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

t_file_fd	*ft_realize_filefd(t_pointer_cmd *pointerB)
{
	t_cmd	*temp;
	t_file_fd	*t_file;
	int	i;

	i = 0;
	temp = pointerB->first;
	t_file = (t_file_fd *)malloc(sizeof(t_file_fd));
	if (t_file == NULL)
		return (NULL);
	t_file->file_fd = 0;
	t_file->file_fdfinal = 0;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "infile", 7) == 0)
			i = ft_error_deux(t_file->file_fd = open(temp->cmd, O_RDONLY, 0644), temp->cmd, t_file);
		if (i == 1)
			return (NULL);
//		if (ft_strncmp(temp->type, "here_doc", 9) == 0)
//			ft_error(t_file->file_fd = ft_heredoc(temp->cmd), "here_doc", t_file);
		if (i == 1)
			return (NULL);
		if (ft_strncmp(temp->type, "outfile", 8) == 0)
			i = ft_error_deux(t_file->file_fdfinal = open(temp->cmd, O_WRONLY | O_TRUNC | O_CREAT, 0644), temp->cmd, t_file);
		if (i == 1)
			return (NULL);
		if (ft_strncmp(temp->type, "append", 7) == 0)
			i = ft_error_deux(t_file->file_fdfinal = open(temp->cmd, O_WRONLY | O_APPEND | O_CREAT, 0644), temp->cmd, t_file);
		if (i == 1)
			return (NULL);
		temp = temp->next;
	}
	if (t_file->file_fd == 0)
		ft_error(t_file->file_fd = open("/dev/null", O_RDONLY, 0644), "/dev/null");
	return (t_file);
}
