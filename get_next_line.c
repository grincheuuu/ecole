/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:21:27 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/24 17:15:46 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_and_save(int fd, char *save)
{
	char	*buf;
	int	readbytes;

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
			return (NULL);
		}
		buf[readbytes] = '\0';
		save = ft_strjoin(save, buf);
		if (strchr(save) == '\n')
			break ;
	}
	free (buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || sizeof(buf) <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
}

int	main(void)
{
	int	fd;
	char	*line;

	line = NULL;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}
