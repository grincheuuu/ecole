#include "libft_malloc.h"
#include <sys/mman.h>

#include <assert.h>
#include <errno.h>
#include <stdbool.h>

t_alloue stock = {NULL, NULL, NULL, 0, 0};

size_t  ft_align(size_t len)
{
    size_t  len_zone;

    if (len < 0)
        return (-1);
    if (len % 16 == 0)
        return (len);
    len_zone = (len / 16) * 16 + 16;
    return (len_zone);
}

void ft_puthex_fd(unsigned char n, int fd, int z)
{
    char	c;
    unsigned char		div;
    unsigned char		mod;

    c = 0;
    if (n >= 0 && n <= 15)
    {
        if (n <= 9)
        {
            c = '0' + n;
        }
        else
            c = 'A' + n - 10;
        if (z != 2 || (z == 2 && c != '0'))
            write (fd, &c, 1);
        else if (z == 2 && c == '0')
            write(fd, " ", 1);
    }
    else
    {
        div = n / 16;
        mod = n % 16;
        ft_puthex_fd(div, fd, z);
        ft_puthex_fd(mod, fd, z);
    }
}

void show_alloc_mem()
{
    t_block     *temp = stock.tiny;

    ft_putstr_fd("\nshow allow\n|", 1);
    while (temp != NULL)
    {
        if (temp->debut_page == 1)
        {
            unsigned char    *str = (unsigned char *)temp;
            for (size_t i = 0; i < temp->size; i++)
            {
                ft_puthex_fd(str[i], 1, 0);
                write(1, " ", 1);
                if (i % 16 == 0)
                    write(1, "|\n|", 3);
            }
            write(1, "|\nnewblock\n|", 12);
        }
        temp = temp->next;
    }
    ft_putstr_fd("\nfin show\n", 1);
}


void ft_print_char()
{
    t_block     *temp = stock.tiny;

    while (temp != NULL)
    {
        if (temp->debut_page == 1)
        {
            unsigned char    *str = (unsigned char *)temp;
            for (size_t i = 0; i < temp->size; i++)
            {
                if (ft_isalnum(str[i]) == 1 || str[i] == ' ')
                    write(1, &str[i], 1);
                else
                    ft_puthex_fd(str[i], 1, 2);
                write(1, " ", 1);
                if (i % 32 == 0)
                    write(1, "|\n|", 3);
            }
            write(1, "|\nnewblock\n|", 12);
        }
        temp = temp->next;
    }
}

void print_space(void)
{
    t_block     *temp = stock.tiny;

    ft_putstr_fd("\nprint space tiny\n", 1);
    ft_putstr_fd("\ntaille = ", 1);
    ft_putnbr_fd(stock.tiny_stock, 1);
    write(1, "\n", 1);
    while (temp != NULL)
    {
        ft_putnbr_fd(temp->size, 1);
        write (1, ", ", 1);
        ft_putnbr_fd(temp->occupe, 1);
        write (1, ", ", 1);
        ft_putnbr_fd(temp->debut_page, 1);
        write(1, " | ", 3);
        temp = temp->next;
    }
    ft_putstr_fd("\nfin print\n", 1);
//    ft_print_char();
}

void    ft_free_page(t_block *page)
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
    munmap((void *)page, len);
    return;
}

void    ft_free_first(t_block *page_point, bool i)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = page_point->next;
    if (i == 1) // large
    {
        if (page_point->occupe == 1)
            return;
        temp_before = page_point;
        page_point = iter;
        munmap(temp_before, temp_before->size);
        return;        
    }
    while (iter != NULL)
    {
        if (iter->occupe == 1)
            return;
        if (iter->debut_page == 1)
        {
            temp_before = page_point;
            page_point = iter;
            munmap(temp_before, temp_before->size);
            return;
        }
        iter = iter->next;
    }
}

void    ft_supr_page(t_block *page_point, bool i)
{
    t_block     *temp;
    t_block     *temp_before;
    t_block     *iter = NULL;

    if (page_point == NULL)
        return;
    temp = page_point;
    temp_before = page_point;
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
    ft_free_first(page_point, i);
}

