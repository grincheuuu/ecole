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

int	ft_echo(char **str)
{
	int	g;
	int	i;
	int	t;

	i = 1;
	t = 0;
	g = ft_search_option_echo(str);
	while (i < g)
		i++;
	if (g != 0)
	{
		while (str[i] != NULL)
		{
			if (t == 1)
			{
				write(1, " ", 1);
				t = 0;
			}
			ft_putstr_fd(str[i], 1);
			t = 1;
			i++;
		}
	}
	ft_space(str);
	return (0);
}

void	ft_space(char **option)
{
	int	i;

	i = 0;
	if (option[1] == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	else if (option[1][0] != '-' || option[1][1] != 'n')
	{
		write(1, "\n", 1);
		return ;
	}
	i++;
	while (option[1][i] != '\0')
	{
		if (option[1][i] != 'n')
		{
			write(1, "\n", 1);
			break ;
		}
		i++;
	}
}

int	ft_search_option_echo(char **option)
{
	int	i;
	int	j;

	j = 1;
	if (option[1] != NULL && option[1][0] == '\0')
		return (1);
	while (option[j] != NULL)
	{
		i = 0;
		while (option[j][i] != '\0')
		{
			if ((option[j][0] == '-' && option[j][1] != 'n'))
				return (j);
			if ((option[j][0] != '-' && option[j][1] != 'n') || (i > 0
					&& option[j][i] != 'n'))
			{
				return (j);
			}
			i++;
		}
		j++;
	}
	return (0);
}

char	*ft_old_pwd(void)
{
	char	*buffer;
	size_t	size;

	size = 1024;
	if (size <= 0)
		return (NULL);
	buffer = malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (getcwd(buffer, size) == NULL)
	{
		write(2, "Cannot get current working directory path\n", 43);
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	ft_only_cd(t_pointer **pointera, char *var)
{
	t_list	*temp;
	char	*zoz;
	int		i;

	i = 0;
	zoz = NULL;
	temp = (*pointera)->first;
	while (temp != NULL)
	{
		if (ft_strncmp(var, temp->str, 4) == 0)
		{
			zoz = ft_strdup(temp->str + 5);
			ft_cd(zoz, pointera);
			free(zoz);
			return ;
		}
		temp = temp->next;
		i++;
	}
	return ;
}
