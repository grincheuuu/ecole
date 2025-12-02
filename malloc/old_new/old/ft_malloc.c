#include "libft_malloc.h"

//realloc
//large free
//show alloc
//show bonus
//threads
t_alloue stock = {NULL, NULL, NULL, 0, 0};
/*
void show_alloc_mem()
{
    t_block     *temp = stock.tiny;
    char        *end = NULL;
    size_t      size = 0;

    ft_putstr_fd("\nshow allow\n", 1);
    while (temp != NULL)
    {
        if (temp->debut_page == 1)
        {
            size = temp->size;
            while (temp->next != NULL && temp->next->debut_page != 1)
            {
                ft_print_adresse((void *)temp);
                write(1, " - ", 3);
                end = (char *)temp + (temp->size);
                ft_print_adresse((void *)end);
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
}*/

void    ft_show(t_block *liste)
{
    t_block *iter = liste;

    ft_print_adresse(liste, 1);
    while (iter != NULL)
    {
        if (iter->occupe == 1)
        {
            ft_print_adresse(iter, 0);
        }
        iter = iter->next;
    }
}

void show_alloc_mem()
{
    ft_putstr_fd("\nshow allow\n", 1);
    ft_putstr_fd("TINY : ", 1);
    ft_show(stock.tiny);
    ft_putstr_fd("SMALL : ", 1);
    ft_show(stock.small);
    ft_putstr_fd("LARGE : ", 1);
    ft_show(stock.large);
    ft_putstr_fd("\nfin show\n", 1);
}

void print_space(void)
{
    t_block     *temp_tiny = stock.tiny;
    t_block     *temp_small = stock.small;
    t_block     *temp_large = stock.large;
    size_t          i = 9 * sysconf(_SC_PAGESIZE);

    ft_putstr_fd("\nprint spaceeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n", 1);
    ft_putstr_fd("\ntinyyyyyyyyyy\n", 1);
    ft_print_space(temp_tiny, stock.tiny_stock);
    ft_putstr_fd("\nsmalllllllllllll\n", 1);
    ft_print_space(temp_small, stock.small_stock);
    ft_putstr_fd("\nlargeeeeeeeeeeeeee", 1);
    ft_print_space(temp_large, i);
//    show_alloc_mem();
}

t_block *ft_block(t_block *suspens, void *ptr)
{
    t_block *op = NULL;
    void *iter = NULL;

    op = suspens;
    while (op != NULL)
    {
        iter = (void *)((char *)op + BLOCK_HEADER);
        if (iter == ptr)
            return (op);
        op = op->next;
    }
    return (NULL);
}

t_block *ft_find_block(void *ptr)
{
    t_block *block = NULL;

    block = ft_block(stock.tiny, ptr);
    if (block != NULL)
        return (block);
    block = ft_block(stock.small, ptr);
    if (block != NULL)
        return (block);
    block = ft_block(stock.large, ptr);
    if (block != NULL)
        return (block);
    return (NULL);
}
/*
void    free(void *ptr)  // bloc deja free
{  
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
    print_space();
//    ft_putstr_fd("\nfree0 avant avant\n", 1);
//    print_space();
//    point = (t_block *)((char *)ptr - BLOCK_HEADER);
    point = ft_find_block(ptr);
    if (point == NULL)
    {
        ft_putstr_fd("\n\nNNNNNNNUUUUUUUUUUUUUUUUULLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n", 1);
        return;
    }
    ft_putstr_fd("\n\nfree-2\n", 1);
    point->occupe = 0;
//    print_space();
//    ft_putstr_fd("free0 avant\n", 1);
    if (point->size <= (len_page))
    {
        ft_putstr_fd("\nlarge-3\n", 1);
        len = len_page;
        start_list = stock.tiny;
        stock.tiny_stock += point->size + BLOCK_HEADER;
        len_stock = &stock.tiny_stock;
    }
    else if (point->size <= (8 * len_page))
    {
        ft_putstr_fd("\nlarge-22\n", 1);
        len = 8 * len_page;
        start_list = stock.small;
        stock.small_stock += point->size + BLOCK_HEADER;
        len_stock = &stock.small_stock;
    }
    else
    {
//        ft_putstr_fd("\nlarge-1\n", 1);
        start_list = stock.large;
        if (stock.large == NULL)
            return;
        len = stock.large->size + BLOCK_HEADER;
        ft_supr_page(&start_list, len, 1);
//        print_space();
//        ft_putstr_fd("sortie(222222222222222222222222222222222222222) apres\n\n\n", 1);
        return;
    }
//    ft_putstr_fd("freeanormal\n", 1);
    ft_defragment_page(start_list);
    ft_supr_page(&start_list, len, 0);
    if (start_list == NULL)
        return;
//    ft_putstr_fd("\nfreeanormaaal\n", 1);
    iter = start_list;
    while (iter != NULL)
    {
        if (iter->debut_page == 1)
            i++;
        if (iter->occupe == 1)
            j += iter->size + BLOCK_HEADER;
        iter = iter->next;
    }
    *len_stock = i * len - j;
    print_space();
}*/

