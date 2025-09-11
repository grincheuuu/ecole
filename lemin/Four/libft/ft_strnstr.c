/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:37:23 by mminet            #+#    #+#             */
/*   Updated: 2025/07/03 18:54:16 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && n > 0)
	{
		n = n + j + 1;
		j = 0;
		while (str[i + j] == to_find[j] && n > 0)
		{
			j++;
			n--;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
		n--;
	}
	return (0);
}
