/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algooo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:41:32 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 16:55:22 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nb	*ft_count_nb(t_pointer *pointerA, t_pointer *pointerB)
{
	t_list	*temp;
	t_nb	*tnb;
	t_nb	*tnbf;
	int		tempi;

	tnbf = NULL;
	tempi = 0;
	temp = pointerA->first;
	tnb = ft_num(pointerA, pointerB, temp->nb, 0);
	temp = temp->next;
	while (tempi < tnb->la && temp != NULL)
	{
		tempi += 1;
		tnbf = ft_num(pointerA, pointerB, temp->nb, tempi);
		tnb = ft_algoo_tnb(tnb, tnbf);
		if (tnb->num == 0 || tnb->num == 1)
			break ;
		temp = temp->next;
	}
	return (tnb);
}

t_nb	*ft_num(t_pointer *pointerA, t_pointer *pointerB, int nb, int i)
{
	t_nb	*tnb;

	tnb = ft_tnb_init(pointerA, pointerB, nb);
	tnb->index = i;
	tnb->p = ft_place(pointerB, nb);
	tnb->rev_placeb = tnb->lb - tnb->p;
	if (tnb->p > tnb->lb / 2 && (tnb->index <= tnb->la / 2))
		tnb->num = tnb->index + tnb->rev_placeb;
	else if ((tnb->p <= tnb->lb / 2) && tnb->index > tnb->la / 2)
		tnb->num = tnb->la - tnb->index + 1 + tnb->p;
	else if ((tnb->index > tnb->la / 2) && tnb->p > tnb->lb / 2)
		tnb->num = ft_rev_num(pointerA, tnb->index, tnb->rev_placeb);
	else
	{
		if (tnb->p > tnb->index)
			tnb->num = (tnb->p + tnb->index
					- ((tnb->p - tnb->index) / 2)
					+ tnb->p - tnb->index);
		else
			tnb->num = (tnb->p + tnb->index
					- ((tnb->index - tnb->p) / 2)
					+ tnb->index - tnb->p);
	}
	return (tnb);
}

int	ft_place(t_pointer *pointerB, int nb)
{
	t_list	*ant;
	t_list	*pos;
	int		p;
	int		nsup;
	int		ninf;

	p = 0;
	nsup = ft_ordre_max(pointerB, nb);
	ninf = ft_ordre_min(pointerB, nb);
	ant = pointerB->first;
	pos = pointerB->first->next;
	if (nb > pointerB->first->nb && ft_max_nb(pointerB, ant->nb) == 0)
		return (p);
	if (nb < pointerB->end->nb && ft_min_nb
		(pointerB, pointerB->end->nb) == 0)
		return (ft_lstsize(pointerB->first));
	if (nb == nsup || nb == ninf)
		return (ft_push_mm(pointerB, nb, ninf, nsup));
	else
	{
		p = ft_place_deux(ant, pos, pointerB, nb);
		if (p != 0)
			return (p);
	}
	return (0);
}

int	ft_place_deux(t_list *ant, t_list *pos, t_pointer *pointerb, int nb)
{
	int	p;
	int	ninf;
	int	nsup;

	p = 0;
	nsup = ft_ordre_max(pointerb, nb);
	ninf = ft_ordre_min(pointerb, nb);
	while (pos != NULL)
	{
		p++;
		if ((nb > ant->nb && nb < pos->nb
				&& pos->nb == nsup
				&& ant->nb == ninf)
			|| (nb < ant->nb && nb > pos->nb
				&& ant->nb == nsup
				&& pos->nb == ninf))
			return (p);
		ant = ant->next;
		pos = pos->next;
	}
	return (0);
}

int	ft_max_nb(t_pointer *pointerB, int nb)
{
	t_list	*temp;

	temp = pointerB->first;
	while (temp != NULL)
	{
		if (temp->nb > nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}
