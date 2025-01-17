/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:12 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:26 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	if ((char)c == '\0')
	{
		i = ft_strlen(str);
		return (&str[i]);
	}
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main () {
   const char str[] = ""; 
   const char ch = '\0';
   char *p;
   p = ft_strchr(str, ch);
   printf("String starting from %c is: %s \n", ch, p);
   return 0;
}
*/