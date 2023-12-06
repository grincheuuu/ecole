/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:45:59 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:49:13 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n > 0)
	{
		if (*p == uc)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "tutorialspoint";
	int	c;
	char	*resultat;
	size_t	n;
	
	c = 'q';
	n = sizeof(char) * strlen(str);
	resultat = ft_memchr(str, c, n);
	printf("charactere %c resultat %s", c, resultat);
	return (0);
}*/
