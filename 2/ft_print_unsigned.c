/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:36:48 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/13 14:41:51 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_count(unsigned int j)
{
	int	i;

	i = 0;
	if (j == 0)
		return (1);
	while (j > 0)
	{
		i++;
		j = j / 10;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int a)
{
	unsigned int	j;
	int				c;
	int				i;
	int				div;
	int				mod;

	j = a;
	i = 0;
	div = 0;
	mod = 0;
	if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write (1, &c, 1);
	}
	else
	{
		div = a / 10;
		mod = a % 10;
		ft_print_unsigned(div);
		ft_print_unsigned(mod);
	}
	i = ft_count(j);
	return (i);
}
/*
int	main(void)
{
	unsigned int	a;

	a = 158;
	printf("\n%d", ft_print_unsigned(a));
	return (0);
}*/
