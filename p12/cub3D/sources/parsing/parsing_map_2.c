/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:31:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:33:19 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	bad_pixel2(t_cubfile *cubfile, int co, int co2)
{
	if ((co2 == 0 || (co + 1) >= cubfile->column_length)
		|| ((cubfile->map[co + 1][co2 - 1] != 0)
		&& (cubfile->map[co + 1][co2 - 1] != 1)))
		return (print_and_return("the map is invalid\n"));
	if (((co + 1) >= cubfile->column_length)
		|| ((cubfile->map[co + 1][co2] != 0)
		&& (cubfile->map[co + 1][co2] != 1)))
		return (print_and_return("the map is invalid\n"));
	if (((co2 + 1) >= cubfile->row_length || (co + 1) >= cubfile->column_length)
		|| ((cubfile->map[co + 1][co2 + 1] != 0)
		&& (cubfile->map[co + 1][co2 + 1] != 1)))
		return (print_and_return("the map is invalid\n"));
	return (0);
}

int	bad_pixel(t_cubfile *cubfile, int co, int co2)
{
	if ((co2 + 1) >= cubfile->row_length || ((cubfile->map[co][co2 + 1] != 0)
		&& (cubfile->map[co][co2 + 1] != 1)))
		return (print_and_return("the map is invalid\n"));
	if (((co2 + 1) >= cubfile->row_length || (co) == 0)
		|| ((cubfile->map[co - 1][co2 + 1] != 0)
		&& (cubfile->map[co - 1][co2 + 1] != 1)))
		return (print_and_return("the map is invalid\n"));
	if ((co == 0) || ((cubfile->map[co - 1][co2] != 0)
		&& (cubfile->map[co - 1][co2] != 1)))
		return (print_and_return("the map is invalid\n"));
	if ((co2 == 0 || (co) == 0) || ((cubfile->map[co - 1][co2 - 1] != 0)
		&& (cubfile->map[co - 1][co2 - 1] != 1)))
		return (print_and_return("the map is invalid\n"));
	if ((co2) == 0 || ((cubfile->map[co][co2 - 1] != 0)
		&& (cubfile->map[co][co2 - 1] != 1)))
		return (print_and_return("the map is invalid\n"));
	if (bad_pixel2(cubfile, co, co2) == 1)
		return (1);
	return (0);
}

void	put_in_map_int_line(t_cubfile *cubfile,
	char **map_char, int co, int *co2)
{
	while (map_char[co][*co2] != '\0')
	{
		if (map_char[co][*co2] == '0')
			cubfile->map[co][*co2] = 0;
		if (map_char[co][*co2] == '1')
			cubfile->map[co][*co2] = 1;
		if (map_char[co][*co2] == ' ')
			cubfile->map[co][*co2] = 2;
		if (map_char[co][*co2] == 'N' || map_char[co][*co2] == 'S'
			|| map_char[co][*co2] == 'E' || map_char[co][*co2] == 'W')
			cubfile->map[co][*co2] = 0;
		(*co2)++;
	}
}

void	finalize_put_in_map_int_line(t_cubfile *cubfile, char **map_char)
{
	int	co;
	int	co2;

	co2 = 0;
	co = 0;
	while (map_char[co])
	{
		co2 = 0;
		cubfile->map[co] = (int *)malloc((cubfile->row_length) * sizeof(int));
		if (!cubfile->map[co])
			fail_char_to_int_map2(cubfile, &map_char);
		put_in_map_int_line(cubfile, map_char, co, &co2);
		if (co2 < cubfile->row_length)
		{
			while (co2 < cubfile->row_length)
			{
				cubfile->map[co][co2] = 2;
				co2++;
			}
		}
		co++;
	}
}

void	print_map_char(char **map_char)
{
	int	co;

	co = 0;
	while (map_char[co])
	{
		printf("map :%s\n", map_char[co]);
		co++;
	}
}
