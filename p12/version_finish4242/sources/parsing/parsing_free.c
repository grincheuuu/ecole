/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:38:40 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 03:49:28 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map_char(char ***map_char)
{
	int	co;

	co = 0;
	while ((*map_char)[co] != NULL)
	{
		free((*map_char)[co]);
		co++;
	}
	free(*map_char);
}

int	free_if_2(char ***map_char, t_cubfile *cubfile)
{
	free_map_char(map_char);
	if (cubfile->no_path)
		free(cubfile->no_path);
	free(cubfile->so_path);
	free(cubfile->we_path);
	free(cubfile->ea_path);
	free(cubfile->floor_color);
	free(cubfile->ceiling_color);
	free(cubfile);
	exit(0);
}

void	free_readline(char **line, int fd, t_cubfile *cubfile)
{
	while (*line)
	{
		free(*line);
		(*line) = get_next_line(fd, cubfile);
	}
	free(*line);
}

void	free_cub_file2(t_cubfile *cubfile)
{
	if (cubfile->no_path)
		free(cubfile->no_path);
	free(cubfile->so_path);
	free(cubfile->we_path);
	free(cubfile->ea_path);
	free(cubfile->floor_color);
	free(cubfile->ceiling_color);
	free(cubfile->map);
	free(cubfile);
}

void	free_map_char_lines(t_cubfile *cubfile, int fd, char ***map_char)
{
	char	*line;

	line = get_next_line(fd, cubfile);
	while (line)
	{
		free(line);
		line = get_next_line(fd, cubfile);
	}
	free(line);
	free_map_char(map_char);
}
