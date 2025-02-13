/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:16:35 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:16:37 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

# define WIDTH   320
# define HEIGHT  200

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

typedef struct s_map
{
	double	x;
	double	y;
	char	o;
}	t_map;

typedef struct	s_dest
{
	int		xp[WIDTH];
	char	O;
	double		Lcumulelateral[WIDTH];
	double		hcumuleHorizontale[WIDTH];
	double		hcumule[WIDTH];
	double		Dx[WIDTH];
	double		Dy[WIDTH];
//	int		h_mur[WIDTH];
	double	Px;
	double	Py;
	int		murHaut[WIDTH];
	int		murBas[WIDTH];
	double 	Lc[WIDTH];
	double 	e[WIDTH]; // angle
	double	ra;
	int		Ori;
	char	signe[WIDTH];
	int		longueur;
	char	*largeur;
}	t_dest;

typedef struct s_fractal
{
	void	*mlx_co;
	void	*mlx_win;
	int		signe;
	int		indice;
	double	shift_x;
	int		Ori;
	int		ra;
	t_img	img;
	t_map	map;
	double	pixel_r;
	double	pixel_i;
	double	dx;
	double	dy;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	t_img north_texture;
    t_img south_texture;
    t_img east_texture;
    t_img west_texture;
}	t_fractal;


int			ft_mouse_action(int button, int x, int y, t_fractal *fractal);
int			ft_key_action(int keysym, t_fractal *fractal);
int			ft_close_all(t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
int			ft_strncmp(char *s1, char *s2, int n);
int			main(int argc, char **argv);
void		ft_render(t_fractal *fractal, t_dest *dest);
void		ft_render_deux(t_fractal *fractal);
void		ft_init(t_fractal *fractal);
void		ft_putstr_fd(char *s, int fd);
void		ft_which_fractal(t_fractal *fractal, int x, int y);
void		ft_zoom(t_fractal *fractal, double nb);
void		my_minilibx_pixel_put(int x, int y, t_img *img, int color);
void		ft_analyse_argjulia(char **argv);
void		ft_atof_test(const char *nptr);
void		ft_error_julia(void);
double		ft_atof(char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*get_next_line(int fd);
int			ft_strlen(const char *s1);

void		ft_search_player(char **tab, t_dest *dest, t_fractal *fractal);
t_dest		*ft_ray_casting(char **tab, t_dest *dest);
t_dest		*ft_distance(t_dest *dest, int i, int x, int y);
t_dest		*ft_horizontale(t_dest *dest, double x, double y, int i, char **tab);
t_dest		*ft_verticale(t_dest *dest, double x, double y, int i, char **tab);
void		ft_pose_carte(t_fractal *fractal);
char		**ft_gnl(t_dest **dest);
void        ft_fre(char **tab);
t_dest  	*ft_perpendiculaire(t_dest *dest, double x, double y, int i, char **tab);
void		ft_signe(t_dest **dest, t_fractal **fractal);
void 		init_textures(t_fractal *fractal);
void 		init_img(t_fractal *fractal);
char 		get_wall_direction(t_dest *dest, int x);
int			get_texture_color(t_img *texture, int x, int y);
double 		calculate_offset_in_wall(t_dest *dest, int x);
void		ft_NewImage(t_fractal *fractal);


#endif