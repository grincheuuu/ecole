#include "libft_malloc.h"

size_t  ft_align(size_t len)
{
    size_t  len_zone;

    if (len < 0)
        return (-1);
    if (len % 16 == 0)
        return (len);
    len_zone = (len / 16) * 16;
    return (len_zone + 16);
}


void ft_print_char(t_block *liste)
{
    t_block     *temp = liste;

    while (temp != NULL)
    {
        if (temp->debut_page == 1)
        {
            char    *str = (char *)temp;
            for (size_t i = 0; i < temp->size; i++)
            {
                if (ft_isalnum(str[i]) == 1 || str[i] == ' ')
                    write(1, &str[i], 1);
                else
                    ft_puthex_fd((size_t)str[i], 1);
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

    if (liste == NULL)
        return;
    if (temp->size <= (len_page - BLOCK_HEADER))
        ft_putstr_fd("\ntiny\n", 1);
    else if (temp->size <= (8 * len_page - BLOCK_HEADER))
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
}

void ft_print_char_deux(t_block *liste, size_t len)
{
    size_t  len_page = sysconf(_SC_PAGESIZE);
    (void)len;
    int i = 0;
    t_block *iter = liste;
    unsigned char    *c;

    if (liste == NULL)
        return;
    if (iter->size <= (len_page - BLOCK_HEADER))
        ft_putstr_fd("\ntiny\n", 1);
    else if (iter->size <= (8 * len_page - BLOCK_HEADER))
        ft_putstr_fd("\nsmall\n", 1);
    else
        ft_putstr_fd("\nlarge\n", 1);
    while (iter != NULL) // un block
    {
        if (iter->debut_page == 1)
        {
            i++;
            write(1, ORANGE, 5);
            ft_putstr_fd("\n|PAGE n ", 1);
            ft_putnbr_fd(i, 1);
            write(1, "|\n", 3);
            write(1, NC, 5);
        }
        if (iter->occupe == 1)
        {
            for (size_t i = 0; i < BLOCK_HEADER; i++)
            {
                write(1, YELLOW, 5);
                write(1, "H", 1);
                write(1, NC, 5);
            }
            write(1, "-", 2);
            c = (unsigned char *)iter + BLOCK_HEADER;
            for (size_t n = 0; n < (iter->size - BLOCK_HEADER); n++)
            {
                if (ft_isprint(c[n]) == 1)
                    write(1, &c[n], 1);
                else
                    write(1, ".", 1);
            }
            write(1, "\n", 1);
        }
        else
        {
            for (size_t j = 0; j < iter->size; j++)
            {
                if (j < BLOCK_HEADER)
                {
                    write(1, YELLOW, 5);
                    write(1, "H", 1);
                    write(1, NC, 5);
                }
                else
                    write(1, "0", 1);
            }
            write(1, "\n", 1);
        }
        iter = iter->next;
    }
}

void    *ft_end_generate(pthread_mutex_t *mutex1, pthread_mutex_t *mutex_stock)
{
    pthread_mutex_unlock(mutex1);
    pthread_mutex_unlock(mutex_stock);
    return (NULL);
}