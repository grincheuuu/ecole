/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:02:28 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:03:58 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_new_line1(char **read_lines)
{
	free(*read_lines);
	return (NULL);
}

void	*free_new_line2(char **read_lines, t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("Error\n");
	printf("error :malloc failed\n");
	free(read_lines);
	return (NULL);
}

char	*ft_new_lines(char *read_lines, t_cubfile *cubfile)
{
	int		i;
	int		j;
	char	*new_lines;

	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	if (!read_lines[i])
		return (free_new_line1(&read_lines));
	new_lines = (char *)malloc(sizeof(char) * (ft_strlen(read_lines) - i + 1));
	if (!new_lines)
		return (free_new_line2(&read_lines, cubfile));
	i++;
	j = 0;
	while (read_lines[i])
		new_lines[j++] = read_lines[i++];
	new_lines[j] = '\0';
	free(read_lines);
	return (new_lines);
}

void	*free_lines(t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("Error\n");
	printf("error :malloc failed\n");
	return (NULL);
}

char	*ft_lines(char *read_lines, t_cubfile *cubfile)
{
	char	*lines;
	int		i;

	i = 0;
	if (!read_lines[i])
		return (NULL);
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	lines = (char *)malloc(sizeof(char) * i + 2);
	if (!lines)
		free_lines(cubfile);
	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	if (read_lines[i] == '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	lines[i] = '\0';
	return (lines);
}
