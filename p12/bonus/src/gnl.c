/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:36:42 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/24 15:36:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

double	ft_atof(char *s)
{
	double	nb;
	double	decimal;
	int		signe;

	nb = 0;
	signe = 1;
	decimal = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			signe *= -1;
	}
	while (*s != '.' && *s != '\0')
		nb = (nb * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s != '\0')
	{
		decimal /= 10;
		nb = nb + (*s++ - 48) * decimal;
	}
	return (nb * signe);
}

char	*ft_strdup(const char *str)
{
	int	i;
	char	*dest;

	i = ft_strlen(str);
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_gnl(char c)
{
	char	*line;
	char	**tab;
	int		file_fd;
	int	i;

	line = NULL;
	tab = NULL;
	i = 0;
	file_fd = 0;
	(void)c;
	file_fd = open("src/t.txt", O_RDWR | O_CREAT, 0644);
	if (file_fd == -1)
	{
		perror("open error\n");
		exit (EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			break;
		free(line);
		i++;
	}
	close(file_fd);
	free(line);
	line  = NULL;
	tab = malloc((i + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	file_fd = open("src/t.txt", O_RDONLY, 0644);
	if (file_fd == -1)
	{
		write (2, "open error\n", 11);
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			break;
		tab[i] = ft_strdup(line);
		i++;
		free(line);
	}
	tab[i] = NULL;
	free(line);
	close(file_fd);
	i = 0;
	while(tab[i] != NULL)
	{
		printf("tab[i] %s\n", tab[i]);
		i++;
	}
	return (tab);
}
