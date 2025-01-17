/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 15:47:44 by tguerran         ###   ########.fr       */
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

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

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
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*floor_color;
	int		*ceiling_color;
	int		row_length;
	int		column_length;
	int		**map;
	int		player_x;
	int		player_y;
	char	player_orientation;
	int		failed;
	int		number_of_path;
	int		number_of_rgb;
	int		condition;
	int		condition2;
	int		fd;
	int		co;
}	t_cubfile;

////--------------- INIT -----------------////

	// init_data.c //
void		init_data(t_data *data);
void		init_img_clean(t_img *img);
void		init_ray(t_ray *ray);

	// init_mlx.c //
void		init_mlx(t_data *data);
void		init_img(t_data *data, t_img *image, int width, int height);
void		init_texture_img(t_data *data, t_img *image, char *path);

	// init_texture.c //
void		init_textures(t_data *data);
void		init_texinfo(t_texinfo *textures);
void		last_spaces(char **newline, int co);

////--------------- PARSING -----------------////

	// parsing_init_free.c //
t_cubfile	*init_cubfile(void);
int			free_path_fail(t_cubfile *cubfile, char **line,
				int fd, char ***map_char);
void		free_cub_file(t_cubfile *cubfile);
void		free_files_rgb(char ***map_char, t_cubfile *cubfile,
				char **line, int fd);
void		free_files_rgb2(t_cubfile *cubfile, char **line, int fd);

	// parsing_map.c //
char		**init_map_char(void);
int			validate_map(t_cubfile *cubfile);
int			validate_map(t_cubfile *cubfile);
void		update_map_char(char **line, t_cubfile *cubfile,
				char ***map_char, int *start_map);
int			map_parsing(char ***map_char, t_cubfile *cubfile,
				char *line, int *start_map);

	// parsing_map_2.c //
int			bad_pixel(t_cubfile *cubfile, int co, int co2);
int			bad_pixel2(t_cubfile *cubfile, int co, int co2);
void		put_in_map_int_line(t_cubfile *cubfile,
				char **map_char, int co, int *co2);
void		finalize_put_in_map_int_line(t_cubfile *cubfile, char **map_char);
int			char_to_int_map(t_cubfile *cubfile, char **map_char);

	// parsing_player.c //
int			multiplayer_exeption(int *number_of_players,
				t_cubfile *cubfile, int co, int co2);
int			count_player(t_cubfile *cubfile,
				char **map_char, int *number_of_players);
int			finalise_player(t_cubfile *cubfile,
				char **map_char, int *number_of_players);

	// parsing_handle.c //
int			handle_no_path(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);
int			handle_so_path(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);
int			handle_we_path(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);
int			handle_ea_path(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);
int			handle_floor_rgb(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);

	// parsing_handle_2.c //
int			handle_paths(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);
int			handle_line_map(char *line, t_cubfile *cubfile,
				char ***map_char, int *start_map);
int			handle_line_rgb(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);
int			handle_line_processing(char *line, t_cubfile *cubfile,
				char ***map_char, int *start_map);
int			handle_ceiling_rgb(char *line, t_cubfile *cubfile,
				char ***map_char, int fd);

	// parsing_return_path.c //
int			print_return_so_path_error(char **line, t_cubfile *cubfile,
				char *path);
int			print_return_we_path_error(char **line, t_cubfile *cubfile,
				char *path);
int			print_return_ea_path_error(char **line, t_cubfile *cubfile,
				char *path);
int			print_return_no_path_error(char **line, t_cubfile *cubfile,
				char *path);

	// parsing_free.c //
void		free_map_char(char ***map_char);
int			free_if_2(char ***map_char, t_cubfile *cubfile);
void		free_cub_file2(t_cubfile *cubfile);
void		free_readline(char **line, int fd, t_cubfile *cubfile);
void		free_map_char_lines(t_cubfile *cubfile, int fd, char ***map_char);

	// parsing_free_2.c //
int			cubfile_failed(t_cubfile *cubfile, char ***map_char);
void		clean_map_char_null(t_cubfile *cubfile, int fd, char **line,
				char ***map_char);
void		finalize_exit_codes(int *exit_code, char ***map_char,
				t_cubfile *cubfile);

	// parsing_utils_1.c //
int			is_str_digit(char *str);
void		*free_strjoin2(char **s1, t_cubfile *cubfile);
void		*free_strjoin1(t_cubfile *cubfile);
char		*ft_strjoin2(char *s1, char *s2, t_cubfile *cubfile);
char		*ft_strchr2(char *s, char c);

	// parsing_utils_2.c //
void		*free_new_line1(char **read_lines);
void		*free_new_line2(char **read_lines, t_cubfile *cubfile);
char		*ft_new_lines(char *read_lines, t_cubfile *cubfile);
void		*free_lines(t_cubfile *cubfile);
char		*ft_lines(char *read_lines, t_cubfile *cubfile);

	// parsing_utils_3.c //
