/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 05:44:52 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

// Initialise la direction et le plan du joueur en fonction de son orientation initiale ('N', 'S', 'E', 'W').

void	init_player_north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0; //direction
		player->dir_y = -1;
		player->plane_x = 0.66; // 33degrre
		player->plane_y = 0;
	}
}

void	init_player_east_west(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

// Configure la direction initiale du joueur en fonction de l'orientation donnée par la map.

void init_player_direction(t_data *data)
{
    printf("Player Direction (Before Init): %c\n", data->player.dir);

    if (data->player.dir == 'N' || data->player.dir == 'S')
        init_player_north_south(&data->player);
    else if (data->player.dir == 'E' || data->player.dir == 'W')
        init_player_east_west(&data->player);
    else
        printf("Error: Invalid player direction '%c'\n", data->player.dir);
}
