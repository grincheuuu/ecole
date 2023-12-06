/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:51:01 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/13 14:32:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_p(int m)
{
	char	c;

	c = 0;
	c = m + '0';
	write (STDOUT_FILENO, &c, 1);
}

static size_t	ft_lenint(int m)
{
	size_t	count;

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

int	ft_limits(int n)
{
	(void)n;
	write (STDOUT_FILENO, "-2147483648", 11);
	return (11);
}

int	ft_print_int(int n)
{
	int			div;
	int			mod;
	int			len;

	if (n == -2147483648)
		return (ft_limits(n));
	len = ft_lenint(n);
	div = 0;
	mod = 0;
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n = n * -1;
	}
	if (n >= 0 && n <= 9)
		ft_p(n);
	else if (n > 9)
	{
		div = n / 10;
		mod = n % 10;
		ft_print_int(div);
		ft_p(mod);
	}
	return (len);
}
