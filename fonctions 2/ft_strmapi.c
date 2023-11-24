/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:53:52 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 15:13:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	f(unsigned int index, char c)
{
	(void)index;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);	
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	char			*dest;
	unsigned int	i;

	l = strlen(s);
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char *)malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < l)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[l] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	*str = "hello";
	char		*resultat;

	resultat = ft_strmapi(str, f);
	printf("%s\n", resultat);
	free(resultat);
	return (0);
}*/

La fonction ft_strmapi semble être une fonction personnalisée en langage C. En général, elle est utilisée pour appliquer une fonction donnée à chaque caractère d'une chaîne de caractères (str) tout en préservant l'indice de caractère. Le résultat de l'application de la fonction est stocké dans une nouvelle chaîne de caractères allouée dynamiquement. Cette fonction est souvent utilisée pour transformer ou modifier une chaîne de caractères en appliquant une opération personnalisée à chaque caractère.

    str : La chaîne de caractères d'entrée sur laquelle vous souhaitez appliquer la fonction f.
    f : Un pointeur de fonction qui prend deux arguments : un entier sans signe (représentant l'indice de caractère) et un caractère (char), et qui renvoie un caractère.

La fonction ft_strmapi itère sur chaque caractère de la chaîne str, applique la fonction f à ce caractère en passant à la fois l'indice de caractère et le caractère lui-même, puis stocke le résultat dans une nouvelle chaîne de caractères allouée dynamiquement. La nouvelle chaîne résultante contient les résultats de l'application de la fonction f à chaque caractère de str.
