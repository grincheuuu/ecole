/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:21:56 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/20 03:54:38 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void debug_ray(t_ray *ray)
{
    printf("Valeurs de la structure t_ray:\n");
    printf("speed: %f, direction: %f\n", ray->speed, ray->direction);
     printf("orientation: %c, O: %c\n", ray->orientation, ray->O);
    printf("dx: %f, dy: %f\n", ray->dx, ray->dy);
    printf("Px: %f, Py: %f\n", ray->Px, ray->Py);
     printf("ra: %f, Ori: %d\n", ray->ra, ray->Ori);
     printf("longueur: %d, largeur: %s\n", ray->longueur, ray->largeur);

    printf("xp:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("xp[%d]: %d ", i, ray->xp[i]);
    }
    printf("\n");

    printf("Lcumulelateral:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("Lcumulelateral[%d]: %f ", i, ray->Lcumulelateral[i]);
    }
    printf("\n");

    printf("hcumuleHorizontale:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("hcumuleHorizontale[%d]: %f ", i, ray->hcumuleHorizontale[i]);
    }
    printf("\n");

    printf("Dx et Dy:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("Dx[%d]: %f, Dy[%d]: %f\n", i, ray->Dx[i], i, ray->Dy[i]);
    }

    printf("murHaut et murBas:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("murHaut[%d]: %d, murBas[%d]: %d\n", i, ray->murHaut[i], i, ray->murBas[i]);
    }

    printf("Lc et e (angle):\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("Lc[%d]: %f, e[%d]: %f\n", i, ray->Lc[i], i, ray->e[i]);
    }

    printf("signe:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("signe[%d]: %c ", i, ray->signe[i]);
    }
    printf("\n");
}

void debug_player(t_player *player)
{
    printf("Valeurs de la structure t_player:\n");
    printf("pos_x: %f, pos_y: %f\n", player->pos_x, player->pos_y);
    printf("dir_x: %f, dir_y: %f\n", player->dir_x, player->dir_y);
    printf("plane_x: %f, plane_y: %f\n", player->plane_x, player->plane_y);
    printf("angle_direction: %f\n", player->angle_direction);
}

void debug_data(t_data *data)
{
    printf("Valeurs de la structure t_data:\n");
    printf("win_width: %d, win_height: %d\n", data->win_width, data->win_height);

    //debug_player(&data->player);
    //debug_ray(&data->ray);

    printf("Textures:\n");
    //printf("north_texture: %p, south_texture: %p\n", data->north_texture, data->south_texture);
    //printf("east_texture: %p, west_texture: %p\n", data->east_texture, data->west_texture);

    printf("mlx_co: %p, mlx_win: %p\n", data->mlx_co, data->mlx_win);
    printf("img: %p\n", &data->img);
    printf("map: %p\n", &data->map);
}

void ft_search_player(char **tab, t_ray *ray, t_data *fractal) {
    int x, y;

    y = 0;
    while (tab[y] != NULL) {
        x = 0;
        while (tab[y][x] != '\0') {
            if (tab[y][x] == 'N' || tab[y][x] == 'S' || tab[y][x] == 'E' || tab[y][x] == 'O') {
                ray->Px = (x +1) * 64 - 32;
                ray->Py = (y +1) * 64 - 32;
                fractal->player.pos_x = ray->Px;
                fractal->player.pos_y = ray->Py;
                ray->O = tab[y][x];
                tab[y][x] = '0';
                ft_signe(ray, fractal);
                return;
            }
            x++;
        }
        y++;
    }
}

