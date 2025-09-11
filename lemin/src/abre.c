/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abre.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:32 by gschwart          #+#    #+#             */
/*   Updated: 2025/06/30 18:05:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

g_list    **ft_pointer_begin(t_lem_in *run, g_list ***all_room)
{
    g_list  **pointer;
    int i = 0;
//    int j;

    while (run->start->neighbors[i] != NULL)
        i++; 
    if (i == 0)
        return (NULL);
    pointer = (g_list **)malloc((i + 1) * sizeof(g_list *));
    if (pointer == NULL)
        return (NULL);
    pointer[i] = NULL;                                                                                                   
    i = 0;
    while (run->start->neighbors[i] != NULL)
    {
        pointer[i] = (g_list *)malloc(sizeof(g_list));
        pointer[i]->before = NULL;
        pointer[i]->next = NULL;
        pointer[i]->name = run->start->neighbors[i]->name;
        pointer[i]->is_start = run->start->neighbors[i]->is_start;
        pointer[i]->is_end = run->start->neighbors[i]->is_end;
        pointer[i]->chemin = ft_strdup(run->start->neighbors[i]->name);
        pointer[i]->count = 0;
        pointer[i]->no_end = 0;
        pointer[i]->all_chemins = NULL;
        pointer[i]->all_chemins = ft_create_and_add_chemins(NULL, run->start->neighbors[i]->name); // **
        (*all_room) = ft_ajout_room((*all_room), pointer[i]);
//        printf("debut i %d, name %s\n", i, pointer[i]->name);
//        ft_print_list_maillon(pointer);
        i++;
    }
//    ft_print_all((*all_room), "begin");
//    ft_print_list_maillon(pointer);
    return (pointer);
}

g_list    **ft_ajout_room(g_list **all_room, g_list *pointer)
{
    int i = 0;
    g_list    **all = NULL;

    if (pointer == NULL)
        return (all_room);
    if (all_room == NULL)
    {
        all = (g_list **)malloc((2) * sizeof(g_list *));
        if (all == NULL)
            return (NULL);
        all[i] = pointer;
        all[++i] = NULL;
        return (all);
    }
    while (all_room[i] != NULL)
    {
        if (ft_strncmp(all_room[i]->name, pointer->name, strlen(pointer->name) + 1) == 0)
            return (all_room);
        i++;
    }
    all = (g_list **)malloc((i + 2) * sizeof(g_list *));
    if (all == NULL)
        return (NULL);
    i = 0;
    while (all_room[i] != NULL)
    {
        all[i] = all_room[i];
        i++;
    }
    free(all_room);
    all[i] = pointer;
    all[++i] = NULL;
    return (all);
}

void    ft_maillon_list(g_list **pointer, t_lem_in *run, g_list ***all_room)
{
    int     i = 0;
    int     j = 1;
    g_list  **tab_pointer = pointer;
    g_list  **sup = NULL;
    t_chaine  **a = malloc(sizeof(t_chaine *));
    t_chaine    **c = malloc(sizeof(t_chaine *));
    t_a         *b = NULL;

    *a = NULL;
    *c = NULL;
    while (tab_pointer != NULL && tab_pointer[i] != NULL && j != 0)
    {
        j = 0;
        while (tab_pointer[i] != NULL)
        {
            if (tab_pointer[i]->is_end == 1)
            {
                i++;
                j++;
                continue;
            }
            ft_next_maillon(&tab_pointer[i], run, all_room);
            i++;
            j++;
        }
        ft_verifie(tab_pointer, &a, &b);
        if (j != 0)
        {
            sup = tab_pointer;
            tab_pointer = ft_create_tab(tab_pointer);
            free(sup);
        }
        i = 0;
    }
//    ft_print_a(*a);
//    ft_print_b(b);
    ft_create_c(b, &c);
//    ft_print_a(*c);
    ft_verifie_end_deux(run->nb_ants, a);
    ft_free_a(a);
    ft_free_a(c);
    ft_free_b(&b);
}

void ft_verifie_end_deux(int ants, t_chaine **a)
{
    t_liste_chaine    *tab = NULL;
    t_chaine    *temp = *a;
    t_liste_chaine  *new_g = NULL;
    t_all_group     *list = NULL;

//    printf("\n\nprintf end\n");
    (void)ants;
    if (a == NULL || (*a) == NULL)
        return;
    for (int min = 0; temp != NULL; min++)
    {
        // point n, before, next un group new_g
//        printf("\nnew\n");
        new_g = ft_create_new_group(temp);
        if (temp->before != NULL)
            ft_before(&new_g, temp); //         ft_compare_liste();
        ft_next(&new_g, temp);
        ft_add_group(&list, new_g); //liste chaine de new_g;
        temp = temp->next;
    }
//    ft_print_group(&list);
    tab = ft_min_group(list, ants);
    ft_send_result_deux(tab, ants);
    ft_free_t_all(&list);
    free(list);
    return;
}

t_liste_chaine    *ft_min_group(t_all_group *list, int ants)
{
    t_liste_chaine  *new = NULL;
    t_all_group     *temp = list;
    int count_turn[2];
    int n = 0;
    int i = 0;

    count_turn[0] = 0;
    count_turn[1] = ft_count_sortie(temp->group, ants);
    while (temp != NULL)
    {
        n = ft_count_sortie(temp->group, ants);
//        printf("n %d\n", n);
//        ft_print_group(&temp);
        if (n <= count_turn[1])
        {
            count_turn[0] = i;
            count_turn[1] = n;
        }
        i++;
        temp = temp->next;
    }
    temp = list;
    i = 0;
    while (temp->next != NULL && i < count_turn[0])
    {
//        printf("n %d, %d\n", count_turn[0], count_turn[1]);
        temp = temp->next;
        i++;
    }
    new = temp->group;
    return (new);
}

int     ft_count_sortie(t_liste_chaine *group, int ants)
{
    int         i;
    int         j = 0;
    t_liste_chaine  *temp = group;
    int         n = 0;

    i = temp->count;
//    printf("hello, i %d", i);
    while (n < ants)
    {
        temp = group;
        while (temp != NULL)
        {
//            printf("temp name %s, count %d, i %d\n", temp->name, temp->count, i);
            if (temp->count == i)
            {
                while (temp != NULL && temp->count == i)
                {
//                    printf("\ntemp name %s , count %d j%d ants %d     ", temp->name, temp->count, j + 1, ants);
//                    ft_print_tab(temp->liste);
                    j++;
                    if (n + j >= ants)
                    {
//                        printf("\nfini\n");
                        return (i);
                    }
                    temp = temp->next;
                }
            }
            else
                temp = temp->next;
//            printf("\n %d\n", j);
        }
        i++;
        n += j;
    }
    return (i);
}

int ft_compare_list(t_liste_chaine *new_g, char **tab)
{
    while (new_g != NULL)
    {
        for (int j = 0; new_g->liste[j] != NULL; j++)
        {
            for (int i = 0; tab[i] != NULL; i++)
            {
                if (ft_strncmp(tab[i], new_g->liste[j], ft_strlen(new_g->liste[j]) + 1) == 0)
                    return (1);
            }
        }
        new_g = new_g->next;
    }
    return (0);
}

void    ft_before(t_liste_chaine **new_g, t_chaine *temp)
{
    t_liste_chaine  *new = NULL;

    temp = temp->before;
    while (temp != NULL)
    {
        if (ft_compare_list(*new_g, temp->tab) == 0)
        {
            new = ft_create_new_group(temp);
            ft_add_back(new_g, new);
            new = NULL;
        }
        temp = temp->before;
    }
}

void    ft_next(t_liste_chaine **new_g, t_chaine *temp)
{
    t_liste_chaine  *new = NULL;

    temp = temp->next;
    while (temp != NULL)
    {
        if (ft_compare_list(*new_g, temp->tab) == 0)
        {
            new = ft_create_new_group(temp);
            ft_add_back(new_g, new);
            new = NULL;
        }
        temp = temp->next;
    }
}

t_liste_chaine  *ft_create_new_group(t_chaine *temp)
{
    t_liste_chaine  *group;

    if (temp == NULL)
        return (NULL);
    group = malloc(sizeof(t_liste_chaine));
    if (group == NULL)
        return (NULL);
    group->liste = ft_copy_chemin(temp->tab, NULL);
    group->name = ft_strdup(temp->name);
    group->count = temp->count;
    group->next = NULL;
    return (group);
}

void    ft_add_back(t_liste_chaine **list, t_liste_chaine *new_g)
{
    t_liste_chaine  *temp = NULL;

    if (list == NULL || new_g == NULL)
    {
        printf("return\n");
        return;
    }
    if (*list == NULL)
    {
        *list = new_g;
        return;
    }
    temp = *list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_g;
}

void    ft_add_group(t_all_group **list, t_liste_chaine *new_g)
{
    t_all_group *temp = NULL;
    t_all_group *new = NULL;

    if (new_g == NULL)
        return;
    new = malloc(sizeof(t_all_group));
    if (new == NULL)
        return;
    new->group = new_g;
    new->next = NULL;
    if (*list == NULL)
    {
        *list = new;
        return;
    }
    temp = *list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

void    ft_send_result_deux(t_liste_chaine *tab, int ants)
{
    int i = 0;
    int j;
    int o = 0;
    t_sortie **n;
    t_liste_chaine  *temp;
    char    *str = NULL;
    int fourmies = 0;
    int r;
    int t = 0;

//    printf("\nsend\n");
    if (tab == NULL)
        return;
    temp = tab;
    r = tab->count;
    while (temp != NULL)
    {
        o++;
        temp = temp->next;
    }
    n = malloc((o + 1) * sizeof(t_sortie *));
    if (n == NULL)
        return;
    temp = tab;
    for (int u = 0; u < o; u++)
    {
        n[u] = malloc(sizeof(t_sortie));
        if (n[u] == NULL)
        {
//            ft_free_n(n);
            return;
        }
        n[u]->retard = tab->count - r;
        n[u]->nb = 0;
        n[u]->add = 0;
        n[u]->lengh = 0;
        n[u]->trajet = tab->liste;
        n[u]->fourmie_name = NULL;
        n[u]->index_fourmie = NULL;
        n[u]->end_fourmie = NULL;
        tab = tab->next;
    }
    n[o] = NULL;
    ft_attribute(&n, o, ants);
    j = 0;
//    ft_print_sortie(n, ants);
    while (fourmies < ants) // danger j
    {
        i = 0;
        write (1, "\n", 1);
        while (n[i] != NULL && fourmies < ants)
        {
            t = n[i]->add; // avancer dans les fourmies d'un chemin
//            printf("t %d, lengh %d, j %d, i %d, retard, %d\n", t, n[i]->lengh, j, i, n[i]->retard);
            while (t < n[i]->lengh && t <= j)
            {
//                printf("debut\n");
                if (n[i]->end_fourmie[t] == 1)
                {
                    write(1, "L", 1);
                    str = ft_itoa((n[i]->fourmie_name[t] + 1));
                    ft_putstr_fd(str, 1);
                    free(str);
                    str = NULL;
                    write(1, "-end ", 5);
                    t++;
                    n[i]->add = t;
                    fourmies++;
                    continue;
                }
                write(1, "L", 1);
                str = ft_itoa((n[i]->fourmie_name[t] + 1));
                ft_putstr_fd(str, 1);
                write(1, "-", 1);
                ft_putstr_fd(n[i]->trajet[n[i]->index_fourmie[t]], 1);
                write (1, " ", 1);
                free(str);
                str = NULL;
                n[i]->index_fourmie[t]++;
                if (n[i]->trajet[n[i]->index_fourmie[t]] == NULL) //avancer dans un chemin
                    n[i]->end_fourmie[t] = 1;
                t++;
            }
            i++;
        }
        j++;
    }
    ft_free_n(n);
}




























void ft_verifie_end(t_lem_in *run, g_list **pointer, t_chaine ***a)
{
    int i = 0;
    int t = 0;
    t_chaine    **tab = NULL;

//    printf("\n\nprintf\n");
//    printf("pointer i %d %p\n", i, pointer);
    while (pointer[i] != NULL)
    {
//        printf("pointer i %d %p\n", i, pointer[i]);
        if (pointer[i]->is_end == 1)
            t++;
        i++;
//        printf("i %d\n", i);
    }
    if (t == 0 || (**a) == NULL)
        return;
    tab = ft_calcul_end_trois((*a), run->nb_ants);
    ft_send_result(tab, run->nb_ants);
//    free(tab);
    return;
}

void    ft_send_result(t_chaine **tab, int ants)
{
    int i = 0;
    int j;
    int o = 0;
    t_sortie **n;
    int fourmies = 0;
    int r;
    int t = 0;

//    printf("\nsend\n");
    if (tab == NULL || *tab == NULL)
        return;
    r = tab[0]->count;
    while (tab[o] != NULL)
        o++;
    n = malloc((o + 1) * sizeof(t_sortie *));
    if (n == NULL)
        return;
    for (int u = 0; u < o; u++)
    {
        n[u] = malloc(sizeof(t_sortie));
        if (n[u] == NULL)
        {
            ft_free_n(n);
            return;
        }
        n[u]->retard = tab[u]->count - r;
        n[u]->nb = 0;
        n[u]->add = 0;
        n[u]->lengh = 0;
        n[u]->trajet = (*tab)->tab;
        n[u]->fourmie_name = NULL;
        n[u]->index_fourmie = NULL;
        n[u]->end_fourmie = NULL;
    }
    n[o] = NULL;
    ft_attribute(&n, o, ants);
    j = 0;
//    ft_print_sortie(n, ants);
    while (fourmies < ants)
    {
        i = 0;
        printf("\n");
        while (n[i] != NULL && fourmies < ants)
        {
            t = n[i]->add; // avancer dans les fourmies d'un chemin
            while (t < n[i]->lengh && i >= n[i]->retard && t <= j)
            {
                if (n[i]->end_fourmie[t] == 1)
                {
                    printf("L%d-", (n[i]->fourmie_name[t] + 1));
                    printf("end ");
                    t++;
                    n[i]->add = t;
                    fourmies++;
                    continue;
                }
                printf("L%d-", (n[i]->fourmie_name[t] + 1));
                printf("%s ", n[i]->trajet[n[i]->index_fourmie[t]]);
                n[i]->index_fourmie[t]++;
                if (n[i]->trajet[n[i]->index_fourmie[t]] == NULL) //avancer dans un chemin
                    n[i]->end_fourmie[t] = 1;
                t++;
            }
            i++;
        }
        j++;
    }
//    ft_free_n(n); //leak
}

void    ft_attribute(t_sortie ***n, int o, int ants)
{
    int *tab;
    int nb = 0;
    int i = 0;
    int t = 0;

    tab = (int *)malloc(o * sizeof(int));
    if (tab == 0)
        return;
    for (int y = 0; y < o; y++)
        tab[y] = 0;
    while (nb < ants)
    {
        i = 0;
        while ((*n)[i] != NULL && nb < ants)
        {
            if ((*n)[i]->retard <= t)
            {
                tab[i] += 1;
                nb++;
            }
            i++;
        }
        t++;
    }
    i = 0;
    while ((*n)[i] != NULL)
    {
//        printf("int i = %d tab[i] %d\n", i, tab[i]);
        (*n)[i]->fourmie_name = malloc(tab[i] * sizeof(int));
        (*n)[i]->index_fourmie = malloc(tab[i] * sizeof(int));
        (*n)[i]->end_fourmie = malloc(tab[i] * sizeof(int));
        if ((*n)[i]->fourmie_name == NULL || (*n)[i]->index_fourmie == NULL || (*n)[i]->end_fourmie == NULL)
        {
            free(tab); //
            return;
        }
        (*n)[i]->lengh = tab[i];
        tab[i] = 0;
        i++;
    }
    nb = 0;
    t = 0;
    while (nb < ants)
    {
        i = 0;
        while ((*n)[i] != NULL && nb < ants)
        {
            if ((*n)[i]->retard <= t)
            {
//                printf("sdfsd i %d nb %d\n", i, nb);
                (*n)[i]->fourmie_name[tab[i]] = nb;
                (*n)[i]->index_fourmie[tab[i]] = 0;
                (*n)[i]->end_fourmie[tab[i]] = 0;
                tab[i]++;
                nb++;
            }
            i++;
        }
        t++;
    }
    free(tab);
    return;
}

t_chaine    **ft_calcul_end_trois(t_chaine **a, int ants)
{
    t_chaine    *temp = (*a);
    t_chaine    **tab;
    int         i;
    int         j = 0;
    int         n = 0;

//    printf("\n result\n");
    i = temp->count;
    j = ft_count_end(temp, j, ants);
    tab = malloc((j + 1) * sizeof(t_chaine*));
    if (tab == NULL)
        return (NULL);
    j = 0;
    while (temp != NULL)
    {
        if (temp->count == i)
        {
            while (temp != NULL && temp->count == i)
            {
                tab[j] = temp;
                j++;
                if (n + j >= ants)
                {     
                    tab[j] = NULL;
                    return (tab);
                }
                temp = temp->next;
            }
        }
        else
            temp = temp->next;
        i++;
        n += j;
    }
    tab[j] = NULL;
    return (tab);
}

int ft_count_end(t_chaine *temp, int j, int ants)
{
    int         i;
    int         n = 0;

    i = temp->count;
    while (temp != NULL)
    {
        if (temp->count == i)
        {
            while (temp != NULL && temp->count == i)
            {
//                printf("temp name %s %s, count %d j%d ants %d     ", temp->name, temp->chemin, temp->count, j + 1, ants);
                j++;
                if (n + j >= ants)
                {
//                    printf("\nfini\n");
                    return (j);
                }
                temp = temp->next;
            }
        }
        else
            temp = temp->next;
//        printf("\n");
        i++;
        n += j;
    }
    return j;
}

void ft_verifie(g_list **pointer, t_chaine ***a, t_a **b)
{
    int i = 0;
    int t = 0;
    t_chemin    *temp;

    (void)b;
    while (pointer[i] != NULL)
    {
        if (pointer[i]->is_end == 1)
        {
//            ft_add_new_deux(b, pointer[i]);
            temp = pointer[i]->all_chemins->list;
            while (temp != NULL)
            {   
                ft_create_add_new(a, pointer[i]->name, temp);
                t++;
                temp = temp->next;
            }
        }
        i++;
    }
}

void	ft_add_new_deux(t_a **b, g_list *pointer)
{
	t_a	*temp;
    t_a *new;

	if (pointer == NULL)
		return;
    new = malloc(sizeof(t_a));
    if (new == NULL)
        return;
    new->cas = pointer;
    new->next = NULL;
    if (*b == NULL)
    {
        *b = new;
        return;
    }
    temp = *b;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}


int ft_compare(t_chaine *m, t_chaine *maillon)
{
    int         i = 0;
    int         j = 0;

    while (maillon->tab[i] != NULL)
    {
        j = 0;
        while (m->tab[j] != NULL)
        {
            if (ft_strncmp(maillon->tab[i], m->tab[j], ft_strlen(maillon->tab[i]) + 1) == 0) // identique
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_calcul_end_deux(t_chaine **a, int ants)
{
    t_chaine    *temp = (*a);
    int         min = 2147483647;
    int         max = 0;
    int         i;
    int         n = 0;
    int         j;

    while (temp != NULL)
    {
        if (temp->count <= min)
        {
            min = temp->count;
            n++;
        }
        if (temp->count > max)
            max = temp->count;
        temp = temp->next;
    }
    i = min + 1;
    j = n;
    while (i <= max)
    {
        temp = (*a);
        while (temp != NULL)
        {
            if (temp->count == i)
                j++;
            temp = temp->next;
        }
        n += j;
        i++;
    }
    if (n >= ants)
        return (1);
    return (0);
}

int ft_calcul_end(int *tab, int ants, int t)
{
    int nb = 2147483647;
    int v = t;
    int i = t;
    int c = 0;
    int max = tab[v];
    int x;

    while (v > 0)
    {
        if (max < tab[v])
            max = tab[v];
        if (nb > tab[v])
            nb = tab[v];
        v--;
    }
    x = max;
    while(max > 0)
    {
        if ((tab[i] - nb) <= 0)
            c++;
        tab[i]--;
        i--;
        if (i < 0)
            i = t;
        max--;
    }
//    printf("calcul end x %d t %d -> nb ants %d\n", x, t, ants);
    free(tab);
//    printf("count x %d + t %d = x + t %d .. ants %d\n", x, t, x + t + 1, ants);
    if ((x + t + 1) >= ants)
        return (1);
    return (0);
}

g_list **ft_create_tab(g_list **pointer)
{
    int i = 0;
    int v;
    int t = 0;
    g_list **tabl = NULL;

    while (pointer[i] != NULL)
    {
        if (pointer[i]->next != NULL)
        {
            v = 0;
            while (pointer[i]->next[v] != NULL)
            {
                t++;
                v++;
            }
        }
        i++;
    }
    if (t == 0)
        return (NULL);

    tabl = (g_list **)malloc((t + 1) * sizeof(g_list *));
    if (tabl == NULL)
        return (NULL);
    i = 0;
    t = 0;
    while (pointer[i] != NULL)
    {
        if (pointer[i]->next != NULL)
        {
            v = 0;
            while (pointer[i]->next[v] != NULL)
            {
                tabl[t] = pointer[i]->next[v];
                t++;
                v++;
            }
        }
        i++;
    }
    tabl[t] = NULL;
    return (tabl);
}
/*
g_list  **ft_create_tab(g_list **pointer)
{
    int i = 0;
    int v;
    int t = 0;
    g_list  **tabl = NULL;

    while (pointer[i] != NULL)
    {
        v = 0;
        while (pointer[i]->next != NULL && pointer[i]->next[v] != NULL)
        {
            if (pointer[i]->is_end != 1)
                t++;
            
            v++;
        }
        i++;
    }
    if (t == 0)
        return (NULL);
    tabl = (g_list **)malloc((t + 1) * sizeof(g_list *));
    if (tabl == NULL)
        return (NULL);
    i = 0;
    t = 0;
    while (pointer[i] != NULL)
    {
        v = 0;
        while (pointer[i]->next != NULL && pointer[i]->next[v] != NULL)
        {
            if (pointer[i]->is_end != 1)
            {
                tabl[t] = pointer[i]->next[v];
                t++;
            }
            v++;
        }
        i++;
    }
    tabl[t] = NULL;
    return (tabl);
}*/