void		*free_read_lines1(t_cubfile *cubfile);
void		*free_read_lines2(char **buffer);
char		*ft_read_lines(int fd, char *read_lines, t_cubfile *cubfile);
char		*get_next_line(int fd, t_cubfile *cubfile);
int			nblist(const char *str, char c);

	// parsing_utils_4.c //
void		free_split2(char **split);
char		**ft_realloc(char **old_envp, size_t new_size);

	// put_test_rgb.c //
int			put_rgb_floor(t_cubfile *cubfile, char *charnum);
int			put_rgb_ceiling(t_cubfile *cubfile, char *charnum);
int			number_exeptions(char **numbers, int co);
int			test_rgb(char *charnum);

	// fail_map.c //
void		fail_char_to_int_map2(t_cubfile *cubfile, char ***map_char);
void		fail_char_to_int_map(char ***map_char, t_cubfile *cubfile);

	// process_file.c //
int			print_exit_code(char *str);
void		exit_code_status(int number_of_path,
				int number_of_rgb, int *exit_code);
int			end_file(char ***map_char, t_cubfile *cubfile);
int			process_file(int fd, t_cubfile *cubfile, char ***map_char);

	// updates_char.c //
void		finalize(char ***envp, char **new_envp, char *new_var, int i);
void		print_messages(void);
int			updates_char(char ***envp, const char *line);

	// lines_analysis.c //
int			test_existence(char *filename);
int			how_many_lines(t_cubfile *cubfile, char **map_char);
int			print_and_return(char *str);
int			does_line_have(char *line);

	// pars_rand.c //
void		update_cub(t_cubfile *cubfile);
int			verif(char *map, t_cubfile *cubfile);
int			file_exists(const char *filename);
int			is_valid_cub_file(const char *filename);
int			error_usage(int argc, char **argv);

	// main2.c //
void		allocate_map_line(t_data *data, int line_index, int width);
void		copy_map_line(char *dest, int *src, int width);
void		transfer_map(t_data *data, t_cubfile *cubfile);
void		transfer_player_and_texinfo(t_data *data, t_cubfile *cubfile);
void		transfer_cubfile_to_data(t_data *data, t_cubfile *cubfile);

void		update_cub(t_cubfile *cubfile);
int			free_updates_char(char **new_var);

	// spaces.c //
int			size_monospace(char *line);
int			cf_exeption(int i, char **newline, int co, char **line);
void		newline_co(char **newline, int *co);
int			nesw_exeption(int i, char **newline, int co, char **line);
char		*get_rid_of_spaces(char **line);

	// spaces2.c //
int			wrong_spaces(char *line);
void		all_line_null(char **line);
void		newline_co(char **newline, int *co);
int			size2_path(int i, char **line);

////--------------- RAYCASTING -----------------////
	// render.c //
void		set_frame_pixel(t_data *data, t_img *image, int x, int y);
void		draw_frame(t_data *data);
void		render_raycast(t_data *data);
int			render(t_data *data);
void		render_images(t_data *data);

	// raycasting.c //
void		init_raycasting_info(int x, t_ray *ray, t_player *player);
void		begin_rays(t_ray *ray, t_player *player);
void		useful_rays(t_data *data, t_ray *ray);
void		end_rays(t_ray *ray, t_data *data, t_player *player);
int			raycasting(t_player *player, t_data *data);

	// texture.c //
void		init_texture_pixels(t_data *data);
void		get_texture_index(t_data *data, t_ray *ray);
void		update_texture(t_data *data, t_texinfo *tex, t_ray *ray, int x);

	// image_utils.c //
void		set_image_pixel(t_img *image, int x, int y, int color);

////--------------- PLAYER -----------------////

	// input_handler.c //
void		ft_event(t_data *data);
int			ft_key_release(int key, t_data *data);
int			ft_key_press(int key, t_data *data);

	// player_dir.c //
void		init_player_north_south(t_player *player);
void		init_player_east_west(t_player *player);
void		init_player_direction(t_data *data);

	// player_move.c //
int			calculate_and_validate_move(t_data *data, double dir_x,
				double dir_y);
int			move_forward(t_data *data);
int			move_backward(t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);
int			move_player(t_data *data);

	// player_rotate.c //
int			rotate_player(t_data *data, double rotdir);
void		rotate_plane(t_player *player, double rotspeed);
int			validate_move(t_data *data, double new_x, double new_y);

	//player_pos.c//
bool		is_valid_position(t_data *data, double x, double y);
bool		is_not_wall(t_data *data, double x, double y);
bool		is_within_map_bounds(t_data *data, double x, double y);
int			validate_move(t_data *data, double new_x, double new_y);

////--------------- EXIT -----------------////

	// exit.c //
void		clean_exit(t_data *data, int code);
int			ft_quit(t_data *data);

	// ft_free.c //
void		free_tab(void **tab);
int			free_data(t_data *data);

#endif
