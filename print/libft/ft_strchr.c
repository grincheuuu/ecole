/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:30:30 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:16 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*p;

	p = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			p = str;
			return ((char *)p);
		}
		str++;
	}
	if (*str == (char )c)
	{
		p = str;
		return ((char *)p);
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "hello world";
	int	c;
	char	*resultat;

	c = 'e';
	resultat = ft_strchr(str, c);
	if (resultat != NULL)
	{
		printf("%c%s", c, str);
		printf("%s", resultat);
	}
	else
		printf("%c,NULL%s", c, str);
	return (0);
}*/
