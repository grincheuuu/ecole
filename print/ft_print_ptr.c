/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:43:44 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/10 15:40:58 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hexx(long long int t)
{
	unsigned long long int	div;
	unsigned long long int	mod;
	char					c;

	div = 0;
	mod = 0;
	c = 0;
	if (t >= 0 && t < 16)
	{
		if (t > 9)
			c = t + 'a' - 10;
		else
			c = t + '0';
		write (1, &c, 1);
	}
	else
	{
		div = t / 16;
		mod = t % 16;
		ft_print_hexx(div);
		ft_print_hexx(mod);
	}
}

int	ft_print_ptr(void *p)
{
	unsigned long long int	t;
	long int				z;
	int						count;

	if (p == NULL)
	{
		write (1, "NIL", 3);
		return (3);
	}
	write (1, "oX", 2);
	t = (unsigned long long int)p;
	count = 2;
	z = t;
	while (z > 0)
	{
		count++;
		z /= 16;
	}
	ft_print_hexx(t);
	return (count);
}
/*
int	main(void)
{
	int	c;
	int	*p;
	char	hex [] = "0123456789abcdef";

	c = 15;
	p = &c;
	printf("\n%d", ft_print_ptr(p));
	printf("\n%p", p);
	return (0);
}*/
