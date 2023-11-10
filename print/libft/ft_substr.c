/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:27:29 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/07 13:38:57 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	l;
	size_t	sub_len;

	l = ft_strlen(s);
	sub_len = len;
	if (s == NULL || len < 0)
		return (NULL);
	if (l <= start)
		return (ft_strdup(""));
	if (start + len >= l)
		sub_len = l - start;
	dest = malloc((sub_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strncpy(dest, (s + start), sub_len);
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
