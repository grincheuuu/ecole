/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:19 by gschwart          #+#    #+#             */
/*   Updated: 2025/06/30 18:05:21 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_room
{
    int x;
    int y;
    bool is_visited;
    bool is_start;
    bool is_end;
    char *name;
    struct s_room **neighbors;
}            t_room;

/// structure principale ///
typedef struct s_lem_in
{
    int nb_ants;
    t_room *start;
    t_room *end;
    t_room **rooms;
}               t_lem_in;

typedef struct s_list
{
    struct s_list  **before;
    struct s_list   **next;
    char            *name;
    bool        is_start;
    bool        is_end;
    char            *chemin;
    int             count;
    int             no_end; // 0 pas fini, 1 pas de end
}   g_list;

typedef struct s_chaine
{
    char    *name;
    char    *chemin;
    int     count;
    struct s_chaine *next;
} t_chaine;

void	ft_fre_pointer(g_list **pointer);
g_list    **ft_pointer_begin(t_lem_in *run, g_list ***all_room);
void    ft_maillon_list(g_list **pointer, t_lem_in *run, g_list ***all_room);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void    ft_count_chemin(g_list **pointer, g_list **all_room, char *suivant);
void    ft_next_maillon(g_list **pointer, t_lem_in *run, g_list ***all_room);
g_list    *ft_new_add(t_room *ad, g_list *pointer);
g_list  **ft_create_tab(g_list **pointer);
int     ft_verifie(t_lem_in *run, g_list **pointer, t_chaine ***a);
int     ft_calcul_end(int *tab, int ants, int t);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int	    ft_strlen(const char *str);
void	ft_printf_maillon(g_list * pointer, int v);
void	ft_print_all(g_list **all_room, char *str);
g_list    **ft_ajout_room(g_list **all_room, g_list *name);
int	    ft_search_room_all(g_list **all_room, char *name);
void    ft_chemin_count_new(g_list *pointer, g_list **new);
int     ft_calcul_end_deux(t_chaine **a, int ants);
void	ft_create_add_new(t_chaine **chaine, g_list *new);
t_chaine	*ft_lstnew(g_list *new);
void	ft_lstadd_back(t_chaine **lst, t_chaine *new);
void	ft_print_a(t_chaine **a);
void	ft_free_a(t_chaine **a);
void	ft_free_all(g_list **pointer);
int	ft_compare_maillon(g_list **pointer, g_list *a, int i, int j);
void	ft_free_t_room(t_room *ab);
void	ft_free_all_end(g_list **pointer);

#endif
