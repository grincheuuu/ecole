/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:18:23 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/24 18:10:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if ((dest == NULL) && (src == NULL))
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[20];
	const char	src[] = "bonjour";
	size_t	n;
	
	n = sizeof(src);
	ft_memcpy(dest, src, n);
	printf("%s", dest);
	return (0);
}*/

La fonction memcpy est une fonction de la bibliothèque standard en langage C (et d'autres langages de programmation similaires) qui est utilisée pour copier un bloc de mémoire source vers un bloc de mémoire de destination. Elle permet de copier des données d'une zone mémoire à une autre de manière efficace et rapide.

    dest : Un pointeur vers le bloc de mémoire de destination où vous souhaitez copier les données.
    src : Un pointeur vers le bloc de mémoire source contenant les données que vous souhaitez copier.
    n : Le nombre d'octets à copier du bloc source vers le bloc de destination.

La fonction memcpy copie les n premiers octets du bloc source (src) vers le bloc de destination (dest). Elle est souvent utilisée pour copier des tableaux, des structures, ou des données brutes d'un endroit à un autre en mémoire.

Il est important de noter que la fonction memcpy ne vérifie pas les limites du tableau de destination, il est donc de la responsabilité du programmeur de s'assurer que suffisamment de mémoire est allouée pour le tableau de destination afin d'éviter des dépassements de mémoire (buffer overflows).
