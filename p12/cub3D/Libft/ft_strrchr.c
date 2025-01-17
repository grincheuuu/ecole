/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:56 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:35 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned int	i;
	int				x;

	x = 1;
	str = (char *)s;
	i = ft_strlen(str);
	if ((char)c == '\0')
		return (&str[i]);
	while (i != 0)
	{
		if ((char)c == str[i])
			return (&str[i]);
		i--;
	}
	while (x > 0)
	{
		if ((char)c == str[i])
			return (&str[i]);
		x--;
		i--;
	}
	return (NULL);
}
/*
int main()
{
    char str[] = "bonjours";
 
    char chr = 'b';
 
    char* ptr = ft_strrchr(str, chr);
 
    if (ptr) {
        printf("Last occurrence of %c in %s is at index %ld and %s ",
               chr, str, ptr-str , ptr);
    }
    else {
        printf("%c is not present in %s ", chr, str);
    }
    return 0;
}
*/