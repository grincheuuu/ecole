#include "libft_malloc.h"

t_alloue stock = {NULL, NULL, NULL, 0, 0, 
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    0, 0};

__attribute__((constructor))
static void ft_init_getenv(void)
{
    char *v = 0;

    if ((v = getenv("MALLOC_VERBOSE")))
        stock.MALLOC_VERBOSE = ft_atoi(v);
    if ((v = getenv("MALLOC_NO_DEFRAGMENT")))
        stock.MALLOC_NO_DEFRAGMENT = ft_atoi(v);
}

void    ft_Verbose(char action, char *zone, size_t len_zone)
{
    if (stock.MALLOC_VERBOSE == 0)
        return;
    if (action == 'm')
    {
        ft_putstr_fd("-----MALLOC-----", 1);
        ft_putstr_fd("nous somme en train de malloc une zone de type: ", 1);
        ft_putstr_fd(zone, 1);
        ft_putstr_fd(" la taille de la zone d'allocation est de ", 1);
        ft_putnbr_fd(len_zone, 1);
        ft_putstr_fd("---------\n", 1);
    }
    else if (action == 'f')
    {
        ft_putstr_fd("-----FREE-----", 1);
    }
}

void ft_verouille_mutex(void)
{
    pthread_mutex_lock(&stock.tiny_mutex);
    pthread_mutex_lock(&stock.small_mutex);
    pthread_mutex_lock(&stock.large_mutex);
    pthread_mutex_lock(&stock.tiny_stock_mutex);
    pthread_mutex_lock(&stock.small_stock_mutex);
}

void ft_deverouille_mutex(void)
{
    pthread_mutex_unlock(&stock.tiny_mutex);
    pthread_mutex_unlock(&stock.small_mutex);
    pthread_mutex_unlock(&stock.large_mutex);
    pthread_mutex_unlock(&stock.tiny_stock_mutex);
    pthread_mutex_unlock(&stock.small_stock_mutex);
}

void show_alloc_mem()
{
    ft_verouille_mutex();
    ft_putstr_fd("\nshow allow\n", 1);
    ft_putstr_fd("TINY : ", 1);
    ft_show(stock.tiny);
    ft_putstr_fd("SMALL : ", 1);
    ft_show(stock.small);
    ft_putstr_fd("LARGE : ", 1);
    ft_show(stock.large);
    ft_putstr_fd("\nfin show\n", 1);
    ft_deverouille_mutex();
}

void print_space(void)
{
    t_block     *temp_tiny = stock.tiny;
    t_block     *temp_small = stock.small;
    t_block     *temp_large = stock.large;
    size_t          i = 9 * sysconf(_SC_PAGESIZE);

    ft_verouille_mutex();
    ft_putstr_fd("\nPRINT ZONE ALLOUE\n", 1);
    ft_print_space(temp_tiny, stock.tiny_stock);
    ft_print_space(temp_small, stock.small_stock);
    ft_print_space(temp_large, i);
    ft_putstr_fd("\n....\n", 1);
    ft_deverouille_mutex();
}

void print_char(void)
{
    t_block     *temp_tiny = stock.tiny;
    t_block     *temp_small = stock.small;
    t_block     *temp_large = stock.large;
    size_t          i = 9 * sysconf(_SC_PAGESIZE);

    ft_verouille_mutex();
    ft_putstr_fd("\nPRINT MEMORY\n", 1);
    ft_print_char_deux(temp_tiny, stock.tiny_stock);
    ft_print_char_deux(temp_small, stock.small_stock);
    ft_print_char_deux(temp_large, i);
    ft_putstr_fd("\n....\n", 1);
    ft_deverouille_mutex();
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

void    free(void *ptr)
{  
    t_block *point;
    t_block *iter = NULL;
    t_block *start_list = NULL;
    size_t         i = 0;
    size_t         j = 0;
    size_t         len = 0;
    size_t  len_page = sysconf(_SC_PAGESIZE);
    size_t  *len_stock = NULL;
    pthread_mutex_t *mutex1;
    pthread_mutex_t *mutex_stock;

    if (ptr == NULL)
        return;
    point = ft_find_block(ptr);
    if (point == NULL)
        return;
    ft_Verbose('f', "", 0);
    point->occupe = 0;
    if (point->size <= (len_page))
    {
        len = len_page;
        mutex1 = &stock.tiny_mutex;
        mutex_stock = &stock.tiny_stock_mutex;
        pthread_mutex_lock(mutex1);
        pthread_mutex_lock(mutex_stock);
        start_list = stock.tiny;
        stock.tiny_stock += point->size + BLOCK_HEADER;
        len_stock = &stock.tiny_stock;
    }
    else if (point->size <= (8 * len_page))
    {
        len = 8 * len_page;
        mutex1 = &stock.small_mutex;
        mutex_stock = &stock.small_stock_mutex;
        pthread_mutex_lock(mutex1);
        pthread_mutex_lock(mutex_stock);
        start_list = stock.small;
        stock.small_stock += point->size + BLOCK_HEADER;
        len_stock = &stock.small_stock;
    }
    else
    {
        pthread_mutex_lock(&stock.large_mutex);
        ft_free_large(ptr, &stock.large);
        pthread_mutex_unlock(&stock.large_mutex);
        return;
    }
    if (stock.MALLOC_NO_DEFRAGMENT == 0)
        ft_defragment_page(start_list);
    ft_supr_page(&start_list, len, 0);
    if (start_list == NULL)
        return;
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
    pthread_mutex_unlock(mutex1);
    pthread_mutex_unlock(mutex_stock);
}

size_t *ft_specific_stock(t_block *point)
{
    size_t *len_stock;
    size_t  len_page = sysconf(_SC_PAGESIZE);

    if (point == NULL)
        return 0;
    if (point->size <= len_page)
        len_stock = &stock.tiny_stock;
   else if (point->size <= 8 * len_page)
        len_stock = &stock.small_stock;
    else
        len_stock = NULL;
    return len_stock;
}

t_block    *create_block_page(size_t page_size, size_t *in_stock)
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
    point->occupe = 0;
    point->debut_page = 1;
    point->next = NULL;
    if (in_stock)
        *in_stock += point->size;
    return (point);
}

