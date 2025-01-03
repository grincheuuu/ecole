/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:50:36 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:35:16 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cubfile_failed(t_cubfile *cubfile, char ***map_char)
{
	int	coo2;

	coo2 = 0;
	while (map_char[coo2] != NULL)
	{
		free(map_char[coo2]);
		coo2++;
	}
	free(map_char);
	free(cubfile);
	return (1);
}

void	clean_map_char_null(t_cubfile *cubfile,
	int fd, char **line, char ***map_char)
{
	if (cubfile->floor_color)
		free(cubfile->floor_color);
	if (cubfile->ceiling_color)
		free(cubfile->ceiling_color);
	if (cubfile->ea_path)
		free(cubfile->ea_path);
	if (cubfile->no_path)
		free(cubfile->no_path);
	if (cubfile->so_path)
		free(cubfile->so_path);
	if (cubfile->we_path)
		free(cubfile->we_path);
	free_readline(line, fd, cubfile);
	free(*map_char);
	free(cubfile);
	exit (0);
}

void	finalize_exit_codes(int *exit_code,
	char ***map_char, t_cubfile *cubfile)
{
	int	char_int_res;

	if ((*exit_code) == 1)
		free_map_char(map_char);
	if ((*exit_code) == 3)
		(*exit_code) = 1;
	if ((*exit_code) == 0)
	{
		char_int_res = char_to_int_map(cubfile, *map_char);
		if (char_int_res == 2)
			free_if_2(map_char, cubfile);
		if (char_int_res == 1)
		{
			(*exit_code) = 1;
			free_map_char(map_char);
		}
	}
	if ((*exit_code) == 0)
		free_map_char(map_char);
}

int	free_updates_char(char **new_var)
{
	free(new_var);
	printf("Error\n");
	printf("realloc failed");
	return (1);
}
