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

# define WIDTH   800
# define HEIGHT  800

# define BLACK       0x00000
# define WHITE       0xFFFFFF
# define RED   0xFF0000

# define GREEN_LIGHT	0x00CC00
# define BLUE_CIEL       0x66FFFF
# define YELLOW		0xFFFF00

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
	void	*mlx_co;
	void	*mlx_win;
	t_img	img;
	char	*type;
	int		iterations;
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

int			ft_mouse_action(int button, int x, int y, t_fractal *fractal);
int			ft_key_action(int keysym, t_fractal *fractal);
int			ft_close_all(t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
int			ft_strncmp(char *s1, char *s2, int n);
int			main(int argc, char **argv);
void		ft_render(t_fractal *fractal);
void		ft_init(t_fractal *fractal);
void		ft_putstr_fd(char *s, int fd);
void		ft_julia(t_fractal *fractal, int x, int y);
void		ft_mandelbrot(t_fractal *fractal, int x, int y);
void		ft_which_fractal(t_fractal *fractal, int x, int y);
void		ft_zoom(t_fractal *fractal, double nb);
void		my_minilibx_pixel_put(int x, int y, t_img *img, int color);
void		ft_analyse_argjulia(char **argv);
void		ft_atof_test(const char *nptr);
void		ft_error_julia(void);
double		ft_atof(char *s);

#endif
