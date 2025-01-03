/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:48:31 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:29 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src2;
	size_t	value;

	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dest))
		value = ft_strlen(src) + size;
	else
		value = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	while (dest[i] != '\0')
		i++;
	src2 = 0;
	while (src[src2] != '\0' && i + 1 < size)
	{
		dest[i] = src[src2];
		src2++;
		i++;
	}
	dest[i] = '\0';
	return (value);
}
/*
int main()
{
	char str1[] = "Je suis un test";
	char str2[] = "Hello World";
	ft_strlcat(str1, str2, 50);
	printf("%s", str1);
	return (0);
}
*/
