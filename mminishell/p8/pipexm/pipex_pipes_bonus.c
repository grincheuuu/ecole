/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/11 20:27:55 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

t_pointer_p	*ft_pointer_init(t_listp *listp)
{
	t_pointer_p	*pointer;

	pointer = (t_pointer_p *)malloc(sizeof(t_pointer_p));
	if (pointer == NULL)
		return (NULL);
	pointer->first = listp;
	pointer->end = listp;
	return (pointer);
}

int	ft_analyse_here_doc(t_pointer_cmd **pointerB, t_pointer **pointera)
{
	t_cmd	*temp;
	int		file_fd;

	temp = (*pointerB)->first;
	file_fd = 0;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "here_doc", 8) == 0)
		{
			file_fd = open(temp->cmd, O_RDONLY, 0644);
			if (file_fd < 0)
			{
				ft_lstclear_node(&(*pointerB)->first);
				free(pointerB);
				ft_lstclear_bis(&(*pointera)->first);
				free(pointera);
				write(2, "minishell: here_doc : error", 28);
				exit(1);
			}
			close(file_fd);
		}
		temp = temp->next;
	}
	return (0);
}

int	ft_pipeline(t_pointer_cmd *pointerB, t_pointer **pointera, int status)
{
	t_listp	*listp;
	t_listp	*list;
	int		j;
	t_listp	*templistp;

	templistp = NULL;
	j = 0;
	listp = NULL;
	ft_lstadd_back(&listp, ft_lstnew());
	list = listp;
	ft_analyse_here_doc(&pointerB, pointera);
	ft_realize_pipe(&pointerB, &listp, pointera, status);
	status = ft_wait(&listp);
	ft_lstclear(&list);
	return (status >> 8);
}

void	ft_printlist_aa(t_listp **listp)
{
	t_listp	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (*listp == NULL)
	{
		write(1, "NULL", 4);
		return ;
	}
	temp = *listp;
	while (temp != NULL)
	{
		printf("cmd : %d\n", temp->status);
		printf("type : %d\n", temp->pid);
		temp = temp->next;
		i++;
		printf("\nlistp");
	}
}

