/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:54:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_map_line(t_data *data, int line_index, int width)
{
	data->map[line_index] = (char *)malloc(sizeof(char) * (width + 1));
	if (!data->map[line_index])
		clean_exit(data, 1);
}

void	copy_map_line(char *dest, int *src, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (src[j] == 0)
			dest[j] = '0';
		else if (src[j] == 1)
			dest[j] = '1';
		else
			dest[j] = ' ';
		j++;
	}
	dest[width] = '\0';
}

void	transfer_map(t_data *data, t_cubfile *cubfile)
{
	int	i;

	data->map = (char **)malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		clean_exit(data, 1);
	i = 0;
	while (i < data->mapinfo.height)
	{
		allocate_map_line(data, i, data->mapinfo.width);
		copy_map_line(data->map[i], cubfile->map[i], data->mapinfo.width);
		i++;
	}
	data->map[data->mapinfo.height] = NULL;
}

void	transfer_player_and_texinfo(t_data *data, t_cubfile *cubfile)
{
	data->texinfo.north = ft_strdup(cubfile->no_path);
	data->texinfo.south = ft_strdup(cubfile->so_path);
	data->texinfo.west = ft_strdup(cubfile->we_path);
	data->texinfo.east = ft_strdup(cubfile->ea_path);
	data->texinfo.floor = cubfile->floor_color;
	data->texinfo.ceiling = cubfile->ceiling_color;
	data->texinfo.hexfloor = ((cubfile->floor_color[0] & 0xFF) << 16)
		| ((cubfile->floor_color[1] & 0xFF) << 8)
		| (cubfile->floor_color[2] & 0xFF);
	data->texinfo.hexceiling = ((cubfile->ceiling_color[0] & 0xFF) << 16)
		| ((cubfile->ceiling_color[1] & 0xFF) << 8)
		| (cubfile->ceiling_color[2] & 0xFF);
	data->mapinfo.width = cubfile->row_length;
	data->mapinfo.height = cubfile->column_length;
	data->player.pos_x = cubfile->player_x + 0.5;
	data->player.pos_y = cubfile->player_y + 0.5;
	if (cubfile->player_orientation == 'N')
		data->player.dir = 'N';
	else if (cubfile->player_orientation == 'S')
		data->player.dir = 'S';
	else if (cubfile->player_orientation == 'E')
		data->player.dir = 'E';
	else if (cubfile->player_orientation == 'W')
		data->player.dir = 'W';
}

void	transfer_cubfile_to_data(t_data *data, t_cubfile *cubfile)
{
	transfer_player_and_texinfo(data, cubfile);
	transfer_map(data, cubfile);
}
