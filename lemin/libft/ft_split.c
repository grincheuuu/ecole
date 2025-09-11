/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:36:25 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 15:31:50 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mktab(char const *s, char c, char **tab)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	j = 0;
	while (s[a] != '\0')
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
		while (s[a] != '\0' && s[a] != c)
			tab[i][j++] = s[a++];
		if (j != 0)
			tab[i++][j] = '\0';
		j = 0;
	}
	tab[i] = 0;
	return (tab);
}

static int	size(char const *s, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		size++;
		while (s[i] == c && s[i])
			i++;
	}
	return (size);
}

static char	**ft_free(char **tab, int i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		k;

	if (!s)
		return (0);
	i = 0;
	a = 0;
	tab = malloc(sizeof(char *) * (size(s, c) + 1));
	if (tab == NULL)
		return (0);
	while (a < size(s, c))
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0' && s[i++] != '\0')
			k++;
		tab[a] = malloc(sizeof(char) * (k + 1));
		if (tab[a] == NULL)
			return (ft_free(tab, a));
		a++;
	}
	return (mktab(s, c, tab));
}
