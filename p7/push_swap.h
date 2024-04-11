/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:37:52 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/03 18:00:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

typedef struct s_limit
{
	int	max;
	int	index;
	int	size;
	int	min;
	int	indexm;
}	t_limit;

typedef struct s_nb
{
	int	nb;
	int	num;
	int	tempi;
	int	index;
	int	rev_placeb;
	int	la;
	int	lb;
	int	p;
}	t_nb;

typedef struct s_cont
{
	struct s_list	*first;
	struct s_list	*end;
}	t_pointer;

t_pointer	*ft_pointera(int argc, char **argv, t_pointer *pointera);
void		ft_init(t_list **pile_a, t_list **pile_b,
				t_pointer *pointerA, t_pointer *pointerB);
void		ft_swap(t_list *pile_a, t_list *pile_b,
				t_pointer *pointerA, t_pointer *pointerB);
void		ft_lstclear(t_list **chaine);
void		ft_lstadd_back(t_list **chaine, t_list *new);
void		ft_affect(t_list *pile_a, t_pointer *pointerA);
void		ft_pointerend(t_pointer *pointerc);
void		ft_sa(t_pointer *pointerA, int nb);
void		ft_sb(t_pointer *pointerB, int nb);
void		ft_ss(t_pointer *pointerA, t_pointer *pointerB);
void		ft_pa(t_pointer *pointerA, t_pointer *pointerB);
void		ft_pb(t_pointer *pointerA, t_pointer *pointerB);
void		ft_ra(t_pointer *pointerA, int nb);
void		ft_rb(t_pointer *pointerB, int nb);
void		ft_rr(t_pointer *pointerA, t_pointer *pointerB);
void		ft_rra(t_pointer *pointerA, int nb);
void		ft_rrb(t_pointer *pointerB, int nb);
void		ft_rrr(t_pointer *pointerA, t_pointer *pointerB);
void		ft_printlist(t_pointer *pointerA);
void		ft_algorithm(t_limit *limit, t_pointer *pointerA);
void		ft_pos(t_pointer *pointerA, t_limit *limit);
void		ft_class(t_pointer *pointerA,
				t_pointer *pointerB, t_list *pile_a, t_list *pile_b);
void		ft_try(t_limit *limit, t_pointer *pointerA);
void		ft_five(t_pointer *pointerA, t_pointer *pointerB);
void		ft_cross(t_pointer *pointerA, t_pointer *pointerB, int i);
void		ft_cross_b(t_pointer *pointerB);
void		ft_position(t_pointer *pointerB);
void		ft_few(t_pointer *pointerA, t_pointer *pointerB);
void		ft_final(t_pointer *pointerb);
void		ft_rev_algorithm(t_pointer *pointerb);
void		ft_push(t_pointer *pointera, t_pointer *pointerb, t_nb *tnb);
void		ft_ordo_b(t_pointer *pointerb);
void		ft_fre(char **patch);
void		ft_error(char **argv, t_pointer *pointera,
				t_pointer *pointerb, int nb);
void		ft_arv(char **arv, t_pointer *pointera,
				t_pointer *pointerb, int nb);
void		ft_clear(t_pointer *pointera, t_pointer *pointerb);
void		ft_malloc_error(char **dest, size_t n);
void		ft_tnb_deux(int rev_placea, t_pointer *pointera,
				t_pointer *pointerb, t_nb *tnb);
void		ft_tnb_trois(t_nb *tnb, t_pointer *pointera,
				t_pointer *pointerb, int i);
void		ft_tnb_quatre(t_nb *tnb, t_pointer *pointera,
				t_pointer *pointerb, int i);
void		ft_initialisation(t_pointer **pointerb,
				t_list **pile_a, t_list **pile_b, char ***arv);
char		**ft_test_arg(int argc, char **argv,
				t_pointer *pointera, t_pointer *pointerb);
char		**ft_split(char const *s, char c);
int			ft_which_big(t_limit *limita, t_pointer *pointerB);
int			ft_lstsize(t_list *lst);
int			ft_mx(t_pointer *pointerA, int nb);
int			ft_ordre(t_pointer *pointerA);
int			ft_rev_ordre(t_pointer *pointerB);
int			ft_trois(t_pointer *pointerA, t_pointer *pointerB);
int			ft_place(t_pointer *pointeB, int nb);
int			ft_max_nb(t_pointer *pointerB, int nb);
int			ft_min_nb(t_pointer *pointerB, int nb);
int			ft_rev_num(t_pointer *pointerA, int i, int rev_placeB);
int			main(int argc, char **argv);
int			ft_ordre_max(t_pointer *pointerb, int nb);
int			ft_ordre_min(t_pointer *pointerb, int nb);
int			ft_push_mm(t_pointer *pointerb, int nb, int ninf, int nsup);
int			ft_position_deux(t_pointer *pointerb, int i);
int			ft_push_deux(t_list *ant, t_list *pos,
				int nsup, t_pointer *pointerb);
int			ft_push_trois(t_list *ant, t_list *pos,
				int ninf, t_pointer *pointerb);
int			ft_tnb_un(int rev_placea, t_nb *tnb,
				t_pointer *pointera, t_pointer *pointerb);
int			ft_place_deux(t_list *ant, t_list *pos,
				t_pointer *pointerb, int nb);
int			ft_doublons(char **argv);
int			ft_doublons_deux(char **argv, int j, int i);
long		ft_atol(const char *nptr);
size_t		ft_nbparts(char const *s, char c);
size_t		ft_count_chr(char const *s, char c);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
t_nb		*ft_count_nb(t_pointer *pointerA, t_pointer *pointerB);
t_nb		*ft_num(t_pointer *pointerA, t_pointer *pointerB, int nb, int i);
t_nb		*ft_tnb_init(t_pointer *pointera, t_pointer *pointerb, int nb);
t_nb		*ft_algoo_tnb(t_nb *tnb, t_nb *tnbf);
t_list		*ft_maillonlist(int argc, char **argv);
t_list		*ft_lstnew(int nb);
t_list		*ft_arv_maillonlist(char **arv);
t_limit		*ft_which_max(t_pointer *pointerA);
t_limit		*ft_which_max_deux(t_limit *limit, t_list *temp, int i);
t_limit		*ft_init_limit(int nb, int i);

#endif
