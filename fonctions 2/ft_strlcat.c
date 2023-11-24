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
	ls = strlen(src);
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

La fonction ft_strlcat que vous avez fournie semble être une implémentation personnalisée de la fonction strlcat, qui est utilisée pour concaténer des chaînes de caractères en garantissant que la longueur totale ne dépasse pas un certain nombre d'octets (n). Cette fonction est couramment utilisée dans le contexte de la sécurité, notamment pour éviter les débordements de tampon (buffer overflow).

Voici un résumé du fonctionnement de ft_strlcat :

    Elle prend en entrée une chaîne de destination (dest), une chaîne source (src) et un nombre maximum d'octets (n) qui peut être utilisé pour la concaténation.

    Elle parcourt la chaîne de destination jusqu'à la fin (c'est-à-dire jusqu'à ce qu'elle atteigne le caractère nul '\0' ou jusqu'à ce que la longueur totale atteigne n).

    Elle calcule la longueur de la chaîne source (ls) et vérifie plusieurs conditions :
        Si n est égal à zéro, elle renvoie simplement ls, car il n'y a aucune place pour concaténer.
        Si n est inférieur ou égal à la longueur actuelle de dest (td), elle renvoie ls + n, car n est utilisé en entier pour la concaténation.
        Sinon, elle concatène autant de caractères de la chaîne source que possible dans dest, en veillant à ne pas dépasser n - 1 - td caractères.

    Elle renvoie la longueur totale de la chaîne concaténée (c'est-à-dire td + ls).
