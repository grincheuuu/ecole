/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:56:17 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/03 01:56:17 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_oskour(char **tab, char const *s, char sep)
{
	char		**tab1;
	char const	*tmp;

	tmp = s;
	tab1 = tab;
	while (*tmp)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*tmp && *tmp != sep)
			tmp++;
		if (*tmp == sep || tmp > s)
		{
			*tab1 = ft_substr(s, 0, tmp - s);
			s = tmp;
			tab1++;
		}
	}
	*tab1 = NULL;
}

static int	ft_worlen(char const *s, char sep)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			i++;
		while (*s && *s != sep)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;

	if (!s)
		return (NULL);
	size = ft_worlen(s, c);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	ft_oskour(str, s, c);
	return (str);
}
