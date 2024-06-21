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


void    ft_bad_argument(void)
{
    write (2, "the program need 'nb of philo'", 30);   
    write (2, ", 'time to die', 'time to eat', 'time to sleep', time in ms\n", 60);
    write (2, "the program can take an additional argument ", 44);
    write (2, "'number of time each philosopher must eat\n", 42);
    exit (EXIT_FAILURE);
}

void    ft_analyse_argc(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc != 5 || argc != 6)
    {
        ft_bad_argument();
    }
    if (ft_atoi(argv[0]) == 0 && ft_atoi(argv[0]) <= 1024)
    {
        write (2, "nb of philosopher are > 0 et <= 1024\n", 37);
        exit (EXIT_FAILURE);
    }
    while (argv[i] != NULL)
    {
        if (ft_atol_test(argv[i]) == 1)
        {
            ft_bad_argument();
            exit (EXIT_FAILURE);
        }
        i++;
    }
}

t_list  *ft_initialize(char **argv)
{
    t_list  *list;

    list = malloc(sizeof(t_list));
    if (list == NULL)
        return (NULL);
    list->nb = ft_atoi(argv[1]);
    list->die = ft_atoiulong(argv[2]);
    list->think = ft_atoiulong(argv[3]);
    list->eat = ft_atoiulong(argv[4]);
    list->sleep = ft_atoiulong(argv[5]);
    list->fork_r = 1;
    list->fork_l = 1;
    list->sleep = ft_atoiulong(argv[5]);
    return (list);
}

unsigned long   ft_translate_time(char *type)
{
    struct  timeval  tv;
    double  time;

    gettimeofday(&tv, NULL);
    printf("\ntv %ld s. %ld micro s\n\n", tv.tv_sec, tv.tv_usec);
    time = tv.tv_sec + tv.tv_usec / 1000000.0;
    printf("%f time\n", time);
    if (ft_strncmp(type, "ms", 2) == 0)
    {
        return (time * 1000);
    }
    if (ft_strncmp(type, "micro", 5) == 0)
        return (time * 1000000);
    return (0);
}

void    ft_only_philo(char **argv)
{
    unsigned long   time_ms;

    (void)argv;
    time_ms = 0;
    time_ms = ft_translate_time("ms");
    printf("%ld time_ms\n", time_ms);
    time_ms = ft_translate_time("micro");
    printf("%ld time_ms\n", time_ms);
}

int main(int argc, char **argv)
{
//    pthread_t   tid1;
//    t_list  *list;

        (void)argc;
//    ft_analyse_arg(argc, argv);
//    list = ft_initialize(argv);
    if (ft_atoi(argv[1]) == 1)
        ft_only_philo(argv);
/*    pthread_mutex_init(&counter.count_mutex, NULL);
    pthread_create(&tid1, NULL, thread_routine, &counter);
    printf("\nMAIN, creation 1er thread %lu\n", tid1);
    pthread_create(&tid2, NULL, thread_routine, &counter);
    printf("\nMAIN, creation 2eme thread %lu\n", tid2);
    pthread_join(tid1, NULL);
    printf("\nunion du 1er thread %lu\n", tid1);
    pthread_join(tid2, NULL);
    printf("\nunion du 2eme thread %lu\n", tid2);
    if (counter.count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERREUR ! Le compte est de %u%s\n",
					RED, counter.count, NC);
	else
		printf("%sMain: OK. Le compte est de %u%s\n",
					GREEN, counter.count, NC);
    pthread_mutex_destroy(&counter.count_mutex);*/
    return (0);
}
                

