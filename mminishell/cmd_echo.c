/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:43:40 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/24 16:43:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *str)
{
	char **option;
	int	g;
	int	i;

	i = 0;
	option = ft_split(str, ' ');
	g = ft_search_option_echo(option);
	if (option[1] != NULL)
	{
		while (i < g)
			i++;
		while (option[i] != NULL)
		{
			ft_putstr_fd(option[i], 1);
			i++;
		}
	}
	if (g >= 2 || g == 0)
		write (1, "\n", 1);
	ft_fre(option);
}

int	ft_search_option_echo(char **option)
{
	int	i;
	int	j;

	j = 1;
	while (option[j] != NULL)
	{
		i = 0;

		while (option[j][i] != '\0')
		{
			if ((i == 0 && option[j][i] != '-') || (i > 0 && option[j][i] != 'n'))
			{
				return (j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
