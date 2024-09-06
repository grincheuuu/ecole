/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:24:56 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/16 14:44:23 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0' )
	{
		if (*str < 97 || *str > 122)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int main(void)
{
	char	str[] = "hello world";

	ft_str_is_lowercase(str);
	return (0);
}*/
