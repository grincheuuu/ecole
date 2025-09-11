/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:35:39 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 13:56:27 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		val;

	val = (unsigned char)c;
	str = s;
	while (n--)
	{
		if (*str == val)
			return ((void *) str);
		str++;
	}
	return ((void *) NULL);
}
