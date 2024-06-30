/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:59:31 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/19 19:16:18 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
int main(void)
{
	int	nb;
	int	power;
	int	resultat;

	nb = 0;
	power = 0;
	resultat = ft_recursive_power(nb, power);
	printf("nombre %d power%d resultat%d", nb , power, resultat);
	return (0);
}*/
