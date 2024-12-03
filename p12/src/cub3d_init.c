/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:18:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void	ft_malloc_fail(void)
{
	perror("malloc fail");
	exit (EXIT_FAILURE);
}

void init_img(t_fractal *fractal)
{
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT);
    if (!fractal->img.img_ptr)
    {
        perror("Erreur de création de l'image MLX");
        exit(EXIT_FAILURE);
    }

    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                            &fractal->img.bpp,
                                            &fractal->img.line_len,
                                            &fractal->img.endian);
    if (!fractal->img.pixel_ptr)
    {
        perror("Erreur lors de la récupération de l'adresse de l'image MLX");
        exit(EXIT_FAILURE);
    }
}

void init_textures(t_fractal *fractal)
{
    int width, height;

    fractal->north_texture.img_ptr = mlx_xpm_file_to_image(fractal->mlx_co, "src/eagle.xpm", &width, &height);
    if (!fractal->north_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture nord");
        exit(EXIT_FAILURE);
    }
    fractal->north_texture.pixel_ptr = mlx_get_data_addr(fractal->north_texture.img_ptr, &fractal->north_texture.bpp,
                                                      &fractal->north_texture.line_len, &fractal->north_texture.endian);

    fractal->south_texture.img_ptr = mlx_xpm_file_to_image(fractal->mlx_co, "src/test.xpm", &width, &height);
    if (!fractal->south_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture sud");
        exit(EXIT_FAILURE);
    }
    fractal->south_texture.pixel_ptr = mlx_get_data_addr(fractal->south_texture.img_ptr, &fractal->south_texture.bpp,
                                                      &fractal->south_texture.line_len, &fractal->south_texture.endian);

    fractal->east_texture.img_ptr = mlx_xpm_file_to_image(fractal->mlx_co, "src/wall.xpm", &width, &height);
    if (!fractal->east_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture est");
        exit(EXIT_FAILURE);
    }
    fractal->east_texture.pixel_ptr = mlx_get_data_addr(fractal->east_texture.img_ptr, &fractal->east_texture.bpp,
                                                     &fractal->east_texture.line_len, &fractal->east_texture.endian);

    fractal->west_texture.img_ptr = mlx_xpm_file_to_image(fractal->mlx_co, "src/north_texture.xpm", &width, &height);
    if (!fractal->west_texture.img_ptr)
    {
        perror("Erreur de chargement de la texture ouest");
        exit(EXIT_FAILURE);
    }
    fractal->west_texture.pixel_ptr = mlx_get_data_addr(fractal->west_texture.img_ptr, &fractal->west_texture.bpp,
                                                     &fractal->west_texture.line_len, &fractal->west_texture.endian);
}

static void	ft_init_struct(t_fractal *fractal)
{
	fractal->min_r = -4;
	fractal->max_r = 4;
	fractal->min_i = -4;
	fractal->max_i = 4;
	fractal->pixel_r = 0;
	fractal->pixel_i = 0;
	fractal->shift_x = 0;
	fractal->dx = (fractal->max_r - fractal->min_r) / WIDTH;
	fractal->dy = (fractal->max_i - fractal->min_i) / HEIGHT;
	fractal->map.x = 0;
	fractal->map.y = 0;
	fractal->map.o = 0;
    fractal->indice = 0;
    fractal->signe = 1;
}

static void	ft_event(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress,
		KeyPressMask, ft_key_action, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify,
		StructureNotifyMask, ft_close_all, fractal);
}

void	ft_init(t_fractal *fractal)
{

	fractal->mlx_co = mlx_init();
	if (fractal->mlx_co == NULL)
		ft_malloc_fail();
	fractal->mlx_win = mlx_new_window(fractal->mlx_co,
			WIDTH, HEIGHT, "CUB3D");
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_co);
		free(fractal->mlx_co);
		ft_malloc_fail();
	}
	init_img(fractal);
	init_textures(fractal);
	ft_init_struct(fractal);
	ft_event(fractal);
}