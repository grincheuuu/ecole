/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:02:48 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/12 17:04:40 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_minilibx_pixel_put(int x, int y, t_img *img, int color)
{
	int	pixelindex;

	pixelindex = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + pixelindex) = color;
}

double	ft_zi(double temp, double zi)
{
	zi = temp;
	if (zi < 0)
		zi = zi * -1;
	return (zi);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		n--;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

double	ft_atof(char *s)
{
	double	nb;
	double	decimal;
	int		signe;

	nb = 0;
	signe = 1;
	decimal = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			signe *= -1;
	}
	while (*s != '.' && *s != '\0')
		nb = (nb * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s != '\0')
	{
		decimal /= 10;
		nb = nb + (*s++ - 48) * decimal;
	}
	return (nb * signe);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "burnigship", 10) == 0))
	{
		fractal.type = argv[1];
		if (ft_strncmp(argv[1], "julia", 5) == 0)
		{
			ft_analyse_argjulia(argv);
			fractal.julia_x = ft_atof(argv[2]);
			fractal.julia_y = ft_atof(argv[3]);
		}
		ft_init(&fractal);
		ft_render(&fractal);
		mlx_loop(fractal.mlx_co);
	}
	else
	{
		write(2,
			"entre : fractol mandelbrot ou fractol julia <x> <y> ou burnigship",
			66);
		exit (EXIT_FAILURE);
	}
	return (0);
}
