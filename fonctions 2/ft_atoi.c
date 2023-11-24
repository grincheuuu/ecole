/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:38:26 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:40:45 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*endptr;
	int		signe;
	int		resultat;

	signe = 1;
	resultat = 0;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			signe = signe * -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		resultat *= 10;
		resultat += *nptr - '0';
		nptr++;
	}
	if (*nptr != '\0')
		endptr = (char *)nptr;
	return (resultat * signe);
}
/*
int	main(void)
{
	char	str[] = "    -1254";

	printf("%d", ft_atoi(str));
	return (0);
}*/

La fonction atoi (ASCII to Integer) est une fonction couramment utilisée en programmation pour convertir une chaîne de caractères (string) représentant un nombre en une valeur entière (integer). Elle est généralement utilisée pour extraire des nombres entiers à partir de données textuelles, telles que des entrées utilisateur sous forme de chaînes de caractères.
