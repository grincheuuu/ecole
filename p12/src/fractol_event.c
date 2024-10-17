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

int	ft_close_all(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_co, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_co);
	free(fractal->mlx_co);
	exit (EXIT_SUCCESS);
}

int	ft_key_action(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_all(fractal);
	ft_render(fractal);
	return (0);
}
/*
int	ft_mouse_action(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		if (fractal->dx > -0.000000000001 && fractal->dy > -0.000000000001)
		{
			fractal->zoom = 0.95;
			ft_zoom (fractal, 0.95);
		}
	}
	else if (button == Button4)
	{
		if (fractal->dx < 100000000000 && fractal->dy < 100000000000)
		{
			fractal->zoom = 1.05;
			ft_zoom (fractal, 1.05);
		}
	}
	ft_render(fractal);
	return (0);
}

void	ft_zoom(t_fractal *fractal, double nb)
{
	fractal->dx /= nb;
	fractal->dy /= nb;
	fractal->min_r += ((fractal->max_r - fractal->min_r) / 2)
		- (fractal->dx * WIDTH / 2);
	fractal->max_r = fractal->min_r + (WIDTH * fractal->dx);
	fractal->min_i += ((fractal->max_i - fractal->min_i) / 2)
		- (fractal->dy * HEIGHT / 2);
	fractal->max_i = fractal->min_i + (HEIGHT * fractal->dy);
}*/
