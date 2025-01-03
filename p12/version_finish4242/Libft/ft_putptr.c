/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:50:50 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/21 13:38:52 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printptr(unsigned long nb)
{
	if (nb / 16)
		return (ft_printptr(nb / 16) + ft_printptr(nb % 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar(nb - 10 + 'a');
	return (1);
}

size_t	ft_putptr(void *nb)
{
	if (!nb)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_printptr((unsigned long )nb));
}
