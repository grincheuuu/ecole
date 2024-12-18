/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:39:44 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/20 23:39:44 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthex_u(unsigned int nb)
{
	if (nb / 16)
		return (ft_puthex_u(nb / 16) + ft_puthex_u(nb % 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar(nb - 10 + 'A');
	return (1);
}
