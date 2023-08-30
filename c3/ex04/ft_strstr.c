/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:57 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/20 13:44:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*o_str;
	char	*oo_tofind;

	if (*to_find == '\0')
		return (str);
	oo_tofind = to_find;
	while (*str != '\0')
	{
		oo_tofind = to_find;
		if (*str == *to_find)
		{
			o_str = str;
			while (*o_str != '\0' && *oo_tofind != '\0' && *o_str == *oo_tofind)
			{
				o_str++;
				oo_tofind++;
			}
			if (*oo_tofind == '\0')
				return (str);
		}
		str++;
	}
	return (NULL);
}
/*
int main(void)
{
	char	to_find[] = "lo";
	char	str[] = "hello world";
	
	printf("%s", ft_strstr(str, to_find));
	return (0);
}*/
