/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:02:48 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/12 17:04:40 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (s == NULL || fd < 0)
		return ;
	while (*s != '\0')
	{
		write (fd, s, 1);
		s++;
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
		return;
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
	int	j;

	line = NULL;
	tab = NULL;
	i = 0;
	j = 0;
	file_fd = open("text.tmp", O_RDONLY, 0644);
	if (file_fd == -1)
	{
		write (2, "open error\n", 11);
		return ;
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
	file_fd = open("text.tmp", O_RDONLY, 0644);
	if (file_fd == -1)
	{
		write (2, "open error\n", 11);
		return ;
	}
	while (1)
	{
		line = get_next_line(file_fd);
		tab[i] = ft_strdup(line);
		i++;
		free(line);
	}
	tab[i] == NULL;
	free(line);
	close(file_fd);
	return (tab);
}

void	ft_search_player(char **tab, t_fractal *fractal)
{
	int	x;
	int y;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == fractal->map.o)
			{
				fractal->map.x = (x + 1) * 64 - 32;
				fractal->map.y = (y + 1) * 64 - 32;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_ray_casting(char **tab, t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
}

void	ft_pose_carte(t_fractal *fractal)
{
	char	**tab;

	tab = ft_gnl(fractal->map.o);
	ft_search_player(tab, fractal);
	ft_ray_casting(tab, fractal);
	ft_render(fractal);
	mlx_loop(fractal->mlx_co);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0))
	{
		ft_init(&fractal);
		ft_pose_carte(&fractal);
	}
	else
	{
		ft_putstr_fd("tapez : fractol mandelbrot", 1);
		exit (EXIT_FAILURE);
	}
	return (0);
}
