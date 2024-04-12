/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:34 by gschwart          #+#    #+#             */
/*   Updated: 2023/12/18 15:50:05 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE " enter : fractol mandelbrot ou fractol julia <x> <y>"

# define WIDTH   800
# define HEIGHT  800

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_co;
	void	*mlx_win;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	pixel_r;
	double	pixel_i;
	double	dx;
	double	dy;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_fractal;

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
int			ft_strncmp(char *s1, char *s2, int n);
void		fractal_render(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		ft_putstr_fd(char *s, int fd);
void		ft_julia(t_fractal *fractal, int x, int y);
void		ft_mandelbrot(t_fractal *fractal, int x, int y);
void		ft_fractal_calculate(t_fractal *fractal, int x, int y);
void		ft_zoom(t_fractal *fractal, double nb);
void		ft_burnigship(t_fractal *fractal, int x, int y);
double		map(double unscaled_num, double new_min,
				double new_max, double old_min);
double		ft_atof(char *s);

#endif
