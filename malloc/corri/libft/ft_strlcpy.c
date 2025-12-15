/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:01:49 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/24 18:01:40 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	const char	src[] = "hello word";
	char		dest[10];
	size_t		n;
	int			resultat;

	n = 10;
	resultat = ft_strlcpy(dest, src, n);
	printf("%s dest , %s src", dest, src);
	printf("\n %d l", resultat);
	return (0);
}*/
