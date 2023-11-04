/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:44 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 17:43:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_limit(int n, int fd)
{
	write (fd, "-", 1);
	write (fd, "2", 1);
	n = 147483648;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		div;
	int		mod;

	c = 0;
	if (n == -2147483648)
		n = ft_limit(n, fd);
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write (fd, &c, 1);
	}
	else
	{
		div = n / 10;
		mod = n % 10;
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
}
/*
int	main(void)
{
	int	n;
	int	fd;

	n = 124;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}*/
