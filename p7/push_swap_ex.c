/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:57:20 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 15:39:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tnb_un(int rev_placea, t_nb *tnb,
		t_pointer *pointera, t_pointer *pointerb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (rev_placea > tnb->rev_placeb)
		i = (rev_placea + tnb->rev_placeb
				- (rev_placea
					- tnb->rev_placeb)) / 2;
	else
		i = (rev_placea + tnb->rev_placeb
				- (tnb->rev_placeb
					- rev_placea)) / 2;
	while (j < i)
	{
		ft_rrr(pointera, pointerb);
		j++;
	}
	while (rev_placea > i)
	{
		ft_rra(pointera, 3);
		i++;
	}
	return (i);
}

void	ft_tnb_deux(int rev_placea, t_pointer *pointera,
		t_pointer *pointerb, t_nb *tnb)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < rev_placea)
	{
		ft_rra(pointera, 3);
		i++;
	}
	while (j < tnb->p)
	{
		ft_rb(pointerb, 3);
		j++;
	}
}

void	ft_tnb_trois(t_nb *tnb, t_pointer *pointera, t_pointer *pointerb, int i)
{
	int	j;

	j = 0;
	if (tnb->p >= tnb->lb / 2)
	{
		while (i < tnb->index)
		{
			ft_ra(pointera, 3);
			i++;
		}
		while (j < tnb->rev_placeb)
		{
			ft_rrb(pointerb, 3);
			j++;
		}
	}
	else
		ft_tnb_quatre(tnb, pointera, pointerb, i);
}

void	ft_tnb_quatre(t_nb *tnb, t_pointer *pointera,
		t_pointer *pointerb, int i)
{
	int	j;

	j = 0;
	if (tnb->index > tnb->p)
		i = (tnb->index + tnb->p
				- (tnb->index - tnb->p)) / 2;
	else
		i = (tnb->index + tnb->p
				- (tnb->p - tnb->index)) / 2;
	while (j < i)
	{
		ft_rr(pointera, pointerb);
		j++;
	}
	while (tnb->index > i)
	{
		ft_ra(pointera, 3);
		i++;
	}
	while (tnb->p > i)
	{
		ft_rb(pointerb, 3);
		i++;
	}
}

int	ft_rev_num(t_pointer *pointera, int i, int rev_placeb)
{
	int	rev_num_a;

	rev_num_a = ft_lstsize(pointera->first) - i + 1;
	if (rev_num_a >= rev_placeb)
		return ((rev_num_a + rev_placeb
				- (rev_num_a - rev_placeb) / 2) + rev_num_a - rev_placeb);
	else
		return ((rev_num_a + rev_placeb
				- (rev_placeb - rev_num_a) / 2) + rev_placeb - rev_num_a);
}
