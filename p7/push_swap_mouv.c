/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mouv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:35:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 17:15:02 by gschwart         ###   ########.fr       */
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
	ft_pointerend(pointerA);
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
	ft_pointerend(pointerB);
}

void	ft_ss(t_pointer *pointerA, t_pointer *pointerB)
{
	ft_sa(pointerA, 2);
	ft_sb(pointerB, 2);
	write (1, "ss\n", 3);
}

void	ft_pa(t_pointer *pointera, t_pointer *pointerb)
{
	t_list	*tempa;
	t_list	*tempb;

	tempa = NULL;
	tempb = NULL;
	if (pointerb->first == NULL)
		return ;
	tempa = pointera->first;
	tempb = pointerb->first->next;
	pointera->first = pointerb->first;
	pointera->first->next = tempa;
	if (pointera->first->next != NULL)
		pointera->first->next->before = pointera->first;
	pointerb->first = tempb;
	if (pointerb->first != NULL)
		pointerb->first->before = NULL;
	write (1, "pa", 2);
	write (1, "\n", 1);
	ft_pointerend(pointerb);
	ft_pointerend(pointera);
}

void	ft_pb(t_pointer *pointera, t_pointer *pointerb)
{
	t_list	*tempa;
	t_list	*tempb;

	tempa = NULL;
	tempb = NULL;
	if (pointera->first == NULL)
		return ;
	tempb = pointerb->first;
	tempa = pointera->first->next;
	pointerb->first = pointera->first;
	pointerb->first->next = tempb;
	if (pointerb->first->next != NULL)
		pointerb->first->next->before = pointerb->first;
	pointera->first = tempa;
	if (pointera->first != NULL)
		pointera->first->before = NULL;
	write (1, "pb", 2);
	write (1, "\n", 1);
	ft_pointerend(pointera);
	ft_pointerend(pointerb);
}
