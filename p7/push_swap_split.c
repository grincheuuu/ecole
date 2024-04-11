/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:56:14 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/28 18:56:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
