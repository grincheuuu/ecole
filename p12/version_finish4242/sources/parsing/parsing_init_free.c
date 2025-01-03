/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:08:47 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 03:36:37 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_cub_file(t_cubfile *cubfile)
{
	int	co;

	co = 0;
	if (cubfile->floor_color)
		free(cubfile->floor_color);
	if (cubfile->ceiling_color)
		free(cubfile->ceiling_color);
	if (cubfile->ea_path)
		free(cubfile->ea_path);
	if (cubfile->no_path)
		free(cubfile->no_path);
	if (cubfile->so_path)
		free(cubfile->so_path);
	if (cubfile->we_path)
		free(cubfile->we_path);
	while ((co < cubfile->column_length))
	{
		free(cubfile->map[co]);
		co++;
	}
	free(cubfile->map);
	free(cubfile);
}

int	free_path_fail(t_cubfile *cubfile, char **line, int fd, char ***map_char)
{
	if (cubfile->floor_color)
		free(cubfile->floor_color);
	if (cubfile->ceiling_color)
		free(cubfile->ceiling_color);
	if (cubfile->ea_path)
		free(cubfile->ea_path);
	if (cubfile->no_path)
		free(cubfile->no_path);
	if (cubfile->so_path)
		free(cubfile->so_path);
	if (cubfile->we_path)
		free(cubfile->we_path);
	free_readline(line, fd, cubfile);
	free(*map_char);
	return (1);
}

void	free_files_rgb(char ***map_char,
	t_cubfile *cubfile, char **line, int fd)
{
	free(*map_char);
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd, cubfile);
	}
	free(*line);
}

void	free_files_rgb2(t_cubfile *cubfile, char **line, int fd)
{
	free_cub_file(cubfile);
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd, cubfile);
	}
	free(*line);
}

t_cubfile	*init_cubfile(void)
{
	t_cubfile	*cubfile;

	cubfile = (t_cubfile *)malloc(sizeof(t_cubfile));
	if (!cubfile)
	{
		printf("Error\n");
		printf("error :malloc failed\n");
		return (NULL);
	}
	cubfile->no_path = NULL;
	cubfile->so_path = NULL;
	cubfile->we_path = NULL;
	cubfile->ea_path = NULL;
	cubfile->floor_color = NULL;
	cubfile->ceiling_color = NULL;
	cubfile->row_length = 0;
	cubfile->column_length = 0;
	cubfile->map = NULL;
	cubfile->player_x = -1;
	cubfile->player_y = -1;
	cubfile->player_orientation = 0;
	cubfile->failed = 0;
	cubfile->number_of_path = 0;
	cubfile->number_of_rgb = 0;
	return (cubfile);
}
