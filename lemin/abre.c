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

#include "lemin.h"

/*
t_list     *ft_create_maillon()
{
    t_list  *new;

    new = NULL;
    new = ft_lstnew();
    if (new == NULL)
    {
//        ft_lstclear(); // a revoir
        return (NULL);
    }
//    ft_lstadd_back(&arbre, new);

}*/

t_list    **ft_pointer_begin(t_lem_in *run)
{
    t_list  **pointer;
    int i = 0;
    int j;

    while (run->start->neighbors[i] != NULL)
        i++; 
    if (i == 0)
        return (NULL);
    pointer = (t_list **)malloc((i + 1) * sizeof(t_list *));
    if (pointer == NULL)
        return (NULL);                                                                                                       
    i = 0;
    while (run->start->neighbors[i] != NULL)
    {
        j = 0;
        pointer[i] = (t_list *)malloc(sizeof(t_list));
        pointer[i]->before[j] = NULL;
        while (run->start->neighbors[i]->neighbors[j] != NULL)
            j++;
        pointer[i]->next[j] = (t_room **)malloc((j + 1) * sizeof(t_room *));
        if (pointer[i]->next[j] == NULL)
            return (NULL);
        while (run->start->neighbors[i]->neighbors[j] != NULL)
        {
            pointer[i]->next[j] = run->start->neighbors[i]->neighbors[j];
            j++;
        }
        pointer[i]->next[j] = NULL;
        pointer[i]->name = run->start->neighbors[i]->name;
        pointer[i]->is_start = run->start->neighbors[i]->is_start;
        pointer[i]->is_end = run->start->neighbors[i]->is_end;
        pointer[i]->chemin = run->start->neighbors[i]->name;
        pointer[i]->count = 0;
        pointer[i]->no_end = 0;
        i++;
    }
    pointer[i] = NULL;
    return (pointer);
}

void    ft_tree(t_room **pointer)
{
    int i = 0;

    while (pointer[i] != NULL)
    {
        ft_maillon_list(&pointer[i]);
        i++;
    }
}

void    ft_maillon_list(t_list **pointer)
{
    t_list  *new;
    int     i = 0;
    int     j = 1;

    new = NULL;

    while (pointer[i] != NULL && j != 0)
    {
        j = 0;
        if (pointer[i]->is_end != 1)
        {
//            ft_search_next();
            j = 1;
            if(pointer[i]->next == NULL)
            {
                ft_fre((*pointer)->chemin);
                (*pointer)->no_end = 1;
                j = 0;
            }
            while ((*pointer)->next[i])
            {
                
            }
        }
        i++;
    }
}
