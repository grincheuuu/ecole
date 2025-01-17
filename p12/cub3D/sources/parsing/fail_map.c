/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_return_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:20:13 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:20:45 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fail_char_to_int_map(char ***map_char, t_cubfile *cubfile)
{
	int	co;

	printf("Error\n");
	printf("error :malloc failed\n");
	co = 0;
	while (*map_char[co])
	{
		free(*map_char[co]);
		co++;
	}
	free(*map_char);
	free_cub_file2(cubfile);
	exit (1);
}

void	fail_char_to_int_map2(t_cubfile *cubfile, char ***map_char)
{
	int	co3;

	printf("Error\n");
	printf("error :malloc failed\n");
	co3 = 0;
	while (*map_char[co3])
	{
		free(*map_char[co3]);
		co3++;
	}
	free(*map_char);
	free_cub_file2(cubfile);
	exit (1);
}