void    free(void *ptr)  // bloc deja free
{  
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
    print_space();
//    ft_putstr_fd("\nfree0 avant avant\n", 1);
//    print_space();
//    point = (t_block *)((char *)ptr - BLOCK_HEADER);
    point = ft_find_block(ptr);
    if (point == NULL)
    {
        ft_putstr_fd("\n\nNNNNNNNUUUUUUUUUUUUUUUUULLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n", 1);
        return;
    }
    ft_putstr_fd("\n\nfree-2\n", 1);
    point->occupe = 0;
//    print_space();
//    ft_putstr_fd("free0 avant\n", 1);
    if (point->size <= (len_page))
    {
        ft_putstr_fd("\nlarge-3\n", 1);
        len = len_page;
        start_list = stock.tiny;
        stock.tiny_stock += point->size + BLOCK_HEADER;
        len_stock = &stock.tiny_stock;
    }
    else if (point->size <= (8 * len_page))
    {
        ft_putstr_fd("\nlarge-22\n", 1);
        len = 8 * len_page;
        start_list = stock.small;
        stock.small_stock += point->size + BLOCK_HEADER;
        len_stock = &stock.small_stock;
    }
    else
    {
        ft_free_large(ptr, &stock.large);
        return;
    }
//    ft_putstr_fd("freeanormal\n", 1);
    ft_defragment_page(start_list);
    ft_supr_page(&start_list, len, 0);
    if (start_list == NULL)
        return;
//    ft_putstr_fd("\nfreeanormaaal\n", 1);
    iter = start_list;
    while (iter != NULL)
    {
        if (iter->debut_page == 1)
            i++;
        if (iter->occupe == 1)
            j += iter->size + BLOCK_HEADER;
        iter = iter->next;
    }
    *len_stock = i * len - j;
    print_space();
}
/*
void    ft_free_tiny_small(void *ptr, t_block **large, size_t len_page)
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
    if (munmap((void *)point, len_page + BLOCK_HEADER) == -1) {
        ft_putstr_fd("munmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
    }
}

void free(void *ptr)
{
    size_t  len_page = sysconf(_SC_PAGESIZE);
    t_block *prev = NULL;

    if (!ptr)
        return;
    t_block *point = (t_block *)((char *)ptr - BLOCK_HEADER);
    if (!point)
        return;
    point->occupe = 0;
    if (point->size <= len_page) 
    {
        ft_defragment_page(stock.tiny);
        ft_free_tiny_small(ptr, &stock.tiny, len_page);
        stock.tiny_stock += point->size + BLOCK_HEADER;
        return;
    }
    else if (point->size <= 8 * len_page)
    {
        t_block *prev = stock.small;

        while (prev && prev->next != point)
            prev = prev->next;
        if (prev)
            prev->next = point->next;
        if (munmap((void *)point, len_page * 8) == -1) {
            ft_putstr_fd("munmap failed: ", 2);
            ft_putstr_fd(strerror(errno), 2);
            ft_putstr_fd("\n", 2);
        }
        return;
    }
    else
    {
        // large
        ft_free_large(ptr, &stock.large);
        return;
    }
}*/


