/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:11:54 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/23 14:21:58 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}
/*
int	main(void)
{
	int	fd;
	char	s[] = "hello, World";

	fd = 1;
	ft_putstr_fd(s, fd);
	return (0);
}*/
