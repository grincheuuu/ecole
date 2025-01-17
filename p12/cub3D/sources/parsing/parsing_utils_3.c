/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:05:04 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:04:54 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_read_lines1(t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("Error\n");
	printf("error :malloc failed\n");
	return (NULL);
}

void	*free_read_lines2(char **buffer)
{
	free(*buffer);
	return (NULL);
}

char	*ft_read_lines(int fd, char *read_lines, t_cubfile *cubfile)
{
	char	*buffer;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (3 + 1));
	if (!buffer)
		return (free_read_lines1(cubfile));
	r = 1;
	while (!ft_strchr2(read_lines, '\n') && r != 0)
	{
		r = read(fd, buffer, 3);
		if (r == -1)
		{
			free(buffer);
			if (read_lines)
				free(read_lines);
			return (NULL);
		}
		buffer[r] = '\0';
		read_lines = ft_strjoin2(read_lines, buffer, cubfile);
		if (read_lines == NULL)
			return (free_read_lines2(&buffer));
	}
	free(buffer);
	return (read_lines);
}

char	*get_next_line(int fd, t_cubfile *cubfile)
{
	static char		*read_lines;
	char			*lines;

	if (3 <= 0 || fd < 0 || 3 >= 2147483647)
		return (0);
	read_lines = ft_read_lines(fd, read_lines, cubfile);
	if (!read_lines)
		return (NULL);
	lines = ft_lines(read_lines, cubfile);
	read_lines = ft_new_lines(read_lines, cubfile);
	return (lines);
}

int	nblist(const char *str, char c)
{
	int	co;
	int	co2;

	co2 = 0;
	co = 0;
	while (str[co] != '\0')
	{
		if ((str[co] != c)
			&& ((str[co + 1] == c) || (str[co + 1] == '\0')))
			co2++;
		co++;
	}
	return (co2);
}
