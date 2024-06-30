/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_minishell_generate_argv.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:20:07 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:20:23 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	t_lexing	*temp;
	t_lexing	*zoro;
	int			i;

	argv = NULL;
	i = 0;
	temp = (*pointerB)->first;
	zoro = (*pointerB)->first;
	temp = ft_temp(temp, t);
	while (temp != NULL && temp->special_token != 5)
	{
		if (temp->special_token == 0)
			i++;
		temp = temp->next;
	}
	argv = ft_generate_argv_un(zoro, t, i);
	return (argv);
}

char	**ft_generate_argv_un(t_lexing *zoro, int t, int i)
{
	char	**argv;

	argv = (char **)malloc((i + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (zoro != NULL && i < t)
	{
		if (zoro->special_token == 5)
			i++;
		zoro = zoro->next;
	}
	i = 0;
	while (zoro != NULL && zoro->special_token != 5)
	{
		if (zoro->special_token == 0)
		{
			argv[i] = ft_strdup(zoro->cmd);
			i++;
		}
		zoro = zoro->next;
	}
	argv[i] = NULL;
	return (argv);
}

int	ft_initialize(int *status, char ***patch, char ***argv)
{
	*status = 0;
	*patch = NULL;
	*argv = NULL;
	return (0);
}

void	ft_dup(int file_fdfinal)
{
	dup2(file_fdfinal, STDOUT_FILENO);
	close(file_fdfinal);
}
