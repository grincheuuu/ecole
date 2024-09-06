/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:48:57 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/16 20:53:16 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*o_dest;
	unsigned int	osize;

	o_dest = dest;
	while (*dest != '\0')
	{
		size = size + 1;
		dest++;
	}
	osize = size;
	dest = o_dest;
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = '\0';
	return (osize);
}
/*
int main(void)
{
	char	src[] = "hello";
	char	dest[20];
	unsigned int	size;
	
	size = 0;
	ft_strlcpy(dest, src, size);
	return (0);
}*/
