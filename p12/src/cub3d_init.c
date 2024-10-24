/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:18:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void	ft_malloc_fail(void)
{
	perror("malloc fail");
	exit (EXIT_FAILURE);
}

static void	ft_init_struct(t_fractal *fractal)
{
	fractal->min_r = -4;
	fractal->max_r = 4;
	fractal->min_i = -4;
	fractal->max_i = 4;
	fractal->pixel_r = 0;
	fractal->pixel_i = 0;
	fractal->dx = (fractal->max_r - fractal->min_r) / WIDTH;
	fractal->dy = (fractal->max_i - fractal->min_i) / HEIGHT;
	fractal->map.x = 0;
	fractal->map.y = 0;
	fractal->map.o = 0;
}

static void	ft_event(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress,
		KeyPressMask, ft_key_action, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify,
		StructureNotifyMask, ft_close_all, fractal);
}

void	ft_init(t_fractal *fractal)
{
	fractal->mlx_co = mlx_init();
	if (fractal->mlx_co == NULL)
		ft_malloc_fail();
	fractal->mlx_win = mlx_new_window(fractal->mlx_co,
			WIDTH, HEIGHT, "CUB3D");
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		ft_malloc_fail();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_co, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		ft_malloc_fail();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	ft_init_struct(fractal);
	ft_event(fractal);
}
