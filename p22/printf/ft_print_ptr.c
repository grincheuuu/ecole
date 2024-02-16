/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:43:44 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/13 16:48:05 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_putchar(size_t mod)
{
	char	c;

	c = 0;
	if (mod > 9)
		c = mod + 'a' - 10;
	else
		c = mod + '0';
	write (STDOUT_FILENO, &c, 1);
}

static void	ft_print_hexx(size_t t)
{
	size_t	div;
	size_t	mod;
	char	c;

	div = 0;
	mod = 0;
	c = 0;
	if (t >= 0 && t < 16)
	{
		if (t > 9)
			c = t + 'a' - 10;
		else
			c = t + '0';
		write (STDOUT_FILENO, &c, 1);
	}
	else
	{
		div = t / 16;
		mod = t % 16;
		ft_print_hexx(div);
		ft_putchar(mod);
	}
}

int	ft_print_ptr(unsigned char *p)
{
	size_t	t;
	size_t	z;
	int		count;

	count = 0;
	if (p == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	write(1, "0x", 2);
	t = (size_t)p;
	count = 2;
	z = t;
	if (z == 0)
		count++;
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
