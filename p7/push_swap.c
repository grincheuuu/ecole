/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:47:28 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/02 15:46:41 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_list **pile_a, t_list **pile_b,
		t_pointer *pointerA, t_pointer *pointerB)
{
	*pile_a = NULL;
	*pile_b = NULL;
	pointerA->first = NULL;
	pointerA->end = NULL;
	pointerB->first = NULL;
	pointerB->end = NULL;
}

void	ft_swap(t_list *pile_a, t_list *pile_b,
		t_pointer *pointerA, t_pointer *pointerB)
{
	t_limit	*limit;

	limit = NULL;
	ft_affect(pile_a, pointerA);
	limit = ft_which_max(pointerA);
	if (pile_a == NULL)
	{
		ft_clear(pointerA, pointerB);
		free(limit);
		return ;
	}
	if (ft_lstsize(pile_a) <= 3)
		ft_algorithm(limit, pointerA);
	else
	{
		ft_class(pointerA, pointerB, pile_a, pile_b);
	}
	ft_clear(pointerA, pointerB);
	free(limit);
}

char	**ft_test_arg(int argc, char **argv,
		t_pointer *pointera, t_pointer *pointerb)
{
	char	**arv;

	arv = NULL;
	if (argc == 2)
	{
		arv = ft_split(argv[1], ' ');
		ft_arv(arv, pointera, pointerb, 3);
		if (ft_doublons(arv) == 1)
			ft_error(arv, pointera, pointerb, 3);
	}
	else
	{
		ft_arv(argv + 1, pointera, pointerb, 0);
		if (ft_doublons(argv) == 1)
			ft_error(argv, pointera, pointerb, 0);
	}
	return (arv);
}

void	ft_arv(char **arv, t_pointer *pointera, t_pointer *pointerb, int nb)
{
	int	i;
	int	j;

	j = 0;
	while (arv[j] != NULL)
	{
		i = 0;
		if (ft_atol(arv[j]) > 2147483647
			|| ft_atol(arv[j]) < -2147483648)
			ft_error(arv, pointera, pointerb, nb);
		if (!(arv[j][i] == '+' || arv[j][i] == '-'
			|| (arv[j][i] >= '0' && arv[j][i] <= '9')))
			ft_error(arv, pointera, pointerb, nb);
		if ((arv[j][i] == '+' || arv[j][i] == '-') && arv[j][i + 1] == '\0')
			ft_error(arv, pointera, pointerb, nb);
		i++;
		while (arv[j][i] != '\0')
		{
			if (!(arv[j][i] >= '0' && arv[j][i] <= '9'))
				ft_error(arv, pointera, pointerb, nb);
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_pointer	*pointera;
	t_pointer	*pointerb;
	t_list		*pile_a;
	t_list		*pile_b;
	char		**arv;

	pointera = NULL;
	ft_initialisation(&pointerb, &pile_a, &pile_b, &arv);
	pointera = ft_pointera(argc, argv, pointera);
	if (pointera == NULL)
		return (0);
	pointerb = malloc(sizeof(t_pointer));
	if (pointerb == NULL)
	{
		free(pointera);
		return (0);
	}
	ft_init(&pile_a, &pile_b, pointera, pointerb);
	arv = ft_test_arg(argc, argv, pointera, pointerb);
	if (arv == NULL)
		pile_a = ft_maillonlist(argc, argv);
	else
		pile_a = ft_arv_maillonlist(arv);
	ft_swap(pile_a, pile_b, pointera, pointerb);
	return (0);
}
/*
void	ft_printlist(t_pointer *pointerA)
{
	t_list	*temp;
	int		i;

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
	temp = pointerA->end;
	while (i > 0)
	{
		printf("%d", temp->nb);
		temp = temp->before;
		i--;
	}
}*/
