/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 06:13:05 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// Cette fonction initialise les infos pour chaque rayon à tracer sur l’écran 
// En gros, elle calcule la direction du rayon et sa position initiale sur la map 
// en fonction de la caméra du joueur.
// C’est plus propre, et ça nous permet de gérer tous les rayons d’un coup

void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x; //coordonne joueur
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x; // coordonne d'origine
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x); //angle plus rayon
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

// Là, on prépare les étapes pour que le rayon avance correctement dans la grille
// On définit dans quel sens il doit se déplacer (x ou y) et on calcule les distances initiales

void	begin_rays(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0) // vers est
	{
		ray->step_x = -1; //sud
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x; //distance mur
	}
	else
	{
		ray->step_x = 1; //nord
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0) //sud
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

// Ici, c’est le gros du raycasting le rayon avance case par case dans la grille 
// jusqu’à taper un mur
// Avant, on avait deux fonctions séparées pour gérer les collisions avec des murs horizontaux
// ou verticaux. Maintenant, tout est fusionné dans une seule boucle

void	useful_rays(t_data *data, t_ray *ray)
{
	while (1)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25 ||
			ray->map_y > data->mapinfo.height - 0.25 ||
			ray->map_x > data->mapinfo.width - 1.25 ||
			data->map[ray->map_y][ray->map_x] > '0')
			break;
	}
}

// Cette fonction calcule la hauteur de la ligne de mur à afficher pour chaque rayon
// Avant, on faisait ces calculs à différents endroits, selon si c’était horizontal ou vertical
// On calcule les coordonnées pour les textures (wall_x)

void	end_rays(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);

	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = fmax(0, -(ray->line_height) / 2 + data->win_height / 2);
	ray->draw_end = fmin(data->win_height - 1,
		ray->line_height / 2 + data->win_height / 2);

	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

// Voilà la grosse boucle c’est elle qui trace tous les rayons un par un pour chaque colonne 
// de l’écran
// À chaque rayon, on fait : initialisation -> avancer jusqu’au mur -> calculer la ligne à afficher -> appliquer la texture

int	raycasting(t_player *player, t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < data->win_width)
	{
		init_raycasting_info(x, &ray, player);
		begin_rays(&ray, player);
		useful_rays(data, &ray);
		end_rays(&ray, data, player);
		update_texture(data, &data->texinfo, &ray, x);
		x++;
	}
	return (0);
}
