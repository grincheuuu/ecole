/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:56:04 by pmoulin           #+#    #+#             */
/*   Updated: 2023/08/14 21:23:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	div;
	int	mod;

	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;

	}
	else if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else if (nb < 0) //si le nombre est negatif
	{
		ft_putchar('-'); //ont met un moin 
		ft_putnbr(nb * (-1)); // ont met le nombre au positif
	}
	else // affiche les chiffres du nombre grace a la recursion un par un .
	{ // si la fonction a plus de deux nombres appelle ft putchar 
		div = nb / 10;
		mod = nb % 10;
		ft_putnbr(div);
		ft_putnbr(mod);
	}
}

int	main(void)
{
	ft_putnbr(-445354541);
	return (0);
}
