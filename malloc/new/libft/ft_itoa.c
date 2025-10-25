/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:04:22 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/26 11:32:28 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnb(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_destgo(char *dest, int n, int len)
{
	if (n == 0)
		dest[0] = '0';
	if (n == -2147483648)
	{
		dest[--len] = '0' + 8;
		n = -214748364;
	}
	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		dest[--len] = '0' + (n % 10);
		n = n / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;

	len = 0;
	len = ft_putnb(n);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	dest = ft_destgo(dest, n, len);
	return (dest);
}
/*
int	main(void)
{
	int	n;

	n = -1456;
	printf("%s", ft_itoa(n));
	return (0);
}*/
