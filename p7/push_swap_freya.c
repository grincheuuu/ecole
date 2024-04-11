/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_freya.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:38:51 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 16:35:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ordre_max(t_pointer *pointerb, int nb)
{
	t_list	*temp;
	t_limit	*limit;
	int		nsup;

	temp = pointerb->first;
	limit = ft_which_max(pointerb);
	nsup = limit->max;
	if (nsup < nb)
		nsup = nb;
	while (temp != NULL)
	{
		if (temp->nb < nsup && temp->nb > nb)
			nsup = temp->nb;
		temp = temp->next;
	}
	free(limit);
	return (nsup);
}

int	ft_ordre_min(t_pointer *pointerb, int nb)
{
	t_list	*temp;
	t_limit	*limit;
	int		ninf;

	temp = pointerb->first;
	limit = ft_which_max(pointerb);
	ninf = limit->min;
	if (ninf > nb)
		ninf = nb;
	while (temp != NULL)
	{
		if (temp->nb > ninf && temp->nb < nb)
			ninf = temp->nb;
		temp = temp->next;
	}
	free(limit);
	return (ninf);
}

int	ft_push_mm(t_pointer *pointerb, int nb, int ninf, int nsup)
{
	t_list	*ant;
	t_list	*pos;
	int		p;

	p = 0;
	ant = pointerb->first;
	pos = pointerb->first->next;
	while (pos != NULL)
	{
		p++;
		if (nb == ninf)
		{
			if (ft_push_deux(ant, pos, nsup, pointerb) == 0)
				return (p);
		}
		else if (nb == nsup)
		{
			if (ft_push_trois(ant, pos, ninf, pointerb) == 0)
				return (p);
		}
		ant = ant->next;
		pos = pos->next;
	}
	return (p);
}

void	ft_error(char **argv, t_pointer *pointera, t_pointer *pointerb, int nb)
{
	if (nb != 3)
	{
		ft_clear(pointera, pointerb);
		write (2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	else
	{
		ft_fre(argv);
		ft_clear(pointera, pointerb);
		write (2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

void	ft_fre(char **patch)
{
	int	i;

	i = 0;
	while (patch[i] != NULL)
	{
		free(patch[i]);
		i++;
	}
	free(patch);
}
