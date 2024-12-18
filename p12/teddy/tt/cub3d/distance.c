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

t_dest	*ft_horizontale(t_dest *dest, double x, double y, int i, char **tab)
{
	double	L;
	double Lc;
	double	v;
    double  e;
	double	h;
    int     t;
	int	xa;
	int	ya;

    if (dest->signe[i] == '-')
        h = -32.0;
    else
        h = 32.0;
    dest->hcumule[i] = h;
    v = dest->e[i];
    printf("\n");
    e = v * 180 / M_PI;
//    printf("\n dest->e %f i %d  ", dest->e[i], i);
//    printf("\nH  dest e %f i %d dest signe %c char %c ", dest->e[i], i, dest->signe[i], dest->O);
    if (fabs(dest->e[i] - M_PI / 2) < 0.01 || fabs(dest->e[i] - 3 * M_PI / 2) < 0.01)
        L = 0.001;
    else if (dest->e[i] < 0 && ((dest->e[i] + M_PI / 2) < 0.01 || fabs(dest->e[i] + 3 * M_PI /2) < 0.01) && i < 162)
        L = -0.001;
    else if (dest->signe[i] == '+')
        L = h / tan(v);
    else
        L = h / tan(v) * -1;
    x = x - L;
    y = y - h;
    Lc = L;
    xa = (int)x / 64;
    if (dest->signe[i] == '+')
        ya = (int)y / 64 - 1;
    else
        ya = (int)y / 64;
//    printf("Un L %f x %f y %f h %f ya %d xa %d Lc %f\n", L, x, y, h, ya, xa, Lc);
    if (ya < 0 || xa < 0 || ya >= dest->longueur || (xa - 1) >= dest->largeur[ya])
    {
        dest->Lc[i] = Lc;
        dest->Dx[i] = x;
		dest->Dy[i] = y;
        dest->hcumuleHorizontale[i] = dest->hcumule[i];
//        printf("Hechec 1\n");
        return (dest);
    }
    if (tab[ya][xa] == '1')
    {
		dest->Lc[i] = Lc;
        dest->Dx[i] = x;
		dest->Dy[i] = y;
        dest->hcumuleHorizontale[i] = dest->hcumule[i];
//        printf("Hsortie Lc %f dx %f dy %f 1\n", dest->Lc[i], dest->Dx[i], dest->Dy[i]);
        return (dest);
    }
    if (dest->signe[i] == '-')
        h = -64.0;
    else
        h = 64.0;
    y = y - h;
    while (x > 0 && y > 0)
    {
        t = (int)y;
        if (t % 64 == 0)
        {
            if (fabs(dest->e[i]  - M_PI / 2) < 0.01 || fabs(dest->e[i] - 3 * M_PI / 2) < 0.01 || dest->e[i] == M_PI)
                L = 0.001;
            else if (dest->e[i] < 0 && (dest->e[i] + M_PI / 2 ) < 0.01 && i < 162)
                L = -0.001;
            else if (dest->signe[i] == '+')
                L = h / tan(v);
            else
                L = h / tan(v) * -1;
			Lc += L;
            dest->hcumule[i] += h;
            x -= L;
//            printf("1 L %f x %f y %f h %f Lc %f hcumule %f\n", L, x, y, h, Lc, dest->hcumule[i]);
            xa = (int)x / 64;
            if (dest->signe[i] == '+')
                ya = (int)y / 64 - 1;
            else
                ya = (int)y / 64;
            if (ya < 0 || xa < 0 || ya >= dest->longueur || (xa - 1) >= dest->largeur[ya])
            {
//                printf("x %f y %f Lc %f ya %d xa %d destlongeur %d dest-largeur %d", x, y, Lc, ya, xa, dest->longueur, dest->largeur[ya]);
                dest->Dx[i] = x;
				dest->Dy[i] = y;
				dest->Lc[i] = Lc;
                dest->hcumuleHorizontale[i] = dest->hcumule[i];
//                printf("Hecchec 2\n");
                return (dest);
            }
            if (xa < dest->largeur[ya] && tab[ya][xa] == '1')
            {
				dest->Dx[i] = x;
				dest->Dy[i] = y;
				dest->Lc[i] = Lc;
                dest->hcumuleHorizontale[i] = dest->hcumule[i];
//                printf("Htrust 2\n");
                return (dest) ;
            }
/*            else if ((xa - 1) > 0 && tab[ya][xa - 1] == '1')
            {
				dest->Dx[i] = x;
				dest->Dy[i] = y;
				dest->Lc[i] = Lc;
                printf("trusghjht");
                return (dest) ;
            }*/
        }
        y -= h;
    }
//    printf("Hdefaite\n");
	return (dest);
}

