/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:03:04 by gschwart          #+#    #+#             */
/*   Updated: 2023/12/20 17:39:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "burnigship", 10)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atoidouble(argv[2]);
			fractal.julia_y = atoidouble(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_co);
	}
	else
	{
		putstr_fd(
			"enter : fractol mandelbrot ou fractol julia <x> <y> ou burnigship",
			STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	return (0);
}
