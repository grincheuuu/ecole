/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_plus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:08:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/23 18:44:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int	ft_strlen(char *env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return (0);
	while (env[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src == NULL)
		return (NULL);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	ft_exe(char **patch, int t, char *argv, char **env)
{
	char	**com;
	char	**thor;

	com = NULL;
	thor = NULL;
	while (patch[t] != NULL)
	{
		thor = ft_split(patch[t], ' ');
		free(patch[t]);
		com = ft_split(argv, ' ');
		if ((access(thor[0], F_OK | X_OK) == 0))
			ft_error(execve(thor[0], com, env), "execve");
		ft_fre(thor);
		ft_fre(com);
		t++;
	}
}
