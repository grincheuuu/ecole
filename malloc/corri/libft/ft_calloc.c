/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:44:18 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/08 16:11:42 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmend, size_t size)
{
	size_t	size_total;
	char	*ptr;
	int		i;

	i = 0;
	size_total = nmend * size;
	ptr = malloc(size_total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size_total);
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
