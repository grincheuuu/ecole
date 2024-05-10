/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:47 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/12 17:05:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_malloc_fail(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

static void	ft_init_struct(t_fractal *fractal)
{
	fractal->iterations = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->min_r = -4;
	fractal->max_r = 4;
	fractal->min_i = -4;
	fractal->max_i = 4;
	fractal->pixel_r = 0;
	fractal->pixel_i = 0;
	fractal->dx = (fractal->max_r - fractal->min_r) / WIDTH;
	fractal->dy = (fractal->max_i - fractal->min_i) / HEIGHT;
	fractal->center_r = (fractal->max_r - fractal->min_r) / 2;
	fractal->center_i = (fractal->max_i - fractal->min_i) / 2;
}

static void	ft_event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress,
		KeyPressMask, ft_key_action, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress,
		ButtonPressMask, ft_mouse_action, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify,
		StructureNotifyMask, ft_close_all, fractal);
	mlx_hook(fractal->mlx_win, MotionNotify,
		PointerMotionMask, ft_julia_few, fractal);
}

void	ft_init(t_fractal *fractal)
{
	fractal->mlx_co = mlx_init();
	if (fractal->mlx_co == NULL)
		ft_malloc_fail("mlx_co_fail");
	fractal->mlx_win = mlx_new_window(fractal->mlx_co,
			WIDTH, HEIGHT, fractal->type);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		ft_malloc_fail("mlx_win_fail");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_co, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		ft_malloc_fail("img_ptr_fail");
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	ft_init_struct(fractal);
	ft_event_init(fractal);
}

int	ft_julia_few(int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (ft_strncmp(fractal->type, "julia", 5) == 0)
	{
		fractal->julia_x = fractal->min_r
			+ (double)x * fractal->dx + fractal->shift_x / fractal->zoom;
		fractal->julia_y = fractal->min_i
			+ (double)y * fractal->dy + fractal->shift_y / fractal->zoom;
		ft_render(fractal);
	}
	return (0);
}
