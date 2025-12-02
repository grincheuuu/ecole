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
/*
size_t  ft_align(size_t len)
{
    return ((len + (16 - 1)) & ~(16 - 1));
}*/


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
//                else
//                    ft_puthex_fd((void *)str[i], 1);
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
//    ft_print_char(liste);
}
