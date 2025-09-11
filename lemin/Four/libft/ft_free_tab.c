#include "libft.h"

void    ft_free_tab(void *ptr)
{
    int i;
    char **tab;

    tab = (char **)ptr;
    if (!tab)
        return;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
