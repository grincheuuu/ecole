#ifndef LEM_IN_H
# define LEM_IN_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "fcntl.h" // Read
# include "../libft/libft.h"
# include "stdio.h"  // printf and other
# include "stdlib.h" // malloc & free
# include "unistd.h"
#include <stdbool.h>

/// Parsing ///
typedef struct s_parse
{
    char *line;
    char **tab;
    int i;
	int status;
    int is_begin;
    int is_end;
	t_list *file;
	t_list *rooms;

}            t_parse;


/// structure d'une salle ///
typedef struct s_room
{
    int x;
    int y;
    bool is_visited;
    bool is_start;
    bool is_end;
    char *name;
	struct s_room	*back;
	t_list	*neightbors_lst;
    struct s_room **neighbors;
}            t_room;

typedef struct s_ant
{
	t_list *path;
	t_room *room;
}		t_ant;

/// structure principale ///
typedef struct s_lem_in
{
    int nb_ants;
    int nb_rooms;
	t_ant **ants;
    t_room *start;
	t_list	*paths;
    t_room *end;
    t_room **rooms;
}               t_lem_in;

typedef struct s_chemin
{
    char                **chemin;
    int                 count;
    struct s_chemin     *next;
}   t_chemin;

typedef struct s_tab_chemin
{
    t_chemin            *list;  // erreur?
}   t_tab_chemin;

typedef struct i_list
{
    struct i_list  *before;
    struct i_list   **next;
    char            *name;
    bool        is_start;
    bool        is_end;
    t_tab_chemin    *all_chemins; 
    char            *chemin; // inutile
    int             count; // inutile
    int             no_end; // 0 pas fini, 1 pas de end
}   g_list;

typedef struct s_chaine
{
    int     name_chaine;
    char    *name;
    char    **tab;
    int     count;
    struct s_chaine *before;
    struct s_chaine *next;
} t_chaine; // un chemin

typedef struct s_liste_chaine
{
    char    **liste; //une case de début = tab
    char    *name;
    int     count;
    struct s_liste_chaine    *next;
}   t_liste_chaine; // liste chainee d un group

typedef struct s_all_group
{
    t_liste_chaine          *group;
    struct s_all_group   *next;
}   t_all_group; //liste chaine de tous les group

typedef struct s_sortie //impression
{
    int retard;
    int nb;
    int add;
    int lengh;
    char    **trajet;
    int     *fourmie_name;
    int     *index_fourmie;
    int     *end_fourmie;
}   t_sortie;

typedef struct s_a
{
    g_list      *cas;
    struct s_a  *next;
} t_a;

typedef struct s_hash 
{
    char **keys;
    int size;
}   t_hash;

/*
typedef struct s_sortie 
{
    t_chaine    **m; // tab de t_chaine groupe chemins
    struct s_sortie     *next;
}   t_sortie; //liste chaine de groupe de chemins
*/

////// PARSING /////////
char        *get_next_line(int fd);    
void        parsing(t_lem_in *all);
t_room		*get_room_lst(char *str, t_list *rooms);
// Syntax
int			check_nbr_ants(char *line);
int			check_room(char *line);
int			check_link(char *line);
void		parsing_error(t_parse *parse, char *str);

///// fonctions pour ft_lstclear
void		del_str(void *to_del);
void		del_room(void *to_del);
void		del_nothing(void *to_del);

void        my_exit(int code, char *error);
void		free_rooms(t_room **rooms);
t_room		*get_room(char *name, t_room **rooms);

void	ft_fre_pointer(g_list **pointer);
void    ft_maillon_list(g_list **pointer, t_lem_in *run, g_list ***all_room);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void    ft_count_chemin(g_list **pointer, g_list **all_room, char *suivant);
void    ft_next_maillon(g_list **pointer, t_lem_in *run, g_list ***all_room);
g_list    **ft_pointer_begin(t_lem_in *run, g_list ***all_room);
g_list    *ft_new_add(t_room *ad, g_list *pointer);
g_list  **ft_create_tab(g_list **pointer);
g_list    **ft_ajout_room(g_list **all_room, g_list *name);
void     ft_verifie(g_list **pointer, t_chaine ***a);
int     ft_calcul_end(int *tab, int ants, int t);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_printf_maillon(g_list * pointer, int v);
void	ft_print_all(g_list **all_room, char *str);
int	    ft_search_room_all(g_list **all_room, char *name);
void    ft_chemin_count_new(g_list *pointer, g_list **new);
int     ft_calcul_end_deux(t_chaine **a, int ants);
void	ft_create_add_new(t_chaine ***chaine, char *new, t_chemin *temp);
t_chaine	*ft_lstnew_deux(char *new, t_chemin *temp);
void	ft_lstadd_back_deux(t_chaine **lst, t_chaine *new);
void	ft_free_a(t_chaine **a);
void	ft_free_all(g_list **pointer);
int	    ft_compare_maillon(g_list **pointer, g_list *a, int i, int j);
void	ft_free_t_room(t_room *ab);
void	ft_free_all_end(g_list **pointer);
void     ft_verifie_end(t_lem_in *run, g_list **pointer, t_chaine ***a);
t_chaine     **ft_calcul_end_trois(t_chaine **a, int ants);
int     ft_count_end(t_chaine *temp, int j, int ants);
void    ft_send_result(t_chaine **tab, int ants);
void    ft_attribute(t_sortie ***n, int o, int ants);
void	ft_free_n(t_sortie **n);
void	ft_print_sortie(t_sortie **n, int ants);
t_tab_chemin	*ft_create_tab_chemin(void);
t_tab_chemin	*ft_create_and_add_chemins(g_list **pointer, char *name);
void	ft_copy_and_create_list(t_tab_chemin **new_chemin, char *name, t_tab_chemin *all_chemins);
t_chemin	*ft_create_new_list(t_chemin *iter, char *name);
char	**ft_copy_chemin(char **tab, char *name);
void	ft_add_back_list(t_tab_chemin **new_chemin, t_chemin *new_maillon);
int	ft_tab_len(char **tab);
void	ft_ajout_chemin(g_list ***all_room, char *name, g_list **pointer);
g_list	**ft_search_room_all_deux(g_list **all_room, char *name);
void ft_verifie_end_deux(int ants, t_chaine **a, t_lem_in *run);
int ft_compare_list(t_liste_chaine *new_g, char **tab);
void    ft_before(t_liste_chaine **new_g, t_chaine *temp);
void    ft_next(t_liste_chaine **new_g, t_chaine *temp);
t_liste_chaine  *ft_create_new_group(t_chaine *temp);
void    ft_add_back(t_liste_chaine **list, t_liste_chaine *new_g);
void    ft_add_group(t_all_group **list, t_liste_chaine *new_g);
int     ft_count_sortie(t_liste_chaine *group, int ants);
t_liste_chaine    *ft_min_group(t_all_group *list, int ants);
void    ft_send_result_deux(t_liste_chaine *tab, int ants, t_lem_in *run);
void    ft_print_new(t_liste_chaine *new);
void 	ft_free_t_all(t_all_group **list);
void	ft_add_new_deux(t_a **b, g_list *pointer);
void	ft_create_c(t_a *b, t_chaine ***c);
void	ft_free_b(t_a **b);


//int     ft_calcul(t_sortie **tab, int ants, int i);
//int ft_calcul_one_group(t_chaine **m, int ants, int i);
//t_sortie **ft_calcul_end_quatre(t_liste_chaine **b, int ants);



#endif
