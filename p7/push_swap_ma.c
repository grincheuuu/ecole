/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ma.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:25:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/03 17:26:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pointer	*ft_pointera(int argc, char **argv, t_pointer *pointera)
{
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (NULL);
	pointera = malloc(sizeof(t_pointer));
	return (pointera);
}

void	ft_initialisation(t_pointer **pointerb,
		t_list **pile_a, t_list **pile_b, char ***arv)
{
	*pointerb = NULL;
	*pile_a = NULL;
	*pile_b = NULL;
	*arv = NULL;
}
