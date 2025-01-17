/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 17:15:27 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_direction(t_player *player, double rotspeed)
{
	double	tmp_dir_x;

	tmp_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotspeed)
		- player->dir_y * sin(rotspeed);
	player->dir_y = tmp_dir_x * sin(rotspeed) + player->dir_y * cos(rotspeed);
}

void	rotate_plane(t_player *player, double rotspeed)
{
	double	tmp_plane_x;

	tmp_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotspeed)
		- player->plane_y * sin(rotspeed);
	player->plane_y = tmp_plane_x * sin(rotspeed)
		+ player->plane_y * cos(rotspeed);
}

int	rotate_player(t_data *data, double rotdir)
{
	double	rotspeed;

	if (rotdir == 0)
		return (0);
	rotspeed = ROTSPEED * rotdir;
	rotate_direction(&data->player, rotspeed);
	rotate_plane(&data->player, rotspeed);
	return (1);
}
