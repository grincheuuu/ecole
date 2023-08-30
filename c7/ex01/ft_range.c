/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:58:34 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/28 10:52:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;
	int	j;

	i = max - min;
	j = 0;
	if (min >= max)
		return (NULL);
	dest = malloc((i) * sizeof(int));
	if (dest == NULL)
		return (NULL);
	while (j < i)
	{
		dest[j] = min + j;
		j++;
	}
	return (dest);
}
/*
int	main(void)
{
	int	min;
	int	max;

	min = 4;
	max = 8;
	ft_range(min, max);
	return (0);
}*/
