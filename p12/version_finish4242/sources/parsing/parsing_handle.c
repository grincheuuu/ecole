/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:54:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:05:03 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_no_path(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (print_return_no_path_error(&line, cubfile, &line[3]) == 1)
	{
		free_readline(&line, fd, cubfile);
		free(*map_char);
		return (1);
	}
	cubfile->no_path = ft_strdup(&line[3]);
	if (!cubfile->no_path)
		return (free_path_fail(cubfile, &line, fd, map_char));
	return (0);
}

int	handle_so_path(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (print_return_so_path_error(&line, cubfile, &line[3]) == 1)
	{
		free_readline(&line, fd, cubfile);
		free(*map_char);
		return (1);
	}
	cubfile->so_path = ft_strdup(&line[3]);
	if (!cubfile->so_path)
		return (free_path_fail(cubfile, &line, fd, map_char));
	return (0);
}

int	handle_we_path(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (print_return_we_path_error(&line, cubfile, &line[3]) == 1)
	{
		free_readline(&line, fd, cubfile);
		free(*map_char);
		return (1);
	}
	cubfile->we_path = ft_strdup(&line[3]);
	if (!cubfile->we_path)
		return (free_path_fail(cubfile, &line, fd, map_char));
	return (0);
}

int	handle_ea_path(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (print_return_ea_path_error(&line, cubfile, &line[3]) == 1)
	{
		free_readline(&line, fd, cubfile);
		free(*map_char);
		return (1);
	}
	cubfile->ea_path = ft_strdup(&line[3]);
	if (!cubfile->ea_path)
		return (free_path_fail(cubfile, &line, fd, map_char));
	return (0);
}

int	handle_floor_rgb(char *line, t_cubfile *cubfile, char ***map_char, int fd)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (test_rgb(&line[2]) == 1)
	{
		free_files_rgb(map_char, cubfile, &line, fd);
		return (1);
	}
	if (put_rgb_floor(cubfile, &line[2]) == 1)
	{
		free_files_rgb(map_char, cubfile, &line, fd);
		return (1);
	}
	return (0);
}
