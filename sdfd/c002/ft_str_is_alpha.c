/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:09:35 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/31 12:53:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*o_str;

	o_str = str;
	while (*str != '\0')
	{
		while (*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
	str = o_str;
	return (str);
}

int main (void)
{
	char	str[] = "hel  lo";

	printf("%s", ft_strupcase(str));
	return (0);
}
