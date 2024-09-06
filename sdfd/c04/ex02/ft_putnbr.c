/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:33:21 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/18 18:51:10 by gschwart         ###   ########.fr       */
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
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		div = nb / 10;
		mod = nb % 10;
		ft_putnbr(div);
		ft_putnbr(mod);
	}
}
/*
int	main(void)
{
	int	nb;

	nb = -2147483648;
	ft_putnbr(nb);
	return (0);
}*/
