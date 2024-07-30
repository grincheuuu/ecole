/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:41:08 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/10 15:44:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_only_philo(t_list *list)
{
	pthread_t	p1;

	pthread_create(&p1, NULL, ft_thread_routine, list);
	pthread_join(p1, NULL);
}

void	ft_test_die(t_list *list, unsigned long nb)
{
	unsigned long	actual;
	unsigned long	passed;
	unsigned long	st;

	actual = ft_translate_time("ms");
	passed = actual - list->time;
	st = actual - list->begin_time;
	if (passed > list->die)
	{
		printf("%ld philo 1 died", st);
		return ;
	}
	if (nb > 0)
	{
		printf("%ld philo 1 has taken a fork\n", (ft_translate_time("ms")
				- list->begin_time));
		usleep(list->die - passed);
		printf("%ld philo 1 is died\n", (st + list->die - passed));
	}
}

void	*ft_thread_routine(void *data)
{
	t_list	*list;

	list = (t_list *)data;
	list->begin_time = ft_translate_time("ms");
	list->time = ft_translate_time("ms") - list->time;
	ft_test_die(list, list->eat);
	return (NULL);
}

void	ft_thread_mutex_init(t_list **list, t_pointer *pointera)
{
	t_philo	*temp;

	temp = pointera->first;
	pthread_mutex_init(&(*list)->end_mutex, NULL);
	while (temp != NULL)
	{
		pthread_mutex_init(&temp->write_mutex, NULL);
		pthread_mutex_init(&temp->fork_r_mutex, NULL);
		temp->end_mutex = &(*list)->end_mutex;
		temp = temp->next;
	}
}

void	ft_thread_clean(t_pointer **pointera, t_list **list, pthread_t phi[],
		t_philo *list_philo)
{
	unsigned int	i;
	t_philo			*temp;

	i = 0;
	temp = (*pointera)->first;
	while (i < (*list)->nb)
	{
		pthread_join(phi[i], NULL);
		i++;
	}
	while (temp != NULL)
	{
		pthread_mutex_destroy(&temp->fork_r_mutex);
		pthread_mutex_destroy(&temp->write_mutex);
		temp = temp->next;
	}
	pthread_mutex_destroy(list_philo->end_mutex);
	ft_lstclear(&(*pointera)->first);
	free(*pointera);
}
