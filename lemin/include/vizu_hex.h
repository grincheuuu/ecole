#ifndef VIZU_HEX_H
# define VIZU_HEX_H
# include "../mlx/mlx.h"
# include "lem-in.h"
# include <sys/time.h>

///////// IMAGE MLX ///////
typedef struct s_img
{
	void				*img_ptr;
	char				*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;

typedef struct s_tex
{
	t_img				img;
	int					width;
	int					height;
}						t_tex;

typedef struct s_ant_visu
{
    int index;
	float x;
	float y;
    t_room *room;
    t_room *prev_room;
}						t_ant_visu;

typedef struct s_vizu_hex
{
    void    *mlx_ptr;
    void   *win_ptr;
    t_ant_visu **ants;
    t_room **rooms;
	t_room *start;
	t_room *end;
	t_img	back;
	t_img	tmp;
	t_img	room_img;
	t_img	ant_img;
	t_tex   back_tex;
	t_tex	ant;
	t_tex	room;
	int		x_min;
	int		y_min;
	int		diff_max;
	int		win_height;
	float	scale;
	char	*line;
	int		is_anim_running;
	int		anim_percent;
	unsigned long	time_to_sleep;
	unsigned long 	time_start;
}				t_vizu_hex;
////   MLX
int		my_mlx_get_color(t_img *data, int x, int y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	make_back_img(t_vizu_hex *all);
void	add_link(t_vizu_hex *all);
int		free_all(t_vizu_hex *all);
void	put_rooms(t_vizu_hex *all);
void    parsing_vizu(t_lem_in *all);
void	reset_tmp(t_vizu_hex *all);

#endif
