/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:35:09 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/13 17:48:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_malloc_error(char **dest, size_t n)
{
	if (dest[n] == NULL)
	{
		while (n > 0)
			free(dest[--n]);
		free(dest);
		return (NULL);
	}
	return (dest);
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
	dest[len] = 0;
	return (dest);
}
