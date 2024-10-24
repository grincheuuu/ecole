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

#include "cub3d.h"

t_dest	*ft_horizontale(t_dest *dest, int x, int y, int i, char **tab)
{
	double	L;
	double Lc;
	double	v;
	int	h;
	int	xa;
	int	ya;

    h = 32;
    v = dest->e[i];
    L = h / tan(v);
	printf ("Horizontale v %f L %f\n", v, L);
    x = x - L;
    y = y - h;
	printf ("x %d y %d\n", x, y);
    xa = x / 64;
    ya = y / 64 - 1;
	Lc = L;
	printf("xa %d ya %d Lc %f\n", xa, ya, Lc);
    if (tab[ya][xa] == '1')
    {
		dest->Lc[i] = Lc;
		printf ("fin Horizontale 1 %f\n", Lc);
        return (dest);
    }
    h = 64;
    y = y - h;
    while (x > 0 && y > 0)
    {
        if ((int)y % 64 == 0)
        {
            L = h / tan(v);
			Lc += L;
            x -= L;
            ////////////
            xa = x / 64;
            ya = y / 64 - 1;
            if (tab[ya][xa] == '1')
            {
				dest->Dx[i] = x;
				dest->Dy[i] = y;
				dest->Lc[i] = Lc;
				printf("x %d y %d lc %f\n", dest->Dx[i], dest->Dy[i], dest->Lc[i]);
                return (dest) ;
            }
        }
        y -= 64;
    }
	printf("fin Horizontale\n");
	return (NULL);
}

t_dest	*ft_verticale(t_dest *dest, int x, int y, int i, char **tab)
{
	double	L;
	double	Lc;
	double	v;
	double	h;
	int xa;
	int	ya;

    L = 32;
	Lc = 32;
    v = dest->e[i];
    h = L * tan(v);
	if (h < 0)
		h *= -1;
	printf("verticale\n");
	printf("h %f, e %f", h, v);
    x = x - L;
    y = y - h;
	printf(" x %d y %d\n", x, y);
    xa = x / 64;
    ya = y / 64;
	if (xa < 0 || ya < 0)
		return (dest);
	printf("xa %d ya %d\n", xa, ya);
    if (tab[ya][xa + 1] == '1'  || tab[ya][xa] == '1')
    {
		if (dest->Lc[i] > Lc)
			dest->Lc[i] = Lc;
        return (dest);
    }
    L = 64;
    x -= L;
    while (x > 0 && y > 0)
    {
        if ((int)x % 64 == 0)
        {
			Lc += L;
            h = tan(v) * L;
			if (h < 0)
				h *= -1;
            y -= h;
            xa = x / 64;
            ya = y / 64;
			if (xa < 0 || ya < 0)
				return (dest);
            if (tab[ya][xa + 1] == '1' || tab[ya][xa] == '1')
            {
				if (dest->Lc[i] > Lc)
				{
					dest->Dx[i] = x;
					dest->Dy[i] = y;
					dest->Lc[i] = Lc;
				}
                return (dest);
            }
        }
        x -= L;
    }
	return (NULL);
}