void    ft_defragment_page(t_block *page_point)
{
    t_block     *temp = NULL;

    if (page_point == NULL)
        return;
    temp = page_point;
//    ft_putstr_fd("\ndefragment debut\n", 1);
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->debut_page == 1)
        {
            temp = temp->next;
            continue;
        }
        if (temp->occupe == 0 && temp->next->occupe == 0)
        {
            if (temp->debut_page != 1)
                temp->size += temp->next->size;
            if (temp->next != NULL)
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
//    ft_putstr_fd("\ndefragment fin\n", 1);
}

void    free(void *ptr)  // bloc deja free
{  
    ft_putstr_fd("\nfree\n", 1);;
    t_block *point;
    t_block *iter = NULL;
    t_block *start_list = NULL;
    size_t         i = 0;
    size_t         j = 0;
    size_t         len = 0;
    size_t  len_page = sysconf(_SC_PAGESIZE);
    size_t  *len_stock = NULL;

    if (ptr == NULL)
        return;
    point = (t_block *)((char *)ptr - sizeof(t_block));
    point->occupe = 0;
    ft_putstr_fd("sortie()", 1);
    ft_putnbr_fd(point->debut_page, 1);
    ft_putstr_fd("\n", 1);
    ft_putnbr_fd(point->size, 1);
    ft_putstr_fd("\n", 1);
    ft_putnbr_fd(point->occupe, 1);
    ft_putstr_fd("\n\n\n\n", 1);
    print_space();
    if (ptr == stock.tiny || ptr == stock.small)
            return;
    if (point->size <= (2048 - sizeof(t_block)))
    {
        len = 2048;
        start_list = stock.tiny;
        stock.tiny_stock += point->size;
        len_stock = &stock.tiny_stock;
    }
   else if (point->size <= (8 * len_page - sizeof(t_block)))
    {
        len = 8 * len_page;
        start_list = stock.small;
        stock.small_stock += point->size;
        len_stock = &stock.small_stock;
        ft_putstr_fd("sortie(1111111111111111)\n\n\n\n", 1);
        return;
    }
    else
    {
        start_list = stock.large;
        ft_putstr_fd("sortie(222222222222222222)\n\n\n\n\n\n", 1);
//        ft_supr_page(start_list, 1);
//        print_space();
        return;
    }
    ft_defragment_page(start_list);
    ft_supr_page(start_list, 0);
    iter = start_list;
    while (iter != NULL)
    {
        if (iter->debut_page == 1)
            i++;
        else if (iter->occupe == 1)
            j += iter->size;
        iter = iter->next;
    }
    *len_stock = i * (len - sizeof(t_block)) - j;
    print_space();
}

t_block    *create_block_page(size_t page_size, size_t *in_stock)
{
    t_block    *point = NULL;

    point = (t_block *)mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (point == NULL)
    {
        ft_putstr_fd("echec\n", 2);
        return (NULL);
    }
    point->size = page_size - sizeof(t_block);
    point->occupe = 0;
    point->debut_page = 1;
    point->next = NULL;
    *in_stock += point->size;
    ft_putstr_fd("create block\n", 1);
    return (point);
}

void    *ft_first_allocate_block(t_block **temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate;

    ft_putstr_fd("fisrt\n", 1);
    allocate = (t_block *)((char *)((*temp) + 1));
    if (allocate == NULL)
    {
        ft_putstr_fd("fisrt echec \n", 1);
        return (NULL);
    }
    (*temp)->next = allocate;
    allocate->size = len_zone;
    allocate->next = NULL;
    allocate->occupe = 1;
    allocate->debut_page = 0;
    *in_stock -= len_zone;
//    (*liste)->size = (*liste)->size - len_zone;
    write(1, "\nstart\n", 7);
    write(1, "\n", 1);
    print_space();
    return ((void *)(char *)(allocate + 1));
}

void    *ft_split_block(t_block **temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate;

    ft_putstr_fd("split block", 1);
    if (temp == NULL || (*temp) == NULL || len_zone < 16)
        return NULL;
    allocate = (t_block *)((char *)((*temp)) + (*temp)->size);
    allocate->size = len_zone;
    (*temp)->next = allocate;
    allocate->next = NULL; ////
    allocate->occupe = 1;
    allocate->debut_page = 0;
    *in_stock -= len_zone;
//    (*liste)->size = (*liste)->size - len_zone;
    print_space();
//    show_alloc_mem();
    return ((void *)(char *)(allocate + 1));
}

