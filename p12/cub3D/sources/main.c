/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:54:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_args(t_data *data, char **av)
{
	t_cubfile	*cubfile;

	cubfile = init_cubfile();
	if (!cubfile)
		return (1);
	if (verif(av[1], cubfile) != 0)
	{
		free_cub_file(cubfile);
		return (1);
	}
	transfer_cubfile_to_data(data, cubfile);
	free_cub_file(cubfile);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\n");
		printf("rappel usage: \n ./cub3D <example.cub> \n");
		return (1);
	}
	if (error_usage(argc, argv) == 1)
	{
		return (1);
	}
	init_data(&data);
	if (parse_args(&data, argv) != 0)
		return (1);
	init_player_direction(&data);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	ft_event(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
