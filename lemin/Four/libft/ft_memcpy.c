/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:35:51 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 13:39:54 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr;
	const char	*str;

	ptr = dest;
	str = src;
	if (dest == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		*ptr = *str;
		str++;
		ptr++;
		n--;
	}
	return (dest);
}