void	ft_realize_pipe(t_pointer_cmd **pointerB, t_listp **listp,
		t_pointer **pointera, int status)
{
	t_cmd		*temp;
	t_file_fd	*t_file;

	temp = (*pointerB)->first;
	t_file = ft_t_file_initialise(status);
	while (temp != NULL)
	{
		while (temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
			temp = temp->next;
		ft_error(pipe((*listp)->pipe_fd), "pipe_fd");
		ft_error(((*listp)->pid = fork()), "pid");
		if (temp == NULL)
			ft_last(pointerB, pointera, t_file, listp);
		else if (t_file->t == 0)
			ft_un(pointerB, pointera, t_file, listp);
		else
			ft_mid(pointerB, pointera, t_file, listp);
		if (temp != NULL && ft_strncmp(temp->type, "pipe", 4) == 0)
			temp = temp->next;
		t_file->t += 1;
	}
	ft_restore_fd(t_file);
	//	ft_printlist_cmd(pointerB);
	free(t_file);
}

t_file_fd	*ft_t_file_initialise(int status)
{
	t_file_fd	*t_file;

	t_file = (t_file_fd *)malloc(sizeof(t_file_fd));
	if (t_file == NULL)
		return (NULL);
	t_file->stdin_fd = dup(STDIN_FILENO);
	if (t_file->stdin_fd == -1)
	{
		free(t_file);
		return (NULL);
	}
	t_file->stdout_fd = dup(STDOUT_FILENO);
	if (t_file->stdout_fd == -1)
	{
		free(t_file);
		return (NULL);
	}
	t_file->t = 0;
	t_file->status = status;
	return (t_file);
}

int	ft_generate_fd(t_pointer_cmd **pointerB, t_file_fd *t_file, char **argv)
{
	t_cmd	*temp;
	int		file_fd;
	int		file_fdfinal;

	file_fd = 0;
	file_fdfinal = 0;
	temp = (*pointerB)->first;
	if (t_file == NULL)
		return (0);
	while (temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(temp->type, "infile", 6) == 0 || ft_strncmp(temp->type,
				"here_doc", 8) == 0)
		{
			if (ft_error_deux(file_fd = open(temp->cmd, O_RDONLY, 0644),
					temp->cmd, t_file) == 1)
			{
				file_fd = open("/dev/null", O_RDONLY, 0644);
				dup2(file_fd, STDIN_FILENO);
				close(file_fd);
				close(t_file->stdin_fd);
				close(t_file->stdout_fd);
				if (argv != NULL)
					ft_fre(argv);
				free(t_file);
				return (-1);
			}
			dup2(file_fd, STDIN_FILENO);
			close(file_fd);
		}
		if (ft_strncmp(temp->type, "outfile", 7) == 0)
		{
			if (ft_error_deux(file_fdfinal = open(temp->cmd,
						O_WRONLY | O_TRUNC | O_CREAT, 0644), temp->cmd, t_file))
			{
				file_fdfinal = open("/dev/null", O_RDONLY, 0644);
				dup2(file_fdfinal, STDOUT_FILENO);
				close(file_fdfinal);
				close(t_file->stdin_fd);
				close(t_file->stdout_fd);
				if (argv != NULL)
					ft_fre(argv);
				free(t_file);
				return (-1);
			}
			dup2(file_fdfinal, STDOUT_FILENO);
			close(file_fdfinal);
		}
		else if (ft_strncmp(temp->type, "append", 6) == 0)
		{
			if (ft_error_deux(file_fdfinal = open(temp->cmd,
						O_WRONLY | O_APPEND | O_CREAT, 0644), temp->cmd,
					t_file))
			{
				file_fdfinal = open("/dev/null", O_RDONLY, 0644);
				dup2(file_fdfinal, STDOUT_FILENO);
				close(file_fdfinal);
				close(t_file->stdin_fd);
				close(t_file->stdout_fd);
				if (argv != NULL)
					ft_fre(argv);
				free(t_file);
				return (-1);
			}
			dup2(file_fdfinal, STDOUT_FILENO);
			close(file_fdfinal);
		}
		temp = temp->next;
	}
	//	dprintf(2, "\n file_fd=%d file_fdfinal=%d \n", file_fd, file_fdfinal);
	return (0);
}

t_cmd	*ft_temp(t_cmd *temp, int t)
{
	int	j;

	j = 0;
	while (temp != NULL && j < t)
	{
		if (ft_strncmp(temp->type, "pipe", 4) == 0)
			j++;
		temp = temp->next;
	}
	return (temp);
}

int	ft_generate_infile(t_pointer_cmd **pointerB, t_file_fd *t_file,
		t_pointer **pointera, t_listp **listp)
{
	t_cmd	*temp;
	int		file_fd;

	file_fd = 0;
	temp = (*pointerB)->first;
	if (t_file == NULL)
		return (0);
	temp = ft_temp(temp, t_file->t);
	while (temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(temp->type, "infile", 6) == 0 || ft_strncmp(temp->type,
				"here_doc", 8) == 0)
		{
			if (ft_error_deux(file_fd = open(temp->cmd, O_RDONLY, 0644),
					temp->cmd, t_file) == 1)
			{
				file_fd = open("/dev/null", O_RDONLY, 0644);
				dup2(file_fd, STDIN_FILENO);
				close(file_fd);
				if ((*listp)->before != NULL)
					close((*listp)->before->pipe_fd[0]);
				close((*listp)->pipe_fd[0]);
				close((*listp)->pipe_fd[1]);
				ft_clean_final(listp, pointera, pointerB, t_file);
				exit(1);
			}
			dup2(file_fd, STDIN_FILENO);
			close(file_fd);
		}
		temp = temp->next;
	}
	return (file_fd);
}

int	ft_generate_outfile(t_pointer_cmd **pointerB, t_file_fd *t_file,
		t_pointer **pointera, t_listp **listp)
{
	t_cmd	*temp;
	int			file_fdfinal;

	file_fdfinal = 0;
	temp = ft_temopo(pointerB, t_file);
	while (temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(temp->type, "outfile", 7) == 0)
		{
			if (ft_error_deux(file_fdfinal = open(temp->cmd,
						O_WRONLY | O_TRUNC | O_CREAT, 0644), temp->cmd, t_file))
				ft_out_error(listp, pointera, pointerB, t_file);
			ft_dup(file_fdfinal);
		}
		else if (ft_strncmp(temp->type, "append", 6) == 0)
		{
			if (ft_error_deux(file_fdfinal = open(temp->cmd,
						O_WRONLY | O_APPEND | O_CREAT, 0644), temp->cmd,
					t_file))
				ft_out_error(listp, pointera, pointerB, t_file);
			ft_dup(file_fdfinal);
		}
		temp = temp->next;
	}
	return (file_fdfinal);
}

