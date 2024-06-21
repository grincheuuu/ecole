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

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

#define TIMES_TO_COUNT 21000

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

typedef struct s_count
{
    pthread_mutex_t count_mutex;
    unsigned int count;
}   t_count;

void    *thread_routine(void *data)
{
    pthread_t   tid;
    t_count *counter;
    unsigned int    i;

    tid = pthread_self();
    counter = (t_count *)data;
    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread [%ld]: compte au depart = %u.%s\n", YELLOW, (unsigned long)tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);
    i = 0;
    while (i < TIMES_TO_COUNT)
    {
        pthread_mutex_lock(&counter->count_mutex);
        counter->count++;
        pthread_mutex_unlock(&counter->count_mutex);
        i++;
    }
    pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [%ld]: Compte final = %u.%s\n",
		BYELLOW, (unsigned long)tid, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
//    printf("hello");
    return (NULL);
}

void    *thread_routine_deux(void *data)
{
    pthread_t   tid;

    tid = pthread_self();
    printf(" Word ");
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t   tid1;
    pthread_t   tid2;
    t_count counter;
    char	str[] = " hello word";
    int	i;


	i = 0;
    counter.count = 0;
    pthread_mutex_init(&counter.count_mutex, NULL);
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
    pthread_mutex_destroy(&counter.count_mutex);
    return (0);
}
                

