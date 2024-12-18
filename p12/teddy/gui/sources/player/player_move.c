/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 05:46:41 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	calculate_new_position(t_player *player, double dir_x, double dir_y, double *new_x, double *new_y)
{
	*new_x = player->pos_x + dir_x * MOVESPEED;
	*new_y = player->pos_y + dir_y * MOVESPEED;
}

// Calcule les nouvelles positions pour les déplacements avant, arrière, gauche ou droite.
// Chaque fonction utilise `calculate_new_position` pour simplifier le calcul des coordonnées.

int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	calculate_new_position(&data->player, data->player.dir_x, data->player.dir_y, &new_x, &new_y);
	return (validate_move(data, new_x, new_y));
}

int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	calculate_new_position(&data->player, -data->player.dir_x, -data->player.dir_y, &new_x, &new_y);
	return (validate_move(data, new_x, new_y));
}

int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	calculate_new_position(&data->player, data->player.dir_y, -data->player.dir_x, &new_x, &new_y);
	return (validate_move(data, new_x, new_y));
}

int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	calculate_new_position(&data->player, -data->player.dir_y, data->player.dir_x, &new_x, &new_y);
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_forward(data);
	else if (data->player.move_y == -1)
		moved += move_backward(data);
	if (data->player.move_x == -1)
		moved += move_left(data);
	else if (data->player.move_x == 1)
		moved += move_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}
