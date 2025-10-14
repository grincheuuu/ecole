#include "libft_malloc.h"

int main(void)
{
    char    *str;
//    char    larg[2051];
//    char    *copy;

    str = malloc(3);
    str[0] = 'a';
    str[1] = 'b';
    str[2] = '\0';
    ft_putstr_fd(str, 1);
    free(str);
//    str = ft_strdup("ehllo world8");
/*    for (int i = 0; i < 2050; i++)
        larg[i] = 'q';
    larg[2050] = '\0';
    copy = ft_strdup(larg);
    ft_putstr_fd(copy, 1);
    free(copy);*/
//    malloc(3);
    return 0;
}