size_t *ft_specific_stock(t_block *point)
{
    size_t *len_stock;
    size_t  len_page = sysconf(_SC_PAGESIZE);

    if (point == NULL)
        return 0;
    if (point->size <= len_page)
    {
        len_stock = &stock.tiny_stock;
    }
   else if (point->size <= 8 * len_page)
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

    if (new == NULL)
        return NULL;
    for (size_t i = 0; i < size && i < size_alloue; i++)
        copy[i] = temp[i];
    free(ptr);
    print_space();
    write (1, "\ngrroo\n", 5);
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

   ft_putstr_fd("\nreallocccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n|", 1);
    print_space();
//    ft_putnbr_fd(len_size, 1);
//    write (1, "\n", 1);
    if (ptr == NULL)
        return (malloc(size));
    point = (t_block *)((char *)ptr - BLOCK_HEADER);
//    point = ft_find_block(ptr);
//    ft_putnbr_fd(point->size, 1);
    write (1, "\ngrr\n", 5);
    iter = point->next;
    len_stock = ft_specific_stock(point);
    if (point->size >= len_size)
    {
        write (1, "\nokk\n", 5);
//        print_space();
        return (ptr);
    }
    else if (iter == NULL)
    {
        write (1, "\nnno\n", 5);
//        print_space();
        return (ft_new_alloc(size, ptr, point->size));
    } 
    len = len_size - point->size + BLOCK_HEADER + 16; //
    if (iter->occupe == 1 || len < 0 || iter->size < len)
    {
        write (1, "\nllo\n", 5);
//        print_space();
        return (ft_new_alloc(size, ptr, point->size));
    }
    if (len > (iter->size - len))
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
    void        *mem = NULL;
    t_block    *point = NULL;

    ft_putstr_fd("create bloccccccckkkkkkkkkkk\n", 1);
    mem = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
        return NULL;
    }
    point = (t_block *)mem;
    point->size = page_size - BLOCK_HEADER;
    point->occupe = 0;
    point->debut_page = 1;
    point->next = NULL;
    if (in_stock)
        *in_stock += point->size;
    ft_putstr_fd("create block\n", 1);
    return (point);
}

void    *ft_first_allocate_block(t_block *temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate = NULL;
    t_block     *reste = NULL;
    size_t      size_allo_only;
    size_t      size_restante;

    ft_putstr_fd("fisrt   alllllllllllocate\n", 1);
    if (temp == NULL)
        return NULL;
    size_allo_only = len_zone - BLOCK_HEADER;
    if (temp->size < size_allo_only)
        return NULL;
    size_restante = temp->size - size_allo_only;
    if (size_restante >= (size_t)(BLOCK_HEADER))
    {
        allocate = temp;
        reste = (t_block *)((char *)(allocate) + BLOCK_HEADER + size_allo_only);
        reste->size = size_restante - BLOCK_HEADER;
        reste->occupe = 0;
        reste->debut_page = 0;
        reste->next = allocate->next;

        allocate->size = size_allo_only;
        allocate->next = reste;
        allocate->occupe = 1;
        if (in_stock)
            *in_stock -= len_zone;
//        write(1, "\nstart\n", 7);
        print_space();
        return (void *)((char * )allocate + BLOCK_HEADER);
    }
    else
    {
        temp->occupe = 1;
        if (in_stock)
            *in_stock -= temp->size;
//        write(1, "\nstart2\n", 7);
        print_space();
        return (void *)((char *)temp + BLOCK_HEADER);
    }
}

