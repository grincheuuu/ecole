/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_freya.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:38:51 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/27 15:01:33 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ordre_max(t_pointer *pointerb, int nb)
{
	int	nsup;
	t_list	*temp;
	t_limit	*limit;

	temp = pointerb->first;
	limit = ft_which_max(pointerb);
	nsup = limit->max;
	if (nsup < nb)
		nsup = nb;
	while (temp != NULL)
	{
		if (temp->nb < nsup && temp->nb > nb)
			nsup = temp->nb;
		temp = temp->next;
	}
	free(limit);
	return (nsup);
}

int	ft_ordre_min(t_pointer *pointerb, int nb)
{
	int	ninf;
	t_list	*temp;
	t_limit	*limit;

	temp = pointerb->first;
	limit = ft_which_max(pointerb);
	ninf = limit->min;
	if (ninf > nb)
		ninf = nb;
	while (temp != NULL)
	{
		if (temp->nb > ninf && temp->nb < nb)
			ninf = temp->nb;
		temp = temp->next;
	}
	free(limit);
	return (ninf);
}

int	ft_push_mm(t_pointer *pointerb, int nb, int ninf, int nsup)
{
	t_list	*ant;
	t_list	*pos;
	int	p;

	p = 0;
	ant = pointerb->first;
	pos = pointerb->first->next;
	while (pos != NULL)
	{
		p++;
		if (nb == ninf)
		{
			if ((ant->nb == nsup && pos->nb == ft_mx(pointerb, 1))
					|| (ant->nb == ft_mx(pointerb, 1)
					       	&& pos->nb == nsup))
				return (p);
		}
		else if (nb == nsup)
		{
			if ((ant->nb == ft_mx(pointerb, 0) && pos->nb == ninf)
					|| (ant->nb == ninf && pos->nb
						== ft_mx(pointerb, 0)))
				return (p);	
		}
		ant = ant->next;
		pos = pos->next;
	}
	return (p);
}
