/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:26 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 17:14:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*p;
	int			i;

	i = 0;
	p = NULL;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			p = &str[i];
			return ((char *)p);
		}
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "hello word";
	int	c;
	char	*resultat;

	c = 'e';
	resultat = ft_strrchr(str, c);
	if (resultat != NULL)
	{
		printf("%creussi%s", c, str);
		printf("\n%s", resultat);
	}
	else
		printf("%c,NULL%s", c, str);
	return (0);
}*/

 Cette fonction recherche la dernière occurrence du caractère passé en second paramètre dans la chaîne de caractères spécifiée via le premier paramètre.
la fonction strrchr est très proche de la fonction strchr. La différence réside dans le fait que strchr renvoi la position de la première occurrence du caractère recherché alors que strrchr renvoi la dernière occurrence (recherche par la droite : r signifiant right).
Paramètres

    string : la chaîne de caractères dans laquelle effectuer la recherche.
    searchedChar : le caractère recherché.

Valeur de retour

Soit le caractère recherché est présent dans la chaîne et, dans ce cas, un pointeur sur la dernière occurrence du caractère vous sera retourné. Soit le caractère n'est pas présent dans la chaîne et dans ce cas, le pointeur NULL vous sera renvoyé