void    *ft_split_block_in(t_block **temp, size_t len_zone, t_block **nextt, size_t *in_stock)
{
    t_block     *allocate;
    size_t      add = 0;
    size_t      soustraction = 0;

    ft_putstr_fd("\n\n\n\nsplit block in", 1);
    soustraction = (*temp)->size - len_zone - sizeof(t_block) - 1;
    add = ft_align(soustraction);
    if (add >= 0 && (len_zone + add) <= (*temp)->size)
    {
        allocate = (t_block *)((char *)((*temp)) + len_zone); //
        allocate->size = add; // 
        (*temp)->next = allocate;
        allocate->next = (*nextt);
        allocate->occupe = 0;
        allocate->debut_page = 0;
        (*temp)->size -= add;
    }
    else
        (*temp)->next = (*nextt);
    (*temp)->occupe = 1;
    *in_stock -= len_zone;
//    (*liste)->size = (*liste)->size - len_zone;
    print_space();
//    show_alloc_mem();
    return ((void *)(char *)((*temp) + 1));
}

void    *ft_new_alloc(size_t size, void *ptr, size_t size_alloue)
{
    void    *new = malloc(size);
    char    *copy = (char *)new;
    char    *temp = (char *)ptr;
    size_t  size_old = size_alloue - sizeof(t_block);

    if (new == NULL)
        return NULL;
    for (size_t i = 0; i < size_old; i++)
        copy[i] = temp[i];
    free(ptr);
    print_space();
    ft_print_char();
    return ((void *)new);
}

void *realloc(void *ptr, size_t size)
{
    t_block *point;
    t_block *iter = NULL;
    t_block *temp = NULL;
    size_t  len = 0;
    size_t  len_size = ft_align(size + sizeof(t_block));

    ft_putstr_fd("\nrealloc\n|", 1);
    print_space();
    ft_print_char();
    ft_putnbr_fd(sizeof(t_block), 1);
    write (1, "\n", 1);
    ft_putnbr_fd(len_size, 1);
    write (1, "\n", 1);
    if (ptr == NULL)
        return (malloc(size));
    point = (t_block *)((char *)ptr - sizeof(t_block));
    ft_putnbr_fd(point->size, 1);
    write (1, "\n", 1);
    iter = point->next;
    if (point->size >= len_size)
    {
        print_space();
        ft_print_char();
        return (ptr);
    }
    else if (iter == NULL)
    {
        print_space();
        ft_print_char();
        return (ft_new_alloc(size, ptr, point->size));
    } 
    len = ft_align(len_size - point->size + sizeof(t_block) + 1); //
    if (iter->occupe == 1 || len < 0 || iter->size < len)
    {
        print_space();
        ft_print_char();
        return (ft_new_alloc(size, ptr, point->size));
    }
    if (len < 0 || len > (iter->size - len))
    {
        point->size += iter->size;
        point->next = iter->next;
        ft_putstr_fd("\nft_realign 1\n|", 1);
    }
    else
    {
        temp = iter->next;
        point->next = (t_block *)((char *)iter + len);
        point->next->size = len;
        point->next->occupe = 0;
        point->next->debut_page = 0;
        point->next->next = temp;
        stock.tiny->size -= len_size - point->size; //
        point->size = len_size;
        ft_putstr_fd("\nft_realign 2\n|", 1);
    }
    print_space();
    ft_print_char();
    return (ptr);
}

