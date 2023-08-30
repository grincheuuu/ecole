/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:03:12 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/28 12:38:11 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	i = max - min;
	j = 0;
	if (min >= max)
	{
		return (0);
	}
	*range = malloc(i * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (j < i)
	{
		(*range)[j] = min + j;
		j++;
	}
	return (i);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	*range;
	int	resultat;

	min = 4;
	max = 8;
	resultat = ft_ultimate_range(&range, min, max);
	if (resultat == -1)
       	{
        	printf("Memory allocation failed.\n");
        	return 1;
   	}
       	else if (resultat == 0)
       	{
        	printf("min is greater or equal to max.\n");
       		return 1;
   	 }
	else 
	{
        	printf("The elements of the array are: ");
		for (int i = 0; i < resultat; i++) 
		{
			printf("%d ", range[i]);
		}
		printf("\n");
	}
	free(range);
	return (0);
}*/
