/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:43:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 16:03:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_pointer *pointerA, t_pointer *pointerB)
{
	ft_rra(pointerA, 2);
	ft_rrb(pointerB, 2);
	write (1, "rrr\n", 4);
}

long	ft_atol(const char *nptr)
{
	char	*endptr;
	long	resultat;
	int		signe;

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

int	ft_rev_ordre(t_pointer *pointerb)
{
	t_list	*temp;

	temp = pointerb->first;
	while (temp->next != NULL)
	{
		if (temp->nb < temp->next->nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_position(t_pointer *pointerb)
{
	t_list	*ant;
	t_list	*pos;
	int		nb;
	int		i;

	i = 1;
	nb = pointerb->first->nb;
	ant = pointerb->first->next;
	pos = pointerb->first->next->next;
	while (pos != NULL)
	{
		if (nb < ant->nb && nb > pos->nb)
		{
			if (ft_position_deux(pointerb, i) == 1)
				break ;
		}
		i++;
		ant = ant->next;
		pos = pos->next;
	}
}

int	ft_position_deux(t_pointer *pointerb, int i)
{
	int		l;

	l = ft_lstsize(pointerb->first);
	if (i <= l / 2)
	{
		while (i > 0)
		{
			ft_rrb(pointerb, 3);
			i--;
		}
		return (1);
	}
	else
	{
		while (l - i > 0)
		{
			ft_rb(pointerb, 3);
			i++;
		}
		return (1);
	}
	return (0);
}
