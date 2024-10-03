#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char    **ft_split(char *str, char del)
{
    int i;
    int g;
    int j;
    int v;
    int z;
    char    **dest;

    i = 0;
    j = 0;
    g = 0;
    v = 0;
    dest = NULL;
    if (str == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        if(str[i] == del)
        {
            while (str[i] != '\0' && str[i] == del)
                i++;
            j++;
        }
        i++;
    }
    dest = (char **)malloc((j + 1 + 1) * sizeof(char *));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (g <= j)
    {
        v = 0;
        while (str[i] != '\0' && str[i] == del)
            i++;
        z = i;
        while (str[i] != '\0' && str[i] != del)
            i++;
        dest[g] = malloc((i - z + 1) * sizeof(char));
        if (dest[g] == NULL)
            return (NULL);
        while (z < i)
        {
            dest[g][v] = str[z];
            v++;
            z++;
        }
        dest[g][v] = '\0';
        g++;
    }
    dest[g] = NULL;
    return (dest);
}

int	main(void)
{
    char    str[] = "hello word";
    char    sep = ' ';
    char    **chr;
    int i;

    i = 0;
    chr = ft_split(str, sep);
    while (chr[i] != NULL)
    {
        printf("chr %d str %s \n", i, chr[i]);
        free(chr[i]);
        i++;
    }
    free(chr);
    return (0);
}
