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
La fonction calloc est une fonction de la bibliothèque standard du langage C (et de nombreux autres langages de programmation) utilisée pour allouer de la mémoire dynamique et initialiser la mémoire allouée à zéro. Elle est souvent utilisée pour allouer de l'espace pour des tableaux dynamiques et des structures de données.

    num_elements : Le nombre d'éléments que vous souhaitez allouer.
    element_size : La taille en octets de chaque élément.

La fonction calloc alloue de la mémoire pour num_elements éléments, où chaque élément a une taille de element_size octets. Elle renvoie un pointeur vers le début de la mémoire allouée. La mémoire est initialisée à zéro pour chaque octet, ce qui signifie que tous les éléments sont initialisés à zéro.
