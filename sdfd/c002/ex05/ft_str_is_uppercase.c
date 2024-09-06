/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:25:04 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/16 14:46:42 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0' )
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < 65 || *str > 90)
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
	char	str[] = "HELLOWORLD";

	ft_str_is_uppercase(str);
	return (0);
}*/
