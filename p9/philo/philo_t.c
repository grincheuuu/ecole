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

void	ft_create_philo(t_list *list, unsigned int N)
{
	pthread_t		phi[N];
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
	ft_thread_mutex_init(&list, pointera);
	temp = pointera->first;
	while (i < list->nb && temp != NULL)
	{
		pthread_create(&phi[i], NULL, ft_thread_routine_un, temp);
		temp = temp->next;
		i++;
	}
	ft_thread_clean(&pointera, &list, phi, list_philo);
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
	if ((passed) >= listp->die)
	{
		*(listp->end) = 1;
		pthread_mutex_unlock(listp->end_mutex);
		printf("%ld philo 1 died\n", st);
		return (1);
	}
	return (ft_test_deux(listp, chr, passed, nb));
}

int	ft_test_deux(t_philo *listp, char *chr, unsigned long passed,
		unsigned long nb)
{
	long			i;
	unsigned long	st;
	unsigned long	actual;

	actual = ft_translate_time("ms");
	st = actual - listp->begin_time;
	i = (listp->die - nb - passed) + 5;
	if (nb > 0 && i < 0)
	{
		*(listp->end) = 1;
		pthread_mutex_unlock(listp->end_mutex);
		printf("%ld philo %d has taken a fork\n", (ft_translate_time("ms")
				- listp->begin_time), listp->numero_philo);
		printf("%ld philo %d has taken a fork\n", (ft_translate_time("ms")
				- listp->begin_time), listp->numero_philo);
		if (chr != NULL)
			printf("%ld philo %d is %s\n", st, listp->numero_philo, chr);
		if ((listp->die - passed) > 0)
			usleep(listp->die - passed);
		printf("%ld philo %d is died\n", (st + listp->die - passed),
			listp->numero_philo);
		return (1);
	}
	pthread_mutex_unlock(listp->end_mutex);
	return (0);
}
