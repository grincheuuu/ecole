/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:01:47 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/19 11:19:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	char	*o_str;

	o_str = str;
	while (*str != '\0')
	{
		i = 1;
		if (*str >= 'a' && *str <= 'z' && i == 1)
		{
			*str = *str - 32;
			str++;
		}
		else
		{
			while ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') 
				|| (*str >= '0' && *str <= '9'))
			{
				if (*str >= 'A' && *str <= 'Z')
					*str = *str + 32;
				str++;
			}
		}
		str++;
	}
	return (o_str);
}
/*
int main(void)
{
	char	str[] = "heLl1 un toit~zONNe";

	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}*/
