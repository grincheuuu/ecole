/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:23:34 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/23 14:31:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
	write (fd, "\n", 1);
}
/*
int	main(void)
{
	char	s[] = "hello world";
	int	fd;

	fd = 1;
	ft_putendl_fd(s, fd);
}*/
