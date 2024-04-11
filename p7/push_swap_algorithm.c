/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:54 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 17:26:33 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_limit	*ft_which_max(t_pointer *pointerA)
{
	t_list	*temp;
	t_limit	*limit;
	int		i;

	i = 1;
	temp = pointerA->first;
	limit = NULL;
	if (temp != NULL)
		limit = ft_init_limit(temp->nb, i);
	limit = ft_which_max_deux(limit, temp, i);
	return (limit);
}

t_limit	*ft_which_max_deux(t_limit *limit, t_list *temp, int i)
{
	while (temp != NULL)
	{
		if (temp->nb > limit->max)
		{
			limit->max = temp->nb;
			limit->index = i;
		}
		if (temp->nb < limit->min)
		{
			limit->min = temp->nb;
			limit->indexm = i;
		}
		temp = temp->next;
		i++;
	}
	limit->size = i - 1;
	return (limit);
}

void	ft_algorithm(t_limit *limit, t_pointer *pointerA)
{
	if (ft_lstsize(pointerA->first) == 3)
	{
		if (limit->index == limit->size)
		{
			if (pointerA->first->nb > pointerA->first->next->nb)
				ft_sa(pointerA, 3);
		}
		else
			ft_pos(pointerA, limit);
	}
	else if (ft_lstsize(pointerA->first) == 2)
	{
		if (pointerA->first->nb > pointerA->first->next->nb)
			ft_sa(pointerA, 3);
	}
}

void	ft_few(t_pointer *pointerA, t_pointer *pointerB)
{
	t_nb	*tnb;
	int		i;
	int		index;

	i = 0;
	index = 0;
	tnb = NULL;
	ft_pb(pointerA, pointerB);
	ft_pb(pointerA, pointerB);
	ft_final(pointerB);
	while (ft_lstsize(pointerA->first) > 3)
	{
		tnb = ft_count_nb(pointerA, pointerB);
		ft_push(pointerA, pointerB, tnb);
		free(tnb);
	}
	ft_ordo_b(pointerB);
	i = ft_trois(pointerA, pointerB);
	ft_cross(pointerA, pointerB, i);
}
