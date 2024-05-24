/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:47 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/12 17:05:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_malloc_fail(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

static void	ft_init_struct(t_fractal *fractal)
{
	fractal->iterations = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->min_r = -4;
	fractal->max_r = 4;
	fractal->min_i = -4;
	fractal->max_i = 4;
	fractal->pixel_r = 0;
	fractal->pixel_i = 0;
	fractal->dx = (fractal->max_r - fractal->min_r) / WIDTH; 
	/*
	Le pas horizontal dx est calculé en prenant la différence entre la valeur maximale 
	et la valeur minimale de la partie réelle de la fractale, puis en divisant par la largeur de l'écran. 
	Cela permet de déterminer la distance réelle couverte par chaque pixel dans la direction horizontale.
	*/
	fractal->dy = (fractal->max_i - fractal->min_i) / HEIGHT;
	fractal->center_r = (fractal->max_r - fractal->min_r) / 2;
	/*
	Cette ligne de code calcule la valeur du centre horizontal de la 
	fractale et l'assigne à la variable center_r dans la structure fractal.
	*/
	fractal->center_i = (fractal->max_i - fractal->min_i) / 2;
}

static void	ft_event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress,
		KeyPressMask, ft_key_action, fractal);
		/* le mask indique ici de capturer que les touches presser
		ft_key_action c'est le nom de la fonction appeler lorsque l on appui sur ue touche*/
	mlx_hook(fractal->mlx_win, ButtonPress,
		ButtonPressMask, ft_mouse_action, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify,
		StructureNotifyMask, ft_close_all, fractal);
		/* destroynotify, destruction de la fenetre, C'est un masque qui indique
		 à mlx_hook de capturer uniquement les événements de modification de la
		  structure de la fenêtre, ce qui inclut la destruction de la fenêtre.*/
	mlx_hook(fractal->mlx_win, MotionNotify,
		PointerMotionMask, ft_julia_few, fractal);
		/* MotionNotify est le deplacement de la souris et le masque qui va avec*/
}

void	ft_init(t_fractal *fractal)
{
	fractal->mlx_co = mlx_init(); //connecte au serveur graphique avec un pointeur
	if (fractal->mlx_co == NULL)
		ft_malloc_fail("mlx_co_fail");
	fractal->mlx_win = mlx_new_window(fractal->mlx_co,
			WIDTH, HEIGHT, fractal->type); /* cree une nouvel fenetre a l ecran et renvoie
			l'identifiant de la fenetre*/;
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_co); // detruit l'affichage
		free(fractal->mlx_co);// free le pointeur de connexion au serveur
		ft_malloc_fail("mlx_win_fail");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT); /* cree une image
	retourne un pointeur void pour la manipuler*/
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_co, fractal->mlx_win); //detruit la fenetre
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		ft_malloc_fail("img_ptr_fail");
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
			/* retourne des informations sur l image creer*/
			/*img.ptr specifie l image a utiliser, et ensuite l adresse de 3 entiers
			bit par pixel represente le nombre de bit necessaire pour representer
			une couleur de pixel
			line.len represente le nombre d'octet pour une ligne de l image en memoire */
	ft_init_struct(fractal);
	ft_event_init(fractal);
}

int	ft_julia_few(int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (ft_strncmp(fractal->type, "julia", 5) == 0)
	{
		fractal->julia_x = fractal->min_r
			+ (double)x * fractal->dx + fractal->shift_x / fractal->zoom;
		fractal->julia_y = fractal->min_i
			+ (double)y * fractal->dy + fractal->shift_y / fractal->zoom;
		ft_render(fractal);
	}
	return (0);
}
