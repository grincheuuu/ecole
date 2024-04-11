/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_glou.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:42:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/29 17:20:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_maillonlist(int argc, char **argv)
{
	t_list	*new;
	t_list	*chaine;
	int		i;

	i = 1;
	new = NULL;
	chaine = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atol(argv[i]));
		if (new == NULL)
		{
			ft_lstclear(&chaine);
			return (NULL);
		}
		ft_lstadd_back(&chaine, new);
		i++;
	}
	return (chaine);
}

t_list	*ft_arv_maillonlist(char **arv)
{
	t_list	*new;
	t_list	*chaine;
	int		i;

	i = 0;
	new = NULL;
	chaine = NULL;
	while (arv[i] != NULL)
	{
		new = ft_lstnew(ft_atol(arv[i]));
		if (new == NULL)
		{
			ft_lstclear(&chaine);
			return (NULL);
		}
		ft_lstadd_back(&chaine, new);
		i++;
	}
	ft_fre(arv);
	return (chaine);
}

void	ft_clear(t_pointer *pointera, t_pointer *pointerb)
{
	ft_lstclear(&pointera->first);
	ft_lstclear(&pointerb->first);
	free(pointera);
	free(pointerb);
}

int	ft_push_deux(t_list *ant, t_list *pos, int nsup, t_pointer *pointerb)
{
	if ((ant->nb == nsup && pos->nb == ft_mx(pointerb, 1))
		|| (ant->nb == ft_mx(pointerb, 1)
			&& pos->nb == nsup))
		return (0);
	return (1);
}

int	ft_push_trois(t_list *ant, t_list *pos, int ninf, t_pointer *pointerb)
{
	if ((ant->nb == ft_mx(pointerb, 0) && pos->nb == ninf)
		|| (ant->nb == ninf && pos->nb
			== ft_mx(pointerb, 0)))
		return (0);
	return (1);
}
