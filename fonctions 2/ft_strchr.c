/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:30:30 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:16 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*p;

	p = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			p = str;
			return ((char *)p);
		}
		str++;
	}
	if (*str == (char )c)
	{
		p = str;
		return ((char *)p);
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "hello world";
	int	c;
	char	*resultat;

	c = 'e';
	resultat = ft_strchr(str, c);
	if (resultat != NULL)
	{
		printf("%c%s", c, str);
		printf("%s", resultat);
	}
	else
		printf("%c,NULL%s", c, str);
	return (0);
}*/

La fonction strchr est une fonction de la bibliothèque standard en langage C (et d'autres langages de programmation similaires) qui est utilisée pour rechercher la première occurrence d'un caractère particulier dans une chaîne de caractères (string). Elle renvoie un pointeur vers la première occurrence du caractère dans la chaîne, ou un pointeur NULL si le caractère n'est pas trouvé.

    s : La chaîne de caractères dans laquelle vous souhaitez effectuer la recherche.
    c : Le caractère que vous souhaitez rechercher.

La fonction strchr parcourt la chaîne s à partir du début, caractère par caractère, jusqu'à ce qu'elle trouve la première occurrence du caractère c. Une fois qu'elle a trouvé le caractère, elle renvoie un pointeur vers cet emplacement dans la chaîne. Si le caractère n'est pas trouvé, la fonction renvoie un pointeur NULL.
