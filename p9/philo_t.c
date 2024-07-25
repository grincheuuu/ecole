/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:31:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/07/24 15:32:15 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_create_philo(t_list *list)
{
	pthread_t		phi[list->nb];
	t_philo			*list_philo;
	t_pointer		*pointera;
	t_philo			*temp;
	unsigned int	i;

	i = 0;
	pointera = NULL;
	temp = NULL;
	list_philo = ft_maillonlist(list);
	pointera = malloc(sizeof(t_pointer));
	if (pointera == NULL)
		return ;
	pointera->first = NULL;
	pointera->end = NULL;
	ft_affect(list_philo, pointera);
	temp = pointera->first;
	pthread_mutex_init(&list->end_mutex, NULL);
	while (temp != NULL)
	{
		pthread_mutex_init(&list_philo->fork_r_mutex, NULL);
		pthread_mutex_init(&list_philo->write_mutex, NULL);
		temp->end_mutex = &list->end_mutex;
		temp = temp->next;
	}
	temp = pointera->first;
	while (i < list->nb && temp != NULL)
	{
		pthread_create(&phi[i], NULL, ft_thread_routine_deux, temp);
		temp = temp->next;
		i++;
	}
	i = 0;
	while (i < list->nb)
	{
		pthread_join(phi[i], NULL);
		i++;
	}
	temp = pointera->first;
	while (temp != NULL)
	{
		pthread_mutex_destroy(&list_philo->fork_r_mutex);
		pthread_mutex_destroy(&list_philo->write_mutex);
		temp = temp->next;
	}
//	pthread_mutex_destroy(&list->end_mutex);
	ft_lstclear(&pointera->first);
	free(pointera);
}

void	*ft_thread_routine_deux(void *data)
{
	t_philo	*list_philo;

	list_philo = (t_philo *)data;
	list_philo->begin_time = ft_translate_time("ms");
	list_philo->time = ft_translate_time("ms") - list_philo->time;
	while (list_philo->nb_eat > 0)
	{
		if (list_philo->numero_philo % 2 == 0)
		{
			pthread_mutex_lock(&list_philo->before->fork_r_mutex);
			pthread_mutex_lock(&list_philo->fork_r_mutex);
		}
		else
		{
			pthread_mutex_lock(&list_philo->fork_r_mutex);
			pthread_mutex_lock(&list_philo->before->fork_r_mutex);
		}
		pthread_mutex_lock(&list_philo->write_mutex);
		//		printf("\n%d numeroAAAAAAa\n", list_philo->numero_philo);
		ft_test(list_philo, list_philo->eat, "eating");
			//			pthread_mutex_unlock(&list_philo->before->fork_r_mutex);
			//			pthread_mutex_unlock(&list_philo->fork_r_mutex);
			//			pthread_mutex_unlock(&list_philo->write_mutex);
			//			printf("%d numero\n", list_philo->numero_philo);
			//			return (NULL);
		if (*(list_philo)->end == 0)
			printf("%ld philo %d is eating\n", (ft_translate_time("ms")
					- list_philo->begin_time), list_philo->numero_philo);
		pthread_mutex_unlock(&list_philo->write_mutex);
		usleep(list_philo->eat * 1000);
		pthread_mutex_unlock(&list_philo->before->fork_r_mutex);
		pthread_mutex_unlock(&list_philo->fork_r_mutex);
		list_philo->time = ft_translate_time("ms");
		list_philo->nb_eat = list_philo->nb_eat - 1;
		pthread_mutex_lock(&list_philo->write_mutex);
		ft_test(list_philo, list_philo->sleep, "sleeping");
//			pthread_mutex_unlock(&list_philo->write_mutex);
			//			return (NULL);
		if (*(list_philo)->end == 0)
			printf("%ld philo %d is sleeping\n", (ft_translate_time("ms")
					- list_philo->begin_time), list_philo->numero_philo);
		pthread_mutex_unlock(&list_philo->write_mutex);
		usleep(list_philo->sleep * 1000);
		pthread_mutex_lock(&list_philo->write_mutex);
		if (*(list_philo)->end == 0)
			printf("%ld philo %d is thinking\n", (ft_translate_time("ms")
					- list_philo->begin_time), list_philo->numero_philo);
		//		if (ft_test(list_philo, 0, NULL) == 1)
		//			return (NULL);
		pthread_mutex_unlock(&list_philo->write_mutex);
	}
	return (NULL);
}

int	ft_test(t_philo *listp, unsigned long nb, char *chr)
{
	unsigned long	actual;
	unsigned long	passed;
	unsigned long	st;
	long			i;

	i = 0;
	pthread_mutex_lock(listp->end_mutex);
	actual = ft_translate_time("ms");
	passed = actual - listp->time;
	st = actual - listp->begin_time;
	if (*(listp->end) == 1)
	{
		pthread_mutex_unlock(listp->end_mutex);
		return (1);
	}
	if (passed > listp->die)
	{
		printf("%ld philo 1 died\n", st);
		*(listp->end) = 1;
		pthread_mutex_unlock(listp->end_mutex);
		return (1);
	}
	i = (listp->die - nb - passed);
	if (nb > 0 && i < 0)
	{
		if (chr != NULL)
			printf("%ld philo %d is %s\n", st, listp->numero_philo, chr);
		usleep(listp->die - passed);
		printf("%ld philo %d is died\n", (st + listp->die - passed),
			listp->numero_philo);
		*(listp->end) = 1;
		pthread_mutex_unlock(listp->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(listp->end_mutex);
	return (0);
}
