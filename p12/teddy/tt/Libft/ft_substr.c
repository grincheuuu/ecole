/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:40:35 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:36 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*nstr;
	size_t		i;
	size_t		x;

	x = ft_strlen(s);
	i = start;
	if (s == NULL || x < start)
		return (ft_strdup(""));
	if (start + len < x)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((x - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	nstr = str;
	while (i < (start + len) && *(s + i))
		*nstr++ = *(s + i++);
	*nstr = '\0';
	return (str);
}

/*
int main()
{
	char	str[] = "";
	int		i;
	int		y;

	i = 1;
	y = 1;
	ft_substr(str, i, y);
	return (0);
}
*/