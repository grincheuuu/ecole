#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

 #include <stdlib.h>
 #include "./libft/libft.h"
 #include <unistd.h>
 #include <sys/mman.h>
 #include <string.h>
 #include <sys/mman.h>
 #include <assert.h>
 #include <errno.h>
 #include <stdbool.h>
 #include <stdint.h>

#define BLOCK_HEADER ft_align(sizeof(t_block))

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

extern t_alloue stock;


void    free(void *ptr);
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
void    show_alloc_mem();
void    ft_free_page(t_block *page, size_t len, bool i);
void    ft_free_first(t_block **page_point, size_t len, bool i);
void    ft_supr_page(t_block **page_point, size_t len, bool i);
void    ft_defragment_page(t_block *page_point);
void    ft_puthex_fd(size_t n, int fd);
void    ft_print_adresse(t_block *utile, int i);
size_t  ft_align(size_t len);
void ft_print_char(t_block *liste);
void ft_print_space(t_block *liste, size_t len);
void print_space(void);
size_t *ft_specific_stock(t_block *point);
void    *ft_new_alloc(size_t size, void *ptr, size_t size_alloue);
t_block    *create_block_page(size_t page_size, size_t *in_stock);
void    *ft_first_allocate_block(t_block *temp, size_t len_zone, size_t *in_stock);
void    *ft_split_block(t_block *temp, size_t len_zone, size_t *in_stock);
void    *ft_split_block_in(t_block *temp, size_t len_zone, size_t *in_stock);
void    *ft_generate_pointer(t_block **liste, size_t len_zone, size_t page, size_t *in_stock);
t_block    *create_block_large(size_t page_size);
void    *ft_generate_large(t_block **start, size_t len);
void    ft_show(t_block *liste);
t_block *ft_block(t_block *suspens, void *ptr);
t_block *ft_find_block(void *ptr);
size_t  ft_gen_len(size_t len);
void    ft_free_large(void *ptr, t_block **large);
void    ft_free_tiny_small(void *ptr, t_block **large, size_t len_page);

#endif