/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:51:02 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/19 11:32:46 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*o_dest;

	o_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*src != '\0') && (nb > 0))
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	dest = o_dest;
	return (dest);
}
/*
int main(void)
{
	char	src[] = "salut";
	char	dest[20] = "h2e1lo";
	unsigned int	nb;

	nb = 10;
	ft_strncat(dest, src, nb);
	write(1, dest, 4);
	return (0);
}*/
