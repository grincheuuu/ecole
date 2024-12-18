/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 05:48:13 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

// Vérifie si une position donnée est dans les limites de la carte.

bool	is_within_map_bounds(t_data *data, double x, double y)
{
	return (x >= 0.25 && x < data->mapinfo.width - 1.25
			&& y >= 0.25 && y < data->mapinfo.height - 0.25); //empeche de traverser les murs
}

// Vérifie si une position donnée n'est pas un mur.

bool	is_not_wall(t_data *data, double x, double y)
{
	return (data->map[(int)y][(int)x] == '0');
}

// Combine les vérifications des limites de la carte et des collisions avec les murs
// pour déterminer si une position est valide.


bool	is_valid_position(t_data *data, double x, double y)
{
	if (!is_within_map_bounds(data, x, y))
		return (false);
	if (!is_not_wall(data, x, y))
		return (false);
	return (true);
}

// Applique les nouvelles coordonnées au joueur si elles sont valides.
// Permet de déplacer le joueur en vérifiant chaque axe séparément (x et y),

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_position(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_position(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
