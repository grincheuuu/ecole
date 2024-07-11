/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mini_ajout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:40:00 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:40:04 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_test_dir(char *patch)
{
	struct stat	file;

	if (stat(patch, &file) == 0)
	{
		ft_stat(patch);
	}
	else if ((patch != NULL && patch[0] != '\0') && (patch[ft_strlen(patch)
				- 1] == '/' || patch[0] == '/'))
	{
		write(2, "minishell: ", 11);
		ft_putstr_fd(patch, 2);
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		write(2, "minishell: command not found: ", 30);
		ft_putstr_fd(patch, 2);
		write(2, "\n", 1);
	}
}

int	ft_error(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}
