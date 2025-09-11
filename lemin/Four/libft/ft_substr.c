/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:37:39 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 16:05:56 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	int				i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (len > 0)
	{
		dest[i] = s[i + start];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
