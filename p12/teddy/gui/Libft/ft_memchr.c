/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:38:42 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:18:44 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str = (const char *)s;
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main() {
	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int size = 10;
	void * found = ft_memchr( data, 57, size );
	printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );
		found = ft_memchr( data, 50, size );
	printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
	if ( found != NULL ) {
	printf( "La valeur a la position calculee est %d\n", *((char *) found) );
	}

	return(0);
}
*/
