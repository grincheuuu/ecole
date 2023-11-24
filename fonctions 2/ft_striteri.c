
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:06:33 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/23 12:30:05 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	l;
	unsigned int	i;

	l = strlen(s);
	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	my_function(unsigned int index, char *c)
{
	printf("caractere a l indice %u %c\n", index, *c);
}

int	main(void)
{
	char	s[] = "hello word";

	ft_striteri(s, my_function);
	return (0);
}*/

s: The string on which to iterate.
f: The function to apply to each character.
Return value None
External functs. None
Description Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.

La fonction ft_striteri que vous avez fournie est une fonction personnalisée en langage C qui itère sur une chaîne de caractères (s) tout en appliquant une fonction spécifiée (f) à chaque caractère de la chaîne, en passant l'indice de l'itération et un pointeur vers le caractère actuel à la fonction f.

Voici une description de la fonction ft_striteri :

    s : Un pointeur vers la chaîne de caractères à traiter.
    f : Un pointeur de fonction qui prend deux arguments : un entier sans signe (représentant l'indice de caractère) et un pointeur vers un caractère (char *).

La fonction ft_striteri commence par vérifier si les pointeurs s et f sont valides (non nuls). Si l'un d'entre eux est nul, la fonction se termine immédiatement.

Ensuite, elle itère sur chaque caractère de la chaîne en passant l'indice de caractère et un pointeur vers le caractère actuel à la fonction f. La fonction f peut effectuer n'importe quelle opération sur le caractère à cet indice, ou simplement l'afficher, comme dans votre exemple.

Dans cet exemple, la fonction my_function prend l'indice de caractère et le caractère lui-même en argument, puis elle affiche l'indice et le caractère. L'appel à ft_striteri itère sur la chaîne "hello world" et applique my_function à chaque caractère, ce qui affiche l'indice et le caractère correspondant.

Cette fonction est un exemple de la manière dont vous pouvez itérer sur une chaîne de caractères en C tout en effectuant des opérations sur chaque caractère de manière personnalisée en utilisant une fonction spécifiée. Elle est utile pour diverses opérations de traitement de texte ou de transformation de données dans une chaîne de caractères.




