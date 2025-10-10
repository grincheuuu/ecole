/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:33:58 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/23 14:05:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	char	c;
	int	fd;

	c = 'A';
	fd = open("mon_fichier.txt", O_WRONLY);
	if (fd != -1)
	{
		ft_putchar_fd(c, fd);
		close(fd);
	}
	return (0);
}*/
