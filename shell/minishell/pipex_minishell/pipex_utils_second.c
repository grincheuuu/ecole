/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:41:13 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/08 19:41:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src == NULL)
		return (NULL);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_file(char *argv)
{
	int		file_fd;

	file_fd = open(argv, O_RDONLY, 0644);
	if (file_fd == -1)
	{
		perror("file_fd");
		file_fd = open("/dev/null", O_RDONLY);
	}
	return (file_fd);
}

void	ft_test_file_fd(char *argv, t_pointer *pointer)
{
	int	file_fd;
	int	i;

	i = 0;
	file_fd = open(argv, O_RDONLY, 0644);
	if (file_fd == -1)
	{
		i++;
		ft_lstclear(&pointer->first);
		free(pointer);
		exit(EXIT_FAILURE);
	}
	else
		close(file_fd);
}

t_listp	*ft_parent_un(t_listp **listp, t_pointer *pointer)
{
	close((*listp)->pipe_fd[1]);
	return (ft_maillon(*listp, pointer));
}
