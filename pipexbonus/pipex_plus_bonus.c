/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:08:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/20 16:14:35 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int	ft_strlen(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

int	ft_limiteur(char *argv)
{
	int	file_fd;
	char	*line;

	line = NULL;
	file_fd = open(argv, O_RDWR | O_CREAT | O_APPEND, 0644);
	while ((line = get_next_line(0)) != NULL)
	{
		write(file_fd, line, ft_strlen(line));
		free(line);
	}
	return (file_fd);
}
