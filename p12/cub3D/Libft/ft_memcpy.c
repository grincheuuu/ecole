/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:31:36 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 13:32:26 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char			*str1;
	char				*str2;
	size_t				i;

	i = 0;
	str1 = (const char *)src;
	str2 = (char *)dest;
	if ((str1 == NULL) && (str2 == NULL))
		return (NULL);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char str1[] = "Je suis un test";
	char str2[] = "hello World";
	ft_memcpy(str1, str2, sizeof(str2));
	printf("%s",str1);
	return (0);
}
*/
