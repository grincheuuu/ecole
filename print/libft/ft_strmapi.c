/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:53:52 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 15:13:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	f(unsigned int index, char c)
{
	(void)index;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);	
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	char			*dest;
	unsigned int	i;

	l = ft_strlen(s);
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char *)malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < l)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[l] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	*str = "hello";
	char		*resultat;

	resultat = ft_strmapi(str, f);
	printf("%s\n", resultat);
	free(resultat);
	return (0);
}*/
