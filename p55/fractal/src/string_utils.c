/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:27 by gschwart          #+#    #+#             */
/*   Updated: 2023/12/18 16:43:22 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		n--;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s != '\0')
	{
		write (fd, s, 1);
		s++;
	}
}

double	atoidouble(char *s)
{
	double	int_part;
	double	nb;
	int		signe;

	int_part = 0;
	signe = 1;
	nb = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
	{
		if ('-' == *s++)
			signe *= -1;
	}
	while (*s != '.' && *s != '\0')
		int_part = (int_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s != '\0')
	{
		nb /= 10;
		int_part = int_part + (*s++ - 48) * nb;
	}
	return (int_part * signe);
}
