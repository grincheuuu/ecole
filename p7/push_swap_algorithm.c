/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:54 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/14 16:53:14 by gschwart         ###   ########.fr       */
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
	int	i;

	i = 1;
	temp = pointerA->first;
	limit = NULL;
	if (temp != NULL)
		limit = ft_init_limit(temp->nb, i, temp->nb, i);
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

void	ft_algorithm(t_pointer *pointerA)
{
	t_limit	*limit;

	limit = NULL;
	if (ft_lstsize(pointerA->first) == 3)
	{
		limit = ft_which_max(pointerA);
		if (limit->index == limit->size)
		{
			if (pointerA->first->nb > pointerA->first->next->nb)
				ft_sa(pointerA, 3);
		}
		else
			ft_pos(pointerA, limit);
		free(limit);
	}
	else if (ft_lstsize(pointerA->first) == 2)
	{
		if (pointerA->first->nb > pointerA->first->next->nb)
			ft_sa(pointerA, 3);
	}
	ft_printlist(pointerA);
}

int	ft_which_big(t_limit *limita, t_pointer *pointerB)
{
	t_limit	*limitb;

	limitb = ft_which_max(pointerB);
	if ((limita->max - limitb->max) < 0)
	{
		return (1);
	}
	free(limitb);
	return (0);
}
