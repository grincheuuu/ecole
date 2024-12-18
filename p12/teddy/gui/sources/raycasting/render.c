/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 06:05:43 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// - Si le pixel correspond à une texture de mur, on récupère sa couleur dans texture_pixels
// - Sinon, on applique la couleur du plafond si le pixel est en haut de l'écran,
//   ou celle du sol s'il est en bas.

void	set_frame_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->texinfo.hexceiling);
	else
		set_image_pixel(image, x, y, data->texinfo.hexfloor);
}


// Cette fonction génère le rendu complet de la fenêtre pour chaque frame
// Elle crée une image vide, parcourt chaque pixel de la fenêtre et applique une couleur
// ou une texture en appelant set_frame_pixel

void	draw_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	init_img(data, &image, data->win_width, data->win_height);

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}


// Cette fonction s'occupe de tout le processus de raycastin
// Elle initialise les pixels de texture, lance le raycasting,
// puis appelle draw_frame pour dessiner l'image finale

void	render_raycast(t_data *data)
{
	init_texture_pixels(data);
	init_ray(&data->ray);
	raycasting(&data->player, data);
	draw_frame(data);
}

void	render_images(t_data *data)
{
	render_raycast(data);
}

// Fonction principale pour le rendu, appelée en boucle (hook MLX).
// Si le joueur n'a pas bougé (`moved == 0`), on ne fait rien pour économiser les ressources
// et eviter les bugs de rendu pendant les mouvements
// Sinon, on relance tout le processus de rendu avec render_images
// Avant, on relançait systématiquement le rendu à chaque frame

int	render(t_data *data)
{
	data->player.moved += move_player(data);
	if (data->player.moved == 0)
		return (0);
	render_images(data);
	return (0);
}
