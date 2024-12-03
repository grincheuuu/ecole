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

void	my_minilibx_pixel_put(int x, int y, t_img *img, int color)
{
	int	indexpixel;

	indexpixel = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + indexpixel) = color;
}

double calculate_offset_in_wall(t_dest *dest, int x)
{
    double offset;

    if (fabs(dest->Dx[x] - dest->Px) > fabs(dest->Dy[x] - dest->Py))
    {
        offset = fmod(fabs(dest->Dy[x]), 64) / 64.0;
    }
    else
    {
        offset = fmod(fabs(dest->Dx[x]), 64) / 64.0;
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

char get_wall_direction(t_dest *dest, int x)
{
    double diff_x = fabs(dest->Dx[x] - dest->Px);
    double diff_y = fabs(dest->Dy[x] - dest->Py);

    if (diff_x > diff_y)
    {
        if (dest->Dx[x] > dest->Px)
        {
            if (dest->e[x] > M_PI){
                return 'E';
            }
            else
                return 'E';
        }
        else
        {
            if (dest->e[x] > M_PI){
                return 'W';
            }
            else{
                return 'W';
            }
        }
    }
    else
    {
        if (dest->Dy[x] > dest->Py)
            return 'S';
        else
            return 'N'; 
    }
}

void ft_render(t_fractal *fractal, t_dest *dest)
{
    int x, y;
    int texture_x, texture_y;
    int color;
    t_img *current_texture;

    x = 0;
    while (x < WIDTH)
    {
        double wall_offset = calculate_offset_in_wall(dest, x);
        texture_x = (int)(calculate_offset_in_wall(dest, x) * 64) % 64;
        char direction = get_wall_direction(dest, x);
        if (direction == 'N')
            current_texture = &fractal->north_texture; 
        else if (direction == 'S'){
            current_texture = &fractal->south_texture;
        }
        else if (direction == 'E')
        {
            current_texture = &fractal->east_texture;
        }
        else 
            current_texture = &fractal->west_texture;

        y = 0;
        while (y < HEIGHT)
        {
            if (y < (int)dest->murHaut[x])
            {
                my_minilibx_pixel_put(x, y, &fractal->img, RED);
            }
            else if (y < (int)dest->murBas[x])
            {
                texture_y = (int)(((y - dest->murHaut[x]) * 64) / (dest->murBas[x] - dest->murHaut[x])) % 64;
                color = get_texture_color(current_texture, texture_x, texture_y);
                my_minilibx_pixel_put(x, y, &fractal->img, color);
            }
            else
            {
                my_minilibx_pixel_put(x, y, &fractal->img, YELLOW);
            }
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx_co, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}

void ft_render_deux(t_fractal *fractal)
{
    int x, y;
    int texture_x, texture_y;
    int color;
    t_img *current_texture;
    char    direction;

    x = 0;
    while (x < WIDTH)
    {
        if (direction == 'N')
            current_texture = &fractal->north_texture; 
        else if (direction == 'S'){
            current_texture = &fractal->south_texture;
        }
        else if (direction == 'E')
        {
            current_texture = &fractal->east_texture;
        }
        else 
            current_texture = &fractal->west_texture;

        y = 0;
        while (y < HEIGHT)
        {
            my_minilibx_pixel_put(x, y, &fractal->img, YELLOW);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx_co, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}

void    ft_fre(char **tab)
{
    int i;

    i = 0;
    while(tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}