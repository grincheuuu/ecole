/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_air.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/15 17:33:23 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_try(t_limit *limit,t_pointer *pointerA)
{
	if (limit->size != limit->index && limit->size != limit->indexm)
	{
		if (pointerA->first->nb == limit->min)
			ft_sa(pointerA, 3);
	}
	else
	{
		if (limit->max == pointerA->first->nb || limit->min
			       	== pointerA->first->nb)
		{
			ft_rra(pointerA, 3);
			if (pointerA->first->nb == limit->min)
				ft_sa(pointerA, 3);
		}
		else
		{
			ft_ra(pointerA, 3);
			if (pointerA->first->nb == limit->min)
				ft_sa(pointerA, 3);
		}
	}
}

int	ft_mx(t_pointer *pointerA, int nb)
{
	int	max;
	t_list	*temp;

	max = 0;
	temp = NULL;
	max = pointerA->first->nb;
	temp = pointerA->first;
	while (temp != NULL)
	{
		if (nb == 1)
		{
			if (temp->nb > max)
				max = temp->nb;
		}
		else
		{
			if (temp->nb < max)
				max = temp->nb;
		}
		temp = temp->next;
	}
	return (max);
}

void	ft_cross_b(t_pointer *pointerB)
{
	t_limit	*limit;
	int	l;

	l = 0;
	limit = ft_which_max(pointerB);
	if (ft_rev_ordre(pointerB) == 0)
		return ;
	l = ft_lstsize(pointerB->first);
	if (limit->min == pointerB->first->nb)
		ft_rb(pointerB, 3);
	else if (pointerB->first->nb != limit->max)
	{
		ft_position(pointerB, l);
	}
	free(limit);
}

void	ft_cross(t_pointer *pointerA, t_pointer *pointerB, int i)
{
	while (pointerB->first != NULL)
	{
		if (((pointerA->end->nb > pointerB->first->nb)
			       	&& (pointerA->end->nb
				       	< pointerA->first->nb)) && i < 3)
		{
			printf("ii%dii", i);
			ft_rra(pointerA, 3);
			i++;
//			ft_printlist(pointerA);
		}
		else
			ft_pa(pointerA, pointerB);
//		ft_printlist(pointerA);
//		ft_printlist(pointerB);
		printf("\n");
	}
	while (i < 3)
	{
		ft_rra(pointerA, 3);
		i++;
	}
}


void	ft_five(t_pointer *pointerA, t_pointer *pointerB)
{
	int	i;

	i = 0;
	while (ft_lstsize(pointerA->first) != 3)
		ft_pb(pointerA, pointerB);
	ft_printlist(pointerB);
	ft_printlist(pointerA);
	i = ft_trois(pointerA, pointerB);
/*	if (ft_which_big(ft_which_max(pointerA), pointerB) == 0)
	{
		i++;
		ft_try(ft_which_max(pointerA), pointerA);
	}
	else
		ft_algorithm(pointerA);*/
	ft_printlist(pointerA);
	ft_cross_b(pointerB);
	ft_cross(pointerA, pointerB, i);
	printf("five");
	ft_printlist(pointerA);
	ft_printlist(pointerA);
	printf("AAA");
}
