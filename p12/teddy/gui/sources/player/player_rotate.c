/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 05:48:48 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_direction(t_player *player, double rotspeed) //rotation du joueur
{
	double	tmp_dir_x;

	tmp_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotspeed) - player->dir_y * sin(rotspeed); //vecteur directionnel
	player->dir_y = tmp_dir_x * sin(rotspeed) + player->dir_y * cos(rotspeed);
	printf("dix_x %f dix_y %f\n", player->dir_x, player->dir_y);
}

void	rotate_plane(t_player *player, double rotspeed) //rotation du plan de la camera
{
	double	tmp_plane_x;

	tmp_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotspeed) - player->plane_y * sin(rotspeed);
	player->plane_y = tmp_plane_x * sin(rotspeed) + player->plane_y * cos(rotspeed);
}

// Combine les rotations de direction et de plan dans une seule fonction.

int	rotate_player(t_data *data, double rotdir)
{
	double	rotspeed;

	if (rotdir == 0) // pas de rotations
		return (0);
	rotspeed = ROTSPEED * rotdir; // rotdir sens de la rotation, positif sens horaire, negatif sens antihoraire

	rotate_direction(&data->player, rotspeed);
	rotate_plane(&data->player, rotspeed);
	return (1);
}
