#include "libft_malloc.h"

void ft_puthex_fd(size_t n, int fd)
{
    char	c;
    unsigned char		div;
    unsigned char		mod;

    c = 0;
    if (n >= 0 && n <= 15)
    {
        if (n <= 9)
            c = '0' + n;
        else
            c = 'A' + n - 10;
        write (fd, &c, 1);
    }
    else
    {
        div = n / 16;
        mod = n % 16;
        ft_puthex_fd(div, fd);
        ft_puthex_fd(mod, fd);
    }
}

void    ft_print_adresse(void *addr)
{
    write(1, "Ox", 2);
    ft_puthex_fd((size_t)addr, 1);
}

/*
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
}*/