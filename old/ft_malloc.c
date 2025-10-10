#include "libft_malloc.h"
#include <sys/mman.h>

#include <assert.h>
#include <errno.h>
#include <stdbool.h>

t_alloue stock = {NULL, NULL, NULL};

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

void    ft_free_first(t_block *page_point)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = page_point->next;
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

void    ft_supr_page(size_t len, size_t len_page, t_block *page_point)
{
    t_block     *temp;
    t_block     *temp_before;
    t_block     *iter = NULL;

    if (len <= 2048)
        temp = page_point;
    else if (len <= (8 * len_page))
        temp =stock.small;
    else
        temp =stock.large;
    if (temp == NULL)
        return;
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
    ft_free_first(page_point);
}

void    ft_defragment_page(size_t len, size_t len_page, t_block *page_point)
{
    t_block     *temp = NULL;

    if (len <= 2048)
        temp = page_point;
    else if (len <= (8 * len_page))
        temp = stock.small;
//    else
//        temp = stock.large;
    if (temp == NULL)
        return;
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

void    free(void *ptr)
{  
    ft_putstr_fd("\nfree\n", 1);
//    ft_putstr_fd("supr page 000000000000000000\n\n", 2);
    print_space();
    t_block *page_point = stock.tiny;
    t_block *point;
    t_block *iter = stock.tiny;
    size_t         i = 0;
    size_t         j = 0;
    size_t  len_page = sysconf(_SC_PAGESIZE);

    if (ptr == NULL)
        return;
    point = (t_block *)((char *)ptr - sizeof(t_block));
    point->occupe = 0;
    if (point->size <= (2048 - sizeof(t_block)))
        stock.tiny->size += point->size;
/*    else if (point->size <= (8 * len_page))
        stock.small += point->size;
    else
        stock.large += point->size;*/
//    ft_putstr_fd("supr page 1111111111111\n\n", 2);
//    print_space(); /// probleme
    ft_defragment_page(point->size, len_page, page_point);
    ft_supr_page(point->size, len_page, page_point);
//    ft_putstr_fd("supr page  222222222222222\n\n", 2);
//    print_space();
    while (iter != NULL)
    {
        if (iter->debut_page == 1)
            i++;
        else if (iter->occupe == 1)
            j += iter->size;
        iter = iter->next;
    }
    stock.tiny->size = i * (2048 - sizeof(t_block)) - j;
//    ft_putstr_fd("supr page  3333333333333333333\n\n", 2);
    print_space();
}

t_block    *create_block_page(size_t page_size)
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
    ft_putstr_fd("create block\n", 1);
    return (point);
}

void    *ft_first_allocate_block(t_block *temp, size_t len_zone)
{
    t_block     *allocate;

    ft_putstr_fd("fisrt\n", 1);
    allocate = (t_block *)((char *)(temp + 1));
    if (allocate == NULL)
    {
        ft_putstr_fd("fisrt echec \n", 1);
        return (NULL);
    }
    temp->next = allocate;
    allocate->size = len_zone;
    allocate->next = NULL;
    allocate->occupe = 1;
    allocate->debut_page = 0;
    stock.tiny->size -= len_zone;
    write(1, "\nstart\n", 7);
//    ft_putnbr_fd(temp->occupe, 1);
//    write(1, "\nend\n", 5);
//    ft_putnbr_fd(allocate->occupe, 1);
    write(1, "\n", 1);
    print_space();
    return ((void *)(char *)(allocate + 1));
}

void    *ft_split_block(t_block *temp, size_t len_zone)
{
    t_block     *allocate;

    ft_putstr_fd("split block", 1);
    if (temp == NULL || len_zone < 16)
        return NULL;
    allocate = (t_block *)((char *)(temp) + temp->size);
    allocate->size = len_zone;
    temp->next = allocate;
    allocate->next = NULL; ////
    allocate->occupe = 1;
    allocate->debut_page = 0;
    stock.tiny->size = stock.tiny->size - len_zone;
    print_space();
//    show_alloc_mem();
    return ((void *)(char *)(allocate + 1));
}

void    *ft_split_block_in(t_block *temp, size_t len_zone, t_block *nextt)
{
    t_block     *allocate;
    size_t      add = 0;
    size_t      soustraction = 0;

    ft_putstr_fd("\n\n\n\nsplit block in", 1);
//    ft_putnbr_fd(len_zone, 1);
//    ft_putstr_fd("\n\n\n\n", 1);
    soustraction = temp->size - len_zone - sizeof(t_block) - 1;
    add = ft_align(soustraction);
    if (add >= 0 && (len_zone + add) <= temp->size)
    {
        allocate = (t_block *)((char *)(temp) + len_zone); //
        allocate->size = add; // 
        temp->next = allocate;
        allocate->next = nextt;
        allocate->occupe = 0;
        allocate->debut_page = 0;
        temp->size -= add;
//        stock.tiny->size = stock.tiny->size + add; ///
    }
    else
        temp->next = nextt;
    temp->occupe = 1;
    stock.tiny->size = stock.tiny->size - len_zone;
    print_space();
//    show_alloc_mem();
    return ((void *)(char *)(temp + 1));
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

void    *malloc(size_t size)
{
    size_t    len_page = sysconf(_SC_PAGESIZE);
    size_t  len_zone;

//    ft_putnbr_fd(size, 1);
    if (size == 0)
    {
        ft_putstr_fd("size 0\n", 1);
        return (NULL);
    }
    len_zone = sizeof(t_block) + size;
    len_zone = ft_align(len_zone);
    if (len_zone <= (2048 - sizeof(t_block)))//tiny
    {
        ft_putstr_fd("\ntiny\n", 1);
        if (stock.tiny == NULL)
        {
            stock.tiny = create_block_page(2048);
            if (stock.tiny == NULL)
            {
                ft_putstr_fd("echec 1\n", 1);
                return (NULL);
            }
            stock.tiny->size += 2048 - sizeof(t_block);
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
                stock.tiny->size += temp->size - sizeof(t_block);
                return (ft_first_allocate_block(temp, len_zone));
            }
            while (temp->next != NULL)
            {
                if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
                {
//                    ft_putstr_fd("oooooooooooooooooooooo", 1);
                    return (ft_split_block_in(temp, len_zone, temp->next));
                }
                temp = temp->next;
            }
//            ft_putstr_fd("iiiiiiiiiiiiiiiiiiiiiiii", 1);
            if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
                return (ft_split_block_in(temp, len_zone, temp->next));
//            ft_putstr_fd("ffffffffffffffffff", 1);
            return (ft_split_block(temp, len_zone));
        }
    }
    else if (len_zone <= (8 * len_page))
    {
        //small
        if (stock.small == NULL)
            stock.small = create_block_page((8 * len_page));       
    }
    else
    {
        //large
        if (stock.large == NULL)
            stock.large = create_block_page(len_zone);
    }
//    ft_putnbr_fd(size, 1);
//    ft_putstr_fd("return NULL\n", 1);
    return NULL;
}