void    ft_next_maillon(g_list **pointer, t_lem_in *run, g_list ***all_room)
{
    int v = 0;
    int i = 0;
    int j = 0;

    while (run->rooms[v] != NULL)
    {
        if (ft_strncmp(run->rooms[v]->name, (*pointer)->name, ft_strlen((*pointer)->name) + 1) == 0)
        {
            if (run->rooms[v]->neighbors == NULL)
            {
                (*pointer)->next = NULL;
                return;
            }
            while (run->rooms[v]->neighbors[i + j] != NULL)
            {
                if (ft_search_room_all((*all_room), run->rooms[v]->neighbors[i + j]->name) == 1)
                    j++;
                else if (run->rooms[v]->neighbors[i + j] == run->end)
                    j++;
                else
                    i++;
            }
            (*pointer)->next = (g_list **)malloc((i + 2) * sizeof(g_list *));
            if ((*pointer)->next == NULL)
                return;
            i = 0;
            j = 0;
            while (run->rooms[v]->neighbors[i + j] != NULL)
            {
                if (ft_search_room_all((*all_room), run->rooms[v]->neighbors[i + j]->name) == 1)
                {
                    ft_count_chemin(pointer, (*all_room), run->rooms[v]->neighbors[i + j]->name);
                    ft_ajout_chemin(all_room, run->rooms[v]->neighbors[i + j]->name, pointer);
                    j++;
                    continue;
                }
                if (run->rooms[v]->neighbors[i + j] == run->end)
                {
                    (*pointer)->is_end = 1;
                    (*pointer)->next[i] = NULL;
                    j++;
                    continue;
                }
                (*pointer)->next[i] = ft_new_add(run->rooms[v]->neighbors[i + j], (*pointer));
                (*all_room) = ft_ajout_room((*all_room), (*pointer)->next[i]);
                i++;
            }
            if ((*pointer)->next != NULL)
                (*pointer)->next[i] = NULL;
            break ;
        }
        v++;
    }
}

