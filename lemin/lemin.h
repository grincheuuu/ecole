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
    int nb_rooms;
    t_room *start;
    t_room *end;
    t_room *rooms;
}               t_lem_in;

typedef struct s_list
{
    t_room   **before;
    t_room   **next;
    char            *name;
    bool        is_start;
    bool        is_end;
    char            **chemin;
    int             count;
    int             no_end; // 0 pas fini, 1 pas de end
}   t_list;

t_list	*ft_lstnew(void);
void	ft_lstadd_back(t_list **chaine, t_list *new);
void	ft_lstclear(t_list **chaine);
void	ft_affect(t_list *pile_a, t_pointer *pointera);
void	ft_pointerend(t_pointer *pointerc);
t_pointer	*ft_pointera(int argc, char **argv, t_pointer *pointera);
void	ft_fre(char **patch);

t_list    **ft_pointer_begin(t_lem_in *run);
void    ft_maillon_list(t_list **pointer);

#endif

