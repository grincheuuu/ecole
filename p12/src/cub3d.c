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

void	ft_search_player(char **tab, t_dest *dest, t_fractal *fractal)
{
	int	x;
	int y;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == 'N' || tab[y][x] == 'S' || tab[y][x] == 'E' || tab[y][x] == 'O')
			{
				dest->Px = (x + 1) * 64 - 32;
				dest->Py = (y + 1) * 64 - 32;
				dest->O = tab[y][x];
				ft_signe(&dest, &fractal);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_signe(t_dest **dest, t_fractal **fractal)
{
	int	i;

	i = 0;
//	printf("signe ");
	if ((*dest)->O == 'N' && (*fractal)->indice != 1)
	{
		(*dest)->Ori = 0;
		(*dest)->ra = 60 * M_PI / 180;
	}
	else if ((*dest)->O == 'E' && (*fractal)->indice != 1)
	{
		(*dest)->Ori = 0;
		(*dest)->ra = 150 * M_PI / 180;
	}
	else if ((*dest)->O == 'S' && (*fractal)->indice != 1)
	{
		(*dest)->Ori = 1;
		(*dest)->ra = -60 * M_PI / 180;
	}
	else if ((*dest)->O == 'O' && (*fractal)->indice != 1)
	{
		(*dest)->Ori = 1;
		(*dest)->ra = -150 * M_PI / 180;

	}
	if ((*fractal)->indice == 0)
	{
		(*fractal)->ra = (*dest)->ra;
		(*fractal)->Ori = (*dest)->Ori;
	}
//	printf("dest %f shift %f \n", (*dest)->ra, (*fractal)->shift_x);
	if ((*dest)->ra)
		printf("%d\n", (*dest)->ra);
	if ((*fractal)->shift_x)
		printf("%d\n", (*fractal)->shift_x);
	if ((*fractal)->indice)
		printf("%d\n", (*fractal)->indice);
	if ((*fractal)->indice != 1 && (fabs((*dest)->ra + (*fractal)->shift_x) >= M_PI || fabs((*dest)->ra + (*fractal)->shift_x) <= 0.01))
		(*fractal)->indice = 1;
	if ((*fractal)->indice == 1)
	{
//		printf("i %d indice", i);
		(*dest)->Ori = (*fractal)->Ori;
		(*dest)->ra = (*fractal)->ra;
		if ((*fractal)->Ori == 0)
		{
			if (((*dest)->ra + (*fractal)->shift_x) >= M_PI) // 180° g -> d
			{
				(*dest)->Ori = 1;
				(*fractal)->signe = -1;
				(*fractal)->shift_x = 0;
			}
			else if (((*dest)->ra + (*fractal)->shift_x) <= 0.01) // 0° d -> g
			{
				(*dest)->Ori = 1;
				(*fractal)->signe = -1;
				(*fractal)->shift_x = -179.98 * M_PI / 180;
			}
			(*dest)->ra = 0.01 + (*fractal)->shift_x;
			(*fractal)->Ori = (*dest)->Ori;
			(*fractal)->ra = -0.01;
//			printf("     dest %f shift %f  HOHO\n", (*dest)->ra, (*fractal)->shift_x);
		}
		else if ((*fractal)->Ori == 1)
		{
			if (fabs((*dest)->ra + (*fractal)->shift_x) <= 0.01) // 0 g -> d
			{
				(*dest)->Ori = 0;
				(*fractal)->signe = 1;
				(*fractal)->shift_x = 179.99 * M_PI / 180;
			}
			else if (fabs((*dest)->ra + (*fractal)->shift_x) >= M_PI) // -180 d -> g
			{
				(*dest)->Ori = 0;
				(*fractal)->signe = 1;
				(*fractal)->shift_x = 0;
			}
			(*dest)->ra = -0.01 + (*fractal)->shift_x;
			(*fractal)->ra = 0.01;

			(*fractal)->Ori = (*dest)->Ori;
//			printf("     dest %f shift %f  haha\n", (*dest)->ra, (*fractal)->shift_x);
		}
	}
	else
		(*dest)->ra += (*fractal)->shift_x;
}

t_dest	*ft_ray_casting(char **tab, t_dest *dest)
{
//	double	x;
//	double	y;
	int	i;

	i = 0;
	while (i < WIDTH)
	{
//		x = 3.5 * 64;
//		y = 5.5 * 64;
		dest = ft_horizontale(dest, dest->Px, dest->Py, i, tab);
		dest = ft_verticale(dest, dest->Px, dest->Py, i, tab);
		dest = ft_distance(dest, i, dest->Px, dest->Py);
//		printf ("dest[i] %d, i %d, murHAUT %d murBAS %d LC %f e %f\n", i, dest->xp[i], dest->murHaut[i], dest->murBas[i], dest->Lc[i], dest->e[i]);
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
	double	v;
//	double	angleDiff;
	double	dl;
	double	d;

	(void)y;
	v = dest->e[i] * 180 / M_PI;
	b = M_PI / 2 - dest->e[i]; //	b = 90 * 3.14159 / 180 - dest->e[i];
	d = (x - dest->Dx[i]);
	dl = (y - dest->Dy[i]);
	t = 90 * M_PI / 180 + 90 * M_PI / 180 - dest->e[i];
	a = -M_PI / 2 - dest->e[i];
//	printf(" fgfdgfsdgsfd i %d Lc %f e %f sgfgf\n", i, dest->Lc[i], dest->e[i]);
//	printf(" i %d Lc %f d %i hcumu %f dest->e[i] %f  ", i, dest->Lc[i], d, dest->hcumule[i], dest->e[i]);
	if (dest->e[i] > 0 && fabs(dest->e[i]) >= M_PI / 4)
	{
		if (fabs(dest->e[i] - M_PI / 2) < 0.01)
		{
			if (dest->signe[i] == '+')
				dest->Lc[i] = dest->hcumuleHorizontale[i];
			else
				dest->Lc[i] = -dest->hcumuleHorizontale[i];
		}
		else
			dest->Lc[i] = (d / cos(dest->e[i])) * cos(b);
//		printf("e %f b %f ghgfdh\n", dest->e[i], b);
	}
	else if (fabs(dest->e[i]) >= M_PI / 4)
	{
		if (dest->e[i] < 0 && fabs(dest->e[i] + M_PI / 2) < 0.01) // probleme i < 162
		{
			if (dest->signe[i] == '+')
				dest->Lc[i] = dest->hcumuleHorizontale[i];
			else
				dest->Lc[i] = -dest->hcumuleHorizontale[i];
		}
		else
			dest->Lc[i] = ((d / cos(dest->e[i])) * cos(a)) * -1;
//		printf("e %f a %f\n", dest->e[i], a);
	}
	if (fabs(dest->e[i]) <= M_PI / 4)
	{
//		printf("lateral lateral %f\n", dest->Lcumulelateral[i]);
		if (fabs(dest->e[i]) < 0.01)
		{
			dest->Lc[i] = dest->Lcumulelateral[i];
//			printf("stylo vert %f\n", dest->e[i]);
		}
		else
			dest->Lc[i] = ((dl / sin(dest->e[i])) * sin(b));
	}
	if (fabs(dest->Lc[i]) <= 0.01)
	{
		if (dest->signe[i] == '+')
			dest->Lc[i] = dest->hcumuleHorizontale[i];
		else
			dest->Lc[i] = -dest->hcumuleHorizontale[i];
	}
//	dest->Lc[i] = sqrt((dest->Px - dest->Dx[i]) * (dest->Px - dest->Dx[i]) + (dest->Py - dest->Dy[i]) * (dest->Py - dest->Dy[i]));
/*	if (dest->e[i] > 0)
	{
		dest->Lc[i] = d * cos(b);
		printf(" b %f, dest->Lc[i] %f d %f\n", b, dest->Lc[i], d);
	}
	else
	{
		dest->Lc[i] = d * cos(a);
		printf(" a %f, dest->Lc[i] %f d %f\n", a, dest->Lc[i], d);
	}*/
	h_mur = 64 / dest->Lc[i] * 277;
//	printf(" h_mur %d ", h_mur);
	if (h_mur < 0)
		h_mur *= -1;
//	printf(" h_mur2 %d Lc2 %f\n\n", h_mur, dest->Lc[i]);
	dest->murHaut[i] = HEIGHT / 2 - h_mur / 2;
	dest->murBas[i] = HEIGHT / 2 + h_mur / 2;
	return (dest);
}

void	ft_pose_carte(t_fractal *fractal)
{
	int	i;
//	double	ra;
	double	v;
	char	**tab;
	t_dest	*dest;
	
	i = 0;
//	ra = 60 * M_PI / 180;
	dest = malloc(sizeof(t_dest));
	if (dest == NULL)
		return;
	tab = ft_gnl(&dest);
	ft_search_player(tab, dest, fractal);
	while (i < WIDTH)
	{
		dest->xp[i] = i;
		dest->hcumule[i] = 0;
		dest->hcumuleHorizontale[i] = 0;
		dest->Lcumulelateral[i] = 0;
		dest->Lc[i] = 0.0;
		dest->Dx[i] = 0.0;
		dest->Dy[i] = 0.0;
		dest->murHaut[i] = 0;
		dest->murBas[i] = 0;

		if (dest->Ori == 0)
			dest->e[i] = dest->ra + i * (60 * M_PI / 180) / WIDTH;
		else
			dest->e[i] = dest->ra - i * (60 * M_PI / 180) / WIDTH;

		if (dest->Ori == 0)
			dest->signe[i] = '+';
		else
			dest->signe[i] = '-';
	//	printf("Ti %d dest->e[i] %f signe %c\n", i, dest->e[i], dest->signe[i]);
		if (fabs(dest->e[i]) >= M_PI)
		{
			if (dest->Ori == 0)
			{
				dest->ra = 0 + i * (60 * M_PI / 180) / WIDTH;
				dest->Ori = 1;
			}
			else
			{
				dest->ra = 0 - i * (60 * M_PI / 180) / WIDTH;
				dest->Ori = 0;
			}
		}
		if (fabs(dest->e[i]) >= M_PI)
		{
			if (dest->signe[i] == '+')
				dest->e[i] = -0.001;
			else
				dest->e[i] = 0.001;
		}
		else if (dest->e[i] > M_PI / 2 && dest->signe[i] == '+')
			dest->e[i] = (M_PI - dest->ra - i * (60 * M_PI / 180) / WIDTH) * -1;
		else if (fabs(dest->e[i]) > M_PI / 2 && dest->signe[i] == '-')
			dest->e[i] = (M_PI + dest->ra - i * (60 * M_PI / 180) / WIDTH);
		v = dest->e[i] * 180 / M_PI;
	//	printf("v %f\n", v);
		i++;
	}
	dest = ft_ray_casting(tab, dest);
	ft_render(fractal, dest);
	mlx_loop(fractal->mlx_co);
    free(dest);
    ft_fre(tab);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	(void)argc;
	(void)argv;
	fractal = malloc(sizeof(t_fractal));
	ft_init(fractal);
	ft_pose_carte(fractal);
	free(fractal);
	return (0);
}