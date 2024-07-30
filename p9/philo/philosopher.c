/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:07:55 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/10 15:07:57 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_bad_argument(void)
{
	write(2, "the program need : 'nb of philo' ", 33);
	write(2, "'time to die' 'time to eat' 'time to sleep'.\n", 45);
	write(2, "the time is in ms.\n", 19);
	write(2, "the program can take an additional argument : ", 46);
	write(2, "'number of time each philosopher must eat'.\n", 44);
	exit(EXIT_FAILURE);
}

void	ft_analyse_argc(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		ft_bad_argument();
	}
	if (ft_atol_test(argv[1]) == 1 || (ft_atoiulong(argv[1]) > 200)
		|| (ft_atoiulong(argv[1]) == 0))
	{
		write(2, "nb of philosopher are > 0 et <= 1024\n", 37);
		exit(EXIT_FAILURE);
	}
	while (argv[i] != NULL)
	{
		if (ft_atol_test(argv[i]) == 1)
		{
			ft_bad_argument();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

t_list	*ft_initialize(char **argv)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->nb = ft_atoi(argv[1]);
	list->die = ft_atoiulong(argv[2]);
	list->eat = ft_atoiulong(argv[3]);
	list->sleep = ft_atoiulong(argv[4]);
	list->fork_r = 1;
	list->fork_l = 1;
	list->end = 0;
	list->write = 0;
	list->nb_eat = ft_atoiulong(argv[5]);
	list->begin_time = 0;
	list->time = 0;
	return (list);
}

unsigned long	ft_translate_time(char *type)
{
	struct timeval	tv;
	double			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec + tv.tv_usec / 1000000.0;
	if (ft_strncmp(type, "ms", 2) == 0)
	{
		return (time * 1000);
	}
	if (ft_strncmp(type, "micro", 5) == 0)
		return (time * 1000000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	ft_analyse_argc(argc, argv);
	list = ft_initialize(argv);
	if (ft_atoi(argv[1]) == 1)
		ft_only_philo(list);
	else
		ft_create_philo(list, list->nb);
	free(list);
	return (0);
}
