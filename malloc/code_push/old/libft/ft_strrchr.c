/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:26 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 17:14:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*p;
	int			i;

	i = 0;
	p = NULL;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			p = &str[i];
			return ((char *)p);
		}
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "hello word";
	int	c;
	char	*resultat;

	c = 'e';
	resultat = ft_strrchr(str, c);
	if (resultat != NULL)
	{
		printf("%creussi%s", c, str);
		printf("\n%s", resultat);
	}
	else
		printf("%c,NULL%s", c, str);
	return (0);
}*/
