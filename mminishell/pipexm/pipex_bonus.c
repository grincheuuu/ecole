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

int	ft_pipex_start(t_pointer **pointera, t_pointer_cmd *pointerB)
{
	int	status;

	status = 0;
	if (ft_search_pipe(pointerB) == 1)
		return (ft_realize_cmd(pointerB, pointera));
	else
	{
		status = ft_pipeline(pointerB, pointera);
	}
	if (status != 0)
		return (status);
	return (status);
}

int ft_realize_cmd(t_pointer_cmd *pointerB, t_pointer **pointera)
{
	char	**argv;
	t_cmd	*temp;
	pid_t	a_pid;
	int		pipe_fd[2];
	int		status;
	t_file_fd	*t_file;

	argv = NULL;
	t_file = NULL;
	status = 0;
	temp = pointerB->first;
	t_file = (t_file_fd *)malloc(sizeof(t_file_fd));
	if (t_file == NULL)
		return (1);
	t_file->file_fd = 0;
	t_file->file_fdfinal = 0;
	argv = ft_generate_argv(&pointerB, 0);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "infile", 6) == 0 || ft_strncmp(temp->type, "here_doc", 8) == 0
			|| ft_strncmp(temp->type, "outfile", 7) == 0 || ft_strncmp(temp->type, "append", 6) == 0)
			t_file = ft_realize_fd(temp, t_file);
		temp = temp->next;	
	}
	if (argv == NULL || *argv[0] == '\0')
	{
		printf("BB");
		ft_fre(argv);
		free(t_file);
		return (0);
	}
//	if (ft_analyse_arg_buildin(argv, pointera, pointerB, NULL) == 0)
//	{
//		free(argv);
//		free(t_file);
//		return (status);
//	}
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childun(pipe_fd, argv, t_file, pointera);
	else
	{
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
	waitpid(a_pid, &status, 0);
	if (access("text.tmp", F_OK) == 0)
		unlink("text.tmp");
	ft_fre(argv);
	free(t_file);
	printf("D");
	return (status);
}

/*
int ft_realize_cmd(t_pointer_cmd *pointerB, t_pointer **pointera)
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
	if (ft_strncmp("./minishell", argv, 11) == 0)
		ft_level(pointera, "SHLVL=");
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	printf("\nAA%sAA\n", argv);
	if (a_pid == 0)
		ft_childun(pipe_fd, argv, env, t_file);
	else
	{
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
	waitpid(a_pid, &status, 0);
	if (access("text.tmp", F_OK) == 0)
		unlink("text.tmp");
	free(argv);
	free(t_file);
	printf("D");
	return (status);
}*/
/*
void	ft_level(t_pointer **pointera, char *str)
{

}*/

int	ft_analyse_arg_buildin(char **argv, t_pointer **pointera, t_pointer_cmd *pointerB, t_listp **listp, t_file_fd *t_file)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	if (ft_strncmp(argv[0], "echo", ft_strlen(argv[0]) - 1) == 0)
		ft_echo(argv, pointera, status);
	else if (ft_strncmp(argv[0], "cd", ft_strlen(argv[0]) - 1) == 0)
	{
		while (argv[i] != NULL)
			i++;
		if (i <= 2)
			ft_cd(argv[1], pointera);
		else
		{
			write (2, "bash: cd: too many arguments\n", 30);
			return (1); // exit
		}
	}
	else if (ft_strncmp(argv[0], "pwd", ft_strlen(argv[0]) - 1) == 0)
		ft_pwd(pointera);
	else if (ft_strncmp(argv[0], "export", ft_strlen(argv[0]) - 1) == 0)
	{
		i = 1;
		if (argv[1] == NULL)
			status = ft_export(argv[1], pointera);
		while (argv[i] != NULL)
   		{
        	status = ft_export(argv[i], pointera);
        	i++;
   		}
	}
	else if (ft_strncmp(argv[0], "unset", ft_strlen(argv[0]) - 1) == 0)
		ft_unset(pointera, argv);
	else if (ft_strncmp(argv[0], "env", ft_strlen(argv[0]) - 1) == 0)
		ft_print_env(pointera);
	else if (ft_strncmp(argv[0], "exit", ft_strlen(argv[0]) - 1) == 0)
		ft_cmd_exit(argv, pointera, pointerB);
	else
		return (1);
	printf("\nZZ\n");
//	ft_print_env(pointera);
	ft_lstclear_bis(&(*pointera)->first);
	free(*pointera);
	ft_lstclear_node(&(pointerB)->first);
	free(pointerB);
	ft_fre(argv);
	free(t_file);
	ft_lstclear(listp);
	exit(EXIT_FAILURE);
}

void	ft_childun(int pipe_fd[], char **argv, t_file_fd *t_file, t_pointer	**pointera)
{
	char	**patch;
	char	**env;

	patch = NULL;
//	dprintf(1, " childun ");
	close(pipe_fd[0]);
//	dprintf(2, " file_fd%d  file_fdfinal%d\n", t_file->file_fd, t_file->file_fdfinal);
	if (t_file->file_fd > 2)
	{
		dprintf(2, "file_fd = STDIN\n");
		dup2(t_file->file_fd, STDIN_FILENO);
		close(t_file->file_fd);
	}
	if (t_file->file_fdfinal > 2)
	{
		dprintf(2, "file_fdfinal = STDOUT\n");
		dup2(t_file->file_fdfinal, STDOUT_FILENO);
		close(t_file->file_fdfinal);
	}
	close(pipe_fd[1]);
	env = ft_transform_env_list(pointera);
//	ft_print_tab(env);
//	ft_print_tab(argv);
	patch = ft_testpath(ft_path(env), argv);
//	ft_print_tab(patch);
//	dprintf(2, "\n2222222\n");
	ft_exe(patch, 0, argv, env);
	free(patch);
	free(env);
	write (2, "pb child", 9);
	return ;
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
/*
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
//		else if (ft_strncmp(temp->type, "here_doc", 9) == 0)
//			ft_error_deux(t_file->file_fd = ft_heredoc(temp->cmd), "here_doc", t_file);
		else if (ft_strncmp(temp->type, "outfile", 8) == 0)
			i = ft_error_deux(t_file->file_fdfinal = open(temp->cmd, O_WRONLY | O_TRUNC | O_CREAT, 0644), temp->cmd, t_file);
		else if (ft_strncmp(temp->type, "append", 7) == 0)
			i = ft_error_deux(t_file->file_fdfinal = open(temp->cmd, O_WRONLY | O_APPEND | O_CREAT, 0644), temp->cmd, t_file);
		if (i == 1)
			t_file->file_fd = open("/dev/null", O_RDONLY, 0644);
		temp = temp->next;
	}
	return (t_file);
}*/
