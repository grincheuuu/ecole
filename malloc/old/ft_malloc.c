#include "libft_malloc.h"
#include <sys/mman.h>

#include <assert.h>
#include <errno.h>
#include <stdbool.h>


//realloc
//large free
//show alloc
//show bonus
//threads
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

void    ft_print_adresse(t_block *temp)
{
    unsigned char    *str = (unsigned char *)temp;

    write(1, "Ox", 2);
    for (size_t i = 0; i <= sizeof(t_block); i++)
    {
        write(1, &str[i], 1);
//        ft_puthex_fd(str[i], 1, 0);
//                if (i % 16 == 0)
    }
}

void show_alloc_mem()
{
    t_block     *temp = stock.tiny;
    size_t      size = 0;

    ft_putstr_fd("\nshow allow\n", 1);
    while (temp != NULL)
    {
        if (temp->debut_page == 1)
        {
            size = temp->size;
            while (temp->next != NULL && temp->next->debut_page != 1)
            {
                ft_print_adresse(temp);
                write(1, " - ", 3);
                ft_print_adresse(temp);
                write(1, " : ", 3);
                ft_putnbr_fd(size, 1);
                write(1, " bytes\n", 7);
                temp = temp->next;
            }
        }
        else
            temp = temp->next;
    }
    ft_putstr_fd("\nfin show\n", 1);
}

