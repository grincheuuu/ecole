/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:16:35 by gschwart          #+#    #+#             */
/*   Updated: 2024/11/13 05:39:53 by tguerran         ###   ########.fr       */
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

# define BLACK       0x00000
# define WHITE       0xFFFFFF
# define RED   0xFF0000
# define GREEN_LIGHT	0x00CC00
# define BLUE_CIEL       0x66FFFF
# define YELLOW		0xFFFF00
#define GREY 0x808080
#define DARK_BLUE 0x00008B

# define WIDTH   320
# define HEIGHT  200

typedef struct s_img {
    void        *img_ptr;
    char    *pixel_ptr;
    int     bpp;           
    int     line_len;      
    int         size_line;
    int         endian;
} t_img;


typedef struct s_map {
    double         x;
    double         y;
    char        **layout;
} t_map;


typedef struct s_ray {
    double  speed;
    double  direction;
    int     xp[WIDTH];
    char    orientation;
	char	O;
    double  Lcumulelateral[WIDTH];
    double  hcumuleHorizontale[WIDTH];
    double  hcumule[WIDTH];
    double  Dx[WIDTH];
    double  Dy[WIDTH];
    double  dx;
    double  dy;
    double  Px;
    double  Py;
    int     murHaut[WIDTH];
    int     murBas[WIDTH];
    double  Lc[WIDTH];
    double  e[WIDTH];
    double  ra;
    int     Ori;
    char    signe[WIDTH];
    int     longueur;
    char    *largeur;
} t_ray;


typedef struct s_player {
    double      pos_x;
    double      pos_y;
    double      dir_x;
    double      dir_y;
    double      plane_x;
    double      plane_y;
    double      angle_direction;
} t_player;

typedef struct s_data {
    void        *mlx_co;
    void        *mlx_win;
    t_img       img;            // Image principale pour le rendu
    t_player    player;         // Position et orientation du joueur
    t_map       map;            // Carte et autres éléments
    t_ray       ray;            // Informations de raycasting
    int         win_width;
    int         win_height;
    t_img north_texture;
    t_img south_texture;
    t_img east_texture;
    t_img west_texture;
} t_data;

// Event handlers
void        ft_event(t_data *data);
int         ft_key_action(int keysym, t_data *data);
int         ft_close_all(t_data *data);

// Initialization functions
void        init_data(t_data *data);
void        ft_render(t_data *data, t_ray *ray);
void        ft_pose_carte(t_data *data);
//void        ft_search_player(char **tab, t_player *player,t_ray *ray, t_data *data);

// Utility functions
void        my_minilibx_pixel_put(int x, int y, t_img *img, int color);
double      ft_atof(char *s);
int         ft_strlen(const char *s1);
char        *ft_strjoin(char *s1, char *s2);
char        *ft_strchr(const char *s, int c);
char        *ft_strcpy(char *ray, const char *src);
char        *get_next_line(int fd);
char        **ft_gnl(t_ray *ray);
void        ft_fre(char **tab);

// Raycasting functions
t_ray      *ft_ray_casting(char **tab, t_ray *ray, t_data *data);
// t_ray	*ft_distance(t_ray *ray, int i, t_player *player);
t_ray       *ft_horizontale(t_ray *ray, t_player *player, t_map *map, int i, char **tab);
t_ray       *ft_verticale(t_ray *ray, t_player *player, t_map *map, int i, char **tab);
t_ray       *ft_perpendiculaire(t_ray *ray, t_player *player, int i, char **tab);
void        ft_signe(t_ray *ray, t_data *data);

#endif