void    *ft_first_allocate_block(t_block *temp, size_t len_zone, size_t *in_stock,
    pthread_mutex_t *mutex1, pthread_mutex_t *mutex_stock)
{
    t_block     *allocate = NULL;
    t_block     *reste = NULL;
    size_t      size_allo_only;
    size_t      size_restante;

    if (temp == NULL)
        return (ft_end_generate(mutex1, mutex_stock));
    size_allo_only = len_zone - BLOCK_HEADER;
    if (temp->size < size_allo_only)
        return (ft_end_generate(mutex1, mutex_stock));
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
        pthread_mutex_unlock(mutex1);
        pthread_mutex_unlock(mutex_stock);
        return (void *)((char * )allocate + BLOCK_HEADER);
    }
    else
    {
        temp->occupe = 1;
        if (in_stock)
            *in_stock -= temp->size;
        pthread_mutex_unlock(mutex1);
        pthread_mutex_unlock(mutex_stock);
        return (void *)((char *)temp + BLOCK_HEADER);
    }
}

void    *ft_split_block(t_block *temp, size_t len_zone, size_t *in_stock,
    pthread_mutex_t *mutex1, pthread_mutex_t *mutex_stock)
{
    t_block     *allocate = NULL;
    t_block     *reste = NULL;
    size_t      size_allo_only;
    size_t      size_restante;

    if (temp == NULL)
        return (ft_end_generate(mutex1, mutex_stock));
    size_allo_only = len_zone - BLOCK_HEADER;
    if (temp->size < size_allo_only)
        return (ft_end_generate(mutex1, mutex_stock));
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
        pthread_mutex_unlock(mutex1);
        pthread_mutex_unlock(mutex_stock);
        return ((void *)((char * )allocate + BLOCK_HEADER));
    }
    else
    {
        temp->occupe = 1;
        if (in_stock)
            *in_stock -= temp->size;
        pthread_mutex_unlock(mutex1);
        pthread_mutex_unlock(mutex_stock);
        return ((void *)((char *)temp + BLOCK_HEADER));
    }
}

void    *ft_generate_pointer(t_block **liste, size_t len_zone, size_t page, size_t *in_stock,
    pthread_mutex_t *mutex1, pthread_mutex_t *mutex_stock)
{
    if (liste == NULL || in_stock == NULL)
        return NULL;
    pthread_mutex_lock(mutex1);
    pthread_mutex_lock(mutex_stock);
    if ((*liste) == NULL)
    {
        (*liste) = create_block_page(page, in_stock);
        if ((*liste) == NULL)
            return (ft_end_generate(mutex1, mutex_stock));
        return (ft_first_allocate_block(*liste, len_zone, in_stock, mutex1, mutex_stock));
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
                return (ft_end_generate(mutex1, mutex_stock));
            return (ft_first_allocate_block(temp, len_zone, in_stock, mutex1, mutex_stock));
        }
        while (temp->next != NULL)
        {
            if (temp->occupe == 0 && temp->size >= len_zone)
                return (ft_split_block(temp, len_zone, in_stock, mutex1, mutex_stock));
            temp = temp->next;
        }
        if (temp->occupe == 0 && temp->size >= len_zone)
            return (ft_split_block(temp, len_zone, in_stock, mutex1, mutex_stock));
        temp->next = create_block_page(page, in_stock);
        temp = temp->next;
        if (temp == NULL)
            return (ft_end_generate(mutex1, mutex_stock));
        return (ft_first_allocate_block(temp, len_zone, in_stock, mutex1, mutex_stock));
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

void    *ft_generate_large(t_block **start, size_t len, pthread_mutex_t *large_mutex)
{
    t_block     *iter = NULL;
    size_t      len_alloc = 0;

    len_alloc = ft_gen_len(len);
    pthread_mutex_lock(large_mutex);
    if ((*start) == NULL)
    {
        (*start) = create_block_large(len_alloc);
        pthread_mutex_unlock(large_mutex);
        return (void *)((char *)(*start) + BLOCK_HEADER);
    }
    else
    {
        iter = (*start);
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = create_block_large(len_alloc);
        if (iter->next == NULL)
        {
            pthread_mutex_unlock(large_mutex);
            return (NULL);
        }
        iter = iter->next;
    }
    pthread_mutex_unlock(large_mutex);
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
        page = len_page;
        ft_Verbose('m', "TINY", len_zone);
        return (ft_generate_pointer(&stock.tiny, len_zone, page, &stock.tiny_stock,
            &stock.tiny_mutex, &stock.tiny_stock_mutex));
    }
    else if (len_zone <= (8 * len_page) - BLOCK_HEADER)
    {
        page = 8 * len_page;
        ft_Verbose('m', "SMALL", len_zone);
        return (ft_generate_pointer(&stock.small, len_zone, page, &stock.small_stock,
            &stock.small_mutex, &stock.small_stock_mutex));
    }
    else
    {
        ft_Verbose('m', "LARGE", len_zone);
        return (ft_generate_large(&stock.large, (len_zone), &stock.large_mutex));
    }
}