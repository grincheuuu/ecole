/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:44:23 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/16 18:30:28 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	while (*str != '\0' )
	{
		if (*str <= 31 || *str == 127)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main (void)
{
	char	str[] = "\n";

	ft_str_is_printable(str);
	return (0);
}*/
