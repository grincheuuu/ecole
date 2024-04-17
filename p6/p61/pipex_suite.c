/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:06:16 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/08 20:06:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve_error(int n, const char *str, char ***thor, char ***com)
{
	if (n == -1)
	{
		perror(str);
		ft_fre(*thor);
		ft_fre(*com);
		exit(EXIT_FAILURE);
	}
}

int	ft_file(char *argv)
{
	int		file_fd;

	file_fd = open(argv, O_RDONLY, 0644);
	if (access(argv, R_OK) != 0)
	{
		perror("file_fd");
		file_fd = open("/dev/null", O_RDONLY);
	}
	return (file_fd);
}
