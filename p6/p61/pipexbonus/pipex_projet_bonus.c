/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_projet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:45:07 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/13 13:45:42 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_fre(char **patch)
{
	int	i;

	i = 0;
	while (patch[i] != NULL)
	{
		free(patch[i]);
		i++;
	}
	free(patch);
}

size_t	ft_count_chr(char const *s, char c)
{
	size_t	twolen;

	twolen = 0;
	while (*s && *s++ != c)
	{
		twolen++;
	}
	return (twolen);
}

void	ft_malloc_error(char **dest, size_t n)
{
	if (dest[n] == NULL)
	{
		printf("NULL");
		while (n > 0)
			free(dest[--n]);
		free(dest);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	n;
	size_t	len;
	size_t	twolen;

	if (!s)
		return (0);
	len = ft_nbparts(s, c);
	dest = (char **)malloc((len + 1) * sizeof(char *));
	if (!dest)
		return (0);
	n = 0;
	while (n < len)
	{
		while (*s == c)
			s++;
		twolen = ft_count_chr(s, c);
		dest[n] = (char *)malloc(sizeof(char) * (twolen + 1));
		ft_malloc_error(dest, n);
		ft_strlcpy(dest[n], (char *)s, twolen + 1);
		s = s + twolen;
		n++;
	}
	dest[len] = NULL;
	return (dest);
}

char	**ft_path(char **env)
{
	char	*dest;
	char	**result;
	int		i;
	int		l;

	i = 0;
	l = 0;
	result = NULL;
	dest = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			l = ft_strlenn(env[i], "PATH=");
			dest = malloc(sizeof(char) * (l + 1));
			if (dest == NULL)
				return (NULL);
			dest = ft_strcpyy(env[i], dest, "PATH=");
			break ;
		}
		i++;
	}
	result = ft_split(dest, ':');
	free(dest);
	return (result);
}