void ft_print_char(t_block *liste)
{
    t_block     *temp = liste;


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

void ft_print_space(t_block *liste, size_t len)
{
    size_t  len_page = sysconf(_SC_PAGESIZE);
    t_block *temp = liste;

    if (temp == NULL)
        return;
    ft_putstr_fd("\nprint space\n", 1);
    if (temp->size <= (2048 - sizeof(t_block)))
        ft_putstr_fd("\ntiny\n", 1);
    else if (temp->size <= (8 * len_page - sizeof(t_block)))
        ft_putstr_fd("\nsmall\n", 1);
    else
        ft_putstr_fd("\nlarge\n", 1);
    ft_putstr_fd("taille = ", 1);
    ft_putnbr_fd(len, 1);
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
//    ft_print_char(liste);
}

void print_space(void)
{
    t_block     *temp_tiny = stock.tiny;
    t_block     *temp_small = stock.small;
    t_block     *temp_large = stock.large;
    size_t          i = 9 * sysconf(_SC_PAGESIZE);

    ft_putstr_fd("\ntinyyyyyyyyyy\n", 1);
    ft_print_space(temp_tiny, stock.tiny_stock);
    ft_putstr_fd("\nsmalllllllllllll\n", 1);
    ft_print_space(temp_small, stock.small_stock);
    ft_putstr_fd("\nlargeeeeeeeeeeeeee", 1);
    ft_print_space(temp_large, i);
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
    if (munmap((void *)page, len) == -1)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
    return;
}
/*
void    ft_mise_a_jour_stock(t_block *point, t_block *start_list)
{
    t_block *before = NULL;

    if (point == NULL)
        return;
    while (start_list != NULL || start_list != point)
    {
        before = start_list;
        start_list = start_list->next;
    }
    if (start_list == NULL)
        return;
    if (before == NULL)
    {
        start_list->next = start_list->next;
    }
    before->next = start_list->next;
}*/

void    ft_free_first(t_block *page_point, bool i)
{
    t_block     *temp_before = NULL;
    t_block     *iter = NULL;

    iter = page_point->next;
//    ft_putstr_fd("\nfirrrrrrrrrssssssssssssssssssssttttttttttt\n", 1);
    if (i == 1) // large
    {
//        ft_putstr_fd("\nfirrrrrtttttttttt\n", 1);
        if (page_point->occupe == 1)
            return;       
    }
    else // tiny, small
    {
        ft_putstr_fd("\nlarge333333333333333\n", 1);
        while (iter != NULL)
        {
            if (iter->occupe == 1)
                return;
            if (iter->debut_page == 1)
                break;
            iter = iter->next;
        }
    }
    temp_before = page_point;
    page_point = iter;
    munmap(temp_before, temp_before->size);
    ft_putstr_fd("\nlarge4444444444444444444444444444444444\n", 1);
    return;
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
//    ft_putstr_fd("\nlarge1\n", 1);
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
//    ft_putstr_fd("\nlarge\n", 1);
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
    ft_putstr_fd("\n\neeeeeeeeeeeeeeeeeeefree FREE free eeeeeeeeeeeeeeeeeeeeeeeee\n\n", 1);;
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
    ft_putstr_fd("\nlarge0 avant avant\n", 1);
    print_space();
    point = (t_block *)((char *)ptr - sizeof(t_block));
    ft_putstr_fd("\n\nlarge-2\n", 1);
    point->occupe = 0;
//    print_space();
    ft_putstr_fd("large00 avant\n", 1);
//    if (ptr == stock.tiny || ptr == stock.small)   /////
//            return;  ///////
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
    }
    else
    {
//        ft_putstr_fd("\nlarge-1\n", 1);
        start_list = stock.large;
        ft_supr_page(start_list, 1);
        print_space();
        ft_putstr_fd("sortie(222222222222222222222222222222222222222) apres\n\n\n", 1);
        return;
    }
    ft_putstr_fd("\nanormal\n", 1);
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

size_t *ft_specific_stock(t_block *point)
{
    size_t *len_stock;
    size_t  len_page = sysconf(_SC_PAGESIZE);

    if (point == NULL)
        return 0;
    if (point->size <= (2048 - sizeof(t_block)))
    {
        len_stock = &stock.tiny_stock;
    }
   else if (point->size <= (8 * len_page - sizeof(t_block)))
    {
        len_stock = &stock.small_stock;
    }
    else
    {
        len_stock = NULL;
    }
    return len_stock;
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
    return ((void *)new);
}

void *realloc(void *ptr, size_t size)
{
    t_block *point;
    t_block *iter = NULL;
    t_block *temp = NULL;
    size_t  len = 0;
    size_t  len_size = ft_align(size + sizeof(t_block));
    size_t  *len_stock = NULL;

    ft_putstr_fd("\nreallocccccccccccccccc\n|", 1);
    print_space();
    ft_putnbr_fd(len_size, 1);
    write (1, "\n", 1);
    if (ptr == NULL)
        return (malloc(size));
    point = (t_block *)((char *)ptr - sizeof(t_block));
    ft_putnbr_fd(point->size, 1);
    write (1, "\n", 1);
    iter = point->next;
    len_stock = ft_specific_stock(point);
    if (point->size >= len_size)
    {
        print_space();
        return (ptr);
    }
    else if (iter == NULL)
    {
        print_space();
        return (ft_new_alloc(size, ptr, point->size));
    } 
    len = ft_align(len_size - point->size + sizeof(t_block) + 1); //
    if (iter->occupe == 1 || len < 0 || iter->size < len)
    {
        print_space();
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
        if (len_stock != NULL)
            len_stock -= len_size - point->size; //
        point->size = len_size;
        ft_putstr_fd("\nft_realign 2\n|", 1);
    }
    print_space();
    return (ptr);
}

t_block    *create_block_page(size_t page_size, size_t *in_stock)
{
    t_block    *point = NULL;

    point = (t_block *)mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (point == MAP_FAILED)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
        return NULL;
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

    ft_putstr_fd("fisrt   alllllllllllocate\n", 1);
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
    write(1, "\nstart\n", 7);
    write(1, "\n", 1);
    print_space();
    return ((void *)((char *)allocate + sizeof(t_block)));
}

void    *ft_split_block(t_block **temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate;

    ft_putstr_fd("split blockkkkkkkkkkkkk", 1);
    if (temp == NULL || (*temp) == NULL || len_zone < 16)
        return NULL;
    allocate = (t_block *)((char *)((*temp)) + (*temp)->size);
    (*temp)->next = allocate;
    allocate->size = len_zone;
    allocate->next = NULL; ////
    allocate->occupe = 1;
    allocate->debut_page = 0;
    *in_stock -= len_zone;
    print_space();
//    show_alloc_mem();
    return ((void *)((char *)allocate + sizeof(t_block)));
}

void    *ft_split_block_in(t_block **temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate;
    size_t      add = 0;
    size_t      calcul = 0;
    size_t      soustraction = 0;

    ft_putstr_fd("\n\n\n\nsplit block innnnnnnnnnn", 1);
    soustraction = (*temp)->size - len_zone - sizeof(t_block) - 1;
    add = ft_align(soustraction);
    calcul = (*temp)->size - len_zone;
    if (add >= 0 && add <= calcul)
    {
        allocate = (t_block *)((char *)((*temp)) + len_zone); //
        allocate->size = add; // 
        allocate->next = (*temp)->next;
        (*temp)->next = allocate;
        allocate->occupe = 0;
        allocate->debut_page = 0;
        (*temp)->size -= calcul;
        *in_stock -= len_zone;
    }
    else
        *in_stock -= (*temp)->size;
    (*temp)->occupe = 1;
    print_space();
//    show_alloc_mem();
    return ((void *)((char *)(*temp) + sizeof(t_block)));
}

void    *ft_generate_pointer(t_block **liste, size_t len_zone, size_t page, size_t *in_stock)
{
    if (liste == NULL)
        return NULL;
    if ((*liste) == NULL)
    {
        (*liste) = create_block_page(page, in_stock);
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
            temp->next = create_block_page(page, in_stock);
            temp = temp->next;
            if (temp == NULL)
                return (NULL);
            return (ft_first_allocate_block(&temp, len_zone, in_stock));
        }
        while (temp->next != NULL)
        {
            if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
                return (ft_split_block_in(&temp, len_zone, in_stock));
            temp = temp->next;
        }
//        if (temp->occupe == 0 && temp->size >= len_zone && temp->debut_page != 1)
//            return (ft_split_block_in(&temp, len_zone, &temp->next, in_stock));
        return (ft_split_block(&temp, len_zone, in_stock));
    }
}

