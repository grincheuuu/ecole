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

#include "fractol_bonus.h"

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
	else if (keysym == XK_Left)
		fractal->shift_x -= 40 * fractal->dx;
	else if (keysym == XK_Right)
		fractal->shift_x += 40 * fractal->dx;
	else if (keysym == XK_Down)
		fractal->shift_y += 40 * fractal->dy;
	else if (keysym == XK_Up)
		fractal->shift_y -= 40 * fractal->dy;
	else if (keysym == XK_Control_R)
		fractal->iterations += 5;
	else if (keysym == XK_Alt_R)
		fractal->iterations -= 5;
	ft_render(fractal);
	return (0);
}

int	ft_mouse_action(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		if (fractal->dx > -0.000000000001 && fractal->dy > -0.000000000001)
		{
			fractal->zoom = 0.95;
			ft_zoom (fractal, 0.95, x, y);
		}
	}
	else if (button == Button4)
	{
		if (fractal->dx < 100000000000 && fractal->dy < 100000000000)
		{
			fractal->zoom = 1.05;
			ft_zoom (fractal, 1.05, x, y);
		}
	}
	ft_render(fractal);
	return (0);
}

void	ft_zoom(t_fractal *fractal, double nb, int x, int y)
{
	(void)nb;
	fractal->center_r = fractal->min_r + (double)x * fractal->dx;
	fractal->center_i = fractal->min_i + (double)y * fractal->dy;
	fractal->dx /= fractal->zoom;
	fractal->dy /= fractal->zoom;
	fractal->min_r += (fractal->max_r - fractal->min_r) / 2
		- (fractal->dx * WIDTH / 2.0);
	fractal->max_r = fractal->min_r + (WIDTH * fractal->dx);
	fractal->min_i += (fractal->max_i - fractal->min_i) / 2
		- (fractal->dy * HEIGHT / 2.0);
	fractal->max_i = fractal->min_i + (HEIGHT * fractal->dy);
	ft_center(fractal, nb, x, y);
}

void	ft_center(t_fractal *fractal, double nb, int x, int y)
{
	(void)nb;
	fractal->min_r = fractal->center_r - (double)x * fractal->dx;
	fractal->max_r = fractal->min_r + WIDTH * fractal->dx;
	fractal->min_i = fractal->center_i - (double)y * fractal->dy;
	fractal->max_i = fractal->min_i + HEIGHT * fractal->dy;
}
