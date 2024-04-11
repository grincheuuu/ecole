/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algoo_deux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:39:24 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/02 20:00:13 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nb	*ft_algoo_tnb(t_nb *tnb, t_nb *tnbf)
{
	t_nb	*sup;

	sup = NULL;
	if (tnb->num > tnbf->num)
	{
		sup = tnb;
		tnb = tnbf;
		free(sup);
	}
	else
		free(tnbf);
	return (tnb);
}

int	ft_min_nb(t_pointer *pointerB, int nb)
{
	t_list	*temp;

	temp = pointerB->first;
	while (temp != NULL)
	{
		if (temp->nb < nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_which_big(t_limit *limita, t_pointer *pointerB)
{
	t_limit	*limitb;

	limitb = ft_which_max(pointerB);
	if (limitb->max < 0 && limita->max > 0)
	{
		free(limitb);
		return (0);
	}
	else if (limita->max < 0 && limitb->max > 0)
	{
		free(limitb);
		return (1);
	}
	else if ((limita->max - limitb->max) < 0)
	{
		free(limitb);
		return (1);
	}
	free(limitb);
	return (0);
}

int	ft_doublons(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1] != NULL)
	{
		j = i + 1;
		if (ft_doublons_deux(argv, j, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_doublons_deux(char **argv, int j, int i)
{
	int	g;
	int	t;

	while (argv[j] != NULL)
	{
		t = 0;
		g = 0;
		while (argv[i][t] != '\0')
		{
			if (argv[i][t] != argv[j][t])
			{
				g = 0;
				break ;
			}
			g = 1;
			t++;
		}
		if (g == 1 && argv[j][t] == '\0')
			return (1);
		j++;
	}
	return (0);
}
