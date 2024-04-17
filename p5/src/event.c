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
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
/*	ft_zoom_deux(fractal, 0.5);
	if (button == Button5)
	{
		ft_zoom_deux(fractal, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT /2;
		if (x < 0)
			ft_move(fractal, ((double)x * -1 / WIDTH), 'L');
		if (x > 0)
			ft_move(fractal, ((double)x / WIDTH), 'R');
		if (y < 0)
			ft_move(fractal, ((double)y * -1 /HEIGHT), 'U');
		if (y > 0)
			ft_move(fractal, ((double)y / HEIGHT), 'D');
	}
	else if (button == Button4)
	{
		ft_zoom_deux(fractal, 0.5);
	}*/
	if (button == Button5)
	{
		fractal->zoom = 0.95;
		ft_zoom (fractal, 0.95, x, y);
	}
	else if (button == Button4)
	{
		fractal->zoom = 1.05;
		ft_zoom (fractal, 1.05, x, y);
	}
	fractal_render(fractal);
	return (0);
}

void	ft_zoom(t_fractal *fractal, double nb, int x, int y)
{
	(void)nb;
	(void)x;
	(void)y;
	fractal->dx /= fractal->zoom;
	fractal->dy /= fractal->zoom;
	fractal->min_r += ((fractal->max_r - fractal->min_r) / 2) - (fractal->dx * WIDTH / 2);
	fractal->max_r = fractal->min_r + (WIDTH * fractal->dx);
	fractal->min_i += ((fractal->max_i - fractal->min_i) / 2) - (fractal->dy * HEIGHT / 2);
	fractal->max_i = fractal->min_i + (HEIGHT *fractal->dy);
	fractal->shift_x = (double)x * fractal->dx * fractal->zoom;
	fractal->shift_y = (double)y * fractal->dy * fractal->zoom;
//	ft_center(fractal, nb, x, y);
}

void	ft_center(t_fractal *fractal, double nb, int x, int y)
{
    (void)nb;

    fractal->min_r += x * fractal->dy * 1;
    fractal->max_r += x * fractal->dy * 1;
    fractal->min_i += y * fractal->dy * 1;
    fractal->max_i += y * fractal->dy * 1;
}
/*
void	ft_center(t_fractal *fractal, double nb,  int x, int y)
{
	(void)nb;
	fractal->center_r += fractal->min_r;
	fractal->center_i += fractal->min_i;
	fractal->min_r = fractal->center_r - (double)x * fractal->dx;
	fractal->max_r = fractal->min_r + WIDTH * fractal->dx;
	fractal->min_i = fractal->center_i - (double)y * fractal->dy;
	fractal->max_i = fractal->min_i + HEIGHT * fractal->dy;
}*/

//	printf("%f\n,%f\n,%f\n,%f\n", fractal->min_r, fractal->max_r, fractal->min_i, fractal->max_i);
/*
void	ft_zoom(t_fractal *fractal, double nb,  int x, int y)
{
	double	center_x;
	double	center_y;

	fractal->dx /= nb;
	fractal->dy /= nb;
	center_x = (fractal->max_r - fractal->min_r) / 2;
	center_y = (fractal->max_i - fractal->min_i) / 2;
	fractal->min_r = center_x - x * fractal->dx - (fractal->dx * WIDTH / 2);
	fractal->max_r = fractal->min_i + WIDTH * fractal->dx;
	fractal->min_i = center_y - y * fractal->dy;
	fractal->max_i = fractal->min_i + HEIGHT * fractal->dy - (fractal->dy * HEIGHT / 2);
	printf("%f,%f,%f,%f", fractal->min_r, fractal->max_r, fractal->min_i, fractal->max_i);
}*/

/*
void	ft_zoom_deux(t_fractal *fractal, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = fractal->min_r - fractal->max_r;
	center_i = fractal->max_i - fractal->min_i;
	fractal->max_r = fractal->max_r + (center_r - zoom * center_r) / 2;
	fractal->min_i = fractal->max_r + zoom * center_r;
	fractal->min_i = fractal->min_i + (center_i - zoom * center_i) / 2;
	fractal->max_i = fractal->min_i + zoom * center_i;
}

void	ft_move(t_fractal *fractal, double nb, char c)
{
	double	center_r;
	double	center_i;

	center_r = fractal->max_r - fractal->min_r;
	center_i = fractal->max_i - fractal->min_i;
	if (c == 'L')
	{
			fractal->min_r -= center_r * nb;
			fractal->max_r -= center_r * nb;
	}
	if (c == 'R')
	{
			fractal->min_r += center_r * nb;
			fractal->max_r += center_r * nb;
	}
	if (c == 'D')
	{
			fractal->min_i -= center_i * nb;
			fractal->max_i -= center_i * nb;
	}
	if (c == 'U')
	{
			fractal->min_i += center_i * nb;
			fractal->max_i += center_i * nb;
	}
}*/