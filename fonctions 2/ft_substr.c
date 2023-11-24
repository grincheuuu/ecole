/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:27:29 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 12:26:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	l;
	size_t	sub_len;

	l = strlen(s);
	sub_len = len;
	if (s == NULL || len < 0)
		return (NULL);
	if (l <= start)
		return (strdup(""));
	if (start + len >= l)
		sub_len = l - start;
	dest = malloc((sub_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	strncpy(dest, (s + start), sub_len);
	dest[sub_len] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char const	s[] = "hello word";
	unsigned int	start;
	size_t		len;

	start = 6;
	len = 4;
	printf("%s", ft_substr(s, start, len));
	return (0);
}*/

La fonction ft_substr est une fonction personnalisée en langage C qui est utilisée pour extraire une sous-chaîne d'une chaîne de caractères donnée, en spécifiant une position de départ (start) et une longueur maximale (len). La sous-chaîne extraite est ensuite renvoyée sous forme d'une nouvelle chaîne de caractères allouée dynamiquement.

Voici un aperçu du fonctionnement de ft_substr :

    Elle commence par vérifier si la chaîne d'entrée s est nulle ou si la longueur len est négative. Si l'une de ces conditions est vraie, la fonction renvoie un pointeur NULL, indiquant une erreur.

    Elle calcule la longueur totale de la chaîne d'entrée s en utilisant la fonction strlen.

    Ensuite, elle vérifie si la position de départ start est supérieure ou égale à la longueur totale de la chaîne s. Si c'est le cas, elle renvoie une nouvelle chaîne vide, car il n'y a rien à extraire.

    Elle ajuste la valeur de sub_len (la longueur de la sous-chaîne) en fonction de la valeur de len spécifiée et de la longueur totale de s. Si la somme de start et len est supérieure ou égale à la longueur totale de s, elle réduit sub_len pour éviter de dépasser la fin de la chaîne.

    Elle alloue dynamiquement de la mémoire pour la nouvelle chaîne résultante dest en utilisant malloc, en réservant suffisamment d'espace pour sub_len caractères plus un caractère nul '\0'.

    Enfin, elle copie la sous-chaîne de la chaîne d'entrée s (en commençant à la position start et en copiant sub_len caractères) dans la nouvelle chaîne dest, puis ajoute un caractère nul à la fin de dest pour terminer correctement la nouvelle chaîne.

La nouvelle chaîne résultante dest est ensuite renvoyée.
