/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:30 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/21 15:50:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char		*s1;
	char		*s2;
	unsigned int	n;

	s1 = "-5";
	s2 = "1";
	n = 4;
	printf("%d", ft_strncmp(s1, s2, n));
	return (0);
}*/