t_block    *create_block_large(size_t page_size)
{
    t_block    *point = NULL;

    point = (t_block *)mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (point == MAP_FAILED)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
        return NULL;
    }
    point->size = page_size;
    point->occupe = 1;
    point->debut_page = 1;
    point->next = NULL;
    ft_putstr_fd("create block\n", 1);
    write(1, "\nstart  large\n", 15);
    return (point);
}

void    *ft_generate_large(t_block **start, size_t len)
{
    t_block     *iter = NULL;

    if ((*start) == NULL)
    {
        ft_putstr_fd("\nnew\n", 1);
        (*start) = create_block_large(len);
        iter = (*start);
    }
    else
    {
        iter = (*start);
        ft_putstr_fd("else\n", 1);
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = create_block_large(len);
        if (iter->next == NULL)
            return (NULL);
        iter = iter->next;
    }
    ft_putstr_fd("return block\n", 1);
    print_space();
    return ((void *)((char *)iter + sizeof(t_block)));
}

void    *malloc(size_t size)
{
    size_t    len_page = sysconf(_SC_PAGESIZE);
    size_t      len_zone;
    size_t      page = 0;

    if (size == 0)
        return (NULL);
    len_zone = sizeof(t_block) + size;
    len_zone = ft_align(len_zone);
    if (len_zone <= (2048 - sizeof(t_block)))//tiny
    {
//        show_alloc_mem();
        ft_putstr_fd("\ntinyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n", 1);
        page = 2048;
        return (ft_generate_pointer(&stock.tiny, len_zone, page, &stock.tiny_stock));
    }
    else if (len_zone <= (8 * len_page - sizeof(t_block)))
    {
        ft_putstr_fd("\nsmallllllllllllllllllllllllll\n", 1);
        page = 8 * len_page;
        return (ft_generate_pointer(&stock.small, len_zone, page, &stock.small_stock));
    }
    else
    {
        ft_putstr_fd("\nlargeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n", 1);
        return (ft_generate_large(&stock.large, len_zone));
    }
}