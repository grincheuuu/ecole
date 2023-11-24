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

La fonction memmove est une fonction de la bibliothèque standard en langage C (et d'autres langages de programmation similaires) utilisée pour copier un bloc de mémoire source vers un bloc de mémoire de destination, tout en gérant correctement les cas où les deux blocs se chevauchent. Contrairement à la fonction memcpy, memmove est conçue pour garantir une copie correcte des données même lorsque les zones source et destination se superposent.

    dest : Un pointeur vers le bloc de mémoire de destination où vous souhaitez copier les données.
    src : Un pointeur vers le bloc de mémoire source contenant les données que vous souhaitez copier.
    n : Le nombre d'octets à copier du bloc source vers le bloc de destination.

La fonction memmove copie les n premiers octets du bloc source (src) vers le bloc de destination (dest), tout en garantissant que la copie se fera correctement même si les deux blocs de mémoire se chevauchent.
