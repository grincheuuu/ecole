/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:35:09 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/26 18:57:25 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_error(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

int	ft_nbparts(char const *s, char c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	t = 0;
	if (s[i])
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			t++;
			i++;
		}
		while (s[i] != c)
		{
			i++;
		}
		j++;
	}
	return (j);
}

char	**ft_l_parts(char **dest, char const *s, char c, int len)
{
	int	b;
	int	i;
	int	t;
	int	g;

	b = 0;
	i = 0;
	t = 0;
	g = 0;
	while (len > 0)
	{
		while (s[i] == c)
		{
			t++;
			i++;
		}
		while (s[i] != c)
			i++;
		dest[g] = (char *)malloc((i - t + 1) * sizeof(char));
		if (dest[g] == NULL)
			return (ft_malloc_error(dest));
		g++;
		len--;
	}
	return (dest);
}

char	**ft_tdest(char	**dest, char const *s, char c, int len)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	while (len > 0)
	{
		t = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			dest[j][t] = s[i];
			i++;
			t++;
		}
		dest[j][t] = '\0';
		j++;
		len--;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_nbparts(s, c);
	dest = (char **)malloc((len + 1) * sizeof(char *));
	if (*dest == NULL)
		return (NULL);
	dest = ft_l_parts(dest, s, c, len);
	dest = ft_tdest(dest, s, c, len);
	dest[len] = NULL;
	return (dest);
}
/*
int	main(void)
{
	char	s[] = "hello world bouh";
	char	c;

	c = 0;
	ft_split(s, c);
	return (0);
}*/
