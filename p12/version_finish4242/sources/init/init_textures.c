/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 16:35:18 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*load_texture_to_buffer(t_data *data, char *path, int tex_size)
{
	t_img	texture_img;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &texture_img, path);
	buffer = ft_calloc(1, sizeof(int) * tex_size * tex_size);
	if (!buffer)
		clean_exit(data, 5);
	y = 0;
	while (y < tex_size)
	{
		x = 0;
		while (x < tex_size)
		{
			buffer[y * tex_size + x] = texture_img.addr[y * tex_size + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(data->mlx, texture_img.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof(int *));
	if (!data->textures)
		clean_exit(data, 5);
	data->textures[NORTH] = load_texture_to_buffer(data, data->texinfo.north,
			data->texinfo.size);
	data->textures[SOUTH] = load_texture_to_buffer(data, data->texinfo.south,
			data->texinfo.size);
	data->textures[EAST] = load_texture_to_buffer(data, data->texinfo.east,
			data->texinfo.size);
	data->textures[WEST] = load_texture_to_buffer(data, data->texinfo.west,
			data->texinfo.size);
}

void	init_texinfo(t_texinfo *texinfo)
{
	texinfo->north = NULL;
	texinfo->south = NULL;
	texinfo->west = NULL;
	texinfo->east = NULL;
	texinfo->floor = 0;
	texinfo->ceiling = 0;
	texinfo->hexfloor = 0x0;
	texinfo->hexceiling = 0x0;
	texinfo->size = 64;
	texinfo->step = 0.0;
	texinfo->pos = 0.0;
	texinfo->x = 0;
	texinfo->y = 0;
}
