/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:41:24 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	l;

	l = strlen(s1) + strlen(s2);
	dest = malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	strcpy(dest, s1);
	strcat(dest, s2);
	return (dest);
}
/*
int	main(void)
{
	char const	s1[] = "hello bonjour";
	char const	s2[] = "123";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/

La fonction ft_strjoin que vous avez fournie est une implémentation personnalisée d'une fonction de concaténation de chaînes en langage C. Elle prend deux chaînes de caractères en entrée (s1 et s2) et les concatène pour former une nouvelle chaîne de caractères. Voici un résumé de son fonctionnement :

    Elle calcule la longueur totale requise pour la nouvelle chaîne résultante en ajoutant les longueurs de s1 et s2.

    Elle alloue de la mémoire dynamiquement pour la nouvelle chaîne résultante en utilisant malloc.

    Si l'allocation de mémoire réussit, elle copie le contenu de s1 dans la nouvelle chaîne, puis ajoute le contenu de s2 à la fin de la nouvelle chaîne en utilisant strcat.

    Elle renvoie un pointeur vers la nouvelle chaîne concaténée.
    
La fonction strcpy recopie le contenu de la chaine src vers la chaine allouée pointée par dest et retourne le pointeur vers la chaine de destination (le caractère nul est inclus dans la copie).
Mais attention: il est nécessaire au préalable de s'être assuré que la taille réservé dans dest est supérieure ou égale à la taille de la chaine pointée par src.

 strcat ajoute à la chaine dest la chaine src. Il est nécessaire d'être sûr d'avoir réservé assez de place dans la chaine dest pour recevoir la chaine src en plus de son contenu. De même que pour strncpy, il existe une variation permettant de limiter la longueur de la chaine globale:

    char *strncat(char *dest, const char *src, size_t n)

strncat() ne recopie que les n premiers octets de src à la fin de dest et ajoute 0 à la fin, 0 n'étant pas pris en compte dans n.
Pour ne pas faire de débordement mémoire, il faut donc que n soit égal à la taille réservée de dest, diminué de strlen(dest) et encore diminué de 1 pour le caractère nul final.



