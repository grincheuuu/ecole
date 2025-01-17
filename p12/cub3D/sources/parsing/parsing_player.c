/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:23:15 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:24:07 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	multiplayer_exeption(int *number_of_players,
	t_cubfile *cubfile, int co, int co2)
{
	cubfile->player_x = co2;
	cubfile->player_y = co;
	(*number_of_players)++;
	if (*number_of_players > 1)
	{
		printf("Error\n");
		printf ("error: player: this is not a multiplayer ");
		printf ("game, please put one and only one player\n");
		cubfile->player_x = 42;
		cubfile->player_y = 42;
		return (2);
	}
	return (0);
}

int	count_player(t_cubfile *cubfile, char **map_char, int *number_of_players)
{
	int	co;
	int	co2;

	co = 0;
	co2 = 0;
	how_many_lines(cubfile, map_char);
	while (map_char[co])
	{
		co2 = 0;
		while (map_char[co][co2] != '\0')
		{
			if (map_char[co][co2] == 'N' || map_char[co][co2] == 'S'
				|| map_char[co][co2] == 'E' || map_char[co][co2] == 'W')
			{
				cubfile->player_orientation = map_char[co][co2];
				if (multiplayer_exeption(number_of_players,
						cubfile, co, co2) == 2)
					return (2);
			}
			co2++;
		}
		co++;
	}
	return (0);
}

int	finalise_player(t_cubfile *cubfile, char **map_char, int *number_of_players)
{
	if (count_player(cubfile, map_char, number_of_players) == 2)
		return (2);
	if (*number_of_players < 1)
	{
		printf("Error\n");
		printf ("error: player: where is the damn player?\n");
		return (2);
	}
	return (0);
}
