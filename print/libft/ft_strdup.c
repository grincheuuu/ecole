/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:01:52 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	src[] = "salut hello";

	printf("%s", ft_strdup(src));
	return (0);
}*/
