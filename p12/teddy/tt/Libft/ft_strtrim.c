/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:06:24 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:37 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	lenc;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	lenc = ft_strlen(s1);
	while (lenc && ft_strchr(set, s1[lenc]))
		lenc--;
	return (ft_substr(s1, 0, lenc + 1));
}

// int	main()
// {
// 	char	*dest;

// 	dest = ft_strtrim("", "");
// 	printf("%s\n", dest);
// 	return (0);
// }
