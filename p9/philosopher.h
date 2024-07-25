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
	int	write;
	unsigned long	die;
	unsigned int	end;
	unsigned long	eat;
	unsigned long	sleep;
	unsigned long	fork_r;
	unsigned long	fork_l;
	unsigned long	nb_eat;
	unsigned long	time;
	unsigned long	begin_time;
	pthread_mutex_t	end_mutex;
}					t_list;

typedef struct s_philo
{
	unsigned int	nb;
	unsigned int	numero_philo;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
	unsigned int	*end;
	int	*write;
	unsigned long	fork_r;
	unsigned long	nb_eat;
	unsigned long	time;
	unsigned long	begin_time;
	pthread_mutex_t	fork_r_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*end_mutex;
	struct s_philo	*before;
	struct s_philo	*next;
}					t_philo;

typedef struct s_pointer
{
	struct s_philo	*first;
	struct s_philo	*end;
}					t_pointer;

unsigned long		ft_atoiulong(const char *nptr);
t_list				*ft_initialize(char **argv);
int					ft_atol_test(const char *nptr);
int					ft_atoi(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_bad_argument(void);
void				ft_analyse_argc(int argc, char **argv);
unsigned long		ft_translate_time(char *type);
void				*ft_thread_routine(void *data);
void				ft_translate(char **argv);
int					ft_test_die(t_list *list, unsigned long nb, char *chr);
void				ft_only_philo(t_list *list);
void				ft_create_philo(t_list *list);
void				*ft_thread_routine_deux(void *data);
int					ft_test(t_philo *listp, unsigned long nb, char *chr);
t_philo				*ft_maillonlist(t_list *list);
t_philo				*ft_lstnew(t_list *list, unsigned int n);
void				ft_lstadd_back(t_philo **chaine, t_philo *new);
void				ft_affect(t_philo *pile_a, t_pointer *pointera);
void				ft_lstclear(t_philo **chaine);
void				ft_create_philo(t_list *list);
t_pointer   		**ft_create_pointera(t_philo *list_philo);

#endif
