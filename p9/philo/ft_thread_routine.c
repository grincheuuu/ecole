/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:25:19 by gschwart          #+#    #+#             */
/*   Updated: 2024/07/29 19:25:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_lauch(t_philo **list_philo)
{
	if ((*list_philo)->numero_philo % 2 == 0)
	{
		pthread_mutex_lock(&(*list_philo)->before->fork_r_mutex);
		pthread_mutex_lock(&(*list_philo)->fork_r_mutex);
	}
	else
	{
		usleep(1000);
		pthread_mutex_lock(&(*list_philo)->fork_r_mutex);
		pthread_mutex_lock(&(*list_philo)->before->fork_r_mutex);
	}
}

void	ft_philo_eat(t_philo **list_philo)
{
	pthread_mutex_lock(&(*list_philo)->write_mutex);
	ft_test(*list_philo, (*list_philo)->eat, "eating");
	pthread_mutex_lock((*list_philo)->end_mutex);
	if (*(*list_philo)->end == 0)
	{
		printf("%ld philo %d has taken a fork\n", (ft_translate_time("ms")
				- (*list_philo)->begin_time), (*list_philo)->numero_philo);
		printf("%ld philo %d has taken a fork\n", (ft_translate_time("ms")
				- (*list_philo)->begin_time), (*list_philo)->numero_philo);
		printf("%ld philo %d is eating\n", (ft_translate_time("ms")
				- (*list_philo)->begin_time), (*list_philo)->numero_philo);
	}
	else
		(*list_philo)->nb_eat = 1;
	pthread_mutex_unlock((*list_philo)->end_mutex);
	pthread_mutex_unlock(&(*list_philo)->write_mutex);
	usleep((*list_philo)->eat * 1000);
	pthread_mutex_unlock(&(*list_philo)->before->fork_r_mutex);
	pthread_mutex_unlock(&(*list_philo)->fork_r_mutex);
	(*list_philo)->nb_eat = (*list_philo)->nb_eat - 1;
}

void	*ft_thread_routine_un(void *data)
{
	t_philo	*list_philo;

	list_philo = (t_philo *)data;
	list_philo->begin_time = ft_translate_time("ms");
	list_philo->time = ft_translate_time("ms") - list_philo->time;
	while (list_philo->nb_eat > 0)
	{
		ft_lauch(&list_philo);
		ft_philo_eat(&list_philo);
		ft_sleeping(&list_philo);
		pthread_mutex_lock(&list_philo->write_mutex);
		pthread_mutex_lock(list_philo->end_mutex);
		if (*(list_philo)->end == 0)
			printf("%ld philo %d is thinking\n", (ft_translate_time("ms")
					- list_philo->begin_time), list_philo->numero_philo);
		pthread_mutex_unlock(list_philo->end_mutex);
		pthread_mutex_unlock(&list_philo->write_mutex);
	}
	return (NULL);
}

void	ft_sleeping(t_philo **list_philo)
{
	(*list_philo)->time = ft_translate_time("ms");
	pthread_mutex_lock(&(*list_philo)->write_mutex);
	ft_test(*list_philo, (*list_philo)->sleep, "sleeping");
	pthread_mutex_lock((*list_philo)->end_mutex);
	if (*(*list_philo)->end == 0)
		printf("%ld philo %d is sleeping\n", (ft_translate_time("ms")
				- (*list_philo)->begin_time), (*list_philo)->numero_philo);
	pthread_mutex_unlock((*list_philo)->end_mutex);
	pthread_mutex_unlock(&(*list_philo)->write_mutex);
	usleep((*list_philo)->sleep * 1000);
}
