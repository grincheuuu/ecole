#include <unistd.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int main(void)
{
    char    *str;
    char    larg[100];
	char	**tab;
	char	**tab2;
	char    *str2;
	char	c;

/*    for (int i = 0; i < 99; i++)
        larg[i] = 'q';
    larg[99] = '\0';
	tab = malloc(201 * sizeof(char *));
	if (tab == NULL)
		return 1;
    for (int j = 0; j < 200; j++)
        tab[j] = ft_strdup(larg);
	tab[200] = NULL;
	for (int j = 0; tab[j] != NULL; j++)
	{
		free(tab[j]);
		write(1,"\n\n\n", 1);
	}
	free(tab);
	char	*ko[41];
	for (int i = 0; i < 40; i++)
		ko[i] = strdup("kokokokoffffffffffffffggggggggggggggggko");
	ko[40] = NULL;
	for (int i = 0; ko[i] != NULL; i++)
		free(ko[i]);
	free(ko);*/
//	str  = ft_strdup("hello word");
//	free(str);
//	str = NULL;
	str2 = malloc(301);
	for (int i = 0; i < 300; i++)
        str2[i] = 'q';
	str2[300] = '\0';
	char *bb2[11];
//	bb2 = malloc((11) * sizeof(char *));
	if (bb2 == NULL)
	{
		write(1, "error\n", 6);
		return 1;
	}
	for (int k = 0; k < 10; k++)
		bb2[k] = ft_strdup(str2);
	realloc(bb2[9], 500);
	realloc(bb2[9], 1500);
	realloc(bb2[9], 400);
	bb2[10] = NULL;
/*	for (int k = 0; bb2[k] != NULL; k++)
		free(bb2[k]);*/
//	free(bb2);
//	free(str2);
/*	char *zo;
	zo = ft_strdup(str2);
	realloc(zo, 100000);
	malloc(300000);
	malloc(300000);
	malloc(300000);
	malloc(300000);
	malloc(140000);
	malloc(240000);
	malloc(340000);
	malloc(40000);
	malloc(40000);
	malloc(30000);
	tab2 = malloc((11) * sizeof(char *));
	if (tab2 == NULL)
		write(1, "error\n", 6);
	for (int k = 0; k < 10; k++)
		tab2[k] = ft_strdup("hello word");
	tab2[10] = NULL;
	for (int k = 0; tab2[k] != NULL; k++)
		free(tab2[k]);
	free(tab2);
	malloc(1);
	realloc(tab2, 1400);
	malloc(1000);
	malloc(1900);*/
//	malloc(1);
    return 0;
}
