/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:06:33 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/07 13:49:55 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	l;
	unsigned int	i;

	l = ft_strlen(s);
	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	my_function(unsigned int index, char *c)
{
	printf("caractere a l indice %u %c\n", index, *c);
}

int	main(void)
{
	char	s[] = "hello word";

	ft_striteri(s, my_function);
	return (0);
}*/
