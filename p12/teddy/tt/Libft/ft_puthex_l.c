/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:50:43 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/21 12:27:34 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthex_l(unsigned int nb)
{
	if (nb / 16)
		return (ft_puthex_l(nb / 16) + ft_puthex_l(nb % 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar(nb - 10 + 'a');
	return (1);
}
