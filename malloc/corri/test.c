#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "libft_malloc.h"

static int	ft_limit(int n, int fd)
{
	write (fd, "-", 1);
	write (fd, "2", 1);
	n = 147483648;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		div;
	int		mod;

	c = 0;
	if (n == -2147483648)
		n = ft_limit(n, fd);
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write (fd, &c, 1);
	}
	else
	{
		div = n / 10;
		mod = n % 10;
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
}

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

void print(char *s)
{
    write(1, s, strlen(s));
}

int main(void)
{
    char    *str;
    char    *larg;
	char	**tab;
	char	**tab2;
	char    *str2;
	char	*str3;
	char	c;

	str = malloc(1);
	free(str);
//	print_space();
	larg = malloc(100 * sizeof(char));
    for (int i = 0; i < 99; i++)
        larg[i] = 'q';
    larg[99] = '\0';
//	print_char();
	tab = malloc(201 * sizeof(char *));
	if (tab == NULL)
		return 1;
    for (int j = 0; j < 200; j++)
        tab[j] = ft_strdup(larg);
//	print_space();
//	print_char();
	tab[200] = NULL;
	for (int j = 0; tab[j] != NULL; j++)
		free(tab[j]);
	free(tab);
	free(larg);
//	print_space();
	char	**ko;
	ko = malloc(10 * sizeof(char *));
	for (int i = 0; i < 9; i++)
		ko[i] = strdup("kokokokoffffffffffffffggggggggggggggggko");
	ko[10] = NULL;
	for (int i = 0; ko[i] != NULL; i++)
		free(ko[i]);
	str  = ft_strdup("hello word");
	str2 = realloc(str, 30000);
    for (int i = 0; i < 999; i++)
        str2[i] = 'Z';
//	print_char();
//	print_space();
/*	free(bb2);
	show_alloc_mem();
	str2 = (char *)realloc(str2, 15001);
	for (int i = 0; i < 15000; i++)
        str2[i] = 'q';
	str2[15000] = '\0';
	str2 = (char *)realloc(str2, 151);
	for (int i = 0; i < 150; i++)
        str2[i] = 'q';
	str2[150] = '\0';
	str2 = (char *)realloc(str2, 150001);
	for (int i = 0; i < 150000; i++)
        str2[i] = 'q';
	str2[150000] = '\0';
	str2 = (char *)realloc(str2, 1501);
	for (int i = 0; i < 1500; i++)
        str2[i] = 'q';
	str2[1500] = '\0';*/
//	free(str2);
//	free(bb2);
/*	str3 = malloc(150001);
	for (int i = 0; i < 150000; i++)
        str3[i] = 'q';
	str3[150000] = '\0';
	char **bb3;
	bb3 = malloc((11) * sizeof(char *));
	if (bb3 == NULL)
	{
		write(1, "error\n", 6);
		return 1;
	}
	for (int k = 0; k < 10; k++)
	{
		write(1, "\n", 1);
		ft_putnbr_fd(k, 1);
		write(1, "\n", 1);
		bb3[k] = ft_strdup(str3);
	}
	bb3[10] = NULL;*/
//	for (int k = 0; bb3[k] != NULL; k++)
//		free(bb3[k]);
//	free(bb3);
//	free(str3);
//	malloc(1);
//	free(bb2);
/*	char	*a1 = ft_strdup("hello");
	char	*a2 = ft_strdup("hello word");
	char	*a3 = ft_strdup("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
	realloc(a1, 100);
	realloc(a2, 200);
	realloc(a3, 400);*/
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