void    *ft_split_block(t_block *temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate = NULL;
    t_block     *reste = NULL;
    size_t      size_allo_only;
    size_t      size_restante;

    if (temp == NULL)
        return NULL;
    ft_putstr_fd("ft_split_block\n", 1);
    size_allo_only = len_zone - BLOCK_HEADER;
    if (temp->size < size_allo_only)
        return NULL;
    size_restante = temp->size - size_allo_only;
    if (size_restante >= (size_t)(BLOCK_HEADER + 16))
    {
        allocate = temp;
        reste = (t_block *)((char *)(temp) + BLOCK_HEADER + size_allo_only);
        reste->size = size_restante - BLOCK_HEADER;
        reste->occupe = 0;
        reste->debut_page = 0;
        reste->next = allocate->next;

        allocate->size = size_allo_only;
        allocate->next = reste;
        allocate->occupe = 1;
        if (in_stock)
            *in_stock -= len_zone;
//        write(1, "\nstart\n", 7);
        print_space();
        return ((void *)((char * )allocate + BLOCK_HEADER));
    }
    else
    {
        temp->occupe = 1;
        if (in_stock)
            *in_stock -= temp->size;
//        write(1, "\nstart\n", 7);
        print_space();
        return ((void *)((char *)temp + BLOCK_HEADER));
    }
}
/*
void    *ft_split_block_in(t_block *temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate;
    size_t      add = 0;
    size_t      calcul = 0;
    size_t      soustraction = 0;

//    ft_putstr_fd("\n\n\n\nsplit block innnnnnnnnnn", 1);
    soustraction = temp->size - len_zone - BLOCK_HEADER - 1;
    add = ft_align(soustraction);
    calcul = temp->size - len_zone;
    if (add >= 0 && add <= calcul)
    {
        allocate = (t_block *)((char *)(temp) + len_zone); //
        allocate->size = add; // 
        allocate->next = temp->next;
        temp->next = allocate;
        allocate->occupe = 0;
        allocate->debut_page = 0;
        temp->size -= calcul;
        *in_stock -= len_zone;
    }
    else
        *in_stock -= temp->size;
    temp->occupe = 1;
//    print_space();
//    show_alloc_mem();
    return ((void *)((char *)temp + BLOCK_HEADER));
}*/

void    *ft_generate_pointer(t_block **liste, size_t len_zone, size_t page, size_t *in_stock)
{
//    ft_putstr_fd("\n0\n", 1);
    if (liste == NULL || in_stock == NULL)
        return NULL;
    if ((*liste) == NULL)
    {
        (*liste) = create_block_page(page, in_stock);
        if ((*liste) == NULL)
            return (NULL);
        return (ft_first_allocate_block(*liste, len_zone, in_stock));
    }
    else
    {
//        ft_putstr_fd("\n2\n", 1);
        t_block     *temp = (*liste);
        ft_putnbr_fd(*in_stock, 1);
        ft_putstr_fd("\n2\n", 1);
        ft_putnbr_fd((size_t)len_zone, 1);
        if (*in_stock < len_zone)  // +24
        {
            ft_putstr_fd("\nl1\n", 1);
//            ft_putnbr_fd(temp->size, 1);
            ft_putstr_fd("\nop9\n", 1);
            while (temp->next != NULL)
                temp = temp->next;
//            ft_putstr_fd("\n11x\n", 1);
//            ft_putnbr_fd(temp->size, 1);
            temp->next = create_block_page(page, in_stock);
            ft_putstr_fd("\n111\n", 1);
            temp = temp->next;
            if (temp == NULL)
                return (NULL);
            return (ft_first_allocate_block(temp, len_zone, in_stock));
        }
        while (temp->next != NULL)
        {
            ft_putstr_fd("\n0000000000000000000000000000000000000\n", 1);
            if (temp->occupe == 0 && temp->size >= len_zone)
                return (ft_split_block(temp, len_zone, in_stock));
            temp = temp->next;
        }
        ft_putstr_fd("\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n", 1);
        if (temp->occupe == 0 && temp->size >= len_zone)
            return (ft_split_block(temp, len_zone, in_stock));
        ft_putstr_fd("\nBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n", 1); 
        temp->next = create_block_page(page, in_stock);
        temp = temp->next;
        if (temp == NULL)
            return (NULL);
        return (ft_first_allocate_block(temp, len_zone, in_stock));
    }
}

