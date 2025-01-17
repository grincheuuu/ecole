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

int	print_exit_code(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (1);
}

void	exit_code_status(int number_of_path, int number_of_rgb, int *exit_code)
{
	if (number_of_path < 4)
		(*exit_code) = (print_exit_code("error: not enouth paths\n"));
	if (number_of_path > 4)
		(*exit_code) = (print_exit_code("error: too much paths\n"));
	if (number_of_rgb < 2)
		(*exit_code) = (print_exit_code("error: not enouth colors\n"));
	if (number_of_rgb > 2)
		(*exit_code) = (print_exit_code("error: too much enouth colors\n"));
}

int	end_file(char ***map_char, t_cubfile *cubfile)
{
	int	exit_code;

	exit_code = 0;
	exit_code_status(cubfile->number_of_path,
		cubfile->number_of_rgb, &exit_code);
	if ((*map_char)[1] == NULL && exit_code == 0)
	{
		printf("Error\n");
		printf("error: you forgot to put a map!\n");
		free(*map_char);
		exit_code = 3;
	}
	finalize_exit_codes(&exit_code, map_char, cubfile);
	return (exit_code);
}

int	process_file(int fd, t_cubfile *cubfile, char ***map_char)
{
	int		co;
	int		start_map;
	char	*line;

	co = 0;
	start_map = -1;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, cubfile);
		line = get_rid_of_spaces(&line);
		all_line_null(&line);
		if (cubfile->failed == 1)
			return (cubfile_failed(cubfile, map_char));
		if (!line)
			return (end_file(map_char, cubfile));
		if (handle_line_processing(line, cubfile,
				map_char, &start_map))
			return (1);
		free(line);
		co++;
		cubfile->co = co;
	}
	return (0);
}
