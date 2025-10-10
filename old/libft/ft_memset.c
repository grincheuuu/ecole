/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:31:04 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 18:26:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			i;

	p = str;
	v = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		p[i] = v;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[20] = {0};
	int	c;
	size_t	n;
	size_t	i;

	c = '0';
	n = sizeof(char) * 20;
	i = 0;
	ft_memset(str, c, n);
	while (i < 10)
	{
		printf("%c ", str[i]);
		i++;
	}
	return (0);
}*/
