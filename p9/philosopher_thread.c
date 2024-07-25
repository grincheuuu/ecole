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
/*
void	ft_create_philo(t_list *list)
{
	pthread_t		phi[list->nb];
	t_go			**ldeux;
	unsigned int	i;

	//	t_philo			*philo;
	i = 1;
	ldeux = ft_iniatlize_ldeux(list);
	while (i <= list->nb)
	{
		pthread_mutex_init(&list->fork_r_mutex, NULL);
		pthread_mutex_init(&list->fork_l_mutex, NULL);
		pthread_mutex_init(&list->write_mutex, NULL);
		pthread_create(&phi[i], NULL, ft_thread_routine_deux, ldeux);
		i++;
	}
	i = 1;
	while (i <= list->nb)
	{
		pthread_join(phi[i], NULL);
		i++;
	}
}_mutex, NULL);


t_go	**ft_initialize_ldeux(t_list *list)
{
	t_go	**ldeux;
	int		i;

	ldeux = malloc((list->nb + 1) * sizeof(t_go *));
	if (ldeux == NULL)
		return (NULL);
	while (ldeux[i] != NULL)
	{
		list->nb = list->nb;
		list->die = list->die;
		list->eat = list->eat;
		list->sleep = list->sleep;
		list->fork_r = 1;
		list->write = 0;
		list->nb_eat = list->nb_eat;
		list->begin_time = 0;
		list->time = 0;
		i++;
	}
	ldeux[i] = NULL;
	return (ldeux);
}

void	*ft_thread_routine_deux(void *data)
{
	t_list	*list;

	list = (t_list *)data;
	list->begin_time = ft_translate_time("ms");
	list->time = ft_translate_time("ms") - list->time;
	while (list->nb_eat > 0)
	{
		if (ft_test(list, list->eat, "eating") == 1)
			break ;
		pthread_mutex_lock(&list->fork_r_mutex);
		pthread_mutex_lock(&list->fork_l_mutex);
		pthread_mutex_lock(&list->write_mutex);
		printf("%ld philo %d is eating\n", (ft_translate_time("ms")
				- list->begin_time), list->nb);
		pthread_mutex_unlock(&list->write_mvoid	ft_lstclear(t_philo **chaine)utex);
		usleep(list->eat * 1000);
		pthread_mutex_unlock(&list->fork_r_mutex);
		pthread_mutex_unlock(&list->fork_l_mutex);
		list->time = ft_translate_time("ms");
		list->nb_eat = list->nb_eat - 1;
		if (ft_test(list, list->sleep, "sleeping") == 1)
			break ;
		pthread_mutex_lock(&list->write_mutex);
		printf("%ld philo %d is sleeping\n", (ft_translate_time("ms")
				- list->begin_time), list->nb);
		pthread_mutex_unlock(&list->write_mutex);
		usleep(list->sleep * 1000);
		pthread_mutex_lock(&list->write_mutex);
		printf("%ld philo %d is thinking\n", (ft_translate_time("ms")
				- list->begin_time), list->nb);
		pthread_mutex_unlock(&list->write_mutex);
		if (ft_test(list, 0, NULL) == 1)
			break ;
	}
	return (NULL);
}

int	ft_test(t_list *list, unsigned long nb, char *chr)
{
	unsigned long	actual;
	unsigned long	passed;
	unsigned long	st;
	long			i;

	actual = ft_translate_time("ms");
	passed = actual - list->time;
	st = actual - list->begin_time;
	if (passed > list->die)
	{
		printf("%ld philo 1 died", st);
		return (1);
	}
	i = (list->die - nb - passed);
	if (nb > 0 && i < 0)
	{
		if (chr != NULL)
			printf("%ld philo 1 is %s\n", st, chr);
		usleep(list->die - passed);
		printf("%ld philo 1 is died", (st + list->die - passed));
		return (1);
	}
	return (0);
}*/

void	ft_only_philo(t_list *list)
{
	pthread_t	p1;

	pthread_create(&p1, NULL, ft_thread_routine, list);
	pthread_join(p1, NULL);
}

int	ft_test_die(t_list *list, unsigned long nb, char *chr)
{
	unsigned long	actual;
	unsigned long	passed;
	unsigned long	st;
	long			i;

	actual = ft_translate_time("ms");
	passed = actual - list->time;
	st = actual - list->begin_time;
	if (passed > list->die)
	{
		printf("%ld philo 1 died", st);
		return (1);
	}
	i = (list->die - nb - passed);
	if (nb > 0 && i < 0)
	{
		if (chr != NULL)
			printf("%ld philo 1 is %s\n", st, chr);
		usleep(list->die - passed);
		printf("%ld philo 1 is died", (st + list->die - passed));
		return (1);
	}
	return (0);
}

void	*ft_thread_routine(void *data)
{
	t_list *list;

	list = (t_list *)data;
	list->begin_time = ft_translate_time("ms");
	list->time = ft_translate_time("ms") - list->time;
	while (list->nb_eat > 0)
	{
		if (ft_test_die(list, list->eat, "eating") == 1)
			break ;
		printf("%ld philo 1 is eating\n", (ft_translate_time("ms")
				- list->begin_time));
		usleep(list->eat * 1000);
		list->time = ft_translate_time("ms");
		list->nb_eat = list->nb_eat - 1;
		if (ft_test_die(list, list->sleep, "sleeping") == 1)
			break ;
		printf("%ld philo 1 is sleeping\n", (ft_translate_time("ms")
				- list->begin_time));
		usleep(list->sleep * 1000);
		printf("%ld philo 1 is thinking\n", (ft_translate_time("ms")
				- list->begin_time));
		if (ft_test_die(list, 0, NULL) == 1)
			break ;
	}
	return (NULL);
}