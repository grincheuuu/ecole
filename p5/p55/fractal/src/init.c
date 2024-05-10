/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:47 by gschwart          #+#    #+#             */
/*   Updated: 2023/12/18 15:41:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("problems with malloc");
	exit (EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration_def = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress,
		KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_co = mlx_init();
	if (fractal->mlx_co == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_co,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_co, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
