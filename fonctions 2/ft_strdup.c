/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:01:52 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	src[] = "salut hello";

	printf("%s", ft_strdup(src));
	return (0);
}*/

La fonction strdup n'est pas une fonction standard du langage C, mais elle est présente dans certaines bibliothèques C standard et dans des bibliothèques tierces. Elle est souvent utilisée pour allouer de la mémoire dynamique pour une copie d'une chaîne de caractères (string) existante, puis copier le contenu de la chaîne source dans la nouvelle mémoire allouée.

    str : La chaîne de caractères que vous souhaitez copier.

La fonction strdup effectue deux opérations principales :

    Alloue dynamiquement de la mémoire pour une nouvelle chaîne de caractères ayant la même longueur que la chaîne source str (en utilisant malloc ou une fonction similaire).
    Copie le contenu de str dans la nouvelle mémoire allouée.

Elle renvoie un pointeur vers la nouvelle chaîne de caractères, qui est une copie de la chaîne source.