t_cmd	*ft_temopo(t_pointer_cmd **pointerB, t_file_fd *t_file)
{
	t_cmd	*temp;

	temp = (*pointerB)->first;
	if (t_file == NULL)
		return (NULL);
	temp = ft_temp(temp, t_file->t);
	return (temp);
}

void	ft_dup(int file_fdfinal)
{
	dup2(file_fdfinal, STDOUT_FILENO);
	close(file_fdfinal);
}

void	ft_out_error(t_listp **listp, t_pointer **pointera,
		t_pointer_cmd **pointerB, t_file_fd *t_file)
{
	int	file_fdfinal;

	file_fdfinal = open("/dev/null", O_RDONLY, 0644);
	dup2(file_fdfinal, STDOUT_FILENO);
	close(file_fdfinal);
	if ((*listp)->before != NULL)
		close((*listp)->before->pipe_fd[0]);
	close((*listp)->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
	ft_clean_final(listp, pointera, pointerB, t_file);
	exit(1);
}

char	**ft_generate_argv(t_pointer_cmd **pointerB, int t)
{
	char		**argv;
	t_cmd	*temp;
	t_cmd	*zoro;
	int			i;

	argv = NULL;
	i = 0;
	temp = (*pointerB)->first;
	zoro = (*pointerB)->first;
	temp = ft_temp(temp, t);
	while (temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(temp->type, "word", 4) == 0)
			i++;
		temp = temp->next;
	}
	argv = ft_generate_argv_un(zoro, t, i);
	return (argv);
}

