/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:51:34 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/16 18:51:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	wrong_spaces(char *line)
{
	int	co;
	int	len;

	co = 0;
	len = ft_strlen(line);
	while (line[co] != '\0')
	{
		if (co > 0 && co < len - 1)
		{
			if (ft_isdigit(line[co - 1]) && line[co] == ' ')
			{
				while (line[co] == ' ')
					co++;
				if (ft_isdigit(line[co]))
					return (1);
			}
		}
		co++;
	}
	return (0);
}

void	all_line_null(char **line)
{
	size_t	co;

	co = 0;
	if (*line == NULL)
		return ;
	while (ft_strlen(*line) - 1 > co)
	{
		if ((*line)[co] != ' ')
			return ;
		co++;
	}
	if (ft_strlen(*line) == co)
		return ;
	free(*line);
	(*line) = (char *)malloc(sizeof(char) * 2);
	(*line)[0] = '\n';
	(*line)[1] = '\0';
}

void	newline_co(char **newline, int *co)
{
	(*newline)[(*co)] = ' ';
	(*co)++;
}

int	size2_path(int i, char **line)
{
	int	size;

	size = 3;
	i = i + 2;
	while ((*line)[i] != '\0' && (*line)[i] == ' ')
		i++;
	while ((*line)[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

void	last_spaces(char **newline, int co)
{
	co = co - 2;
	while ((*newline)[co] == ' ')
		co--;
	(*newline)[co + 1] = '\n';
	(*newline)[co + 2] = '\0';
}
