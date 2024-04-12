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

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			fractal->pixel_r = fractal->min_r + (double)x * fractal->dx + fractal->shift_x / fractal->zoom;
			fractal->pixel_i = fractal->min_i + (double)y * fractal->dy + fractal->shift_y / fractal->zoom;
			ft_fractal_calculate(fractal, x, y);
		}
	}
	mlx_put_image_to_window(fractal->mlx_co,
		fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}

void	ft_fractal_calculate(t_fractal *fractal, int x, int y)
{
	if (ft_strncmp(fractal->name , "mandelbrot", 10) == 0)
	{
		ft_mandelbrot(fractal, x, y);
	}
	else if (ft_strncmp(fractal->name , "julia", 5) == 0)
	{
		ft_julia(fractal, x, y);
	}
	else if (ft_strncmp(fractal->name, "burnigship", 10) == 0)
	{
		ft_burnigship(fractal, x, y);
	}
}

void	ft_mandelbrot(t_fractal *fractal, int x, int y)
{
	int	n;
	double	zr;
	double	zi;
	double	temp;
	int	color;

	zr = 0;
	zi = 0;
	n = 0;
	color = 0;
	while (n < fractal->iterations)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			color = ((RED - BLACK) * n) / (fractal->iterations - BLACK) + RED;
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		temp = 2 * zr * zi + fractal->pixel_i;
		zr = zr * zr - zi * zi + fractal->pixel_r;
		zi = temp;
		n++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	ft_julia(t_fractal *fractal, int x, int y)
{
	int	n;
	int	color;
	double	zr;
	double	zi;
	double	temp;

	zr = fractal->pixel_r;
	zi = fractal->pixel_i;
	n = 0;
	while (n < fractal->iterations)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			color = ((RED - BLACK) * n) / (fractal->iterations - BLACK) + RED;
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		temp = 2 * zr * zi + fractal->julia_y;
		zr = zr * zr - zi * zi + fractal->julia_x;
		zi = temp;
		n++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	ft_burnigship(t_fractal *fractal, int x, int y)
{
	int	n;
	double	zr;
	double	zi;
	double	temp;
	int	color;

	zr = 0;
	zi = 0;
	n = 0;
	color = 0;
	while (n < fractal->iterations)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			color = ((WHITE - BLACK) * n) / (fractal->iterations - BLACK) + WHITE;
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		if (zi < 0)
			zi = zi * -1;
		temp = 2 * zr * zi + fractal->pixel_i;
		zr = zr * zr - zi * zi + fractal->pixel_r;
		zi = temp;
		n++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}
