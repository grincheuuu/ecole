/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:44:18 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 12:08:35 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmend, size_t size)
{
	size_t	size_total;
	char	*ptr;
	int		i;

	i = 0;
	if (nmend == 0 || size == 0)
	{
		nmend = 1;
		size = 1;
	}
	size_total = nmend * size;
	ptr = malloc(size_total);
	if (ptr == NULL)
		return (NULL);
	while (ptr[i] != '\0')
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	size_t	nmend;
	size_t	size;

	nmend = 5;
	size = sizeof(int);
	ft_calloc(nmend, size);
	return (0);
}*/
