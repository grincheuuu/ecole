/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:43:20 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/16 16:44:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ordre(t_pointer *pointerA)
{
	t_list	*temp;

	temp = pointerA->first;
	while (temp->next != NULL)
	{
		if (temp->nb > temp->next->nb)
			return (1);
		temp = temp->next;
	}
	return (0);

}

t_limit	*ft_init_limit(int nb, int i)
{
	t_limit	*limit;

	limit = malloc(sizeof(limit));
	if (limit == NULL)
		return (NULL);
	limit->max = nb;
	limit->index = i;
	limit->size = 0;
	limit->min = nb;
	limit->max = i;
	return (limit);
}

void	ft_pos(t_pointer *pointerA, t_limit *limit)
{
	t_list	*temp;

	temp = pointerA->first;
	if (pointerA->first == NULL || limit == NULL)
		return ;
	if (limit->max == temp->nb)
		ft_ra(pointerA, 3);
	else 
		ft_rra(pointerA, 3);
	if (ft_ordre(pointerA) == 1)
	{
		ft_sa(pointerA, 3);
	}
}

int	ft_trois(t_pointer *pointerA, t_pointer *pointerB)
{
	t_limit	*limit;
	int	i;
	
	i = 0;
	limit = ft_which_max(pointerA);
	if (ft_which_big(limit, pointerB) == 0)
	{
		i++;
		ft_try(limit, pointerA);
	}
	else
		ft_algorithm(pointerA);
	free(limit);
	return (i);
}

void	ft_class(t_pointer *pointerA, t_pointer *pointerB, t_list *pile_a, t_list *pile_b)
{
	t_limit	*limita;
	
	limita = NULL;
	(void)pile_b;
	(void)pile_a;
	if (ft_ordre(pointerA) == 0)
		exit(EXIT_SUCCESS);
	if (ft_lstsize(pointerA->first) <= 5)
		ft_five(pointerA, pointerB);
	else
	{
		ft_few(pointerA, pointerB);
	}
}
