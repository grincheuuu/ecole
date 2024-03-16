/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mouv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:35:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/08 16:22:45 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pointer *pointerA, int nb)
{
	t_list	*temp;
	t_list	*deux;

	temp = NULL;
	if (pointerA->first == NULL || pointerA->first->next == NULL)
		return ;
	temp = pointerA->first;
	deux = pointerA->first->next->next;
	pointerA->first = pointerA->first->next;
	pointerA->first->before = NULL;
	pointerA->first->next = temp;
	pointerA->first->next->before = pointerA->first;
	pointerA->first->next->next = deux;
	if (pointerA->first->next->next != NULL)
		pointerA->first->next->next->before = pointerA->first->next;
	if (nb != 2)
		write (1, "sa\n", 3);
	ft_pointerEnd(pointerA);
}

void	ft_sb(t_pointer *pointerB, int nb)
{
	t_list	*temp;
	t_list	*deux;

	temp = NULL;
	if (pointerB->first == NULL || pointerB->first->next == NULL)
		return ;
	temp = pointerB->first;
	deux = pointerB->first->next->next;
	pointerB->first = pointerB->first->next;
	pointerB->first->before = NULL;
	pointerB->first->next = temp;
	pointerB->first->next->before = pointerB->first;
	pointerB->first->next->next = deux;
	if (pointerB->first->next->next != NULL)
		pointerB->first->next->next->before = pointerB->first->next;
	if (nb != 2)
		write (1, "sb\n", 3);
	ft_pointerEnd(pointerB);
}

void	ft_ss(t_pointer *pointerA, t_pointer *pointerB)
{
	ft_sa(pointerA, 2);
	ft_sb(pointerB, 2);
	write (1, "ss\n", 3);
}

void	ft_pa(t_pointer *pointerA, t_pointer *pointerB)
{
	t_list	*tempA;
	t_list	*tempB;

	tempA = NULL;
	tempB = NULL;
	if (pointerB->first == NULL)
		return ;
	tempA = pointerA->first;
	tempB = pointerB->first->next;
	pointerA->first = pointerB->first;
	pointerA->first->next = tempA;
	if (pointerA->first->next != NULL)
		pointerA->first->next->before = pointerA->first;
	pointerB->first = tempB;
	if (pointerB->first != NULL)
		pointerB->first->before = NULL;
	write (1, "pa", 2);
	write (1, "\n", 1);
	ft_pointerEnd(pointerB);
	ft_pointerEnd(pointerA);
}

void	ft_pb(t_pointer *pointerA, t_pointer *pointerB)
{
	t_list	*tempA;
	t_list	*tempB;

	tempA = NULL;
	tempB = NULL;
	if (pointerA->first == NULL)
		return ;
	tempB = pointerB->first;
	tempA = pointerA->first->next;
	pointerB->first = pointerA->first;
	pointerB->first->next = tempB;
	if (pointerB->first->next != NULL)
		pointerB->first->next->before = pointerB->first;
	pointerA->first = tempA;
	if (pointerA->first != NULL)
		pointerA->first->before = NULL;
	write (1, "pb", 2);
	write (1, "\n", 1);
	ft_pointerEnd(pointerA);
	ft_pointerEnd(pointerB);
}
