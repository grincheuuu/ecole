/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:41:24 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	l;

	l = strlen(s1) + strlen(s2);
	dest = malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	strcpy(dest, s1);
	strcat(dest, s2);
	return (dest);
}
/*
int	main(void)
{
	char const	s1[] = "hello bonjour";
	char const	s2[] = "123";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
