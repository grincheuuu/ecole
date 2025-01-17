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

int	print_return_no_path_error(char **line, t_cubfile *cubfile,
	char *line2 )
{
	if (test_existence(line2) == 1)
	{
		printf("Error\n");
		printf("error: file invalid\n");
		return (1);
	}
	if (cubfile->no_path != NULL)
	{
		printf("Error\n");
		printf("error: there are two north path\n");
		return (1);
	}
	if (((*line)[ft_strlen(*line) - 1] != 'm')
		|| ((*line)[ft_strlen(*line) - 2] != 'p')
		|| ((*line)[ft_strlen((*line)) - 3] != 'x')
		|| ((*line)[ft_strlen(*line) - 4] != '.'))
	{
		printf("Error\n");
		printf("error: the north file is supposed to be a .xpm\n");
		return (1);
	}
	return (0);
}

int	print_return_so_path_error(char **line, t_cubfile *cubfile,
	char *line2 )
{
	if (test_existence(line2) == 1)
	{
		printf("Error\n");
		printf("error: file invalid\n");
		return (1);
	}
	if (cubfile->so_path != NULL)
	{
		printf("Error\n");
		printf("error: there are two south path\n");
		return (1);
	}
	if (((*line)[ft_strlen(*line) - 1] != 'm')
		|| ((*line)[ft_strlen(*line) - 2] != 'p')
		|| ((*line)[ft_strlen((*line)) - 3] != 'x')
		|| ((*line)[ft_strlen(*line) - 4] != '.'))
	{
		printf("Error\n");
		printf("error: the south file is supposed to be a .xpm\n");
		return (1);
	}
	return (0);
}

int	print_return_we_path_error(char **line, t_cubfile *cubfile,
	char *line2)
{
	if (test_existence(line2) == 1)
	{
		printf("Error\n");
		printf("error: file invalid\n");
		return (1);
	}
	if (cubfile->we_path != NULL)
	{
		printf("Error\n");
		printf("error: there are two west path\n");
		return (1);
	}
	if (((*line)[ft_strlen(*line) - 1] != 'm')
		|| ((*line)[ft_strlen(*line) - 2] != 'p')
		|| ((*line)[ft_strlen((*line)) - 3] != 'x')
		|| ((*line)[ft_strlen(*line) - 4] != '.'))
	{
		printf("Error\n");
		printf("error: the west file is supposed to be a .xpm\n");
		return (1);
	}
	return (0);
}

int	print_return_ea_path_error(char **line, t_cubfile *cubfile,
	char *line2 )
{
	if (test_existence(line2) == 1)
	{
		printf("Error\n");
		printf("error: file invalid\n");
		return (1);
	}
	if (cubfile->ea_path != NULL)
	{
		printf("Error\n");
		printf("error: there are two east path\n");
		return (1);
	}
	if (((*line)[ft_strlen(*line) - 1] != 'm')
		|| ((*line)[ft_strlen(*line) - 2] != 'p')
		|| ((*line)[ft_strlen((*line)) - 3] != 'x')
		|| ((*line)[ft_strlen(*line) - 4] != '.'))
	{
		printf("Error\n");
		printf("error: the east file is supposed to be a .xpm\n");
		return (1);
	}
	return (0);
}
