/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:46:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/18 23:14:31 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_close_all(t_data *data)
{
    mlx_destroy_image(data->mlx_co, data->img.img_ptr);
    mlx_destroy_window(data->mlx_co, data->mlx_win);
    mlx_destroy_display(data->mlx_co);
    free(data->mlx_co);
    exit(EXIT_SUCCESS);
}

void ft_NewImage(t_data *data)
{
    ft_pose_carte(data);
}

void move_forward(t_data *data)
{
    data->player.pos_x += cos(data->player.angle_direction) * 3;
    data->player.pos_y += sin(data->player.angle_direction) * 3;
    printf("Avancer: x = %f, y = %f\n", data->player.pos_x, data->player.pos_y);
}

void move_backward(t_data *data)
{
    data->player.pos_x -= cos(data->player.angle_direction) * 3;
    data->player.pos_y -= sin(data->player.angle_direction) * 3;
    printf("Reculer: x = %f, y = %f\n", data->player.pos_x, data->player.pos_y);
}

void move_left(t_data *data)
{
    data->player.pos_x += cos(data->player.angle_direction + M_PI / 2) * 3;
    data->player.pos_y += sin(data->player.angle_direction + M_PI / 2) * 3;
    printf("Déplacer à gauche: x = %f, y = %f\n", data->player.pos_x, data->player.pos_y);
}

void move_right(t_data *data)
{
    data->player.pos_x += cos(data->player.angle_direction - M_PI / 2) * 3;
    data->player.pos_y += sin(data->player.angle_direction - M_PI / 2) * 3;
    printf("Déplacer à droite: x = %f, y = %f\n", data->player.pos_x, data->player.pos_y);
}

void rotate_player(t_data *data, double angle)
{
    data->player.angle_direction += angle;
    // Normaliser l'angle de direction entre 0 et 2 * PI en utilisant fmod
    data->player.angle_direction = fmod(data->player.angle_direction, 2 * M_PI);
    if (data->player.angle_direction < 0) {
        data->player.angle_direction += 2 * M_PI;
    }
    data->ray.ra = data->player.angle_direction;
    ft_signe(&data->ray, data);

}

int ft_key_action(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        ft_close_all(data);
    else if (keysym == XK_Left) // Rotation gauche
        rotate_player(data, -5 * M_PI / 180); // Angle de rotation à gauche
    else if (keysym == XK_Right) // Rotation droite
        rotate_player(data, 5 * M_PI / 180); // Angle de rotation à droite
    else if (keysym == XK_w) // Avancer
        move_forward(data);
    else if (keysym == XK_s) // Reculer
        move_backward(data);
    else if (keysym == XK_a) // Déplacer à gauche
        move_left(data);
    else if (keysym == XK_d) // Déplacer à droite
        move_right(data);
    ft_NewImage(data);
    return (0);
}

void ft_event(t_data *data)
{
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, ft_key_action, data);
    mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, ft_close_all, data);
}
