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
	char	c;
    for (int i = 0; i < 99; i++)
        larg[i] = 'q';
/*    larg[99] = '\0';
	tab = malloc(201 * sizeof(char *));
	if (tab == NULL)
		return 1;
    for (int j = 0; j < 200; j++)
        tab[j] = ft_strdup(larg);
	tab[200] = NULL;*/
//	str  = ft_strdup("hello word9999999999999999999999999999999999999999999");
//	free(str);
//	str = NULL;
/*	for (int i = 0; i < 150; i++)
	{
		str = ft_strdup("hello words99999999998888888888888888888899999999999s");
		free(str);
		str = NULL;
	}
	free(str);*/
//	for (int j = 0; tab[j] != NULL; j++)
//		free(tab[j]);
//	free(tab);
	char	*ko[100];
	for (int i = 1; i < 40; i++)
		ko[i] = strdup("kokokokokokokkokokpkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");
	ko[99] = NULL;
	for (int i = 1; ko[i] != NULL; i++)
		free(ko[i]);
	free(ko);
//	realloc(str, 1400);
//	malloc(1000);
//	malloc(1900);
	malloc(1);
    return 0;
}