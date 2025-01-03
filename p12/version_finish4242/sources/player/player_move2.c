/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:59:35 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 22:45:02 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_left(t_data *data)
{
	return (calculate_and_validate_move(data,
			data->player.dir_y, -data->player.dir_x));
}

int	move_right(t_data *data)
{
	return (calculate_and_validate_move(data,
			-data->player.dir_y, data->player.dir_x));
}
