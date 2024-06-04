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
		if (ft_strncmp(temp->type, "here_doc", 8) == 0 )
		{
			file_fd = open(temp->cmd, O_RDONLY, 0644);
			if (file_fd < 0)
			{
				ft_lstclear_node(&(*pointerB)->first);
				free(pointerB);
				ft_lstclear_bis(&(*pointera)->first);
				free(pointera);
				write (2, "minishell: here_doc : error", 28);
				exit(1);
			}
			close(file_fd);
		}
		temp = temp->next;
	}
	return (0);
}

int	ft_pipeline(t_pointer_cmd *pointerB, t_pointer **pointera)
{
	t_listp		*listp;
	t_listp		*list;
	int			j;
	int			status;
//	t_pointer_p	*pointer;

	j = 0;
	status = 0;
	listp = NULL;
	ft_lstadd_back(&listp, ft_lstnew());
	list = listp;
//	list = ft_pointer_init(listp);
	ft_analyse_here_doc(&pointerB, pointera);
//	listp = ft_lstnew();
//	ft_printlist_aa(&listp);
	ft_realize_pipe(&pointerB, &listp, pointera);
//	ft_printlist_cmd(pointerB);
	status = ft_wait(&listp);
//	ft_printlist_aa(&listp);
	ft_clean_final(list, j);
	return (status >> 8);
}