t_dest	*ft_verticale(t_dest *dest, double x, double y, int i, char **tab)
{
	double	L;
	double	Lc;
	double	v;
    double  h;
	int xa;
	int	ya;

    L = 32;
    v = dest->e[i];
    if (dest->e[i] < 0)
        L = -32;
    Lc = L;
    if(fabs(dest->e[i] - M_PI / 2) < 0.01 || fabs(dest->e[i] - 3 * M_PI / 2) < 0.01)
        return (ft_perpendiculaire(dest, x, y, i, tab));
    else if (dest->e[i] < 0 && (dest->e[i] + M_PI / 2) < 0.01 && i < 162)
        return (ft_perpendiculaire(dest, x, y, i, tab));
    h = L * tan(v);
    if (dest->signe[i] == '-')
        h = -h;
    x = x - L;
    y = y - h;
    printf(" Lc %f ", Lc);
    xa = (int)x / 64;
    ya = (int)y / 64;
//    printf("xa %d, ya %d y %f fgjgfj", xa, ya, y);
    if (ya < 0 || (xa - 1) < 0 || ya >= dest->longueur || xa >= dest->largeur[ya])
    {
        printf("Vdefaaiite 1\n");
        return (dest);
    }
//    printf ("Verticale e %f i%d h %f", e, i, h);
    if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
    {
//        printf (" LcH %f LvV %fouba  ", dest->Lc[i], Lc);
//        printf("sorrtie  mur ya %d xa %d xa + 1 %d  y %f \n", ya, xa, xa + 1, y);
		if (fabs(dest->Lc[i]) > fabs(Lc))
        {
            dest->Dx[i] = x;
			dest->Dy[i] = y;
			dest->Lc[i] = Lc;
            dest->Lcumulelateral[i] = Lc;
            printf("oupi ");
        }
        printf("Vert\n");
        return (dest);
    }
    L = 64;
    if (dest->e[i] < 0)
        L = -64;
    x -= L;
    printf(" Lc %f ", Lc);
//    printf(" hh %f, L %f x %f y %f\n", h, L, x, y);
    while (x > 0 && y > 0)
    {
        if ((int)x % 64 == 0)
        {
			Lc += L;
            h = tan(v) * L;
            if (dest->signe[i] == '-')
                h = -h;
            y -= h;
            xa = x / 64;
            ya = y / 64;
            printf(" Lc %f xa %d ya %d", Lc, xa, ya);
//            printf("xa %d ya %d longueur %d largeur %d ", xa, ya, dest->longueur, dest->largeur[ya]);
            if (ya < 0 || (xa - 1) < 0 || ya >= dest->longueur || xa >= dest->largeur[ya])
            {
//                printf("Vechec 2\n");
                return (dest);
            }
            if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
            {
                printf ("LcH %f LvV %fouba  ", dest->Lc[i], Lc);
                printf("xH %f yH %f lc %f Lf %f\n", dest->Dx[i] / 64, dest->Dy[i] / 64, dest->Lc[i], L);
				if (fabs(dest->Lc[i]) > fabs(Lc))
				{
					dest->Dx[i] = x;
					dest->Dy[i] = y;
					dest->Lc[i] = Lc;
                    dest->Lcumulelateral[i] = Lc;
                    printf(" Victoire Genial\n");
				}
                return (dest);
            }
        }
        x -= L;
    }
//    printf("Vdefaite in\n");
	return (dest);
}

t_dest  *ft_perpendiculaire(t_dest *dest, double x, double y, int i, char **tab)
{
    double  h;
    double  hc;
	int xa;
//    int r;
//    int t;
	int	ya;

    h = 32;
    if (dest->signe[i] == '-')
        h = -h;
    hc = h;
//    t = 0;
//    r = 0;
    y = y - h;
    xa = (int)x / 64;
    ya = (int)y / 64;
    printf("perpendiculaire ");
    if (ya < 0 || (xa - 1) < 0 || ya >= dest->longueur || xa >= dest->largeur[ya])
    {
        printf("Vvechec 3\n");
        return (dest);
    }
    if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
    {
//        printf (" LcH %f LvV %fouba  ", dest->Lc[i], 0.);
//        printf ("dest Hc %f hc %f i %d\n", dest->hcumule[i], hc, i);
		if (dest->hcumule[i] > hc)
        {
            dest->hcumule[i] = hc;
            dest->Lc[i] = 0.001;
            dest->Dx[i] = x;
			dest->Dy[i] = y;
            dest->Lcumulelateral[i] = 0;
            printf("youpi 3  ");
        }
        printf("Vvictoire\n");
        return (dest);
    }
    h = 64;
    if (dest->signe[i] == '-')
        h = -h;
    y -= h;
//    printf(" y %f ", y);
    while (y > 0)
    {
        if ((int)y % 64 == 0)
        {
            hc += h;
            ya = y / 64;
            if (ya < 0 || (xa - 1) < 0 || ya >= dest->longueur || xa >= dest->largeur[ya])
            {
                printf("VVechec 3\n");
                return (dest);
            }
//            printf("ya %d, xa %d ", ya, xa);
//            r = tab[2][3] - 48;
//            t = tab[1][2] - 48;
//            printf("tab xa -1  %d xa  %d\n", r, t);
            if (tab[ya][xa - 1] == '1' || tab[ya][xa] == '1')
            {
				if (dest->hcumule[i] > hc)
				{
                    dest->hcumule[i] = hc;
                    dest->Lc[i] = 0.001;
                    dest->Dx[i] = x;
					dest->Dy[i] = y;
                    dest->Lcumulelateral[i] = 0;
                    printf("VictoireV");
				}
                printf("VictoireV\n");
//                printf (" y %f ", y);
                return (dest);
            }
        }
        y -= h;
    }
    printf("VVdefaite fin\n");
	return (dest);
}