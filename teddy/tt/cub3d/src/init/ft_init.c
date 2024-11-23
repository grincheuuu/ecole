/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:43:38 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/19 02:10:06 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_map(t_map *map)
{
    map->x = 10;
    map->y = 10;
}

void init_ray(t_ray *ray)
{
    int i;

    ray->speed = 0.1;            // Exemple de valeur pour la vitesse
    ray->direction = 0.0;         // Orientation par défaut (vers l'Est)
    ray->Px = 0.0;                // Position x initiale (à adapter)
    ray->Py = 0.0;                // Position y initiale (à adapter)
    ray->ra = 0.0;                // Angle de vue initial
    ray->Ori = 0;                 // Orientation par défaut (0 pour Nord)
    ray->orientation = 'N';       // Orientation initiale du joueur (N/S/E/W)
    ray->O = 'N';                 // Orientation par défaut ('N' ici)

    ray->longueur = 0;              // Taille de la carte en y (à définir)
    ray->largeur = NULL;            // Pointeur pour la largeur de la carte
}

void init_player(t_player *player)
{
    player->pos_x = 2.0;      // Position de départ X (ajuster selon la carte)
    player->pos_y = 2.0;      // Position de départ Y (ajuster selon la carte)
    player->dir_x = -1.0;     // Direction initiale vers l'ouest
    player->dir_y = 0.0;      // Pas de direction verticale
    player->plane_x = 85.0;    // Plan de la caméra en X
    player->plane_y = 0.60;   // Plan de la caméra en Y (détermine le champ de vision)
    player->angle_direction = 0;
}

void init_img(t_data *data)
{
    data->img.img_ptr = mlx_new_image(data->mlx_co, data->win_width, data->win_height);
    if (!data->img.img_ptr)
    {
        perror("Erreur de création de l'image MLX");
        exit(EXIT_FAILURE);
    }

    data->img.pixel_ptr = mlx_get_data_addr(data->img.img_ptr,
                                            &data->img.bpp,
                                            &data->img.line_len,
                                            &data->img.endian);
    if (!data->img.pixel_ptr)
    {
        perror("Erreur lors de la récupération de l'adresse de l'image MLX");
        exit(EXIT_FAILURE);
    }
}

void init_textures(t_data *data)
{
    int width, height;

    data->north_texture.img_ptr = mlx_xpm_file_to_image(data->mlx_co, "src/eagle.xpm", &width, &height);
    if (!data->north_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture nord");
        exit(EXIT_FAILURE);
    }
    data->north_texture.pixel_ptr = mlx_get_data_addr(data->north_texture.img_ptr, &data->north_texture.bpp,
                                                      &data->north_texture.line_len, &data->north_texture.endian);

    data->south_texture.img_ptr = mlx_xpm_file_to_image(data->mlx_co, "src/test.xpm", &width, &height);
    if (!data->south_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture sud");
        exit(EXIT_FAILURE);
    }
    data->south_texture.pixel_ptr = mlx_get_data_addr(data->south_texture.img_ptr, &data->south_texture.bpp,
                                                      &data->south_texture.line_len, &data->south_texture.endian);

    data->east_texture.img_ptr = mlx_xpm_file_to_image(data->mlx_co, "src/wall.xpm", &width, &height);
    if (!data->east_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture est");
        exit(EXIT_FAILURE);
    }
    data->east_texture.pixel_ptr = mlx_get_data_addr(data->east_texture.img_ptr, &data->east_texture.bpp,
                                                     &data->east_texture.line_len, &data->east_texture.endian);

    data->west_texture.img_ptr = mlx_xpm_file_to_image(data->mlx_co, "src/north_texture.xpm", &width, &height);
    if (!data->west_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture ouest");
        exit(EXIT_FAILURE);
    }
    data->west_texture.pixel_ptr = mlx_get_data_addr(data->west_texture.img_ptr, &data->west_texture.bpp,
                                                     &data->west_texture.line_len, &data->west_texture.endian);
}

void init_game(t_data *data) {
    char **tab = ft_gnl(&data->ray);
    ft_search_player(tab, &data->ray, data);
    data->map.layout = tab;
}


void init_data(t_data *data)
{
    data->mlx_co = NULL;
    data->mlx_win = NULL;

    data->mlx_co = mlx_init();
    if (!data->mlx_co)
    {
        perror("Erreur d'initialisation de MLX");
        exit(EXIT_FAILURE);
    }

    data->mlx_win = mlx_new_window(data->mlx_co, data->win_width, data->win_height, "Cub3D");
    if (!data->mlx_win)
    {
        perror("Erreur de création de la fenêtre MLX");
        exit(EXIT_FAILURE);
    }

    init_img(data);
    init_player(&data->player);  
    //init_game(data);
    init_map(&data->map); 
    init_ray(&data->ray);
    init_textures(data); 
}