/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 06:13:05 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 680
# define WIN_HEIGHT 420

# define MOVESPEED 0.0125
# define ROTSPEED 0.015

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hexfloor;
	unsigned long	hexceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			height;
	int			width;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
}	t_data;

typedef struct s_cubfile
{
	char	*no_path;	//juste une char contenant le path
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*floor_color;	//exemple de ce que sa peux contenire:  220,100,0
	int		*ceiling_color;
	int		row_length;		//la c est la longueur d une rangee de la map
	int		column_length;	//la c est la longueur d une colone de la map
	int		**map;
	int		player_x;
	int		player_y;
	char	player_orientation;	//juste un caractere Majuscule N, S, E ou W
	int		failed; //0 si aucun malloc a failed, 0 si un malloc a fail
}	t_cubfile;



////--------------- INIT -----------------////

	// init_data.c //
void	init_data(t_data *data);
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);

	// init_mlx.c //
void	init_mlx(t_data *data);
void	init_img(t_data *data, t_img *image, int width, int height);
void	init_texture_img(t_data *data, t_img *image, char *path);

	// init_texture.c //
void	init_textures(t_data *data);
void	init_texinfo(t_texinfo *textures);


////--------------- RAYCASTING -----------------////
	// render.c //
void	set_frame_pixel(t_data *data, t_img *image, int x, int y);
void	draw_frame(t_data *data);
void	render_raycast(t_data *data);
int		render(t_data *data);
void	render_images(t_data *data);

	// raycasting.c //
void	init_raycasting_info(int x, t_ray *ray, t_player *player);
void	begin_rays(t_ray *ray, t_player *player);
void	useful_rays(t_data *data, t_ray *ray);
void	end_rays(t_ray *ray, t_data *data, t_player *player);
int		raycasting(t_player *player, t_data *data);

	// texture.c //
void	init_texture_pixels(t_data *data);
void	get_texture_index(t_data *data, t_ray *ray);
void	update_texture(t_data *data, t_texinfo *tex, t_ray *ray, int x);

	// image_utils.c //
void	set_image_pixel(t_img *image, int x, int y, int color);

////--------------- PLAYER -----------------////

	// input_handler.c //
void	ft_event(t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_key_press(int key, t_data *data);

	// player_dir.c //
void	init_player_north_south(t_player *player);
void	init_player_east_west(t_player *player);
void	init_player_direction(t_data *data);

	// player_move.c //
void	calculate_new_position(t_player *player, double dir_x, double dir_y, double *new_x, double *new_y);
int		move_forward(t_data *data);
int		move_backward(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
int		move_player(t_data *data);

	// player_rotate.c //
int		rotate_player(t_data *data, double rotdir);
void	rotate_plane(t_player *player, double rotspeed);
int		validate_move(t_data *data, double new_x, double new_y);

	//player_pos.c//
bool	is_valid_position(t_data *data, double x, double y);
bool	is_not_wall(t_data *data, double x, double y);
bool	is_within_map_bounds(t_data *data, double x, double y);
int		validate_move(t_data *data, double new_x, double new_y);

////--------------- EXIT -----------------////

	// exit.c //
void	clean_exit(t_data *data, int code);
int		ft_quit(t_data *data);

	// ft_free.c //
void	free_tab(void **tab);
int		free_data(t_data *data);

#endif
