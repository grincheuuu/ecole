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

int	test_existence(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	how_many_lines(t_cubfile *cubfile, char **map_char)
{
	int	number_lines;
	int	max_length;

	number_lines = 0;
	max_length = 0;
	while (map_char[number_lines])
	{
		if (max_length < (int)ft_strlen(map_char[number_lines]))
			max_length = (int)ft_strlen(map_char[number_lines]);
		number_lines++;
	}
	cubfile->column_length = number_lines;
	cubfile->row_length = max_length;
	return (number_lines);
}

int	print_and_return(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (1);
}

int	does_line_have(char *line)
{
	char	*list;
	int		co;
	int		co2;
	int		co3;

	list = "10 NSEW";
	co = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	while (line[co] != '\0')
	{
		co2 = 0;
		co3 = 0;
		while (list[co2] != '\0')
		{
			if (line[co] == list[co2])
				co3 = 1;
			co2++;
		}
		if (co3 < 1)
			return (1);
		co++;
	}
	return (0);
}
