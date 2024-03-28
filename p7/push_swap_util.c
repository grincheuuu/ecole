/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/15 19:24:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_pointer *pointerA, t_pointer *pointerB)
{
	ft_rra(pointerA, 2);
	ft_rrb(pointerB, 2);
	write (1, "rrr\n", 4);
}

int	ft_atoi(const char *nptr)
{
	char	*endptr;
	int		signe;
	int		resultat;

	signe = 1;
	resultat = 0;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			signe = signe * -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		resultat *= 10;
		resultat += *nptr - '0';
		nptr++;
	}
	if (*nptr != '\0')
		endptr = (char *)nptr;
	return (resultat * signe);
}

int	ft_rev_ordre(t_pointer *pointerB)
{
	t_list	*temp;

	temp = pointerB->first;
	while (temp->next != NULL)
	{
		if (temp->nb < temp->next->nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_position(t_pointer *pointerB, int l)
{
	t_list	*ant;
	t_list	*pos;
	int	nb;
	int	i;

	i = 1;
	nb = pointerB->first->nb;
	ant = pointerB->first->next;
	pos = pointerB->first->next->next;
	while (pos != NULL)
	{
		if (nb < ant->nb && nb > pos->nb)
		{
			if (i <= l / 2)
			{
				while (i > 0)
				{
					ft_rrb(pointerB, 3);
					i--;
				}
				break ;
			}
			else
			{
				while (l - i > 0)
				{
					ft_rb(pointerB, 3);
					i++;
				}
				break ;
			}
		}
		i++;
		ant = ant->next;
		pos = pos->next;
	}
}

int	ft_rev_num(t_pointer *pointerA, int i, int rev_placeB)
{
	int	rev_num_A;
	
	rev_num_A = ft_lstsize(pointerA->first) - i + 1;
	if (rev_num_A >= rev_placeB)
		return ((rev_num_A + rev_placeB - (rev_num_A - rev_placeB) / 2) + rev_num_A - rev_placeB);
	else
		return ((rev_num_A + rev_placeB - (rev_placeB - rev_num_A) / 2) + rev_placeB - rev_num_A);
}
