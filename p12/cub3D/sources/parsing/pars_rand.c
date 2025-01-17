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

void	update_cub(t_cubfile *cubfile)
{
	cubfile->number_of_path++;
	cubfile->condition = 1;
}

int	verif(char *map, t_cubfile *cubfile)
{
	char	**map_char;
	int		fd;

	map_char = init_map_char();
	if (!map_char)
	{
		printf("Error\n");
		printf("error :malloc failed\n");
		return (1);
	}
	fd = open(map, O_RDONLY);
	cubfile->fd = fd;
	if (process_file(fd, cubfile, &map_char) == 1)
		return (1);
	return (0);
}

int	file_exists(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	is_valid_cub_file(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || !filename)
		return (0);
	return (ft_strcmp(&filename[len - 4], ".cub") == 0);
}

int	error_usage(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (!file_exists(argv[1]))
	{
		printf("Error\n");
		printf("Error: The file does not exist \n");
		return (1);
	}
	if (!is_valid_cub_file(argv[1]))
	{
		printf("Error\n");
		printf("Error: the file must have a '.cub' extension \n");
		return (1);
	}
	return (0);
}
