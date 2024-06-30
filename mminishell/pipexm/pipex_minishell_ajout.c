/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_minishell_ajout.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:15:06 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:15:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	t_lexing	*temp;
	int			file_fd;

	temp = (*pointerB)->first;
	file_fd = 0;
	while (temp != NULL)
	{
		if (temp->special_token == 2)
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
	return (status);
}

void	ft_realize_pipe(t_pointer_cmd **pointerB, t_listp **listp,
		t_pointer **pointera, int status)
{
	t_lexing	*temp;
	t_file_fd	*t_file;

	temp = (*pointerB)->first;
	t_file = ft_t_file_initialise(status);
	while (temp != NULL)
	{
		while (temp != NULL && temp->special_token != 5)
			temp = temp->next;
		ft_error(pipe((*listp)->pipe_fd), "pipe_fd");
		ft_error(((*listp)->pid = fork()), "pid");
		if (temp == NULL)
			ft_last(pointerB, pointera, t_file, listp);
		else if (t_file->t == 0)
			ft_un(pointerB, pointera, t_file, listp);
		else
			ft_mid(pointerB, pointera, t_file, listp);
		if (temp != NULL && temp->special_token == 5)
			temp = temp->next;
		t_file->t += 1;
	}
	ft_restore_fd(t_file);
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

/*
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
}*/