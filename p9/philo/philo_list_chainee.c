/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list_chainee.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:01 by gschwart          #+#    #+#             */
/*   Updated: 2024/07/24 15:22:18 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*ft_maillonlist(t_list *list)
{
	t_philo			*new;
	t_philo			*chaine;
	unsigned int	i;

	i = 1;
	new = NULL;
	chaine = NULL;
	while (i <= list->nb)
	{
		new = ft_lstnew(list, i);
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

t_philo	*ft_lstnew(t_list *list, unsigned int n)
{
	t_philo	*new_node;

	new_node = (t_philo *)malloc(sizeof(t_philo));
	if (new_node == NULL)
		return (NULL);
	new_node->nb = list->nb;
	new_node->die = list->die;
	new_node->eat = list->eat;
	new_node->sleep = list->sleep;
	new_node->numero_philo = n;
	new_node->end = &list->end;
	new_node->write = &list->write;
	new_node->fork_r = 1;
	new_node->nb_eat = list->nb_eat;
	new_node->begin_time = 0;
	new_node->time = 0;
	new_node->before = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_philo **chaine, t_philo *new)
{
	t_philo	*temp;

	temp = *chaine;
	if (*chaine == NULL)
		*chaine = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->before = temp;
		new->next = NULL;
	}
}

void	ft_affect(t_philo *pile_a, t_pointer *pointera)
{
	t_philo	*temp;

	temp = pile_a;
	if (pile_a == NULL)
		return ;
	pointera->first = pile_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	pointera->end = temp;
	pile_a->before = pointera->end;
}

void	ft_lstclear(t_philo **chaine)
{
	t_philo	*current;
	t_philo	*second;

	if (*chaine == NULL)
		return ;
	current = *chaine;
	while (current != NULL)
	{
		second = current->next;
		free(current);
		current = second;
	}
	*chaine = NULL;
}
