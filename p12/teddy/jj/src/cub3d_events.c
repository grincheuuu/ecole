/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:17:28 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:17:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_all(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_co, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_co);
	free(fractal->mlx_co);
	exit (EXIT_SUCCESS);
}

void	ft_NewImage(t_fractal *fractal)
{
	ft_pose_carte(fractal);
}

int	ft_key_action(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_all(fractal);
	else if (keysym == XK_Left)
	{
		if (fabs(fractal->shift_x) == M_PI)
			fractal->shift_x = 0;
		fractal->shift_x -= 10 * M_PI / 180;
		ft_NewImage(fractal);
	}
	else if (keysym == XK_Right)
	{
		if (fabs(fractal->shift_x) == M_PI)
			fractal->shift_x = 0;
		fractal->shift_x += 10 * M_PI / 180;
		ft_NewImage(fractal);
	}
	ft_render_deux(fractal);
	return (0);
}