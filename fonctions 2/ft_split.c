/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:35:09 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/06 14:15:57 by gschwart         ###   ########.fr       */
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
			newstr = 1;                     fgfdgds fgfdg fgfdgfds fgfdg 
			nb++;                               1  0  1   0  1    0  1
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
	if (!dest[n])
	{
		while (n > 0)
		{
			free(dest[n--]);
		}
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
	dest[len] = 0;
	return (dest);
}

La fonction split n'est pas une fonction standard du langage C, mais elle est couramment utilisée dans de nombreuses bibliothèques ou implémentations personnalisées. Elle est utilisée pour diviser une chaîne de caractères en plusieurs sous-chaînes (mots ou éléments) en fonction d'un délimiteur spécifié. Les sous-chaînes résultantes sont généralement stockées dans un tableau ou une structure de données appropriée.

    str : La chaîne de caractères à diviser.
    delimiter : Le caractère délimiteur qui spécifie où la division doit avoir lieu.

La fonction de division parcourt la chaîne str, recherche le caractère delimiter et crée de nouvelles sous-chaînes à chaque occurrence de ce caractère. Ces sous-chaînes sont généralement stockées dans un tableau de pointeurs vers des chaînes de caractères (char **) ou une autre structure de données, et elles sont terminées par un caractère nul '\0'.
