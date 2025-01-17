/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:41 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/21 12:30:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putunbr(unsigned int nb)
{
	if (nb / 10)
		return (ft_putunbr(nb / 10) + ft_putunbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}
