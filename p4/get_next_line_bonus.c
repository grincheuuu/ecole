/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:06:49 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/30 18:36:29 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		save = ft_strjoin(save, buf);
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
	static char	*save[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read_and_save(fd, save[fd]);
	if (save[fd] == NULL)
	{
		free (save[fd]);
		return (NULL);
	}
	line = ft_tronc(save[fd]);
	save[fd] = ft_after(save[fd]);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;

	line = NULL;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
        free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
        free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
        free(line);

	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close (fd);
	return (0);
}*/
