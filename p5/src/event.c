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

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = ((map(x, -2, +2, 0) / (800 - 0) - 2)
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = ((map(y, +2, -2, 0) / (800 - 0) + 2)
				* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= 0.5;
	else if (keysym == XK_Right)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5;
	else if (keysym == XK_Control_R)
		fractal->iterations += 5;
	else if (keysym == XK_Alt_R)
		fractal->iterations -= 5;
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
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		ft_zoom (fractal, 1.05);
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

void	ft_zoom(t_fractal *fractal, double nb)
{
	double center_r = (fractal->max_r + fractal->min_r) / 2;
	double center_i = (fractal->max_i + fractal->min_i) / 2;
	fractal->dx /= nb;
	fractal->dy /= nb;
	fractal->min_r += center_r + ((fractal->max_r - fractal->min_r) / 2) - (fractal->dx * WIDTH / 2);
	fractal->max_r = fractal->min_r + (WIDTH * fractal->dx);
	fractal->min_i += center_i + ((fractal->max_i - fractal->min_i) / 2) - (fractal->dy * HEIGHT / 2);
	fractal->max_i = fractal->min_i + (HEIGHT *fractal->dy);
}
