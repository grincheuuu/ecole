/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 06:13:06 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Cette fonction initialise ou réinitialise un tableau 2D de pixels pour stocker les couleurs
// correspondant aux textures. Chaque ligne représente la hauteur de la fenêtre (axe Y),
// et chaque colonne représente la largeur (axe X).

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		clean_exit(data,1);
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			clean_exit(data,1);
		i++;
	}
}

// Cette fonction détermine quelle texture utiliser en fonction de la direction
// du mur touché par le rayon.
// attribuer l'index de la texture (NORD, SUD, EST, OUEST) dans `data->texinfo.index`.
// - Si le rayon touche un mur vertical (`side == 0`), on regarde la direction X.
// - Si le rayon touche un mur horizontal (`side == 1`), on regarde la direction Y.


void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texinfo.index = WEST;
		else
			data->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texinfo.index = SOUTH;
		else
			data->texinfo.index = NORTH;
	}
}

// Cette fonction calcule les couleurs des pixels texturés à afficher pour une colonne
// spécifique (axe X de l'écran).
// - On commence par obtenir l'index de la texture grâce à `get_texture_index`.
// - `tex->x` détermine quelle partie de la texture (en largeur) correspond au mur touché.
//   Si le mur est orienté vers l'intérieur, on inverse la coordonnée pour refléter la texture.
// - On calcule ensuite `tex->step`, qui correspond à l'incrément de texture par pixel,
//   et `tex->pos`, qui est la position actuelle dans la texture (axe Y
// - Pour chaque pixel de la colonne (entre `ray->draw_start` et `ray->draw_end`), 
//   on récupère la couleur dans la texture et l'ajoute à `data->texture_pixels`
// - Les textures sombres (NORD/EST) sont assombrie car c est sympa 

void	update_texture(t_data *data, t_texinfo *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}
