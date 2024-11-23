/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:27:19 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:27:21 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void my_minilibx_pixel_put(int x, int y, t_img *img, int color)
{
    int indexpixel;

    indexpixel = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixel_ptr + indexpixel) = color;
}

double calculate_offset_in_wall(t_ray *ray, int x)
{
    double offset;

    if (fabs(ray->Dx[x] - ray->Px) > fabs(ray->Dy[x] - ray->Py))
    {
        offset = fmod(fabs(ray->Dy[x]), 64) / 64.0;
    }
    else
    {
        offset = fmod(fabs(ray->Dx[x]), 64) / 64.0;
    }

    return offset;
}

int get_texture_color(t_img *texture, int x, int y)
{
    int indexpixel;
    int color;

    if (x >= 64) x = x % 64;
    if (y >= 64) y = y % 64;
    indexpixel = (y * texture->line_len) + (x * (texture->bpp / 8));
    color = *(unsigned int *)(texture->pixel_ptr + indexpixel);
    return color;
}

char get_wall_direction(t_ray *ray, int x)
{
    double diff_x = fabs(ray->Dx[x] - ray->Px);
    double diff_y = fabs(ray->Dy[x] - ray->Py);

    //printf("%f \n", ray->e[x]);
    if (diff_x > diff_y)
    {
        if (ray->Dx[x] > ray->Px)
        {
            if (ray->e[x] > M_PI){
                return 'E';
            }
            else
                return 'E';
        }
        else
        {
            if (ray->e[x] > M_PI){
                return 'W';
            }
            else{
                return 'W';
            }
        }
    }
    else
    {
        if (ray->Dy[x] > ray->Py)
            return 'S';
        else
            return 'N'; 
    }
}


void ft_render(t_data *data, t_ray *ray)
{
    int x, y;
    int texture_x, texture_y;
    int color;
    t_img *current_texture;

    x = 0;
    while (x < WIDTH)
    {
        double wall_offset = calculate_offset_in_wall(ray, x);
        texture_x = (int)(calculate_offset_in_wall(ray, x) * 64) % 64;
        char direction = get_wall_direction(ray, x);
        if (direction == 'N')
            current_texture = &data->north_texture; 
        else if (direction == 'S'){
            current_texture = &data->south_texture;
        }
        else if (direction == 'E')
        {
            current_texture = &data->east_texture;
        }
        else 
            current_texture = &data->west_texture;

        y = 0;
        while (y < HEIGHT)
        {
            if (y < (int)ray->murHaut[x])
            {
                my_minilibx_pixel_put(x, y, &data->img, RED);
            }
            else if (y < (int)ray->murBas[x])
            {
                texture_y = (int)(((y - ray->murHaut[x]) * 64) / (ray->murBas[x] - ray->murHaut[x])) % 64;
                color = get_texture_color(current_texture, texture_x, texture_y);
                my_minilibx_pixel_put(x, y, &data->img, color);
            }
            else
            {
                my_minilibx_pixel_put(x, y, &data->img, YELLOW);
            }
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx_co, data->mlx_win, data->img.img_ptr, 0, 0);
}

void ft_fre(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
