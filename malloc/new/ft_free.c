#include "libft_malloc.h"

void    ft_free_page(t_block *page) //////////////////////////////////
{
    size_t  len = page->size;
    t_block *temp = page->next;

    if (page == NULL)
        return;
    while (temp != NULL)
    {
        if (temp->occupe == 1)
            return;
        if (temp->debut_page == 1)
            break;
        temp = temp->next;
    }
    if (munmap((void *)page, len) == -1)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
    return;
}

void    ft_free_first(t_block **page_point, bool i)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = (*page_point)->next;
    print_space();
    ft_putstr_fd("\nfree555555555555555555555555511111111111\n", 1);
    if ((*page_point) ==  NULL || (i == 0 && (*page_point)->next == NULL) || (*page_point)->occupe == 1)
        return;
    if (i == 0) // small, tiny 
    {
        while (iter != NULL)
        {
            if (iter->occupe == 1)
                return;
            if (iter->debut_page == 1)
                break;
            iter = iter->next;
        }
        return;
    }
    else // large
    {
        if (iter == NULL)
        {
            ft_putstr_fd("\nfree5555555555555555555555555\n", 1);
            munmap(page_point, (*page_point)->size);
            page_point = NULL;
            return;
        }
    }
    temp_before = (*page_point);
    (*page_point) = iter;
    munmap(temp_before, temp_before->size);
    ft_putstr_fd("\nfree4444444444444444444444444444444444\n", 1);
    return;
}

void    ft_supr_page(t_block *page_point, bool i)
{
    t_block     *temp;
    t_block     *temp_before;
    t_block     *iter = NULL;

    if (page_point == NULL)
        return;
    (void)i;
    temp = page_point;
    temp_before = page_point;
    ft_putstr_fd("\nlarge1\n", 1);
    while (temp != NULL)
    {
        if (temp->debut_page == 1 && temp_before != page_point)
        {
            iter = temp->next;
            while (iter != NULL && iter->debut_page != 1)
                iter = iter->next;
            ft_free_page(temp);
            temp = iter;
            temp_before->next = temp;
        }
        else
        {
            temp_before = temp;
            temp = temp->next;
        };
    }
    ft_putstr_fd("\nlarge\n", 1);
    ft_free_first(&page_point, i);
}

void    ft_defragment_page(t_block *page_point)
{
    t_block     *temp = NULL;

    if (page_point == NULL)
        return;
    temp = page_point;
    ft_putstr_fd("\ndefragment debut\n", 1);
    while (temp != NULL && temp->next != NULL)
    {
        ft_putstr_fd("\ndefragment fin0 \n", 1);
        if (temp->next->debut_page == 1)
        {
            ft_putstr_fd("\ndefragment fin1\n", 1);
            temp = temp->next;
            continue;
        }
        if (temp->occupe == 0 && temp->next->occupe == 0)
        {
            if (temp->debut_page != 1)
                temp->size += temp->next->size;
            if (temp->next != NULL)
            temp->next = temp->next->next;
            ft_putstr_fd("\ndefragment fin2\n", 1);
        }
        temp = temp->next;
    }
    ft_putstr_fd("\ndefragment fin\n", 1);
}