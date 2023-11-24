/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:24:04 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_iss(char const *s1, char const *set)
{
	int	tisspace;
	int	i;

	i = 0;
	tisspace = 0;
	while (s1[i] != '\0' && is_in_set(s1[i], set) != 0)
	{
		tisspace++;
		i++;
	}
	return (tisspace);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		tisspace;
	int		endisspace;
	int		l;

	i = 0;
	l = strlen(s1);
	tisspace = ft_iss(s1, set);
	endisspace = 0;
	while (s1[l - 1] != tisspace && is_in_set(s1[l - 1], set) != 0)
	{
		endisspace++;
		l--;
	}
	if ((l - tisspace) <= 0)
		return (strdup(""));
	dest = malloc((l - tisspace + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	strncpy(dest, &s1[tisspace], (l - tisspace));
	dest[l - tisspace] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char const	s1[] = "  hello12world  ";
	char const	set[] = "  ";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/

La fonction ft_strtrim est une fonction personnalisée en langage C qui est couramment utilisée pour supprimer les caractères spécifiés (souvent des espaces) du début et de la fin d'une chaîne de caractères. Cette fonction crée une nouvelle chaîne résultante sans les caractères de suppression.

    s : La chaîne de caractères d'entrée que vous souhaitez traiter.
    set : La chaîne de caractères contenant les caractères à supprimer du début et de la fin de s.

La fonction ft_strtrim commence par supprimer les caractères spécifiés dans set du début de la chaîne s, puis elle supprime les caractères spécifiés du même ensemble du bout de la chaîne s. Le résultat est une nouvelle chaîne de caractères allouée dynamiquement, qui est la version "élaguée" de la chaîne d'origine.

La fonction strdup est une fonction standard du langage C, définie dans la bibliothèque standard du C (généralement string.h). Elle est utilisée pour dupliquer (copier) une chaîne de caractères existante dans une nouvelle zone de mémoire allouée dynamiquement. Cela crée une copie identique de la chaîne d'origine.
    s : La chaîne de caractères que vous souhaitez dupliquer.

La fonction strdup alloue dynamiquement de la mémoire pour une nouvelle chaîne de caractères qui est une copie de la chaîne s spécifiée. Ensuite, elle copie le contenu de s dans cette nouvelle zone de mémoire allouée et renvoie un pointeur vers cette nouvelle chaîne de caractères.

Il est important de noter que la mémoire allouée dynamiquement pour la copie doit être libérée manuellement lorsque vous avez terminé de l'utiliser en appelant la fonction free pour éviter les fuites de mémoire.

 strncpy() prend les mêmes arguments que strcpy() plus n, le nombre maximal d'octets à recopier.

Mais, là encore, attention car strncpy() recopie au plus n caractères sans pour autant tester que le dernier caractère copié est bien NULL. Il est donc nécessaire de s'assurer après un strncpy() que le dernier caractère est bien nul: 
