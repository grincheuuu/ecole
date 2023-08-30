/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:11:39 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/16 14:41:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0' )
	{
		if (*str < 65 || (*str > 90 && *str < 97) || *str > 122)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "h1llo word";

	ft_str_is_alpha(str);
	return (0);
}*/
