/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:38:51 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/19 19:15:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	resultat;

	resultat = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (power > 0)
	{
		resultat *= nb;
		power--;
	}
	return (resultat);
}
/*
int main(void)
{
	int	nb;
	int	power;
	int	resultat;

	nb = 4;
	power = 0;
	resultat = ft_iterative_power(nb, power);
	printf("nombre%d resultat%d", nb, resultat);
	return (0);
}*/
