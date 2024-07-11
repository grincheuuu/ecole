/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:51:24 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/10 15:51:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_list
{
	unsigned int	nb;
	unsigned int	write;
	unsigned long	die;
	unsigned long	think;
	unsigned long	eat;
	unsigned long	sleep;
	unsigned long	fork_r;
	unsigned long	fork_l;
	unsigned long	nb_eat;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	fork_r_mutex;
	pthread_mutex_t	fork_l_mutex;
}					t_list;

unsigned long		ft_atoiulong(const char *nptr);
t_list				*ft_initialize(char **argv);
int					ft_atol_test(const char *nptr);
int					ft_atoi(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_bad_argument(void);
void				ft_analyse_argc(int argc, char **argv);
void				ft_only_philo(char **argv);
unsigned long		ft_translate_time(char *type);
double				ft_time(void);

#endif
