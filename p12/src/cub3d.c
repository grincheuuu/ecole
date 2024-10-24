/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:15:12 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:15:28 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_search_player(char **tab, t_fractal *fractal)
{
	int	x;
	int y;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == fractal->map.o)
			{
				fractal->map.x = (x + 1) * 64 - 32;
				fractal->map.y = (y + 1) * 64 - 32;
				return ;
			}
			x++;
		}
		y++;
	}
}

t_dest	*ft_ray_casting(char **tab, t_fractal *fractal, t_dest *dest)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	(void)fractal;
	while (i < WIDTH)
	{
		x = 3.5 * 64;
		y = 5.5 * 64;
		dest = ft_horizontale(dest, x, y, i, tab);
		dest = ft_verticale(dest, x, y, i, tab);
		dest = ft_distance(dest, i, x, y);
		printf ("dest[i] %d, xp %d, murHAUT %d murBAS %d LC %f e %f\n", i, dest->xp[i], dest->murHaut[i], dest->murBas[i], dest->Lc[i], dest->e[i]);
		i++;
	}
	return (dest);
}

t_dest	*ft_distance(t_dest *dest, int i, int x, int y)
{
	int	h_mur;
	double b;
	double	a;
	double	t;
	int	d;

	(void)y;
	b = M_PI / 2 - dest->e[i]; //	b = 90 * 3.14159 / 180 - dest->e[i];
	d = (x - dest->Dx[i]);
	t = 90 * M_PI / 180 + 90 * M_PI / 180 - dest->e[i];
	a = M_PI / 2 + dest->e[i];
//	if (dest->Lc[i] < 0.1)
//		dest->Lc[i] = 0.1;
//	if (dest->Lc[i] < 0)
//		dest->Lc[i] *= -1;
	if (dest->e[i] <= M_PI / 2)
		dest->Lc[i] = (d / cos(dest->e[i])) * cos(b);
	else
		dest->Lc[i] = (d / cos(dest->e[i])) * cos(a);
	h_mur = 64 / dest->Lc[i] * 277;
//	if (h_mur < 0)
//		h_mur *= -1;
	printf("mur %d, %f %f\n", h_mur, t, a);
	dest->murHaut[i] = HEIGHT / 2 - h_mur / 2;
	dest->murBas[i] = HEIGHT / 2 + h_mur / 2;
	return (dest);
}

void	ft_pose_carte(t_fractal *fractal)
{
	int	i;
	double	ra;
	char	**tab;
	t_dest	*dest;
	
	i = 0;
	ra = 60 * M_PI / 180;
	dest = malloc(sizeof(t_dest));
	if (dest == NULL)
		return;
	while (i < WIDTH)
	{
		dest->xp[i] = i;
		dest->Lc[i] = 0;
		dest->murHaut[i] = 0;
		dest->murBas[i] = 0;
		dest->e[i] = ra + i * ra / WIDTH;
		if (dest->e[i] > M_PI / 2)
			dest->e[i] = (180 * M_PI / 180 - ra - i * ra / WIDTH) * -1;
		i++;
	}
	tab = ft_gnl(fractal->map.o);
	ft_search_player(tab, fractal);
	dest = ft_ray_casting(tab, fractal, dest);
	ft_render(fractal, dest);
	mlx_loop(fractal->mlx_co);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	(void)argc;
	(void)argv;
	fractal = malloc(sizeof(t_fractal));
	ft_init(fractal);
	ft_pose_carte(fractal);
	return (0);
}
