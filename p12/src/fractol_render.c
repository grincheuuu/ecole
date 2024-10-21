/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:00 by gschwart          #+#    #+#             */
/*   Updated: 2023/12/18 19:22:28 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_minilibx_pixel_put(int x, int y, t_img *img, int color)
{
	int	indexpixel;

	indexpixel = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + indexpixel) = color;
}

void	ft_render(t_fractal *fractal, t_dest *dest)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < dest->murHaut[x])
				my_minilibx_pixel_put(x, y, &fractal->img, RED);
			else if (y < dest->murBas[x])
				my_minilibx_pixel_put(x, y, &fractal->img, BLACK);
			else
				my_minilibx_pixel_put(x, y, &fractal->img, YELLOW);
		}
	}
	mlx_put_image_to_window(fractal->mlx_co,
		fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}

void	ft_render_deux(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			my_minilibx_pixel_put(x, y, &fractal->img, YELLOW);
		}
	}
	mlx_put_image_to_window(fractal->mlx_co,
		fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}