/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:49:35 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/24 19:12:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	ls;
	size_t	td;

	i = 0;
	td = 0;
	ls = ft_strlen(src);
	while (dest[td] != '\0')
		td++;
	if (n == 0)
		return (ls);
	if (n <= td)
		return (ls + n);
	while (i < (n - 1 - td) && (src[i] != '\0'))
	{
		dest[td + i] = src[i];
		i++;
	}
	dest[td + i] = '\0';
	return (td + ls);
}
/*
int	main(void)
{
	const char	src[] = "zoz";
	char		dest[5] = "hello";
	size_t		n;
	size_t		resultat;

	n = 5;
	printf("%s dest1\n", dest);
	resultat = ft_strlcat(dest, src, n);
	printf("dest%s\n", dest);
	printf("%s src, %zu resultat", src, resultat);
	return (0);
}*/
