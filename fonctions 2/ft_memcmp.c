/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:59:23 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:50:21 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	const char	s1[] = "hello wor1ld";
	const char	s2[] = "hello 2or";
	size_t	n;

	n = sizeof(char) * 12;
	printf("%d", ft_memcmp(s1, s2, n));
	return (0);
}*/

La fonction memcmp est une fonction de la bibliothèque standard en langage C (et d'autres langages de programmation similaires) utilisée pour comparer deux blocs de mémoire pour déterminer s'ils sont égaux ou non. Elle permet de comparer les contenus de deux zones mémoires en vérifiant chaque octet à partir de l'emplacement de début jusqu'à une certaine longueur.

    ptr1 : Un pointeur vers le premier bloc de mémoire à comparer.
    ptr2 : Un pointeur vers le deuxième bloc de mémoire à comparer.
    num : Le nombre d'octets à comparer.
    
La fonction memcmp compare les num premiers octets des deux blocs de mémoire ptr1 et ptr2. Elle renvoie un entier qui indique le résultat de la comparaison :

    Si les deux blocs de mémoire sont égaux, la fonction renvoie 0.
