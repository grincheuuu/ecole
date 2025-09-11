/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:35:34 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 13:39:54 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = 0;
	s = src;
	d = dest;
	while (n--)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			i++;
			return (dest + i);
		}
		s++;
		d++;
		i++;
	}
	return (0);
}
