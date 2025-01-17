/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:15:38 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:18:31 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**init_map_char(void)
{
	char	**map_char;

	map_char = (char **)malloc(2 * sizeof(char *));
	if (!map_char)
		return (NULL);
	map_char[0] = NULL;
	map_char[1] = NULL;
	return (map_char);
}

int	validate_map(t_cubfile *cubfile)
{
	int	co;
	int	co2;

	co = 0;
	co2 = 0;
	while (co < cubfile->column_length)
	{
		co2 = 0;
		while (co2 < cubfile->row_length)
		{
			if (cubfile->map[co][co2] == 0)
			{
				if (bad_pixel(cubfile, co, co2) == 1)
					return (1);
			}
			co2++;
		}
		co++;
	}
	return (0);
}

int	char_to_int_map(t_cubfile *cubfile, char **map_char)
{
	int	number_of_players;

	number_of_players = 0;
	if (finalise_player(cubfile, map_char, &number_of_players) == 2)
		return (2);
	cubfile->map = (int **)malloc(cubfile->column_length * sizeof(int *));
	if (!cubfile->map)
		fail_char_to_int_map(&map_char, cubfile);
	finalize_put_in_map_int_line(cubfile, map_char);
	return (validate_map(cubfile));
}

void	update_map_char(char **line, t_cubfile *cubfile,
	char ***map_char, int *start_map)
{
	if (((cubfile->co) - *start_map) == 0)
	{
		(*map_char)[0] = ft_strdup(*line);
		if ((*map_char)[0] == NULL)
			clean_map_char_null(cubfile, cubfile->fd, line, map_char);
	}
	else
	{
		if (updates_char(map_char, *line))
		{
			free_cub_file(cubfile);
			free_map_char(map_char);
			free_readline(line, cubfile->fd, cubfile);
			exit(0);
		}
	}
}

int	map_parsing(char ***map_char, t_cubfile *cubfile,
	char *line, int *start_map)
{
	if (does_line_have(line) == 0)
	{
		if ((*start_map) == -1)
			(*start_map) = (cubfile->co);
		if ((line)[ft_strlen(line)] == '\n')
			(line)[ft_strlen(line)] = '\0';
		update_map_char(&line, cubfile, map_char, start_map);
	}
	else if (cubfile->number_of_path == 4 && cubfile->number_of_rgb == 2)
	{
		printf("Error\n");
		printf("error: map: invalid caracter, the only allowed ");
		printf("caracters are '1', '0', ' ', 'N', 'S', 'E', 'W'\n");
		free(line);
		free_map_char_lines(cubfile, cubfile->fd, map_char);
		return (1);
	}
	return (0);
}
