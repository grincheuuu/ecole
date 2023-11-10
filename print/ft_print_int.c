/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:51:01 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/10 16:57:12 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_p(int m)
{
	char	c;

	c = 0;
	c = m + '0';
	write (1, &c, 1);
}

static int	ft_lenint(long int m)
{
	int	count;

	count = 0;
	if (m == 0)
		return (1);
	if (m < 0)
	{
		m = m * -1;
		count++;
	}
	while (m > 0)
	{
		count++;
		m = m / 10;
	}
	return (count);
}

int	ft_print_int(int n)
{
	long int	m;
	int			div;
	int			mod;
	int			len;

	m = (long int)n;
	len = ft_lenint(m);
	div = 0;
	mod = 0;
	if (m < 0)
	{
		write(1, "-", 1);
		m = m * -1;
	}
	if (m > 0 && m < 9)
		ft_p(m);
	else
	{
		div = m / 10;
		mod = m % 10;
		ft_print_int(div);
		ft_print_int(mod);
	}
	return (len);
}
