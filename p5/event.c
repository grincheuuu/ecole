/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:11:50 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/08 18:11:51 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_co, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_co);
	free(fractal->mlx_co);
	exit (EXIT_SUCCESS);
}
/*
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = ((map(x, -2, +2, 0) / (WIDTH - 0) - 2)
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = ((map(y, +2, -2, 0) / (HEIGHT - 0) + 2)
				* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}*/

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		ft_zoom (fractal, 0.95);
	}
	else if (button == Button4)
	{
		ft_zoom (fractal, 2.00);
	}
	fractal_render(fractal);
	return (0);
}

void	ft_zoom(t_fractal *fractal, double nb)
{
	double	center_r;
	double	center_i;
	double half_new_height_i;
	double half_new_width_r;

	center_r = 0;
	center_i = 0;
/*	center_r = fractal->min_r - fractal->max_r;
	center_i = fractal->max_i - fractal->min_i;
	fractal->max_r = fractal->max_r + (center_r - nb * center_r) / 2;
	fractal->min_r = fractal->max_r + nb * center_r;
	fractal->min_i = fractal->min_i + (center_i - nb * center_i) / 2;
	fractal->max_i = fractal->min_i + nb * center_i;*/
/*	center_r = (fractal->max_r + fractal->min_r) / 2.0;
    center_i = (fractal->max_i + fractal->min_i) / 2.0;
    half_new_width_r = ((fractal->max_r - fractal->min_r) * nb) / 2.0;
    half_new_height_i = ((fractal->max_i - fractal->min_i) * nb) / 2.0;
    fractal->min_r = center_r - half_new_width_r;
    fractal->max_r = center_r + half_new_width_r;
    fractal->min_i = center_i - half_new_height_i;
    fractal->max_i = center_i + half_new_height_i;*/
	
}