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
La fonction strlcpy n'est pas une fonction standard du langage C, mais elle est une variante de la fonction strncpy. Elle est utilisée pour copier une chaîne source dans une chaîne de destination en spécifiant une limite de taille maximale. Cela est couramment utilisé pour éviter les débordements de tampon (buffer overflow) en garantissant que la copie ne dépasse pas une certaine taille.
    dest : Un pointeur vers la chaîne de destination où la copie sera effectuée.
    src : Un pointeur vers la chaîne source qui doit être copiée.
    size : La taille maximale de la chaîne de destination, c'est-à-dire le nombre maximum d'octets que vous souhaitez copier.

La fonction strlcpy copie la chaîne source (src) dans la chaîne de destination (dest) jusqu'à ce qu'elle atteigne la taille maximale spécifiée (size), ou jusqu'à la fin de la chaîne source, en veillant à ajouter un caractère nul ('\0') à la fin de la chaîne de destination. Le résultat de la fonction est le nombre d'octets nécessaires pour stocker la chaîne source, même si la copie a été tronquée pour tenir dans la taille maximale.

Il est à noter que strlcpy est plus sécurisée que la fonction strncpy, car elle renvoie le nombre d'octets nécessaires pour stocker la chaîne source, ce qui permet de détecter si la copie a été tronquée. Cela aide les programmeurs à prendre des décisions appropriées en cas de troncature. Cependant, strlcpy n'est pas une fonction standard du langage C, mais elle est souvent implémentée dans des bibliothèques tierces ou des systèmes Unix-like pour améliorer la sécurité des opérations de copie de chaînes.