t_block    *create_block_large(size_t page_size)
{
    void        *mem = NULL;
    t_block    *point = NULL;

    mem = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
        return NULL;
    }
    point = (t_block *)mem;
    point->size = page_size - BLOCK_HEADER;
    point->occupe = 1;
    point->debut_page = 1;
    point->next = NULL;
//    ft_putstr_fd("create block\n", 1);
//    write(1, "\nstart  large\n", 15);
    return (point);
}

size_t  ft_gen_len(size_t len)
{
    size_t  temp = len;
    size_t  len_alloc = 0;
    size_t    len_page = sysconf(_SC_PAGESIZE);

    len_alloc = len / len_page * len_page;
    if (temp % len_page != 0)
        len_alloc += len_page;
    return len_alloc;
}

void    *ft_generate_large(t_block **start, size_t len)
{
    t_block     *iter = NULL;
    size_t      len_alloc = 0;

    len_alloc = ft_gen_len(len);
    if ((*start) == NULL)
    {
//        ft_putstr_fd("\nnew\n", 1);
        (*start) = create_block_large(len_alloc);
//        print_space();
        return (void *)((char *)(*start) + BLOCK_HEADER);
    }
    else
    {
        iter = (*start);
//        ft_putstr_fd("else\n", 1);
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = create_block_large(len_alloc);
        if (iter->next == NULL)
            return (NULL);
        iter = iter->next;
    }
//    ft_putstr_fd("return block\n", 1);
//    print_space();
    return (void *)((char *)iter + BLOCK_HEADER);
}

void    *malloc(size_t size)
{
    size_t    len_page = sysconf(_SC_PAGESIZE);
    size_t      len_zone;
    size_t      page = 0;

    if (size == 0)
        return (NULL);
    len_zone = BLOCK_HEADER + ft_align(size);
    if (len_zone <= (len_page) - BLOCK_HEADER)//tiny
    {
        ft_putstr_fd("\ntinyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n", 1);
        page = len_page;
        return (ft_generate_pointer(&stock.tiny, len_zone, page, &stock.tiny_stock));
    }
    else if (len_zone <= (8 * len_page) - BLOCK_HEADER)
    {
        ft_putstr_fd("\nsmallllllllllllllllllllllllll\n", 1);
        page = 8 * len_page;
        return (ft_generate_pointer(&stock.small, len_zone, page, &stock.small_stock));
    }
    else
    {
        ft_putstr_fd("\nlargeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n", 1);
        return (ft_generate_large(&stock.large, (len_zone)));
    }
}

/*
void    *ft_first_allocate_block(t_block *temp, size_t len_zone, size_t *in_stock)
{
    t_block     *allocate = NULL;
    t_block     *reste = NULL;
    size_t      size_allo_only;
    size_t      size_restante;

    ft_putstr_fd("fisrt   alllllllllllocate\n", 1);
    if (temp == NULL)
        return NULL;
    ft_putstr_fd("fisrt   alllllllllllocate\n", 1);
    size_allo_only = ft_align(len_zone - sizeof(t_block));
//    if (temp->size < size_allo_only)
//        return NULL;
    size_restante = temp->size - size_allo_only;
    if (size_restante >= (ssize_t)(sizeof(t_block) + 16))
    {
        allocate = temp;
        reste = (t_block *)((char *)(allocate) + sizeof(t_block) + size_allo_only);
        reste->size = size_restante - sizeof(t_block);
        reste->occupe = 0;
        reste->debut_page = 0;
        reste->next = allocate->next;

        allocate->size = size_allo_only;
        allocate->next = reste;
        allocate->occupe = 1;
        if (in_stock)
            *in_stock -= len_zone;
        write(1, "\nstart\n", 7);
        print_space();
        return (void *)((char * )allocate + sizeof(t_block));
    }
    else
    {
        temp->occupe = 1;
        if (in_stock)
            *in_stock -= temp->size;
        write(1, "\nstart2\n", 7);
        print_space();
        return (void *)((char *)temp + sizeof(t_block));
    }
}*/