char	**ft_generate_argv_un(t_cmd *zoro, int t, int i)
{
	char	**argv;
	
	argv = (char **)malloc((i + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (zoro != NULL && i < t)
	{
		if (ft_strncmp(zoro->type, "pipe", 4) == 0)
			i++;
		zoro = zoro->next;
	}
	i = 0;
	while (zoro != NULL && ft_strncmp(zoro->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(zoro->type, "word", 4) == 0)
		{
			argv[i] = ft_strdup(zoro->cmd);
			i++;
		}
		zoro = zoro->next;
	}
	argv[i] = NULL;
	return (argv);
}

void	ft_un(t_pointer_cmd **pointerB, t_pointer **pointera, t_file_fd *t_file,
		t_listp **listp)
{
	char	**patch;
	char	**argv;
	char	**env;
	int		status;

	status = 0;
	patch = NULL;
	env = NULL;
	argv = NULL;
	if ((*listp)->pid == 0)
	{
		close((*listp)->pipe_fd[0]);
		close(t_file->stdin_fd);
		close(t_file->stdout_fd);
		ft_generate_infile(pointerB, t_file, pointera, listp);
		if (ft_generate_outfile(pointerB, t_file, pointera, listp) == 0)
			dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
		close((*listp)->pipe_fd[1]);
		argv = ft_generate_argv(pointerB, t_file->t);
		if (!(argv == NULL || argv[0] == NULL))
		{
			if (ft_arg_buildin(argv) == 0)
			{
				ft_signaux_annul(0);
				if (ft_strncmp(argv[0], "exit", 5) == 0)
					status = ft_arg_exit(argv, status);
				else
					status = ft_analyse_arg_buildin(argv, pointera, t_file);
				ft_fre(argv);
				ft_clean_final(listp, pointera, pointerB, t_file);
				ft_signaux_annul(1);
				exit(status);
			}
			env = ft_transform_env_list(pointera);
			patch = ft_testpath(ft_path(env), argv);
			ft_exe(patch, 0, argv, env);
			ft_test_dir(argv[0]);
			ft_fre(env);
		}
		ft_fre(argv);
		free(t_file);
		ft_clean_all(patch, listp, pointerB, pointera);
		exit(EXIT_FAILURE);
	}
	else
		*listp = ft_parent_un(listp);
}

void	ft_mid(t_pointer_cmd **pointerB, t_pointer **pointera,
		t_file_fd *t_file, t_listp **listp)
{
	char	**patch;
	char	**argv;
	char	**env;
	int		t;
	int		status;

	t = 0;
	patch = NULL;
	argv = NULL;
	env = NULL;
	status = 0;
	if ((*listp)->pid == 0)
	{
		close(t_file->stdin_fd);
		close(t_file->stdout_fd);
		if (ft_generate_infile(pointerB, t_file, pointera, listp) == 0)
			dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
		close((*listp)->before->pipe_fd[0]);
		close((*listp)->pipe_fd[0]);
		if (ft_generate_outfile(pointerB, t_file, pointera, listp) == 0)
			dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
		close((*listp)->pipe_fd[1]);
		argv = ft_generate_argv(pointerB, t_file->t);
		if (!(argv == NULL || argv[0] == NULL))
		{
			if (ft_arg_buildin(argv) == 0)
			{
				ft_signaux_annul(0);
				if (ft_strncmp(argv[0], "exit", 5) == 0)
					status = ft_arg_exit(argv, status);
				else
					status = ft_analyse_arg_buildin(argv, pointera, t_file);
				ft_fre(argv);
				ft_clean_final(listp, pointera, pointerB, t_file);
				ft_signaux_annul(1);
				exit(status);
			}
			env = ft_transform_env_list(pointera);
			patch = ft_testpath(ft_path(env), argv);
			ft_exe(patch, t, argv, env);
			ft_test_dir(argv[0]);
			ft_fre(env);
		}
		ft_fre(argv);
		free(t_file);
		ft_clean_all(patch, listp, pointerB, pointera);
		exit(EXIT_FAILURE);
	}
	else
	{
		close((*listp)->before->pipe_fd[0]);
		close((*listp)->pipe_fd[1]);
		*listp = ft_maillon(*listp);
	}
}

int	ft_last(t_pointer_cmd **pointerB, t_pointer **pointera, t_file_fd *t_file,
		t_listp **listp)
{
	char	**patch;
	char	**argv;
	char	**env;
	int		t;
	int		status;

	t = 0;
	status = 0;
	patch = NULL;
	argv = NULL;
	close((*listp)->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
	if ((*listp)->pid == 0)
	{
		close(t_file->stdin_fd);
		close(t_file->stdout_fd);
		if (ft_generate_infile(pointerB, t_file, pointera, listp) == 0)
			dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
		close((*listp)->before->pipe_fd[0]);
		ft_generate_outfile(pointerB, t_file, pointera, listp);
		argv = ft_generate_argv(pointerB, t_file->t);
		if (!(argv == NULL || argv[0] == NULL))
		{
			if (ft_arg_buildin(argv) == 0)
			{
				ft_signaux_annul(0);
				if (ft_strncmp(argv[0], "exit", 5) == 0)
					status = ft_arg_exit(argv, status);
				else
					status = ft_analyse_arg_buildin(argv, pointera, t_file);
				ft_fre(argv);
				ft_clean_final(listp, pointera, pointerB, t_file);
				ft_signaux_annul(1);
				exit(status);
			}
			env = ft_transform_env_list(pointera);
			patch = ft_testpath(ft_path(env), argv);
			ft_exe(patch, t, argv, env);
			ft_test_dir(argv[0]);
			ft_fre(env);
		}
		ft_fre(argv);
		free(t_file);
		ft_clean_all(patch, listp, pointerB, pointera);
		exit(EXIT_FAILURE);
	}
	else
		close((*listp)->before->pipe_fd[0]);
	return (0);
}

void	ft_restore_fd(t_file_fd *t_file)
{
	if (t_file != NULL)
	{
		dup2(t_file->stdin_fd, STDIN_FILENO);
		close(t_file->stdin_fd);
		dup2(t_file->stdout_fd, STDOUT_FILENO);
		close(t_file->stdout_fd);
	}
}

int	ft_arg_buildin(char **argv)
{
	if (argv == NULL || argv[0] == NULL)
		return (1);
	if (argv[0][0] >= '0' && argv[0][0] <= '9')
		return (1);
	if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (0);
	else
		return (1);
}