void    *ft_generate_pointer(t_block **liste, size_t len_zone, size_t taille, size_t *in_stock)
{
    if (liste == NULL || (*liste) == NULL)
    {
        (*liste) = create_block_page(taille, in_stock);
        if ((*liste) == NULL)
            return (NULL);
        return (ft_first_allocate_block(liste, len_zone, in_stock));
    }
    else
    {
        t_block     *temp = (*liste);
        if (*in_stock < len_zone)
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = create_block_page(taille, in_stock);
            temp = temp->next;
            if (temp == NULL)
                return (NULL);
//            (*liste)->size += taille - sizeof(t_block);
            return (ft_first_allocate_block(&temp, len_zone, in_stock));
        }
        while (temp->next != NULL)
        {
            if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
                return (ft_split_block_in(&temp, len_zone, &temp->next, in_stock));
            temp = temp->next;
        }
        if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
            return (ft_split_block_in(&temp, len_zone, &temp->next, in_stock));
        return (ft_split_block(&temp, len_zone, in_stock));
    }
}

t_block    *create_block_large(size_t page_size)
{
    t_block    *point = NULL;

    point = (t_block *)mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (point == NULL)
    {
        ft_putstr_fd("echec\n", 2);
        return (NULL);
    }
    point->size = page_size - sizeof(t_block);
    point->occupe = 1;
    point->debut_page = 1;
    point->next = NULL;
    ft_putstr_fd("create block\n", 1);
    write(1, "\nstart large\n", 7);
    write(1, "\n", 1);
    print_space();
    return (point);
}

void    *ft_generate_large(size_t len)
{
    t_block     *iter = NULL;
    size_t      len_alloc = ft_align(len);

    iter = stock.large;
    if (iter == NULL)
        iter = create_block_large(len_alloc);
    else
    {
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = create_block_large(len_alloc);
        if (iter->next == NULL)
            return (NULL);
        iter = iter->next;
    }
    return ((void *)(char *)(iter + 1));
}

void    *malloc(size_t size)
{
    size_t    len_page = sysconf(_SC_PAGESIZE);
    size_t      len_zone;
    size_t      taille = 0;

    if (size == 0)
        return (NULL);
    len_zone = sizeof(t_block) + size;
    len_zone = ft_align(len_zone);
    if (len_zone <= (2048 - sizeof(t_block)))//tiny
    {
        ft_putstr_fd("\ntiny\n", 1);
        taille = 2048;
        return (ft_generate_pointer(&stock.tiny, len_zone, taille, &stock.tiny_stock));
    }
    else if (len_zone <= (8 * len_page - sizeof(t_block)))
    {
        ft_putstr_fd("\nsmall\n", 1);
        taille = 8 * len_page;
        return (ft_generate_pointer(&stock.small, len_zone, taille, &stock.small_stock));
    }
    else
    {
        ft_putstr_fd("\nlarge\n", 1);
        taille = ft_align(size + sizeof(t_block));
        return (ft_generate_large(taille));
    }
}

/*
void    *malloc(size_t size)
{
    size_t    len_page = sysconf(_SC_PAGESIZE);
    size_t  len_zone;

    if (size == 0)
        return (NULL);
    len_zone = sizeof(t_block) + size;
    len_zone = ft_align(len_zone);
    if (len_zone <= (2048 - sizeof(t_block)))//tiny
    {
        ft_putstr_fd("\ntiny\n", 1);
//        ft_generate_pointer(stock.tiny, len_zone);
        if (stock.tiny == NULL)
        {
            stock.tiny = create_block_page(2048);
            if (stock.tiny == NULL)
                return (NULL);
            return (ft_first_allocate_block(stock.tiny, len_zone));
        }
        else
        {
            t_block     *temp = stock.tiny;
            if (stock.tiny->size < len_zone)
            {
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = create_block_page(2048);
                temp = temp->next;
                if (temp == NULL)
                    return (NULL);
                stock.tiny->size += 2048 - sizeof(t_block);
                return (ft_first_allocate_block(temp, len_zone));
            }
            while (temp->next != NULL)
            {
                if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
                    return (ft_split_block_in(temp, len_zone, temp->next));
                temp = temp->next;
            }
            if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
                return (ft_split_block_in(temp, len_zone, temp->next));
            return (ft_split_block(temp, len_zone));
        }
    }
    else if (len_zone <= (8 * len_page))
    {
        ft_putstr_fd("\nsmall\n", 1);   
    }
    else
    {
        ft_putstr_fd("\nlarge\n", 1);
        if (stock.large == NULL)
            stock.large = create_block_page(len_zone);
    }
    return NULL;
}*/