/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:47:28 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/26 19:18:37 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_list **pile_a, t_list **pile_b, t_pointer *pointerA, t_pointer *pointerB)
{
	*pile_a = NULL;
	*pile_b = NULL;
	pointerA->first = NULL;
	pointerA->end = NULL;
	pointerB->first = NULL;
	pointerB->end = NULL;
}

void	ft_printlist(t_pointer *pointerA)
{
	t_list	*temp;
	int	i;
	
	temp = NULL;
	i = 0;
	printf("\n");
	if (pointerA == NULL)
	{
		write (1, "NULL", 4);
		return ;
	}
	temp = pointerA->first;
	while (temp != NULL)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
		i++;
	}
/*	temp = pointerA->end;
	while (i > 0)
	{
		printf("%d", temp->nb);
		temp = temp->before;
		i--;
	}*/
}

void	ft_swap(t_list *pile_a, t_list *pile_b, t_pointer *pointerA, t_pointer *pointerB)
{
	(void)pointerB;
	(void)pointerA;
	(void)pile_a;
	(void)pile_b;
//	ft_pb(pointerA, pointerB);
//	ft_pb(pointerA, pointerB);
//	ft_pb(pointerA, pointerB);
//	ft_pa(pointerA, pointerB);
//	ft_pa(pointerA, pointerB);
//	ft_pa(pointerA, pointerB);
//	ft_pb(pointerA, pointerB);
//	ft_rrb(pointerB, 3);
//	ft_rra(pointerA, 3);
//	ft_rra(pointerA, 3);
//	ft_rrr(pointerA, pointerB);
//	ft_rr(pointerA, pointerB);
//	ft_ra(pointerA, 3);
//	ft_rb(pointerB, 3);
//	ft_pa(pointerA, pointerB);
//	ft_ss(pointerA, pointerB);
//	ft_sa(pile_a, pointerA, 3);
//	ft_sb(pile_b, pointerB, 3);
	if (pile_a == NULL)
		return ;
	if (ft_lstsize(pile_a) <= 3)
		ft_algorithm(pointerA);
	else
	{
		ft_class(pointerA, pointerB, pile_a, pile_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_pointer	*pointerA;
	t_pointer	*pointerB;

	if ((pointerA = malloc(sizeof(t_pointer))) == NULL)
		return (0);
	if ((pointerB = malloc(sizeof(t_pointer))) == NULL)
		return (0);
	ft_init(&pile_a, &pile_b, pointerA, pointerB);
	if (argc > 1)
		pile_a = ft_maillonlist(argc, argv);
	ft_affect(pile_a, pointerA);
//	ft_printlist(pile_a);
//	ft_printlist(pile_b);
	ft_swap(pile_a, pile_b, pointerA, pointerB);
	printf("\n");
	printf("TINTIN");
	ft_printlist(pointerA);
	printf("\n");
	ft_printlist(pointerB);
	ft_lstclear(&pointerA->first);
	ft_lstclear(&pointerB->first);
	free(pointerA);
	free(pointerB);
	return (0);
}
