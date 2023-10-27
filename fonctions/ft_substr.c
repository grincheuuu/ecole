/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:27:29 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 12:26:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	l;
	size_t	sub_len;

	l = strlen(s);
	sub_len = len;
	if (s == NULL || len < 0)
		return (NULL);
	if (l <= start)
		return (strdup(""));
	if (start + len >= l)
		sub_len = l - start;
	dest = malloc((sub_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	strncpy(dest, (s + start), sub_len);
	dest[sub_len] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char const	s[] = "hello word";
	unsigned int	start;
	size_t		len;

	start = 6;
	len = 4;
	printf("%s", ft_substr(s, start, len));
	return (0);
}*/
