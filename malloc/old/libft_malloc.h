#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

 #include <stdlib.h>
 #include "./libft/libft.h"
 #include <unistd.h>
 #include <sys/mman.h>

typedef struct  s_block
{
    size_t          size;
    int             occupe;
    int             debut_page;
    struct s_block  *next;
}   t_block;

typedef struct  s_alloue
{
    t_block *tiny;
    t_block *small;
    t_block *large;
    size_t  tiny_stock;
    size_t  small_stock;
}   t_alloue;


void    free(void *ptr);
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
void    show_alloc_mem();

#endif