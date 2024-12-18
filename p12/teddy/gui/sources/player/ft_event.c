/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 06:07:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Gestion des touches enfoncées
int	ft_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_quit(data);
	else if (key == XK_Left)
		data->player.rotate -= 1; //sens de la rotation
	else if (key == XK_Right)
		data->player.rotate += 1;
	else if (key == XK_w)
		data->player.move_y = 1;
	else if (key == XK_a)
		data->player.move_x = -1;
	else if (key == XK_s)
		data->player.move_y = -1;
	else if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

// Gestion des touches relâchées
int	ft_key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_quit(data);
	else if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	else if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	else if (key == XK_a && data->player.move_x == -1)
		data->player.move_x = 0;
	else if (key == XK_d && data->player.move_x == 1)
		data->player.move_x = 0;
	else if (key == XK_Left)
		data->player.rotate = 0;
	else if (key == XK_Right)
		data->player.rotate = 0;
	return (0);
}

void	ft_event(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, ft_quit, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, ft_key_release, data);
}
