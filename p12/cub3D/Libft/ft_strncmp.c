/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:33 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:33 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int main(void)
{
	char	s1[] = "je suis un test";
	char	s2[] = "je suis Un test";
	int	n = 15;

	printf("%d", ft_strncmp(s1, s2, n));
	return (0);
}
*/
