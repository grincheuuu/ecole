/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:51:24 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/16 18:51:26 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	size_monospace(char *line)
{
	int	co;

	co = 0;
	while (*line)
	{
		if (*line != ' ')
			co++;
		line++;
	}
	co++;
	return (co);
}

int	cf_exeption(int i, char **newline, int co, char **line)
{
	if ((*line)[i] == 'C' || (*line)[i] == 'F')
	{
		if (wrong_spaces(*line) == 1)
			return (2);
		(*newline) = (char *)malloc((sizeof(char) * size_monospace(*line)));
		if ((*newline) == NULL)
			return (1);
		while ((*line)[i] != '\0')
		{
			if (co == 1)
			{
				(*newline)[co] = ' ';
				co++;
			}
			else if ((*line)[i] != ' ')
			{
				(*newline)[co] = (*line)[i];
				co++;
			}
			i++;
		}
		(*newline)[co - 1] = '\0';
	}
	return (0);
}

void	litv(int *i, int *co, char **newline, char **line)
{
	if ((*co) == 2)
	{
		newline_co(newline, co);
	}
	else if ((*line)[*i] != ' ')
	{
		(*newline)[(*co)] = (*line)[*i];
		(*co)++;
	}
	(*i)++;
}

int	nesw_exeption(int i, char **newline, int co, char **line)
{
	if (((*line)[i] == 'N' && (*line)[i + 1] == 'O')
		|| ((*line)[i] == 'E' && (*line)[i + 1] == 'A')
		|| ((*line)[i] == 'S' && (*line)[i + 1] == 'O')
		|| ((*line)[i] == 'W' && (*line)[i + 1] == 'E'))
	{
		(*newline) = (char *)malloc((sizeof(char)
					* size2_path(i, line)) + 1);
		if ((*newline) == NULL)
			return (1);
		while ((*line)[i] != '\0' && co < 3)
			litv(&i, &co, newline, line);
		(*newline)[co] = '\0';
		while ((*line)[i] == ' ')
			i++;
		while ((*line)[i] != '\0')
		{
			(*newline)[co] = (*line)[i];
			i++;
			co++;
			(*newline)[co] = '\0';
		}
		last_spaces(newline, co);
	}
	return (0);
}

char	*get_rid_of_spaces(char **line)
{
	int		i;
	int		co;
	char	*newline;
	int		result;

	i = 0;
	co = 0;
	newline = NULL;
	if ((*line) == NULL)
		return (NULL);
	while ((*line)[i] == ' ')
		i++;
	result = cf_exeption(i, &newline, co, line);
	if (result == 1)
		return (NULL);
	if (result == 2)
		return (*line);
	co = 0;
	if (nesw_exeption(i, &newline, co, line) == 1)
		return (NULL);
	if (newline == NULL)
		return ((*line));
	free(*line);
	return (newline);
}
