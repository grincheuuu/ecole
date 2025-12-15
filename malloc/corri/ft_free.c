#include "libft_malloc.h"

int ft_free_page(t_block *page, size_t lenn, bool i)
{
    t_block *temp;
    size_t  len = lenn;

    if (page == NULL)
        return (0);
    if (page->occupe == 1)
        return (0);
    if (i == 1)
        len = page->size + BLOCK_HEADER;
    temp = page->next;
    while (temp != NULL)
    {
        if (temp->occupe == 1)
            return (0); // echec
        if (temp->debut_page == 1)
            break;
        temp = temp->next;
    }
    if (munmap((void *)page, len) == -1)
    {
        ft_putstr_fd("munmap failed\n", 2);
        return (0);
    }
    return (1); // succes
}
/*
// Change le type de retour en int (1 si unmap réussi, 0 sinon)
int ft_free_page(t_block *page, size_t lenn, bool i)
{
    t_block *temp;
    size_t  len = lenn;

    if (page == NULL)
        return (0);
    
    // CORRECTION 1 : Vérifier si le premier bloc est occupé !
    if (page->occupe == 1)
        return (0);

    if (i == 1)
        len = page->size + BLOCK_HEADER;

    temp = page->next;
    while (temp != NULL)
    {
        if (temp->occupe == 1)
            return (0); // On retourne 0, on ne détruit rien
        if (temp->debut_page == 1)
            break;
        temp = temp->next;
    }

    if (munmap((void *)page, len) == -1)
    {
        ft_putstr_fd("munmap failed\n", 2); // Message court
        return (0);
    }
    return (1); // Succès
}*/

void    ft_free_first(t_block **page_point, size_t len, bool i)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = (*page_point)->next;
    if ((*page_point) ==  NULL || (i == 0 && (*page_point)->next == NULL))
        return;
    if ((*page_point)->occupe == 1)
        return;
    if ((iter == NULL && i == 1) || iter != NULL)
    {
        if (i == 0) // small, tiny 
        {
            while (iter != NULL)
            {
                if (iter->debut_page == 1)
                    break;
                if (iter->occupe == 1)
                    return;
                iter = iter->next;
            }
            return;
        }
    }
    temp_before = (*page_point);
    if (iter == NULL)
        (*page_point) = NULL;
    else
        (*page_point) = iter;
    if (munmap(temp_before, len) == -1)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
    return;
}

void ft_supr_page(t_block **page_point, size_t len, bool i)
{
    t_block *temp;
    t_block *temp_before;
    t_block *iter = NULL;

    if (page_point == NULL || (*page_point) == NULL)
        return;
    temp = (*page_point);
    temp_before = (*page_point);
    while (temp != NULL)
    {
        if (temp->debut_page == 1 && temp_before != (*page_point))
        {
            iter = temp->next;
            while (iter != NULL && iter->debut_page != 1)
                iter = iter->next;
            ft_free_page(temp, len, i);
            temp = iter;
            temp_before->next = temp;
        }
        else
        {
            temp_before = temp;
            temp = temp->next;
        };
    }
    ft_free_first(page_point, len, i);
}
/*
void ft_supr_page(t_block **page_point, size_t len, bool i)
{
    t_block *temp;
    t_block *temp_before;
    t_block *iter = NULL;

    if (page_point == NULL || (*page_point) == NULL)
        return;
    temp = (*page_point);
    temp_before = (*page_point);
    while (temp != NULL)
    {
        if (temp->debut_page == 1 && temp_before != (*page_point)) // On ne touche pas au premier ici
        {
            // On cherche le début de la prochaine page pour sauvegarder le lien
            iter = temp->next;
            while (iter != NULL && iter->debut_page != 1)
                iter = iter->next;
            // On ne relink que si free a marché
            if (ft_free_page(temp, len, i) == 1) 
            {
                temp = iter;
                temp_before->next = temp; 
                // temp_before ne bouge pas, il pointera vers la nouvelle page suivante
            }
            else
            {
                // La page n'était pas vide, on avance normalement
                // Il faut avancer temp_before jusqu'à la fin de la page actuelle (temp)
                while (temp->next != iter) 
                {
                    temp_before = temp;
                    temp = temp->next;
                }
                // Un dernier pas pour se mettre sur le dernier bloc de la page
                temp_before = temp; 
                temp = temp->next; // temp passe à la page suivante (iter)
            }
        }
        else
        {
            temp_before = temp;
            temp = temp->next;
        }
    }
    ft_free_first(page_point, len, i);
}*/

void    ft_defragment_page(t_block *page_point)
{
    t_block     *temp = NULL;

    if (page_point == NULL)
        return;
    temp = page_point;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->debut_page == 1)
        {
            temp = temp->next;
            continue;
        }
        if (temp->occupe == 0 && temp->next->occupe == 0)
        {
            temp->size += temp->next->size + BLOCK_HEADER;
            if (temp->next != NULL)
                temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void    ft_free_large(void *ptr, t_block **large)
{
    t_block **list = large;
    t_block *point = NULL;

    if (!ptr)
        return;
    point = (t_block *)((char *)ptr - BLOCK_HEADER);
    if (!point)
        return;
    if (*list == point)
    {
        *list = point->next;
    }
    else 
    {
        t_block *prev = *list;
        while (prev && prev->next != point)
            prev = prev->next;
        if (prev)
            prev->next = point->next;
    }
    if (munmap((void *)point, point->size + BLOCK_HEADER) == -1) {
        ft_putstr_fd("munmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
}