void ft_pose_carte(t_data *fractal)
{
    int i;
    t_ray *ray;
    char **tab;

    i = 0;
    ray = malloc(sizeof(t_ray));
    if (ray == NULL)
        return;

    tab = ft_gnl(ray);
    ft_search_player(tab, ray, fractal);

    while (i < WIDTH) {
        ray->xp[i] = i;
        ray->hcumule[i] = 0;
        ray->hcumuleHorizontale[i] = 0;
        ray->Lcumulelateral[i] = 0;
        ray->Lc[i] = 0.0;
        ray->Dx[i] = 0.0;
        ray->Dy[i] = 0.0;
        ray->murHaut[i] = 0;
        ray->murBas[i] = 0;

        ray->e[i] = fractal->player.angle_direction 
                  + (i - WIDTH / 2) * (60 * M_PI / 180) / WIDTH;

        ray->e[i] = fmod(ray->e[i], 2 * M_PI);
        if (ray->e[i] < 0)
            ray->e[i] += 2 * M_PI;

        if (ray->e[i] >= 0 && ray->e[i] < M_PI) {
            ray->signe[i] = '+';
            ray->Ori = 0;
        } else {
            ray->signe[i] = '-';
            ray->Ori = 1;
        }

        if (ray->e[i] >= M_PI / 2 && ray->e[i] < 3 * M_PI / 2) {
            ray->Ori = 1; // Sud
        } else {
            ray->Ori = 0; // Nord
        }

		if (fabs(ray->e[i]) == M_PI)
		{
			if (ray->signe[i] == '+')
				ray->e[i] = -0.001;
			else
				ray->e[i] = 0.001;
		}

        i++;
    }

    ray = ft_ray_casting(tab, ray, fractal);

    ft_render(fractal, ray);

    free(ray);
}

// void	ft_pose_carte(t_data *fractal)
// {
// 	int	i;
// 	double	v;
// 	char	**tab;
// 	t_ray	*ray;
	
// 	i = 0;
// 	ray = malloc(sizeof(t_ray));
// 	if (ray == NULL)
// 		return;

//     tab = ft_gnl(ray);
// 	ft_search_player(tab, ray, fractal);


// 	while (i < WIDTH)
// 	{
// 		ray->xp[i] = i;
// 		ray->hcumule[i] = 0;
// 		ray->hcumuleHorizontale[i] = 0;
// 		ray->Lcumulelateral[i] = 0;
// 		ray->Lc[i] = 0.0;
// 		ray->Dx[i] = 0.0;
// 		ray->Dy[i] = 0.0;
// 		ray->murHaut[i] = 0;
// 		ray->murBas[i] = 0;
// 		if (ray->Ori == 0)
// 			ray->e[i] = ray->ra + i * (60 * M_PI / 180) / WIDTH;
// 		else
// 			ray->e[i] = ray->ra - i * (60 * M_PI / 180) / WIDTH;
//         ray->e[i] = fractal->player.angle_direction 
//             + (i - WIDTH / 2) * (60 * M_PI / 180) / WIDTH;

// 		if (ray->Ori == 0)
// 			ray->signe[i] = '+';
// 		else
// 			ray->signe[i] = '-';		
// 		if (fabs(ray->e[i]) == M_PI)
// 		{
// 			if (ray->Ori == 0)
// 			{
// 				ray->ra = 0 + i * (60 * M_PI / 180) / WIDTH;
// 				ray->Ori = 1;
// 			}
// 			else
// 			{
// 				ray->ra = 0 - i * (60 * M_PI / 180) / WIDTH;
// 				ray->Ori = 0;
// 			}
// 		}
// 		if (fabs(ray->e[i]) == M_PI)
// 		{
// 			if (ray->signe[i] == '+')
// 				ray->e[i] = -0.001;
// 			else
// 				ray->e[i] = 0.001;
// 		}
//         if (ray->e[i] > 0 && ray->e[i] < M_PI / 2) {
//             ray->Ori = 0;  // Nord-Est
//         } else if (ray->e[i] >= M_PI / 2 && ray->e[i] < M_PI) {
//             ray->Ori = 1;  // Sud-Est
//         } else if (ray->e[i] >= M_PI && ray->e[i] < 3 * M_PI / 2) {
//             ray->Ori = 1;  // Sud-Ouest
//         } else {
//             ray->Ori = 0;  // Nord-Ouest
//         }
// 		v = ray->e[i] * 180 / M_PI;
// 		i++;
// 	}
//     ray = ft_ray_casting(tab, ray, fractal);
//     ft_render(fractal, ray);
//     //debug_ray(ray);
//     free(ray);
//     ft_fre(tab);
// }

