/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mouvement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:23:40 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 17:18:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pointer *pointerA, int nb)
{
	t_list	*haut;
	t_list	*bas;

	haut = NULL;
	bas = NULL;
	if (pointerA->first == NULL
		|| pointerA->first->next == NULL
		|| pointerA->end == NULL)
		return ;
	haut = pointerA->first;
	pointerA->first = pointerA->first->next;
	pointerA->first->before = NULL;
	bas = pointerA->end;
	pointerA->end = haut;
	pointerA->end->next = NULL;
	pointerA->end->before = bas;
	pointerA->end->before->next = pointerA->end;
	if (nb != 2)
		write (1, "ra\n", 3);
}

void	ft_rb(t_pointer *pointerB, int nb)
{
	t_list	*haut;
	t_list	*bas;

	haut = NULL;
	bas = NULL;
	if (pointerB->first == NULL
		|| pointerB->first->next == NULL
		|| pointerB->end == NULL)
		return ;
	haut = pointerB->first;
	pointerB->first = pointerB->first->next;
	pointerB->first->before = NULL;
	bas = pointerB->end;
	pointerB->end = haut;
	pointerB->end->next = NULL;
	pointerB->end->before = bas;
	pointerB->end->before->next = pointerB->end;
	if (nb != 2)
		write (1, "rb\n", 3);
}

void	ft_rr(t_pointer *pointerA, t_pointer *pointerB)
{
	ft_ra(pointerA, 2);
	ft_rb(pointerB, 2);
	write (1, "rr\n", 3);
}

void	ft_rra(t_pointer *pointerA, int nb)
{
	t_list	*bas;
	t_list	*haut;

	bas = NULL;
	haut = NULL;
	if (pointerA->first == NULL
		|| pointerA->first->next == NULL
		|| pointerA->end == NULL)
		return ;
	bas = pointerA->end->before;
	haut = pointerA->first;
	pointerA->first = pointerA->end;
	pointerA->first->before = NULL;
	pointerA->first->next = haut;
	pointerA->first->next->before = pointerA->first;
	pointerA->end = bas;
	pointerA->end->next = NULL;
	if (nb != 2)
		write (1, "rra\n", 4);
}

void	ft_rrb(t_pointer *pointerB, int nb)
{
	t_list	*bas;
	t_list	*haut;

	bas = NULL;
	haut = NULL;
	if (pointerB->first == NULL
		|| pointerB->first->next == NULL
		|| pointerB->end == NULL)
		return ;
	bas = pointerB->end->before;
	haut = pointerB->first;
	pointerB->first = pointerB->end;
	pointerB->first->before = NULL;
	pointerB->first->next = haut;
	pointerB->first->next->before = pointerB->first;
	pointerB->end = bas;
	pointerB->end->next = NULL;
	if (nb != 2)
		write (1, "rrb\n", 4);
}
