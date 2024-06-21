/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:58:20 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/21 18:59:41 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atol_test(const char *nptr)
{
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
		return (1);
	if (*nptr == '+')
		nptr++;
	if (!(*nptr > 47 && *nptr < 58))
		return (1);
	while (*nptr > 47 && *nptr < 58)
		nptr++;
	if (*nptr != '\0')
		return (1);
	return (0);
}

unsigned long	ft_atoiulong(const char *nptr)
{
	unsigned long		resultat;

	resultat = 0;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
		nptr++;
	while (*nptr > 47 && *nptr < 58)
	{
		resultat *= 10;
		resultat += *nptr - '0';
		nptr++;
	}
	return (resultat);
}

int	ft_atoi(const char *nptr)
{
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
	return (resultat * signe);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		if (*p1 == '\0')
			return (0);
		p1++;
		p2++;
		n--;
	}
	return (0);
}