t_ray *ft_distance(t_ray *ray, int i, int x, int y)
{
    int h_mur;
    double distance_x, distance_y;
    ray->e[i] = fmod(ray->e[i], 2 * M_PI);
    if (ray->e[i] < 0)
        ray->e[i] += 2 * M_PI;

    distance_x = ray->Dx[i] - x;
    distance_y = ray->Dy[i] - y;

    ray->Lc[i] = sqrt(distance_x * distance_x + distance_y * distance_y);

    h_mur = (int)(64 / ray->Lc[i] * 277);
    if (h_mur < 0)
        h_mur *= -1;

    ray->murHaut[i] = HEIGHT / 2 - h_mur / 2;
    ray->murBas[i] = HEIGHT / 2 + h_mur / 2;

    return ray;
}

// t_ray	*ft_distance(t_ray *dest, int i, int x, int y)
// {
// 	int	h_mur;
// 	double b;
// 	double	a;
// 	double	t;
// 	double	v;
// 	double	dl;
// 	double	d;

// 	(void)y;
// 	v = dest->e[i] * 180 / M_PI;
// 	b = M_PI / 2 - dest->e[i]; //	b = 90 * 3.14159 / 180 - dest->e[i];
// 	d = (x - dest->Dx[i]);
// 	dl = (y - dest->Dy[i]);
// 	t = 90 * M_PI / 180 + 90 * M_PI / 180 - dest->e[i];
// 	a = -M_PI / 2 - dest->e[i];
// 	if (dest->e[i] > 0 && fabs(dest->e[i]) >= M_PI / 4)
// 	{
// 		if (fabs(dest->e[i] - M_PI / 2) < 0.01)
// 		{
// 			if (dest->signe[i] == '+')
// 				dest->Lc[i] = dest->hcumuleHorizontale[i];
// 			else
// 				dest->Lc[i] = -dest->hcumuleHorizontale[i];
// 		}
// 		else
// 			dest->Lc[i] = (d / cos(dest->e[i])) * cos(b);
// 	}
// 	else if (fabs(dest->e[i]) >= M_PI / 4)
// 	{
// 		if (dest->e[i] < 0 && fabs(dest->e[i] + M_PI / 2) < 0.01 && i < 162) // probleme i < 162
// 		{
// 			if (dest->signe[i] == '+'){
// 				dest->Lc[i] = dest->hcumuleHorizontale[i];
//             }
// 			else
//             {
// 				dest->Lc[i] = -dest->hcumuleHorizontale[i];
//             }
//         }
// 		else{
// 			dest->Lc[i] = ((d / cos(dest->e[i])) * cos(a)) * -1;
//         }
//     }
// 	if (fabs(dest->e[i]) <= M_PI / 4)
// 	{
// 		if (fabs(dest->e[i]) < 0.01)
// 			dest->Lc[i] = dest->Lcumulelateral[i];
// 		else
// 			dest->Lc[i] = ((dl / sin(dest->e[i])) * sin(b));
// 	}
// 	if (fabs(dest->Lc[i]) <= 0.01)
// 	{
// 		if (dest->signe[i] == '+')
// 			dest->Lc[i] = dest->hcumuleHorizontale[i];
// 		else
// 			dest->Lc[i] = -dest->hcumuleHorizontale[i];
// 	}
// 	h_mur = 64 / dest->Lc[i] * 277;

// 	if (h_mur < 0)
// 		h_mur *= -1;

// 	dest->murHaut[i] = HEIGHT / 2 - h_mur / 2;
//     dest->murBas[i] = HEIGHT / 2 + h_mur / 2;
// 	return (dest);
// }

