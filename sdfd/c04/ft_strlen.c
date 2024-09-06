/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:23:59 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/31 15:47:57 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
			signe *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		resultat = resultat * 10 + *str - 48;
		str++;
	}
	return ( resultat * signe);
}

int main(void)
{
	char	str[] =" ---++--123ea";

	printf("%d", ft_atoi(str));
	return (0);
}
