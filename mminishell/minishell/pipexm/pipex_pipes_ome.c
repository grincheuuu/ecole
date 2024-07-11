/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes_ome.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:32:34 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:32:45 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_exit_failure(t_pointer **pointera, t_pointer_cmd **pointerB,
		t_file_fd *t_file)
{
	(void)t_file;
	ft_lstclear_bis(&(*pointera)->first);
	free(*pointera);
	ft_lstclear_node(&(*pointerB)->first);
	free(*pointerB);
	rl_clear_history();
	exit(127);
}

void	ft_close_fd(int pipe_fd[], t_file_fd *t_file)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = (unsigned char *)s;
	while (n > 0)
	{
		p[i] = 0;
		n--;
		i++;
	}
}

int	ft_wait(t_listp **listp, t_pointer_cmd **pointerB)
{
	t_listp	*temp;

	temp = *listp;
	while (*listp != NULL)
	{
		temp = *listp;
		*listp = (*listp)->before;
	}
	while (temp->next != NULL)
	{
		close(temp->pipe_fd[0]);
		waitpid(temp->pid, &temp->status, 0);
		temp = temp->next;
	}
	waitpid(temp->pid, &temp->status, 0);
	if (WEXITSTATUS(temp->status))
		temp->status = WEXITSTATUS(temp->status);
	ft_unlink(pointerB);
	return (temp->status);
}

void	ft_stat(char *patch)
{
	struct stat	file;

	stat(patch, &file);
	if (S_ISDIR(file.st_mode))
	{
		write(2, "minishell: ", 11);
		ft_putstr_fd(patch, 2);
		write(2, ": Is a directory\n", 17);
	}
	else if ((access(patch, F_OK | X_OK) < 0))
	{
		write(2, "minishell: ", 11);
		ft_putstr_fd(patch, 2);
		write(2, ": Permission denied\n", 20);
	}
}
