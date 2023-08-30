/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:56:13 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/20 17:35:26 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	signe;
	int	resultat;

	signe = 1;
	resultat = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			signe = signe * -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		resultat *= 10;
		resultat += *str - '0';
		str++;
	}
	return (resultat * signe);
}
/*
int main (void)
{
	char	str[] = " +----124569qw";
	
	printf("%d",ft_atoi(str));
	return (0);
}*/
