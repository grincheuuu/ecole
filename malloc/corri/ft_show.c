#include "libft_malloc.h"

void ft_puthex_fd(size_t n, int fd)
{
    const char *hex_digits = "0123456789ABCDEF";
    char buffer[17]; // 16 chiffres + '\0'
    int i = 0;

    if (n == 0)
    {
        write(fd, "0", 1);
        return;
    }
    while (n > 0 && i < 16)
    {
        buffer[i++] = hex_digits[n % 16];
        n /= 16;
    }
    while (i > 0)
        write(fd, &buffer[--i], 1);
}

void    ft_print_adresse(t_block *temp, int i)
{
    void    *start = NULL;
    void    *end = NULL;

    if (i == 1)
    {
        start = (void *)((char *)temp);
        write(1, "Ox", 2);
        ft_puthex_fd((size_t)start, 1);
        write(1, "\n", 1);
        return;
    }
    start = (void *)((char *)temp + BLOCK_HEADER);
    write(1, "Ox", 2);
    ft_puthex_fd((size_t)start, 1);
    write(1, " - ", 3);
    end = (void *)((char *)temp + BLOCK_HEADER + temp->size);
    write(1, "Ox", 2);
    ft_puthex_fd((size_t)end, 1);
    write(1, " : ", 3);
    ft_putnbr_fd(temp->size, 1);
    write(1, " bytes\n", 7);
}

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