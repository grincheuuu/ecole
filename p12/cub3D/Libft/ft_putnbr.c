/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:07 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/21 12:32:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printnbr(long nb)
{
	if (nb / 10)
		return (ft_printnbr(nb / 10) + ft_printnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_putnbr(int nb)
{
	long	x;

	x = nb;
	if (x == -2147483648)
		return (ft_putstr("-2147483648"));
	if (x < 0)
	{
		x = -x;
		return (ft_putchar('-') + ft_printnbr(x));
	}
	else
		return (ft_printnbr(x));
}
