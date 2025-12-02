#include "libft_malloc.h"

void    ft_free_page(t_block *page, size_t lenn, bool i) //////////////////////////////////
{
    t_block *temp = page->next;
    size_t  len = lenn;

    if (page == NULL)
        return;
    if (i == 1)
        len = page->size + BLOCK_HEADER;
    while (temp != NULL)
    {
        if (temp->occupe == 1)
            return;
        if (temp->debut_page == 1)
            break;
        temp = temp->next;
    }
    ft_putstr_fd("\nfreee3333333333\n", 1);
    if (munmap((void *)page, len) == -1)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
    return;
}

void    ft_free_first(t_block **page_point, size_t len, bool i)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = (*page_point)->next;
    print_space();
    ft_putstr_fd("free555555555555555555555555511111111111\n", 1);
    if ((*page_point) ==  NULL)
    {
        ft_putstr_fd("2222222222222222\n", 1);
        return;
    }
    if ((i == 0 && (*page_point)->next == NULL))
    {
        print_space();
        ft_putstr_fd("333333333333333\n", 1);
        return;
    }
    if ((*page_point)->occupe == 1)
    {
        ft_putstr_fd("1111111111111111111\n", 1);
        return;
    }
    if ((iter == NULL && i == 1) || iter != NULL)
    {
        ft_putstr_fd("\n777777777777777777777777777777777\n", 1);
        if (i == 0) // small, tiny 
        {
            while (iter != NULL)
            {
                if (iter->debut_page == 1)
                {
                    ft_putstr_fd("\n888888888888\n", 1);
                    break;
                }
                if (iter->occupe == 1)
                {
                    ft_putstr_fd("\n777\n", 1);
                    return;
                }
                iter = iter->next;
            }
            ft_putstr_fd("\n6666666\n", 1);
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
    ft_putstr_fd("\nfree4444444444444444444444444444444444\n", 1);
    return;
}
/*
void    ft_free_first(t_block *page_point, size_t len, bool i)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = page_point->next;
    print_space();
    ft_putstr_fd("free555555555555555555555555511111111111\n", 1);
    if (page_point ==  NULL)
    {
        ft_putstr_fd("2222222222222222\n", 1);
        return;
    }
    if ((i == 0 && page_point->next == NULL))
    {
        print_space();
        ft_putstr_fd("333333333333333\n", 1);
        return;
    }
    if (page_point->occupe == 1)
    {
        ft_putstr_fd("1111111111111111111\n", 1);
        return;
    }
    if (i == 0) // small, tiny 
    {
        while (iter != NULL)
        {
            if (iter->debut_page == 1)
            {
                ft_putstr_fd("\n888888888888\n", 1);
                break;
            }
            if (iter->occupe == 1)
            {
                ft_putstr_fd("\n777777777777777\n", 1);
                return;
            }
            iter = iter->next;
        }
        ft_putstr_fd("\n6666666\n", 1);
        return;
    }
    else // large
    {
        if (iter == NULL)
        {
            ft_putstr_fd("\nfree5555555555555555555555555\n", 1);
            munmap(page_point, page_point->size); //////////////////////////
            if (munmap(page_point, (page_point->size + sizeof(t_block))) == -1)
            {
                ft_putstr_fd("mmap failed: ", 2);
                ft_putstr_fd(strerror(errno), 2);
                ft_putstr_fd("\n", 2);
            }
            page_point = NULL;
            return;
        }
    }
    temp_before = page_point;
    page_point = iter;
    if (munmap(temp_before, len) == -1)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
    ft_putstr_fd("\nfree4444444444444444444444444444444444\n", 1);
    return;
}*/

void    ft_supr_page(t_block **page_point, size_t len, bool i)
{
    t_block     *temp;
    t_block     *temp_before;
    t_block     *iter = NULL;

    if (page_point == NULL || (*page_point) == NULL)
    {
        ft_putstr_fd("\nNULLLLLLLLLLLLLLLL11111111111111111\n", 1);
        return;
    }
    temp = (*page_point);
    temp_before = (*page_point);
    ft_putstr_fd("\nsupr\n", 1);
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
    ft_putstr_fd("\npage\n", 1);
    ft_free_first(page_point, len, i);
}

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