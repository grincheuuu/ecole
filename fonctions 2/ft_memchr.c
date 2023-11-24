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

La fonction memchr est une fonction de la bibliothèque standard du langage C (et d'autres langages de programmation similaires) qui est utilisée pour rechercher la première occurrence d'un octet particulier dans un bloc de mémoire. Elle est généralement utilisée pour effectuer des recherches dans des données brutes, telles que des tableaux de caractères, et pour trouver un caractère ou un octet spécifique.

    s : Un pointeur vers le bloc de mémoire dans lequel vous souhaitez effectuer la recherche.
    c : L'octet que vous souhaitez rechercher.
    n : Le nombre d'octets à rechercher dans le bloc de mémoire.

La fonction memchr parcourt le bloc de mémoire pointé par s sur une longueur de n octets et cherche la première occurrence de l'octet c. Si l'octet est trouvé, la fonction renvoie un pointeur vers l'endroit où il a été trouvé dans le bloc de mémoire. Si l'octet n'est pas trouvé, la fonction renvoie un pointeur NULL.
