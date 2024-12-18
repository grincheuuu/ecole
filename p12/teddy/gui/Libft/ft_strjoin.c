/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:10:21 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:29 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((const char *)s1);
	len2 = ft_strlen((const char *)s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str)
	{
		ft_strlcpy(str, s1, len1 + 1);
		ft_strlcat(str, s2, len2 + len1 +1);
		return (str);
	}
	return (NULL);
}
/*
int	main()
{
	char	*dest;

	dest = ft_strjoin("test","hello world");
	printf("%s\n", dest);
	return (0);
}
*/