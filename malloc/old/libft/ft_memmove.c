/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:11:56 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/24 17:20:48 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s)
		return (dest);
	if (d < s || d >= s + n)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[10];
	const char	src[] = "hello";
	size_t	n;

	n = sizeof(src);
	ft_memmove(dest, src, n);
	printf("%s", dest);
	return (0);
}*/
