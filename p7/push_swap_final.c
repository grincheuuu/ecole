/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:38:24 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final(t_pointer *pointerb)
{
	if (ft_rev_ordre(pointerb) == 0)
		return ;
	ft_rev_algorithm(pointerb);
}

void	ft_rev_algorithm(t_pointer *pointerb)
{
	t_limit	*limit;

	limit = NULL;
	if (ft_lstsize(pointerb->first) == 3)
	{
		if (pointerb->first->nb == limit->max)
			return;
		limit = ft_which_max(pointerb);
		if (pointerb->first->nb == limit->min)
			ft_rb(pointerb, 3);
		else
			ft_sb(pointerb, 3);	
		free(limit);
	}
	else if (ft_lstsize(pointerb->first) == 2)
	{
		if (pointerb->first->nb < pointerb->first->next->nb)
			ft_sb(pointerb, 3);
	}
	ft_printlist(pointerb);
}

void	ft_push(t_pointer *pointera, t_pointer *pointerb, t_nb *tnb)
{
	int	i;
	int	j;
	int	rev_placea;

	i = 0;
	j = 0;
	rev_placea = tnb->la - tnb->index;
	if (tnb->index >= tnb->la / 2)
	{
		if (tnb->p >= tnb->lb /2)
		{
			if (rev_placea > tnb->rev_placeb)
				i = (rev_placea + tnb->rev_placeb
					       	- (rev_placea
						       	- tnb->rev_placeb)) / 2;
			else
				i = (rev_placea + tnb->rev_placeb
				       	- (tnb->rev_placeb - rev_placea)) / 2;
			while (j < i)
			{
				ft_rrr(pointera, pointerb);
				j++;
			}
			while (rev_placea > i)
			{
				ft_rra(pointera, 3);
				i++;
			}
			while (tnb->rev_placeb > i)
			{
				ft_rrb(pointerb, 3);
				i++;
			}
		}
		else
		{
			while (i < rev_placea)
			{
				ft_rra(pointera, 3);
				i++;
			}
			while (j < tnb->p)
			{
				ft_rb(pointerb, 3);
				j++;
			}
		}
	}
	else
	{
		if (tnb->p >= tnb->lb / 2)
		{
			while (i < tnb->index)
			{
				ft_ra(pointera, 3);
				i++;
			}
			while (j < tnb->rev_placeb)
			{
				ft_rrb(pointerb, 3);
				j++;
			}

		}
		else
		{
			if (tnb->index > tnb->p)
				i = (tnb->index + tnb->p
					       	- (tnb->index - tnb->p)) / 2;
			else
				i = (tnb->index + tnb->p
				       	- (tnb->p - tnb->index)) / 2;
			printf("pp%dpp%dpp%dpp%d", tnb->p, tnb->index, i, tnb->nb);       	
			while (j < i)
			{
				ft_rr(pointera, pointerb);
				j++;
			}
			while (tnb->index > i)
			{
				ft_ra(pointera, 3);
				i++;
			}
			while (tnb->p > i)
			{
				ft_rb(pointerb, 3);
				i++;
			}
		}
	}
	ft_pb(pointera, pointerb);
}

t_nb	*ft_tnb_init(t_pointer *pointera, t_pointer *pointerb, int nb)
{
	t_nb	*tnb;

	tnb = malloc(sizeof(t_nb));
	if (tnb == NULL)
		return (NULL);
	tnb->nb = nb;
	tnb->tempi = 0;
	tnb->index = 0;
	tnb->rev_placeb = 0;
	tnb->num = 0;
	tnb->la = ft_lstsize(pointera->first);
	tnb->lb = ft_lstsize(pointerb->first);
	tnb->p = 0;
	return (tnb);
}

void	ft_ordo_b(t_pointer *pointerb)
{
	t_limit	*limit;
	int	i;

	i = 1;
	limit = ft_which_max(pointerb);
	printf("ii%dii%dtt", limit->indexm, limit->index);
	if (limit->indexm > ft_lstsize(pointerb->first) / 2)
	{
	
		while (i <= ft_lstsize(pointerb->first) - limit->indexm)
		{
			ft_rrb(pointerb, 3);
			i++;
		}
	}
	else
	{
		while (i <= limit->indexm)
		{
			ft_rb(pointerb, 3);
			i++;
		}
	}
	free(limit);
}
