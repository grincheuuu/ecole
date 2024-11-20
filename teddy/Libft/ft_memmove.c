/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:45:41 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 13:07:07 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*decre(char *str2, char *temp, size_t n)
{
	int		j;

	j = n - 1;
	while (j >= 0)
	{
		str2[j] = temp[j];
		j--;
	}
	return (str2);
}

void	*incre(char *str2, char *temp, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		str2[i] = temp[i];
		i++;
	}
	return (str2);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*str1;
	char		*str2;
	char		*temp;

	if (dest == src)
		return (dest);
	str1 = (char *)src;
	str2 = (char *)dest;
	temp = str1;
	if (dest < src)
	{
		incre(str2, temp, n);
	}
	else
	{
		decre(str2, temp, n);
	}
	return (dest);
}
/*
int main() 
{ 
    char str1[] = "je suis une phrase a rallonge"; // Array of size 100 
    char str2[] = "lorem ipsum rosa rosae"; // Array of size 5 
  
    puts("str1 before memmove "); 
    puts(str1); 
  
    ft_memmove(str1, str2, 8); 
  
    puts("\nstr1 after memmove "); 
    puts(str1); 
  
    return 0; 
}
*/