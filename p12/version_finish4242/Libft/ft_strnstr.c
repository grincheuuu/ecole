/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:48:51 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:34 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *s2, size_t len)
{
	size_t	pos;

	if (*s2 == '\0')
		return ((char *)str);
	pos = ft_strlen((char *)s2);
	while (*str != '\0' && len-- >= pos)
	{
		if (*str == *s2 && ft_memcmp(str, s2, pos) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
