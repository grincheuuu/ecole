/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:41:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/13 13:43:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(char *env, char *str, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < nb)
	{
		if (env[i] != str[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	ft_strlenn(char *env, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i] == str[i])
	{
		i++;
	}
	while (env[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strcpyy(char *env, char *dest, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i] == str[i])
	{
		i++;
	}
	while (env[i] != '\0')
	{
		dest[j] = env[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	if (dest == NULL)
		return (0);
	if (n == 0)
		return (l);
	while ((i < (n - 1)) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (l);
}

size_t	ft_nbparts(char const *s, char c)
{
	size_t	nb;
	int		newstr;

	nb = 0;
	newstr = 0;
	while (*s)
	{
		if (*s != c && newstr == 0)
		{
			newstr = 1;
			nb++;
		}
		else if (*s == c)
			newstr = 0;
		s++;
	}
	return (nb);
}
