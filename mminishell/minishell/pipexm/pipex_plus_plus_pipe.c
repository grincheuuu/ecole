/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:30:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/15 19:17:51 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_generate_fd(t_pointer_cmd **pointerB, t_file_fd *t_file, char **argv)
{
	t_lexing	*temp;
	int			file_fd;
	int			status;
	int			file_fdfinal;

	file_fd = 0;
	status = 0;
	file_fdfinal = 0;
	temp = (*pointerB)->first;
	if (t_file == NULL)
		return (0);
	while (temp != NULL && temp->special_token != 5)
	{
		if (temp->special_token == 1 || temp->special_token == 2)
			status = ft_generate_fd_un(t_file, argv, temp, file_fd);
		else if (temp->special_token == 3)
			status = ft_generate_fd_deux(t_file, argv, temp, file_fdfinal);
		else if (temp->special_token == 4)
			status = ft_generate_fd_trois(t_file, argv, temp, file_fd);
		temp = temp->next;
		if (status == -1)
			break ;
	}
	return (status);
}

int	ft_generate_fd_un(t_file_fd *t_file, char **argv, t_lexing *temp,
		int file_fd)
{
	int	i;

	file_fd = open(temp->cmd, O_RDONLY, 0644);
	i = ft_error_deux(file_fd, temp->cmd, t_file) == 1;
	if (i == 1)
	{
		file_fd = open("/dev/null", O_RDONLY, 0644);
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
		close(t_file->stdin_fd);
		close(t_file->stdout_fd);
		free(t_file);
		if (argv != NULL)
			ft_fre(argv);
		return (-1);
	}
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	return (0);
}

int	ft_generate_fd_deux(t_file_fd *t_file, char **argv, t_lexing *temp,
		int file_fdfinal)
{
	int	i;

	file_fdfinal = open(temp->cmd, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	i = ft_error_deux(file_fdfinal, temp->cmd, t_file);
	if (i == 1)
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
	return (0);
}

int	ft_generate_fd_trois(t_file_fd *t_file, char **argv, t_lexing *temp,
		int file_fdfinal)
{
	int	i;

	file_fdfinal = open(temp->cmd, O_WRONLY | O_APPEND | O_CREAT, 0644);
	i = ft_error_deux(file_fdfinal, temp->cmd, t_file);
	if (i == 1)
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
	return (0);
}

t_lexing	*ft_temp(t_lexing *temp, int t)
{
	int	j;

	j = 0;
	while (temp != NULL && j < t)
	{
		if (temp->special_token == 5)
			j++;
		temp = temp->next;
	}
	return (temp);
}
