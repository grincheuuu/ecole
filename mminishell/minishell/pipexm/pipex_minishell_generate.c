/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_minishell_generate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:18:04 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:18:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_generate_infile(t_pointer_cmd **pointerB, t_file_fd *t_file,
		t_pointer **pointera, t_listp **listp)
{
	t_lexing	*temp;
	int			file_fd;
	int			i;

	file_fd = 0;
	i = 0;
	temp = ft_temopo(pointerB, t_file);
	while (temp != NULL && temp->special_token != 5)
	{
		if (temp->special_token == 1 || temp->special_token == 2)
		{
			file_fd = open(temp->cmd, O_RDONLY, 0644);
			i = ft_error_deux(file_fd, temp->cmd, t_file);
			if (i == 1)
			{
				ft_generate_infile_error(file_fd, listp);
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

void	ft_generate_infile_error(int file_fd, t_listp **listp)
{
	file_fd = open("/dev/null", O_RDONLY, 0644);
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	if ((*listp)->before != NULL)
		close((*listp)->before->pipe_fd[0]);
	close((*listp)->pipe_fd[0]);
	close((*listp)->pipe_fd[1]);
}

int	ft_generate_outfile(t_pointer_cmd **pointerB, t_file_fd *t_file,
		t_pointer **pointera, t_listp **listp)
{
	t_lexing	*temp;
	int			file_fdfinal;
	int			i;

	file_fdfinal = 0;
	temp = ft_temopo(pointerB, t_file);
	while (temp != NULL && temp->special_token != 5)
	{
		if (temp->special_token == 3)
		{
			i = ft_error_out(&file_fdfinal, 3, temp, t_file);
			if (i == 1)
				ft_out_error(listp, pointera, pointerB, t_file);
			ft_dup(file_fdfinal);
		}
		else if (temp->special_token == 4)
		{
			i = ft_error_out(&file_fdfinal, 4, temp, t_file);
			if (i == 1)
				ft_out_error(listp, pointera, pointerB, t_file);
			ft_dup(file_fdfinal);
		}
		temp = temp->next;
	}
	return (file_fdfinal);
}

int	ft_error_out(int *file_fdfinal, int n, t_lexing *temp, t_file_fd *t_file)
{
	int	i;

	i = 0;
	if (n == 3)
	{
		*file_fdfinal = open(temp->cmd, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		i = ft_error_deux(*file_fdfinal, temp->cmd, t_file);
	}
	if (n == 4)
	{
		*file_fdfinal = open(temp->cmd, O_WRONLY | O_APPEND | O_CREAT, 0644);
		i = ft_error_deux(*file_fdfinal, temp->cmd, t_file);
	}
	return (i);
}

t_lexing	*ft_temopo(t_pointer_cmd **pointerB, t_file_fd *t_file)
{
	t_lexing	*temp;

	temp = (*pointerB)->first;
	if (t_file == NULL)
		return (NULL);
	temp = ft_temp(temp, t_file->t);
	return (temp);
}
