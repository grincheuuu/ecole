/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:19:07 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/10 14:23:09 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put(int n, int a)
{
	char	c;

	c = '0' + n;
	if (a == 0)
	{
		if (n > 9)
		{
			c = 'a' - 10 + n;
			write (1, &c, 1);
		}
		else
			write (1, &c, 1);
	}
	else
	{
		if (n > 9)
		{
			c = 'A' - 10 + n;
			write (1, &c, 1);
		}
		else
			write (1, &c, 1);
	}
}

static int	ft_count(int m, int nb)
{
	int	count;

	count = 0;
	while (m > 0)
	{
		count++;
		m = m / nb;
	}
	return (count);
}

int	ft_print_hex(int n, int a)
{
	int	nb;
	int	temp;
	int	div;
	int	count;
	int	m;

	temp = 0;
	div = 0;
	nb = 16;
	count = 0;
	m = n;
	if (n >= 0 && n < nb)
		ft_put (n, a);
	else
	{
		temp = n / nb;
		div = n % nb;
		ft_print_hex(temp, a);
		ft_print_hex(div, a);
	}
	count = ft_count(m, nb);
	return (count);
}
/*
int main(void)
{
	int	n = 15;
	char	hex[] = "0123456789abcdef";
	int	a;

	a = 0;
	printf("\n%d", ft_print_hex(n, a));
	return (0);
}*/
