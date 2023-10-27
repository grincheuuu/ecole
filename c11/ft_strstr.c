/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:57 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/16 11:07:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_lenstr(char *str)
{
	int i = 0;
	while(*str)
	{
		str++;
		i++;
	}
	return (i);
}
char *ft_strstr(char *str, char *to_find)
{
	char	*o_tofind;
	int	cpt = 0;
	int	i = ft_lenstr(to_find);

	while(*str != '\0')
	{
		o_tofind = str; 
		while(*str == *to_find)	
		{
			printf("cpt = %d\n",cpt);
			if(cpt == i-1)
			{	
				str = o_tofind;
				return (str);
			}
			str++;
			to_find++;
			cpt++;
		}
		str++;
	}
	return (0);
}

int main(void)
{
	char	to_find[] = "wor";
	char	str[] = "hello world";
	
	printf("%s", ft_strstr(str, to_find));
	return (0);
}
