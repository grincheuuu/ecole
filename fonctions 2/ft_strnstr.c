/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:28:59 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 11:18:51 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	big[] = "1hello 2Bon 2Bonjour";
	const char	little[] = "2Bonjour";
	size_t		len;

	len = 8;
	printf("%s ", ft_strnstr(big, little, len));
	return (0);
}*/

Le code que vous avez fourni implémente la fonction ft_strnstr, qui est une version personnalisée de la fonction strnstr. La fonction ft_strnstr est utilisée pour rechercher la première occurrence d'une sous-chaîne (little) dans une chaîne principale (big), en spécifiant une limite de taille (len) pour la recherche.

Voici un aperçu du fonctionnement de ft_strnstr :

    Elle commence par vérifier si la sous-chaîne little est vide (c'est-à-dire si son premier caractère est le caractère nul '\0'). Si c'est le cas, elle renvoie un pointeur vers la chaîne principale big, car une sous-chaîne vide est considérée comme trouvée partout dans big.

    Ensuite, elle itère sur chaque caractère de la chaîne principale big jusqu'à ce qu'elle atteigne la fin de la chaîne principale ou la limite de taille spécifiée len.

    Pour chaque caractère de big, elle commence une autre boucle pour vérifier si la sous-chaîne little correspond à partir de cet emplacement. Elle compare les caractères un par un jusqu'à ce qu'une différence soit trouvée ou que la fin de little soit atteinte.

    Si tous les caractères de little correspondent à partir de l'emplacement actuel dans big, elle renvoie un pointeur vers le début de l'occurrence de little dans big.

    Si la fin de la limite de taille len est atteinte dans big sans avoir trouvé little, ou si une différence est trouvée lors de la comparaison, elle passe à l'emplacement suivant dans big et répète le processus.

    Si little n'est pas trouvé dans big dans les limites de la taille len, la fonction renvoie un pointeur NULL pour indiquer que la sous-chaîne n'a pas été trouvée.
