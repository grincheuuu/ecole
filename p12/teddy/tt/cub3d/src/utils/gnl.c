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

#include "../cub3d.h"


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
	char	*ray;

	i = ft_strlen(str);
	ray = malloc((i + 1) * sizeof(char));
	if (ray == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ray[i] = str[i];
		i++;
	}
	ray[i] = '\0';
	return (ray);
}

char **ft_gnl(t_ray *ray) {
    char *line = NULL;
    char **tab = NULL;
    int file_fd, line_count = 0;

    // Ouvre le fichier pour compter les lignes
    file_fd = open("src/utils/t.txt", O_RDONLY);
    if (file_fd == -1) {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Compter les lignes
    while ((line = get_next_line(file_fd)) != NULL) {
        free(line);
        line_count++;
    }
    close(file_fd);

    // Allouer la mémoire pour `tab` et `ray->largeur`
    tab = malloc((line_count + 1) * sizeof(char *));
    ray->largeur = malloc(line_count * sizeof(int));
    if (!tab || !ray->largeur) {
        perror("Erreur d'allocation");
        exit(EXIT_FAILURE);
    }

    // Réouvrir le fichier pour lire les lignes
    file_fd = open("src/utils/t.txt", O_RDONLY);
    if (file_fd == -1) {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lire les lignes et remplir `tab` et `ray->largeur`
    int i = 0;
    while ((line = get_next_line(file_fd)) != NULL) {
        tab[i] = ft_strdup(line);
        ray->largeur[i] = ft_strlen(tab[i]); // Stocker la longueur de chaque ligne
        free(line);
        i++;
    }
    tab[i] = NULL;  // Terminer `tab` par NULL
    close(file_fd);

    ray->longueur = line_count;  // Stocker le nombre total de lignes
    return tab;
}