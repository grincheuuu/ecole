/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_limiteur_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:05:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/21 15:07:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_read_and_save(int fd, char *save)
{
	char	*buf;
	int		readbytes;

	buf = malloc(((BUFFER_SIZE) + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	readbytes = 1;
	while (readbytes != 0)
	{
		readbytes = read(fd, buf, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[readbytes] = '\0';
		save = ft_strjoined(save, buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free (buf);
	return (save);
}

char	*ft_tronc(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (save[j] != '\n' && save[j] != '\0')
	{
		line[j] = save[j];
		j++;
	}
	if (save[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_after(char *save)
{
	char	*dest;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (save[i] != '\0' && save [i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free (save);
		return (NULL);
	}
	while (save[i + j + 1] != '\0')
		j++;
	dest = (char *)malloc((j + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[j] = '\0';
	j = 0;
	while (save[++i] != '\0')
		dest[j++] = save[i];
	free(save);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if (save == NULL)
	{
		free (save);
		return (NULL);
	}
	line = ft_tronc(save);
	save = ft_after(save);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			p = s;
			return ((char *)p);
		}
		s++;
	}
	if (*s == (char)c)
	{
		p = s;
		return ((char *)p);
	}
	return (NULL);
}