g_list    *ft_new_add(t_room *ad, g_list *pointer)
{
    g_list  *new;

    new = (g_list *)malloc(sizeof(g_list));
    if (new == NULL)
        return (NULL);
    new->name = ad->name;
    new->is_start = ad->is_start;
    new->is_end = 0;
    new->no_end = 0;
    new->next = NULL;
    ft_chemin_count_new(pointer, &new);
    new->before = pointer;
    new->all_chemins = ft_create_and_add_chemins(&pointer, ad->name);
    return (new);
}

void    ft_chemin_count_new(g_list *pointer, g_list **new)
{
    char    *str = NULL;
    if (new == NULL || (*new) == NULL)
        return;
    if (pointer == NULL)
    {
        (*new)->count = 1;
        (*new)->chemin = ft_strdup((*new)->name);
        return;
    }
    (*new)->count = pointer->count + 1;
    str = ft_strjoin(pointer->chemin, ";");
    (*new)->chemin = ft_strjoin(str, (*new)->name);
    free(str);
}

void    ft_count_chemin(g_list **pointer, g_list **all_room, char *suivant)
{
    int i = 0;

//    printf("ft_count_chemin\n");
    if (all_room == NULL)
    {
//        printf("ft_count_chemin all_romm == NULL\n");
        return;
    }
    while (all_room[i] != NULL)
    {
        if (ft_strncmp(all_room[i]->name, suivant, ft_strlen(suivant) + 1) == 1)
        {
            if (all_room[i]->before == NULL || (*pointer)->before == NULL) //
            {
                all_room[i]->count = 1;
                if (all_room[i]->chemin == NULL)
                    all_room[i]->chemin = ft_strdup(suivant);
                break ;
            }
//            printf("%d\n", (*pointer)->count);
            if ((all_room[i]->count - 1) > (*pointer)->count)
            {
//                printf("free all_room, pointer before %p\n", (*pointer)->before);
                free(all_room[i]->chemin);
                all_room[i]->count = (*pointer)->before->count + 1;
                all_room[i]->chemin = ft_strjoin((*pointer)->before->chemin, ";");
                all_room[i]->chemin = ft_strjoin(all_room[i]->chemin, all_room[0]->name);
                break ;
            }
        }
        i++;
    }
//    printf("stop \n");
}
