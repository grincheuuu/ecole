#include "libft_malloc.h"

void    *ft_new_alloc(size_t size, void *ptr, size_t size_alloue)
{
    void    *new = malloc(size);
    char    *copy = (char *)new;
    char    *temp = (char *)ptr;

    if (new == NULL)
        return NULL;
    for (size_t i = 0; i < size && i < size_alloue; i++)
        copy[i] = temp[i];
    free(ptr);
    return ((void *)new);
}

void *realloc(void *ptr, size_t size)
{
    t_block *point;
    t_block *iter = NULL;
    t_block *temp = NULL;
    size_t  len = 0;
    size_t  len_size = ft_align(size) + BLOCK_HEADER;
    size_t  *len_stock = NULL;

    if (ptr == NULL)
        return (malloc(size));
    ft_verouille_mutex();
    point = (t_block *)((char *)ptr - BLOCK_HEADER);
    iter = point->next;
    len_stock = ft_specific_stock(point);
    if (point->size >= len_size)
    {
        ft_deverouille_mutex();
        return (ptr);
    }
    else if (iter == NULL)
    {
        ft_deverouille_mutex();
        return (ft_new_alloc(size, ptr, point->size));
    }
    len = len_size - point->size + BLOCK_HEADER + 16;
    if (iter->occupe == 1 || len < 0 || iter->size < len)
    {
        ft_deverouille_mutex();
        return (ft_new_alloc(size, ptr, point->size));
    }
    if (len > (iter->size - len))
    {
        point->size += iter->size;
        point->next = iter->next;
    }
    else
    {
        temp = iter->next;
        point->next = (t_block *)((char *)iter + len);
        point->next->size = len;
        point->next->occupe = 0;
        point->next->debut_page = 0;
        point->next->next = temp;
        if (len_stock != NULL)
            len_stock -= len_size - point->size;
        point->size = len_size;
    }
    ft_deverouille_mutex();
    return (ptr);
}