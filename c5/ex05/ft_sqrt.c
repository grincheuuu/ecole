/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:20:10 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/26 12:04:37 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	if (nb > 2147483647)
		return (0);
	while (i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	int	number;
	int	resultat;

	number = 2147395600;
	resultat = ft_sqrt(number);
	printf("nombre %d resultat %d", number, resultat);
	return (0);
}*/
