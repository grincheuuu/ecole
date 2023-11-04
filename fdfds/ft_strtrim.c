/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:24:04 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_iss(char const *s1, char const *set)
{
	int	tisspace;
	int	i;

	i = 0;
	tisspace = 0;
	while (s1[i] != '\0' && is_in_set(s1[i], set) != 0)
	{
		tisspace++;
		i++;
	}
	return (tisspace);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		tisspace;
	int		endisspace;
	int		l;

	i = 0;
	l = strlen(s1);
	tisspace = ft_iss(s1, set);
	endisspace = 0;
	while (s1[l - 1] != tisspace && is_in_set(s1[l - 1], set) != 0)
	{
		endisspace++;
		l--;
	}
	if ((l - tisspace) <= 0)
		return (strdup(""));
	dest = malloc((l - tisspace + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	strncpy(dest, &s1[tisspace], (l - tisspace));
	dest[l - tisspace] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char const	s1[] = "  hello12world  ";
	char const	set[] = "  ";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
