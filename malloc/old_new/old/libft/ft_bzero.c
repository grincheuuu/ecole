/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:10:40 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/24 18:44:09 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*p;
	int					i;

	i = 0;
	p = (unsigned char *)s;
	while (n > 0)
	{
		p[i] = 0;
		n--;
		i++;
	}
}
/*
int	main(void)
{
	char	str[10] = {0};
	size_t	n;
	size_t	i;

	n = sizeof(char) * 10;
	i = 0;
	ft_bzero(str, n);
	while (i < 10)
	{
		printf("%d ", str[i]);
		i++;
	}
	return (0);
}*/
