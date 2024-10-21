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
	int	j;

	line = NULL;
	tab = NULL;
	i = 0;
	j = 0;
	file_fd = 0;
	(void)c;
	file_fd = open("/home/gschwart/p12/src/t.txt", O_RDWR | O_CREAT, 0644);
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
	file_fd = open("/home/gschwart/p12/src/t.txt", O_RDONLY, 0644);
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

t_dest	*ft_ray_casting(char **tab, t_fractal *fractal, t_dest *dest)
{
	int	x;
	int	y;
	int	i;

	x = 2.5 * 64;
	y = 3.5 * 64;
	i = 0;
	(void)fractal;
	while (i < WIDTH)
	{
		dest = ft_horizontale(dest, x, y, i, tab);
		dest = ft_verticale(dest, x, y, i, tab);
		dest = ft_distance(dest, i);
		//distorsion; t_fractal
		dest->e = dest->e + (60 / WIDTH);
		printf ("dest[i] %d, xp %d, murHAUT %d murBAS %d LC %f e %f\n", i, dest->xp[i], dest->murHaut[i], dest->murBas[i], dest->Lc[i], dest->e);
		i++;
	}
	//position mur
	//on dessine le mur
	return (dest);
}

t_dest	*ft_distance(t_dest *dest, int i)
{
	int	h_mur;

	dest->Lc[i] = (dest->Lc[i] / cos(dest->e)) * cos(30); // distance mur
	h_mur = (64 / dest->Lc[i]) * ((WIDTH/2) / tan(30));
	h_mur = 54;
	printf("mur %d\n", h_mur);
	dest->murHaut[i] = HEIGHT / 2 - h_mur / 2;
	dest->murBas[i] = HEIGHT / 2 + h_mur / 2;
	return (dest);
}

t_dest	*ft_horizontale(t_dest *dest, int x, int y, int i, char **tab)
{
	int	L;
	int Lc;
	int	v;
	int	h;
	int	xa;
	int	ya;

    h = 32;
    v = 60;
    L = h / tan(v);
    x = x - L;
    y = y - h;
    xa = x / 64;
    ya = y / 64 - 1;
	Lc = L;
    if (tab[ya][xa] == '1')
    {
		dest->Lc[i] = Lc;
        return (dest);
    }
    h = 64;
    y = y - h;
    while (x > 0 && y > 0)
    {
        if (y % 64 == 0)
        {
            L = h / tan(v);
			Lc += L;
            x -= L;
            ////////////
            xa = x / 64;
            ya = y / 64 - 1;
            if (tab[ya][xa] == '1')
            {
				dest->Lc[i] = Lc;
                return (dest) ;
            }
        }
        y -= 64;
    }
	return (NULL);
}

t_dest	*ft_verticale(t_dest *dest, int x, int y, int i, char **tab)
{
	int	L;
	int	Lc;
	int	v;
	int	h;
	int xa;
	int	ya;

    L = 32;
	Lc = 32;
    v = 60;
    h = tan(v) * L;
    x = x - L;
    y = y - h;
    xa = x / 64;
    ya = y / 64;
    if (tab[ya][xa + 1] == '1'  || tab[ya][xa] == '1')
    {
		if (dest->Lc[i] > Lc)
			dest->Lc[i] = Lc;
        return (dest);
    }
    L = 64;
    x -= L;
    while (x > 0 && y > 0)
    {
        if (x % 64 == 0)
        {
			Lc += L;
            h = tan(v) * L;
            y -= h;
            xa = x / 64;
            ya = y / 64;
            if (tab[ya][xa + 1] == '1' || tab[ya][xa] == '1')
            {
				if (dest->Lc[i] > Lc)
					dest->Lc[i] = Lc;
                return (dest);
            }
        }
        x -= L;
    }
	return (NULL);
}

void	ft_pose_carte(t_fractal *fractal)
{
	int	i;
	char	**tab;
	t_dest	*dest;
	
	i = 0;
	dest = malloc(sizeof(t_dest));
	if (dest == NULL)
		return;
	while (i < WIDTH)
	{
		dest->xp[i] = i;
		dest->Lc[i] = 0;
		dest->murHaut[i] = 0;
		dest->murBas[i] = 0;
		i++;
	}
	dest->e = 60;
	tab = ft_gnl(fractal->map.o);
	ft_search_player(tab, fractal);
	dest = ft_ray_casting(tab, fractal, dest);
	ft_render(fractal, dest);
	mlx_loop(fractal->mlx_co);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	(void)argc;
	(void)argv;
	fractal = malloc(sizeof(t_fractal));
	ft_init(fractal);
	ft_pose_carte(fractal);
	return (0);
}