void	ft_printlist_aa(t_listp **listp)
{
	t_listp	*temp;
	int		i;

	temp = NULL;
	i = 0;

	if (*listp== NULL)
	{
		write (1, "NULL", 4);
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

int	ft_realize_pipe(t_pointer_cmd **pointerB, t_listp **listp, t_pointer **pointera)
{
	t_cmd	*temp;
	char	**argv;
	int		t;
	int		i;
	int		status;
	t_file_fd	*t_file;

	t = 0;
	status = 0;
	temp = (*pointerB)->first;
	argv = NULL;
	t_file = (t_file_fd *)malloc(sizeof(t_file_fd));
	if (t_file == NULL)
		return (0);
	t_file->file_fd = 0;
	t_file->file_fdfinal = 0;
	while (temp != NULL)
	{
		argv = ft_generate_argv(pointerB, t);
		t_file->file_fd = 0;
		t_file->file_fdfinal = 0;
		while(temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
		{
			printf("\neee  eeeee\n");
			if (ft_strncmp(temp->type, "infile", 6) == 0 || ft_strncmp(temp->type, "here_doc", 8) == 0
			|| ft_strncmp(temp->type, "outfile", 7) == 0 || ft_strncmp(temp->type, "append", 6) == 0)
				t_file = ft_realize_fd(temp, t_file);
			temp = temp->next;
		}
		ft_error(pipe((*listp)->pipe_fd), "pipe_fd");
		ft_error(((*listp)->pid = fork()), "pid");
		if (temp == NULL)
		{
			printf("\n\n\nlast\n\n\n\n\n");
			status = ft_last(argv, *pointerB, pointera, t_file, listp);
		}
		else if (t == 0)
		{
			printf("\n\n\nun\n\n\n\n\n");
			ft_un(argv, *pointerB, pointera, t_file, listp);
		}
		else
			ft_mid(argv, *pointerB, pointera, t_file, listp);
		if (temp != NULL && ft_strncmp(temp->type, "pipe", 4) == 0)
			temp = temp->next;
		i = 0;
		while (argv[i] != NULL)
		{
			printf("\n\n\n\ndfdsfa %s fgfdfdg\n", argv[i]);
			i++;
		}
		ft_fre(argv);	
		t++;
	}
//	ft_printlist_cmd(pointerB);
	free(t_file);
	return (status);
}

char	**ft_generate_argv(t_pointer_cmd **pointerB, int t)
{
	char	**argv;
	t_cmd	*temp;
	t_cmd	*zoro;
	int		i;
	int		j;

	argv = NULL;
	i = 0;
	j = 0;
	temp = (*pointerB)->first;
	zoro = (*pointerB)->first;
	printf("%dtt", t);
	while (temp != NULL && j < t)
	{
		if (ft_strncmp(temp->type, "pipe", 4) == 0)
			j++;
		temp = temp->next;
	}
	while (temp != NULL && ft_strncmp(temp->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(temp->type, "word", 4) == 0)
			i++;
		temp = temp->next;
	}
	argv = (char **)malloc((i + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	j = 0;
	while (zoro != NULL && j < t)
	{
		if (ft_strncmp(zoro->type, "pipe", 4) == 0)
			j++;
		zoro = zoro->next;
	}
	j = 0;
	while (zoro != NULL && ft_strncmp(zoro->type, "pipe", 4) != 0)
	{
		if (ft_strncmp(zoro->type, "word", 4) == 0)
		{
			argv[j] = ft_strdup(zoro->cmd);
			j++;
		}
		zoro = zoro->next;
	}
	argv[j] = NULL;
	return (argv);
}

t_file_fd	*ft_realize_fd(t_cmd *temp, t_file_fd *t_file)
{
	int	i;

	i = 0;
	if (t_file == NULL)
	{
		printf("tfile == NULL");
		return (NULL);
	}
	if (ft_strncmp(temp->type, "infile", 7) == 0)
		i = ft_error_deux(t_file->file_fd = open(temp->cmd, O_RDONLY, 0644), temp->cmd, t_file);
//	else if (ft_strncmp(temp->type, "here_doc", 9) == 0)
//		ft_error_deux(t_file->file_fd = ft_heredoc(temp->cmd), "here_doc", t_file);
	else if (ft_strncmp(temp->type, "outfile", 8) == 0)
		i = ft_error_deux(t_file->file_fdfinal = open(temp->cmd, O_WRONLY | O_TRUNC | O_CREAT, 0644), temp->cmd, t_file);
	else if (ft_strncmp(temp->type, "append", 7) == 0)
		i = ft_error_deux(t_file->file_fdfinal = open(temp->cmd, O_WRONLY | O_APPEND | O_CREAT, 0644), temp->cmd, t_file);
	if (i == 1)
		t_file->file_fd = open("/dev/null", O_RDONLY, 0644);
//	printf("\n file_fd=%d file_fdfinal=%d \n", t_file->file_fd, t_file->file_fdfinal);
	return (t_file);
}


void	ft_un(char **argv, t_pointer_cmd *pointerB, t_pointer **pointera, t_file_fd *t_file, t_listp **listp)
{
	char	**patch;
	char	**env;
	int		t;

	t = 0;
	patch = NULL;
	env = NULL;
	dprintf(2, "dd%sdd ", argv[0]);
	if ((*listp)->pid == 0)
	{
		if (t_file->file_fd > 2)
		{
			dup2(t_file->file_fd, STDIN_FILENO);
			close(t_file->file_fd);
		}
		if (t_file->file_fdfinal > 2)
		{
			dup2(t_file->file_fdfinal, STDOUT_FILENO);
			close(t_file->file_fdfinal);
		}
		else
			dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
		close((*listp)->pipe_fd[0]);
		close((*listp)->pipe_fd[1]);
		if (ft_arg_buildin(argv) == 0)
			ft_analyse_arg_buildin(argv, pointera, pointerB, listp, t_file);
		env = ft_transform_env_list(pointera);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		ft_fre(env);
		ft_clean_all(patch, listp);
		write (2, "command not found 1", 19);
		exit(EXIT_FAILURE);
	}
	else
	{
		dprintf(2, "\nelseeeeeeeeeeeeeeeeeeeeeeeee\n");
		*listp = ft_parent_un(listp);
	}
}

void	ft_mid(char **argv, t_pointer_cmd *pointerB, t_pointer **pointera, t_file_fd *t_file, t_listp **listp)
{
	char	**patch;
	char	**env;
	int		t;

	t = 0;
	patch = NULL;
	env = NULL;
	if ((*listp)->pid == 0)
	{
		if (t_file->file_fd > 2)
		{
			dup2(t_file->file_fd, STDIN_FILENO);
			close(t_file->file_fd);
		}
		else
			dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
		close((*listp)->before->pipe_fd[0]);
		if (t_file->file_fdfinal > 2)
		{
			dup2(t_file->file_fdfinal, STDOUT_FILENO);
			close(t_file->file_fdfinal);
		}
		else
			dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
		close((*listp)->pipe_fd[1]);
		close((*listp)->pipe_fd[0]);
		if (ft_arg_buildin(argv) == 0)
			ft_analyse_arg_buildin(argv, pointera, pointerB, listp, t_file);
		env = ft_transform_env_list(pointera);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		ft_clean_all(patch, listp);
		write (2, " command not found ", 19);
		exit(EXIT_FAILURE);
	}
	else
	{
		close((*listp)->before->pipe_fd[0]);
		close((*listp)->pipe_fd[1]);
		*listp = ft_maillon(*listp);
	}
}

int	ft_last(char **argv, t_pointer_cmd *pointerB, t_pointer **pointera, t_file_fd *t_file, t_listp **listp)
{
	char	**patch;
	char	**env;
	int		t;

	t = 0;
	patch = NULL;
	(void)pointerB;
//	dprintf(2, "ll%sll ", argv[0]);
	close((*listp)->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
	if ((*listp)->pid == 0)
	{
		if (t_file->file_fd > 2)
		{
			dprintf(2, "\nfilefd = %d\n", t_file->file_fd);
			dup2(t_file->file_fd, STDIN_FILENO);
			close(t_file->file_fd);
		}
		else
			dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
		if (t_file->file_fdfinal > 2)
		{
			dprintf(2, "\nfilefdfinal = %d\n", t_file->file_fdfinal);
			dup2(t_file->file_fdfinal, STDOUT_FILENO);
			close(t_file->file_fdfinal);
		}
		if (ft_arg_buildin(argv) == 0)
			ft_analyse_arg_buildin(argv, pointera, pointerB, listp, t_file);
		env = ft_transform_env_list(pointera);
		patch = ft_testpath(ft_path(env), argv);
		ft_exe(patch, t, argv, env);
		ft_free_last(patch);
		ft_lstclear(listp);
		ft_fre(env);
		exit(EXIT_FAILURE);
	}
	else
		close((*listp)->before->pipe_fd[0]);
	return (0);
}

int	ft_arg_buildin(char **argv)
{
	if (ft_strncmp(argv[0], "echo", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else if (ft_strncmp(argv[0], "cd", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else if (ft_strncmp(argv[0], "pwd", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else if (ft_strncmp(argv[0], "export", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else if (ft_strncmp(argv[0], "unset", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else if (ft_strncmp(argv[0], "env", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else if (ft_strncmp(argv[0], "exit", ft_strlen(argv[0]) - 1) == 0)
		return(0);
	else
		return (1);
}

/*
char	**ft_create_arg(t_pointer_cmd **pointerB)
{
	t_cmd	*zoro;
	t_cmd	*temp;
	char	**argv;
	int		i;
	int		t;

	i = 0;
	argv = NULL;
	zoro = (*pointerB)->first;
	temp = (*pointerB)->first;
//	i = ft_lst_size(*pointerB);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "pipe", 4) == 0)
			i++;
		else if (ft_strncmp(temp->type, "word", 4) == 0)
			i++;
		printf("\n\n\n\n  %s  \n\n\n\n\n", temp->type);
		temp = temp->next;
	}			printf("\n\n\n\n  %s type \n\n\n\n\n", zoro->type);
			printf("\n\n\n\n  %s  argv \n\n\n\n\n", argv[i]);
	argv = (char **)malloc((i + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	printf("  ca%dca  ", i);
	t = 0;
	while (zoro != NULL)
	{
		printf("\nI\n");
		if (ft_strncmp(zoro->type, "pipe", 4) == 0)
		{
			printf("\n\n\n\n  %s type \n\n\n\n\n", zoro->type);
			printf("\n\n\n\n  %s  argv \n\n\n\n\n", argv[i]);
			argv[t] = ft_strdup(zoro->cmd);
		}
		else if (ft_strncmp(zoro->type, "word", 5) == 0)
		{
			printf("\n\n\n\n  %s type \n\n\n\n\n", zoro->type);
			printf("\n\n\n\n  %s  argv \n\n\n\n\n", argv[i]);
			argv[t] = ft_strdup(zoro->cmd);
		}
		printf("\n\n\n\n  %s type \n\n\n\n\n", zoro->type);
		printf("\n\n\n\n  %s  cmd \n\n\n\n\n", zoro->cmd);
		t++;
	}
	argv[t] = NULL;
	i = 0;
	while (argv[i] != NULL)
	{
		printf("\n\n\n\n  %s aargv \n\n\n\n\n", argv[i]);
		i++;		
	}
	return (argv);
}

int	ft_lst_size(t_pointer_cmd *pointerB)
{
	t_cmd	*temp;
	int	i;

	i = 0;
	temp = pointerB->first;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->type, "pipe", 4) == 0)
			i++;
		else if (ft_strncmp(temp->type, "word", 4) == 0)
			i++;
		temp = temp->next;
	}
	return (i);
}*/
