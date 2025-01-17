/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handle_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:21:31 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 15:54:50 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_ceiling_rgb(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (test_rgb(&line[2]) == 1)
	{
		free_map_char(map_char);
		free_files_rgb(map_char, cubfile, &line, fd);
		return (1);
	}
	if (put_rgb_ceiling(cubfile, &line[2]) == 1)
	{
		free_map_char(map_char);
		free_files_rgb(map_char, cubfile, &line, fd);
		return (1);
	}
	return (0);
}

int	handle_paths(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (handle_no_path(line, cubfile, map_char, fd) == 1)
			return (1);
		update_cub(cubfile);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (handle_so_path(line, cubfile, map_char, fd) == 1)
			return (1);
		update_cub(cubfile);
	}
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		update_cub(cubfile);
		if (handle_we_path(line, cubfile, map_char, fd) == 1)
			return (1);
	}
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		update_cub(cubfile);
		if (handle_ea_path(line, cubfile, map_char, fd) == 1)
			return (1);
	}
	return (0);
}

int	handle_line_map(char *line, t_cubfile *cubfile,
	char ***map_char, int *start_map)
{
	if (map_parsing(map_char, cubfile, line, start_map) == 1)
		return (1);
	return (0);
}

int	handle_line_rgb(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	if (line[0] == 'F' && line[1] == ' ' && cubfile->condition == 0)
	{
		if (handle_floor_rgb(line, cubfile, map_char, fd) == 1)
			return (1);
		(cubfile->number_of_rgb)++;
		cubfile->condition2 = 1;
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		if (handle_ceiling_rgb(line, cubfile, map_char, fd) == 1)
			return (1);
		(cubfile->number_of_rgb)++;
		cubfile->condition2 = 1;
	}
	return (0);
}

int	handle_line_processing(char *line, t_cubfile *cubfile,
	char ***map_char, int *start_map)
{
	cubfile->condition = 0;
	if (handle_paths(line, cubfile, map_char, cubfile->fd) == 1)
		return (1);
	cubfile->condition2 = 0;
	if (handle_line_rgb(line, cubfile, map_char, cubfile->fd) == 1)
		return (1);
	if ((((cubfile->number_of_path == 4) && (cubfile->number_of_rgb == 2))
			|| (line[0] != '\n')) && (cubfile->condition2 == 0))
	{
		if (handle_line_map(line, cubfile, map_char, start_map) == 1)
			return (1);
	}
	if (*start_map != -1 && (cubfile->floor_color == NULL
			|| cubfile->ceiling_color == NULL))
	{
		printf("Error\n");
		printf("error: map: invalid caracter, the only allowed ");
		printf("caracters are '1', '0', ' ', 'N', 'S', 'E', 'W'\n");
		free_readline(&line, cubfile->fd, cubfile);
		free_map_char(map_char);
		return (1);
	}
	return (0);
}