char get_current_direction(double angle)
{
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;

    if (angle >= 0 && angle < M_PI / 4)
        return 'O'; // ouest
    else if (angle >= M_PI / 4 && angle < 3 * M_PI / 4)
        return 'N'; // Nord
    else if (angle >= 3 * M_PI / 4 && angle < 5 * M_PI / 4)
        return 'E'; // est
    else if (angle >= 5 * M_PI / 4 && angle < 7 * M_PI / 4)
        return 'S'; // Sud
    else
        return 'O'; // Retour à ouest
}

void ft_signe(t_ray *ray, t_data *data) {
    char direction = get_current_direction(data->player.angle_direction);
    //printf("Direction actuelle : %c\n", direction);

    if (direction == 'N') {
        ray->Ori = 0;
        ray->ra = M_PI / 2;  // 90 degrés
    } else if (direction == 'E') {
        ray->Ori = 0;
        ray->ra = 0;  // 0 degrés
    } else if (direction == 'S') {
        ray->Ori = 1;
        ray->ra = 3 * M_PI / 2;  // 270 degrés
    } else if (direction == 'O') {
        ray->Ori = 1;
        ray->ra = M_PI;  // 180 degrés
    }
    //printf("Direction actuelle : %d\n", ray->Ori);

    ray->ra += data->player.angle_direction;

    //printf("teddy %f \n", data->player.angle_direction);
    ray->ra = fmod(ray->ra, 2 * M_PI);
    if (ray->ra < 0)
        ray->ra += 2 * M_PI;
}

t_ray *ft_ray_casting(char **tab, t_ray *ray, t_data *data)
{
    int i;

    i = 0;

    while (i < WIDTH)
    {
        ray->ra = data->ray.ra;
        ray = ft_horizontale(ray, &data->player, &data->map, i, tab);
        ray = ft_verticale(ray, &data->player, &data->map, i, tab);
        ray = ft_distance(ray, i, data->player.pos_x, data->player.pos_y);
        i++;
    }
    return ray;
}

void ft_player(char **tab, t_ray *ray, t_data *fractal)
{
    int x, y;

    y = 0;
    while (tab[y] != NULL) {
        x = 0;
        while (tab[y][x] != '\0') {
            if (tab[y][x] == 'N' || tab[y][x] == 'S' || tab[y][x] == 'E' || tab[y][x] == 'O') {
                ray->Px = (x + 1) * 64 - 32;
                ray->Py = (y + 1) * 64 - 32;
                fractal->player.pos_x = ray->Px;
                fractal->player.pos_y = ray->Py;
                ray->O = tab[y][x];
                if (tab[y][x] == 'N') {
                    fractal->player.angle_direction = M_PI / 2;  // 90 degrés
                } else if (tab[y][x] == 'O') {
                    fractal->player.angle_direction = 0;         // 0 degrés
                } else if (tab[y][x] == 'S') {
                    fractal->player.angle_direction = 3 * M_PI / 2; // 270 degrés
                } else if (tab[y][x] == 'E') {
                    fractal->player.angle_direction = M_PI;     // 180 degrés
                }
                tab[y][x] = '0';
                return;
            }
            x++;
        }
        y++;
    }
}

void main_loop(t_data *data)
{
    ft_pose_carte(data);
    mlx_put_image_to_window(data->mlx_co, data->mlx_win, data->img.img_ptr, 0, 0);
}

int main(int argc, char **argv)
{
    t_data data;
    (void)argv;
    (void)argc;
    data.win_width = WIDTH;
    data.win_height = HEIGHT;
    init_data(&data);
    data.map.layout = ft_gnl(&data.ray);
    ft_player(data.map.layout, &data.ray, &data);
    ft_event(&data);
    mlx_loop_hook(data.mlx_co, main_loop, &data);
    mlx_loop(data.mlx_co);

    return (0);
}
