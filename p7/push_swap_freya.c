/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_freya.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:38:51 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/16 17:22:40 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_few(t_pointer *pointerA, t_pointer *pointerB)
{
	int	i;

	i = 0;
	ft_pb(pointerA, pointerB);
	ft_pb(pointerA, pointerB);
	while (ft_lstsize(pointerA->first) != 3)
	{
		ft_cross_b(pointerB);
		ft_which_pb(pointerA, pointerB);
//		ft_pb(pointerA, pointerB);
	}
	i = ft_trois(pointerA, pointerB);
	ft_printlist(pointerA);
	ft_cross(pointerA, pointerB, i);
	ft_printlist(pointerA);
	ft_printlist(pointerA);
	printf("AAA");
}

void	ft_which_pb(t_pointer *pointerA, t_pointer *pointerB)
{
	t_list	*temp;
	t_list	*fin;
	t_compte	*compte;

	compte = ft_compte_init(pointerA, pointerB);
	temp = pointerA->first;
	fin = pointerA->end;
	while (compte->indexi < ft_lstsize(pointerA->first) / 2)
	{
		if (compte->num > ft_compte(pointerB, temp->nb, compte))
			compte->num = ft_compte(pointerB, temp->nb, compte);
		if (compte->num == 1)
			break ;
		temp = temp->next;
		compte->indexi += 1;
	}
	while (ft_lstsize(pointerA->first) / 2 - compte->indexj > 0)
	{
		compte->indexj += 1;
		if (compte->num > ft_compte(pointerB, fin->nb, compte))
			compte->num = ft_compte(pointerB, fin->nb, compte);
		if (compte->num == 1)
			break ;
		fin = fin->before;
	}
}

int	ft_compte(t_pointer *pointerB, int nb, t_compte *compte)
{
	t_list	*ant;
	t_list	*pos;

	ant = pointerB->first;
	pos = pointerB->first->next;
	if (nb > ant->nb)
		return (a);
	if (nb < pointerB->end->nb)
		return (f);
	while (compte->indexa < ft_lstsize(pointerB->first) / 2)
	{
		compte->indexa += 1;
		if (nb > ant && nb < pos)
			return (ft_comp(compte, "i", "a"));
		ant = ant->next;
		pos = pos->next;
	}
	ant = pointerB->end->before;
	pos = pointerb->end;
	compte->indexf = 1;
	while (ft_lstsize(pointerB->first) / 2 - compte->indexf > 0)
	{
		compte->indexf += 1;
		if (nb > ant && nb < pos)
			return (ft_comp(compte, "j", "f"));
		ant = ant->before;
		pos = pos->before;
	}
	return (0);
}

int	ft_comp(t_compte *compte, char c, char d)
{
	if (c == 'i' && d == 'a')
	{
		if (compte->indexa > compte->indexi)
			return (((compte->indexa + compte->indexi)
					       	- (compte->indexa
						       	- compte->indexi)) / 2);
		else
			return (((compte->indexa + compte->indexi) 
                                                - (compte->indexi 
                                                        - compte->indexa)) / 2);
	}
	else if (c == 'j' && d == 'f')
	{
		if (compte->indexf > compte->indexj)
			return (((compte->indexf + compte->indexj)
					       	- (compte->indexf
						       	- compte->indexj)) / 2);
		else
			return (((compte->indexf + compte->indexj) 
                                                - (compte->indexj 
                                                        - compte->indexf)) / 2);
	}
	else
//		return (compte->indexi + compte->indexj + compte->indexa
//			       	+ compte->indexf);
}

t_compte	*ft_compte_init(t_pointer *pointerA, t_pointer *pointerB)
{
	t_compte	*compte;

	compte = malloc(sizeof(t_compte));
	if (compte == NULL)
		return ;
	compte->num = ft_compte(pointerB, pointerA->first->nb, 0 , "i");
	compte->indexi = 0;
	compte->indexj = 0;
	compte->indexa = 0;
	compte->indexf = 0;
	compte->nb = pointerA->first->nb;
	return (compte);
}
