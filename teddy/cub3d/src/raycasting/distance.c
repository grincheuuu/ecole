/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:40:08 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:40:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray *ft_horizontale(t_ray *ray, t_player *player, t_map *map, int i, char **tab)
{
	double	L;
	double Lc;
	double	v;
    double  e;
	double	h;
    int     t;
	int	xa;
	int	ya;
    double x;
    double y;

    x = player->pos_x;
    y = player->pos_y;

    if (ray->signe[i] == '-')
        h = -32.0;
    else
        h = 32.0;
    
    ray->hcumule[i] = h;
    v = ray->e[i];
    e = v * 180 / M_PI;
    if (fabs(ray->e[i] - M_PI / 2) < 0.01 || fabs(ray->e[i] - 3 * M_PI / 2) < 0.01)
        L = 0.001;
    else if (ray->e[i] < 0 && ((ray->e[i] + M_PI / 2) < 0.01 || fabs(ray->e[i] + 3 * M_PI /2) < 0.01) && i < 162)
        L = -0.001;
    else if (ray->signe[i] == '+')
        L = h / tan(v);
    else
        L = h / tan(v) * -1;
    x = x - L;
    y = y - h;
    Lc = L;
    xa = (int)x / 64;
    if (ray->signe[i] == '+')
        ya = (int)y / 64 - 1;
    else
        ya = (int)y / 64;
    if (ya < 0 || xa < 0 || ya >= ray->longueur || (xa - 1) >= ray->largeur[ya])
    {
        ray->Lc[i] = Lc;
        ray->Dx[i] = x;
		ray->Dy[i] = y;
        ray->hcumuleHorizontale[i] = ray->hcumule[i];
        return (ray);
    }
    if (tab[ya][xa] == '1')
    {
		ray->Lc[i] = Lc;
        ray->Dx[i] = x;
		ray->Dy[i] = y;
        ray->hcumuleHorizontale[i] = ray->hcumule[i];
        return (ray);
    }
    if (ray->signe[i] == '-')
        h = -64.0;
    else
        h = 64.0;
    y = y - h;
    while (x > 0 && y > 0)
    {
        t = (int)y;
        if (t % 64 == 0)
        {
            if (fabs(ray->e[i]  - M_PI / 2) < 0.01 || fabs(ray->e[i] - 3 * M_PI / 2) < 0.01 || ray->e[i] == M_PI)
                L = 0.001;
            else if (ray->e[i] < 0 && (ray->e[i] + M_PI / 2 ) < 0.01 && i < 162)
                L = -0.001;
            else if (ray->signe[i] == '+')
                L = h / tan(v);
            else
                L = h / tan(v) * -1;
			Lc += L;
            ray->hcumule[i] += h;
            x -= L;
            xa = (int)x / 64;
            if (ray->signe[i] == '+')
                ya = (int)y / 64 - 1;
            else
                ya = (int)y / 64;
            if (ya < 0 || xa < 0 || ya >= ray->longueur || (xa - 1) >= ray->largeur[ya])
            {
                ray->Dx[i] = x;
				ray->Dy[i] = y;
				ray->Lc[i] = Lc;
                ray->hcumuleHorizontale[i] = ray->hcumule[i];
                return (ray);
            }
            if (xa < ray->largeur[ya] && tab[ya][xa] == '1')
            {
				ray->Dx[i] = x;
				ray->Dy[i] = y;
				ray->Lc[i] = Lc;
                ray->hcumuleHorizontale[i] = ray->hcumule[i];
                return (ray) ;
            }
        }
        y -= h;
    }
	return (ray);
}

t_ray *ft_verticale(t_ray *ray, t_player *player, t_map *map, int i, char **tab)
{
	double	L;
	double	Lc;
	double	v;
    double  h;
	int xa;
	int	ya;
    double x;
    double y;

    x = player->pos_x;
    y = player->pos_y;

     L = 32;
    v = ray->e[i];
    if (ray->e[i] < 0)
        L = -32;
    Lc = L;
    if(fabs(ray->e[i] - M_PI / 2) < 0.01 || fabs(ray->e[i] - 3 * M_PI / 2) < 0.01)
        return (ft_perpendiculaire(ray, player, i, tab));
    else if (ray->e[i] < 0 && (ray->e[i] + M_PI / 2) < 0.01 && i < 162)
        return (ft_perpendiculaire(ray, player, i, tab));
    h = L * tan(v);
    if (ray->signe[i] == '-')
        h = -h;
    x = x - L;
    y = y - h;
    xa = (int)x / 64;
    ya = (int)y / 64;
    if (ya < 0 || (xa - 1) < 0 || ya >= ray->longueur || xa >= ray->largeur[ya])
        return (ray);
    if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
    {
		if (fabs(ray->Lc[i]) > fabs(Lc))
        {
            ray->Dx[i] = x;
			ray->Dy[i] = y;
			ray->Lc[i] = Lc;
            ray->Lcumulelateral[i] = Lc;
        }
        return (ray);
    }
    L = 64;
    if (ray->e[i] < 0)
        L = -64;
    x -= L;
    while (x > 0 && y > 0)
    {
        if ((int)x % 64 == 0)
        {
			Lc += L;
            h = tan(v) * L;
            if (ray->signe[i] == '-')
                h = -h;
            y -= h;
            if (ray->e[i] > M_PI / 2 && ray->e[i] <= 3 * M_PI / 2) {
                L = -64; // Ouest
            } else {
                L = 64;  // Est
            }

            xa = x / 64;
            ya = y / 64;
            if (ya < 0 || (xa - 1) < 0 || ya >= ray->longueur || xa >= ray->largeur[ya])
                return (ray);
            if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
            {
				if (fabs(ray->Lc[i]) > fabs(Lc))
				{
					ray->Dx[i] = x;
					ray->Dy[i] = y;
					ray->Lc[i] = Lc;
                    ray->Lcumulelateral[i] = Lc;
				}
                return (ray);
            }
        }
        x -= L;
    }
	return (ray);
}

t_ray *ft_perpendiculaire(t_ray *ray, t_player *player, int i, char **tab)
{
    double h;
    double hc;
    int xa;
    int ya;

    double x;
    double y;

    x = player->pos_x;
    y = player->pos_y;
    h = 32;
    if (ray->signe[i] == '-')
        h = -h;
    hc = h;
    y = y - h;
    xa = (int)x / 64;
    ya = (int)y / 64;
    if (ya < 0 || (xa - 1) < 0 || ya >= ray->longueur || xa >= ray->largeur[ya])
        return (ray);
    if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
    {
		if (ray->hcumule[i] > hc)
        {
            ray->hcumule[i] = hc;
            ray->Lc[i] = 0.001;
            ray->Dx[i] = x;
			ray->Dy[i] = y;
            ray->Lcumulelateral[i] = 0;
        }
        return (ray);
    }
    h = 64;
    if (ray->signe[i] == '-')
        h = -h;
    y -= h;
    while (y > 0)
    {
        if ((int)y % 64 == 0)
        {
            hc += h;
            ya = y / 64;
            if (ya < 0 || (xa - 1) < 0 || ya >= ray->longueur || xa >= ray->largeur[ya])
                return (ray);
            if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
            {
				if (ray->hcumule[i] > hc)
				{
                    ray->hcumule[i] = hc;
                    ray->Lc[i] = 0.001;
                    ray->Dx[i] = x;
					ray->Dy[i] = y;
                    ray->Lcumulelateral[i] = 0;
				}
                return (ray);
            }
        }
        y -= h;
    }
	return (ray);
}
