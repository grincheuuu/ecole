/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:57:59 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/18 05:55:05 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strchr2(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}

void	*free_strjoin2(char **s1, t_cubfile *cubfile)
{
	free(*s1);
	cubfile->failed = 1;
	printf("error :malloc failed\n");
	return (NULL);
}

void	*free_strjoin1(t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("error :malloc failed\n");
	return (NULL);
}

char	*ft_strjoin4(char *s1, char *s2, t_cubfile *cubfile)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (free_strjoin1(cubfile));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free_strjoin2(&s1, cubfile));
	i = -1;
	j = 0;
	while (s1[++i] != '\0' && s1)
		str[i] = s1[i];
	while (s2[j] != '\0' && s2)
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

void	*free_new_line1(char **read_lines)
{
	free(*read_lines);
	return (NULL);
}

void	*free_new_line2(char **read_lines, t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("error :malloc failed\n");
	free(read_lines);
	return (NULL);
}

char	*ft_new_lines(char *read_lines, t_cubfile *cubfile)
{
	int		i;
	int		j;
	char	*new_lines;

	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	if (!read_lines[i])
		return (free_new_line1(&read_lines));
	new_lines = (char *)malloc(sizeof(char) * (ft_strlen(read_lines) - i + 1));
	if (!new_lines)
		return (free_new_line2(&read_lines, cubfile));
	i++;
	j = 0;
	while (read_lines[i])
		new_lines[j++] = read_lines[i++];
	new_lines[j] = '\0';
	free(read_lines);
	return (new_lines);
}

void	*free_lines(t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("error :malloc failed\n");
	return (NULL);
}

char	*ft_lines(char *read_lines, t_cubfile *cubfile)
{
	char	*lines;
	int		i;

	i = 0;
	if (!read_lines[i])
		return (NULL);
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	lines = (char *)malloc(sizeof(char) * i + 2);
	if (!lines)
		free_lines(cubfile);
	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	if (read_lines[i] == '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	lines[i] = '\0';
	return (lines);
}

void	*free_read_lines1(t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("error :malloc failed\n");
	return (NULL);
}

void	*free_read_lines2(char **buffer)
{
	free(*buffer);
	return (NULL);
}

char	*ft_read_lines(int fd, char *read_lines, t_cubfile *cubfile)
{
	char	*buffer;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (3 + 1));
	if (!buffer)
		return (free_read_lines1(cubfile));
	r = 1;
	while (!ft_strchr2(read_lines, '\n') && r != 0)
	{
		r = read(fd, buffer, 3);
		if (r == -1)
		{
			free(buffer);
			if (read_lines)
				free(read_lines);
			return (NULL);
		}
		buffer[r] = '\0';
		read_lines = ft_strjoin4(read_lines, buffer, cubfile);
		if (read_lines == NULL)
			return (free_read_lines2(&buffer));
	}
	free(buffer);
	return (read_lines);
}

char	*get_next_line(int fd, t_cubfile *cubfile)
{
	static char		*read_lines;
	char			*lines;

	if (3 <= 0 || fd < 0 || 3 >= 2147483647)
		return (0);
	read_lines = ft_read_lines(fd, read_lines, cubfile);
	if (!read_lines)
		return (NULL);
	lines = ft_lines(read_lines, cubfile);
	read_lines = ft_new_lines(read_lines, cubfile);
	return (lines);
}
////////////////////////////////////////////////////////////////

//split
////////////////////////////////////////////////////////////////

int	nblist(const char *str, char c)
{
	int	co;
	int	co2;

	co2 = 0;
	co = 0;
	while (str[co] != '\0')
	{
		if ((str[co] != c)
			&& ((str[co + 1] == c) || (str[co + 1] == '\0')))
			co2++;
		co++;
	}
	return (co2);
}

char	*minl(const char *str, char c, int co2)
{
	char	*newl;
	int		co;

	co = 0;
	while (str[co + co2] != c && str[co + co2] != '\0')
		co++;
	co++;
	newl = (char *)malloc((co) * sizeof(char));
	if (!newl)
	{
		printf("error :malloc failed\n");
		return (NULL);
	}
	co = 0;
	while (str[co + co2] != c && str[co + co2] != '\0')
	{
		newl[co] = str[co + co2];
		co++;
	}
	newl[co] = '\0';
	return (newl);
}

void	*split_fail(void)
{
	printf("error :malloc failed\n");
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**nell;
	int		co;
	int		co2;
	int		size;

	size = nblist(str, c);
	nell = (char **)malloc((size + 1) * sizeof(char *));
	if (!nell)
		return (split_fail());
	co2 = 0;
	co = 0;
	while (str[co] != '\0')
	{
		if ((co == 0 || (str[co - 1] == c))
			&& (str[co] != c))
		{
			nell[co2] = minl(str, c, co);
			co2++;
		}
		co++;
	}
	nell[co2] = 0;
	return (nell);
}

////////////////////////////////////////////////////////////////

int	test_existence(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	if (close(fd) == -1)
		return (1);
	return (0);
}

//test des couleurs rgb
//////////////////////////////////////////////////////////////////

int	ft_atoi(const char *str)
{
	int	i;
	int	sig;
	int	result;

	i = 0;
	sig = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	if ((str[i + 1] == '-') || (str[i] == '+'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sig);
}

int	ft_isdigit(int str)
{
	int	car;

	car = str;
	if (car < '0' || car > '9')
	{
		return (0);
	}
	return (1);
}

//0 if there are no digit in a str, else: 1
int	is_str_digit(char *str)
{
	int	co;

	co = 0;
	while (str[co] != '\0')
	{
		if (ft_isdigit(str[co]) == 0)
			return (1);
		co++;
	}
	return (0);
}

void	free_split(char **str)
{
	int	co;

	co = 0;
	while (str[co])
	{
		free(str[co]);
		co++;
	}
	free(str);
}

int	put_rgb_floor(t_cubfile *cubfile, char *charnum)
{
	char	**numbers;
	int		co;

	co = 0;
	if (cubfile->floor_color)
	{
		printf("error: there are two floor color lines!\n");
		return (1);
	}
	cubfile->floor_color = (int *)malloc(3 * sizeof(int));
	if (!cubfile->floor_color)
	{
		printf("error :malloc failed\n");
		return (1);
	}
	numbers = ft_split(charnum, ',');
	while (co < 3)
	{
		cubfile->floor_color[co] = ft_atoi(numbers[co]);
		co++;
	}
	free_split(numbers);
	return (0);
}

int	put_rgb_ceiling(t_cubfile *cubfile, char *charnum)
{
	char	**numbers;
	int		co;

	co = 0;
	if (cubfile->ceiling_color)
	{
		printf("error: there are two ceiling color lines!\n");
		return (1);
	}
	cubfile->ceiling_color = (int *)malloc(3 * sizeof(int));
	if (!cubfile->ceiling_color)
	{
		printf("error :malloc failed\n");
		return (1);
	}
	numbers = ft_split(charnum, ',');
	while (co < 3)
	{
		cubfile->ceiling_color[co] = ft_atoi(numbers[co]);
		co++;
	}
	free_split(numbers);
	return (0);
}

int	number_exeptions(char **numbers, int co)
{
	if (is_str_digit(numbers[co]) == 1)
	{
		printf("error: there is a non int in the RGB colors\n");
		free_split(numbers);
		return (1);
	}
	if (strlen(numbers[co]) > 3)
	{
		printf("error: the number is too big, it must be less than 255\n");
		free_split(numbers);
		return (1);
	}
	if (ft_atoi(numbers[co]) > 255)
	{
		printf("error: the number is too big, it must be less than 255\n");
		free_split(numbers);
		return (1);
	}
	return (1);
}

int	test_rgb(char *charnum)
{
	char	**numbers;
	int		co;

	co = 0;
	numbers = ft_split(charnum, ',');
	if (numbers == NULL)
		return (1);
	while (numbers[co])
		co++;
	if (co != 3)
	{
		printf("error: not good colors param\n");
		free_split(numbers);
		return (1);
	}
	co = 0;
	while (numbers[co])
	{
		number_exeptions(numbers, co);
		co++;
	}
	free_split(numbers);
	return (0);
}

//////////////////////////////////////////////////////////////////

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	const char	*a;
	char		*b;
	size_t		co;

	a = (const char *)source;
	b = (char *)destination;
	if ((a == NULL) && (b == NULL))
		return (NULL);
	co = 0;
	while (co < size)
	{
		b[co] = a[co];
		co++;
	}
	return (b);
}

char	*ft_strdup(const char *str)
{
	int		length;
	char	*new_str;

	length = ft_strlen(str) + 1;
	new_str = (char *)malloc(sizeof(char) * length);
	if (!new_str)
	{
		printf("error :malloc failed\n");
		return (NULL);
	}
	ft_memcpy(new_str, str, length);
	return (new_str);
}

t_cubfile	*init_cubfile(void)
{
	t_cubfile	*cubfile;

	cubfile = (t_cubfile *)malloc(sizeof(t_cubfile));
	if (!cubfile)
	{
		printf("error :malloc failed\n");
		return (NULL);
	}
	cubfile->no_path = NULL;
	cubfile->so_path = NULL;
	cubfile->we_path = NULL;
	cubfile->ea_path = NULL;
	cubfile->floor_color = NULL;
	cubfile->ceiling_color = NULL;
	cubfile->row_length = 0;
	cubfile->column_length = 0;
	cubfile->map = NULL;
	cubfile->player_x = -1;
	cubfile->player_y = -1;
	cubfile->player_orientation = 0;
	cubfile->failed = 0;
	return (cubfile);
}

///////////////////////////////////////////////////////////////////////

char	**ft_realloc(char **old_envp, size_t new_size)
{
	char		**new_envp;
	size_t		i;

	new_envp = (char **)malloc(new_size);
	if (!new_envp)
	{
		printf("error :malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (old_envp[i] != NULL)
	{
		new_envp[i] = old_envp[i];
		i++;
	}
	new_envp[i] = NULL;
	free(old_envp);
	return (new_envp);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0) && (*s1 && (*s1 == *s2)))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	finalize(char ***envp, char **new_envp, char *new_var, int i)
{
	*envp = new_envp;
	(*envp)[i] = new_var;
	(*envp)[i + 1] = NULL;
}

void	free_cub_file(t_cubfile *cubfile)
{
	int	co;

	co = 0;
	free(cubfile->no_path);
	free(cubfile->so_path);
	free(cubfile->we_path);
	free(cubfile->ea_path);
	free(cubfile->floor_color);
	free(cubfile->ceiling_color);
	while ((co < cubfile->column_length))
	{
		free(cubfile->map[co]);
		co++;
	}
	free(cubfile->map);
	free(cubfile);
}

int	free_updates_char(char **new_var)
{
	free(new_var);
	printf("realloc failed");
	return (1);
}

int	updates_char(char ***envp, const char *line)
{
	char	*new_var;
	char	**new_envp;
	int		i;

	i = 0;
	new_var = (char *)malloc ((ft_strlen(line) + 1) * sizeof(char));
	if (!new_var)
	{
		printf("malloc failed\n");
		return (1);
	}
	while (line[i] != '\0')
	{
		new_var[i] = line[i];
		i++;
	}
	new_var[i] = '\0';
	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = ft_realloc(*envp, sizeof(char *) * (i + 2));
	if (!new_envp)
		return (free_updates_char(&new_var));
	finalize(envp, new_envp, new_var, i);
	return (0);
}

//////////////////////////////////////////////////

/*void	print_tab(t_cubfile *cubfile)
{
	int	co;
	int	co2;

	co = 0;
	co2 = 0;
	while (co < cubfile->column_length)
	{
		co2 = 0;
		while (co2 < cubfile->row_length)
		{
			printf("%d",cubfile->map[co][co2]);
			co2++;
		}
		printf("\n");
		co++;
	}
}*/

void	print_map_char(char **map_char)
{
	int	co;

	co = 0;
	while (map_char[co])
	{
		printf("map :%s\n", map_char[co]);
		co++;
	}
}

void	free_cub_file2(t_cubfile *cubfile)
{
	free(cubfile->no_path);
	free(cubfile->so_path);
	free(cubfile->we_path);
	free(cubfile->ea_path);
	free(cubfile->floor_color);
	free(cubfile->ceiling_color);
	free(cubfile->map);
	free(cubfile);
}

//ici commence la mega fonction char_to_int_map
////////////////////////////////////////////

int	how_many_lines(t_cubfile *cubfile, char **map_char)
{
	int	number_lines;
	int	max_length;

	number_lines = 0;
	max_length = 0;
	while (map_char[number_lines])
	{
		if (max_length < (int)ft_strlen(map_char[number_lines]))
			max_length = ft_strlen(map_char[number_lines]);
		number_lines++;
	}
	cubfile->column_length = number_lines;
	cubfile->row_length = max_length;
	return (number_lines);
}

int	multiplayer_exeption(int *number_of_players,
	t_cubfile *cubfile, int co, int co2)
{
	cubfile->player_x = co2;
	cubfile->player_y = co;
	(*number_of_players)++;
	if (*number_of_players > 1)
	{
		printf ("error: player: this is not a multiplayer ");
		printf ("game, please put one and only one player\n");
		cubfile->player_x = 42;
		cubfile->player_y = 42;
		return (2);
	}
	return (0);
}

int	count_player(t_cubfile *cubfile, char **map_char, int *number_of_players)
{
	int	co;
	int	co2;

	co = 0;
	co2 = 0;
	how_many_lines(cubfile, map_char);
	while (map_char[co])
	{
		co2 = 0;
		while (map_char[co][co2] != '\0')
		{
			if (map_char[co][co2] == 'N' || map_char[co][co2] == 'S'
				|| map_char[co][co2] == 'E' || map_char[co][co2] == 'W')
			{
				cubfile->player_orientation = map_char[co][co2]; //////// pitier l enleve pas on va ce battre victor
				if (multiplayer_exeption(number_of_players,
						cubfile, co, co2) == 2)
					return (2);
			}
			co2++;
		}
		co++;
	}
	return (0);
}

int	finalise_player(t_cubfile *cubfile, char **map_char, int *number_of_players)
{
	if (count_player(cubfile, map_char, number_of_players) == 2)
		return (2);
	if (*number_of_players < 1)
	{
		printf ("error: player: where is the damn player?\n");
		return (2);
	}
	return (0);
}

void	fail_char_to_int_map(char ***map_char, t_cubfile *cubfile)
{
	int	co;

	printf("error :malloc failed\n");
	co = 0;
	while (*map_char[co])
	{
		free(*map_char[co]);
		co++;
	}
	free(*map_char);
	free_cub_file2(cubfile);
	exit (1);
}

void	fail_char_to_int_map2(t_cubfile *cubfile, char ***map_char)
{
	printf("error :malloc failed\n");
	int co3 = 0;
	while (*map_char[co3])
	{
		free(*map_char[co3]);
		co3++;
	}
	free(*map_char);
	free_cub_file2(cubfile);
	exit (1);
}

//0 si tout vas bien 1 si il y a un probleme
int	char_to_int_map(t_cubfile *cubfile, char **map_char)
{
	int	co;
	int	co2;
	int	number_of_players;

	number_of_players = 0;
	if (finalise_player(cubfile, map_char, &number_of_players) == 2)
		return (2);
	cubfile->map = (int **)malloc(cubfile->column_length * sizeof(int *));
	if (!cubfile->map)
		fail_char_to_int_map(&map_char, cubfile);
	co = 0;
	co2 = 0;
	while (map_char[co])
	{
		co2 = 0;
		cubfile->map[co] = (int *)malloc((cubfile->row_length) * sizeof(int));
		if (!cubfile->map[co])
			fail_char_to_int_map2(cubfile, &map_char);
		while (map_char[co][co2] != '\0')
		{
			if (map_char[co][co2] == '0')
				cubfile->map[co][co2] = 0;
			if (map_char[co][co2] == '1')
				cubfile->map[co][co2] = 1;
			if (map_char[co][co2] == ' ')
				cubfile->map[co][co2] = 2;
			if (map_char[co][co2] == 'N' || map_char[co][co2] == 'S' || map_char[co][co2] == 'E' || map_char[co][co2] == 'W')
				cubfile->map[co][co2] = 0;
			
			co2++;
		}
		//pour que toutes les lignes soit a la meme taile
		if (co2 < cubfile->row_length)
		{
			while(co2 < cubfile->row_length)
			{
				cubfile->map[co][co2] = 2;
				co2++;
			}
		}
		//cubfile->map[co][co2] = NULL;
		co++;
	}
	co = 0;
	co2 = 0;
	while (co < cubfile->column_length)
	{
		co2 = 0;
		while(co2 < cubfile->row_length)
		{
			if (cubfile->map[co][co2] == 0)
			{
				//la c est le pixel 1
				if ((co2+1) >= cubfile->row_length || ((cubfile->map[co][co2 + 1] != 0) && (cubfile->map[co][co2 + 1] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 1||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 2
				if (((co2+1) >= cubfile->row_length || (co) == 0) || ((cubfile->map[co - 1][co2 + 1] != 0) && (cubfile->map[co - 1][co2 + 1] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 2||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 3
				if ((co == 0) || ((cubfile->map[co - 1][co2] != 0) && (cubfile->map[co - 1][co2] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 3||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 4
				if ((co2 == 0 || (co) == 0) || ((cubfile->map[co - 1][co2 - 1] != 0) && (cubfile->map[co - 1][co2 - 1] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 4||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 5
				if ((co2) == 0 || ((cubfile->map[co][co2 - 1] != 0) && (cubfile->map[co][co2 - 1] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 5||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 6
				if ((co2 == 0 || (co + 1) >= cubfile->column_length) || ((cubfile->map[co + 1][co2 - 1] != 0) && (cubfile->map[co + 1][co2 - 1] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 6||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 7
				if (((co + 1) >= cubfile->column_length) || ((cubfile->map[co + 1][co2] != 0) && (cubfile->map[co + 1][co2] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 7||");
					printf("the map is invalid\n");
					return (1);
				}
				//la c est le pixel 8
				if (((co2+1) >= cubfile->row_length || (co + 1) >= cubfile->column_length) || ((cubfile->map[co + 1][co2 + 1] != 0) && (cubfile->map[co + 1][co2 + 1] != 1)))
				{
					//printf("||THERE IS A PROBLEME WITH THE PIX NUMBER 8||");
					printf("the map is invalid\n");
					return (1);
				}
			}
			co2++;
		}
		//printf("\n");
		co++;
	}	
	return (0);
}

//10 NSEW
//1 if there is somthing else, 0 if there is nothing else than what s in "list"
int does_line_have(char *line)
{
	char *list = "10 NSEW";
	int co = 0;
	int co2 = 0;
	int co3 = 0;
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	while (line[co] != '\0')
	{
		co2 = 0;
		co3 = 0;
		while (list[co2] != '\0')
		{
			if (line[co] == list[co2])
			{
				co3 = 1;
			}
			co2++;
		}
		if (co3 < 1)
		{
			//printf("[%c]", line[co]);
			return (1);
		}
		co++;
	}
	return (0);
}


/*void free_cub_file(t_cubfile *cubfile)
{
	int co = 0;
	free(cubfile->no_path);
	free(cubfile->so_path);
	free(cubfile->we_path);
	free(cubfile->ea_path);
	free(cubfile->floor_color);
	free(cubfile->ceiling_color);
	while ((co < cubfile->column_length))
	{
		free(cubfile->map[co]);
		co++;
	}
	free(cubfile->map);
	free(cubfile);
}*/




void free_files_rgb(char ***map_char, t_cubfile *cubfile, char **line, int fd)
{
	free_cub_file(cubfile);
	free(*map_char);
				
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd, cubfile);
	}
	free(*line);
}

void free_files_rgb2(t_cubfile *cubfile, char **line, int fd)
{
	free_cub_file(cubfile);
				
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd, cubfile);
	}
	free(*line);
}



int verif(char *map, t_cubfile *cubfile)
{
	int co = 0;
	int fd;

	int number_of_path = 0;
	int number_of_rgb = 0;
	char **map_char;
	map_char = (char **)malloc(2 * sizeof(char *));
	if (!map_char)//nikel
	{
		printf("error :malloc failed\n");
		return (1);
	}
	map_char[0] = NULL;
	map_char[1] = NULL;
	int start_map = -1;
	char *line;
	
	/*t_cubfile *cubfile = init_cubfile();
	if (!cubfile)
	{
		free(map_char);
		return(1);
	}*/
	fd = open(map, O_RDONLY);

	//while (co <= 50)
	while(1)
	{
		line = get_next_line(fd, cubfile);
		//if (line)
		//	printf("%s\n", line);
		if (cubfile->failed == 1)
		{
			//printf("hahahahahahah");
			int coo2 = 0;
			while(map_char[coo2] != NULL)//555555555555555555555555555555555555555555555555555555555555555555555555555555
			{
				free(map_char[coo2]);
				coo2++;
			}
			free(map_char);
			free(cubfile);
			return (1);
		}
		/*if ((mozambique == 0) && (!line))
		{
			//line = (char *)malloc(sizeof(char) * 2);
			line = "\n";
			mozambique++;
		}*/

		if (!line)					//rajouter unr indication sur ce qui manque
		{
			//printf("%s\n", map);
			//print_map_char(map_char);
			int exit_code = 0;

			if (number_of_path < 4)
			{
				printf("error: not enouth paths\n");
				exit_code = 1;
			}

			if (number_of_path > 4)
			{
				printf("error: too much paths\n");
				exit_code = 1;
			}
			if (number_of_rgb < 2)
			{
				printf("error: not enouth colors\n");
				exit_code = 1;
			}
			if (number_of_rgb > 2)
			{
				printf("error: too much enouth colors\n");
				exit_code = 1;
			}
			if (map_char[1] == NULL && exit_code == 0)
			{
				printf("error: you forgot to put a map!\n");
				free(map_char);
				exit_code = 3;
			}
			/*if (cubfile->player_x < 0)
			{
				printf("error: not enouth players\n");
				exit_code = 1;
			}*/
			
			
			if (exit_code == 1)
			{
				int coo = 0;
				while(map_char[coo] != NULL)
				{
					free(map_char[coo]);
					coo++;
				}
				free(map_char);
			}
			
			if (exit_code == 3)
				exit_code = 1;
			//printf("raaaaa");
			//verification de la map apres l avoir entierement vue
			if (exit_code == 0)
			{
				int char_int_res = char_to_int_map(cubfile, map_char);
				
				if (char_int_res == 2)
				{
					int coo2 = 0;
					while(map_char[coo2] != NULL)
					{
						free(map_char[coo2]);
						coo2++;
					}
					free(map_char);
					free(cubfile->no_path);
					free(cubfile->so_path);
					free(cubfile->we_path);
					free(cubfile->ea_path);
					free(cubfile->floor_color);
					free(cubfile->ceiling_color);
					free(cubfile);
					//free_files_rgb2(cubfile, &line, fd);
					exit(0);
				}
				
				if (char_int_res == 1) //rajouter unr indication sur ce qui manque
				{
					exit_code = 1;
					int coo2 = 0;
					while(map_char[coo2] != NULL)
					{
						free(map_char[coo2]);
						coo2++;
					}
					free(map_char);
				}
				/*else if (char_int_res == 2)
				{
					printf("bingo");
					exit_code = 1;
				}*/
				
			}

			if (exit_code == 0)
			{
			
				int coo = 0;
				while(map_char[coo] != NULL)
				{
					free(map_char[coo]);
					coo++;
				}
				free(map_char);
			}
			
			printf("no more lines\n");
			return(exit_code);
		}
		
		if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		{
			number_of_path++;
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			if (test_existence(&line[3]) == 1)
			{
				printf("error: file invalid\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if (cubfile->no_path != NULL)
			{
				printf("error: there are two north path\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if ((line[ft_strlen(line) - 1] != 'm') || (line[ft_strlen(line) - 2] != 'p') || (line[ft_strlen(line) - 3] != 'x') || (line[ft_strlen(line) - 4] != '.'))
			{
				printf("error: the north file is supposed to be a .xpm\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			
			cubfile->no_path = ft_strdup(&line[3]);
			//cubfile->no_path = NULL;
			if (!cubfile->no_path)
			{
				if (cubfile->floor_color)
					free(cubfile->floor_color);
				if (cubfile->ceiling_color)
					free(cubfile->ceiling_color);
				if (cubfile->ea_path)
					free(cubfile->ea_path);
				if (cubfile->no_path)
					free(cubfile->no_path);
				if (cubfile->so_path)
					free(cubfile->so_path);
				if (cubfile->we_path)
					free(cubfile->we_path);
				while (line)
				{
					free(line);
					line = get_next_line(fd, cubfile);
				}
				free(line);
				
				free(map_char);
				
				free(cubfile);
				return (1);
			}
			//cubfile->no_path = &line[3];
		}
		//south path if
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		{
			number_of_path++;
			//printf("it s the south path\n");
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			if (test_existence(&line[3]) == 1)
			{
				printf("error: file invalid\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if (cubfile->so_path != NULL)
			{
				printf("error: there are two south path\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			if ((line[ft_strlen(line) - 1] != 'm') || (line[ft_strlen(line) - 2] != 'p') || (line[ft_strlen(line) - 3] != 'x') || (line[ft_strlen(line) - 4] != '.'))
			{
				printf("error: the south file is supposed to be a .xpm\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			cubfile->so_path = ft_strdup(&line[3]);
			//cubfile->so_path = NULL;
			if (!cubfile->so_path)
			{
			
				if (cubfile->floor_color)
					free(cubfile->floor_color);
				if (cubfile->ceiling_color)
					free(cubfile->ceiling_color);
				if (cubfile->ea_path)
					free(cubfile->ea_path);
				if (cubfile->no_path)
					free(cubfile->no_path);
				if (cubfile->so_path)
					free(cubfile->so_path);
				if (cubfile->we_path)
					free(cubfile->we_path);
				while (line)
				{
					free(line);
					line = get_next_line(fd, cubfile);
				}
				free(line);
				
				free(map_char);
				
				free(cubfile);
				return (1);
			}
			//cubfile->so_path = NULL;
		}
		// west path if
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		{
			number_of_path++;
			//printf("it s the west path\n");
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			if (test_existence(&line[3]) == 1)
			{
				printf("error: file invalid\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if (cubfile->we_path != NULL)
			{
				printf("there are two west path\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			if ((line[ft_strlen(line) - 1] != 'm') || (line[ft_strlen(line) - 2] != 'p') || (line[ft_strlen(line) - 3] != 'x') || (line[ft_strlen(line) - 4] != '.'))
			{
				printf("error: the west file is supposed to be a .xpm\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			cubfile->we_path = ft_strdup(&line[3]);
			//cubfile->we_path = NULL;
			if (!cubfile->we_path)
			{
				if (cubfile->floor_color)
					free(cubfile->floor_color);
				if (cubfile->ceiling_color)
					free(cubfile->ceiling_color);
				if (cubfile->ea_path)
					free(cubfile->ea_path);
				if (cubfile->no_path)
					free(cubfile->no_path);
				if (cubfile->so_path)
					free(cubfile->so_path);
				if (cubfile->we_path)
					free(cubfile->we_path);
				while (line)
				{
					free(line);
					line = get_next_line(fd, cubfile);
				}
				free(line);
				
				free(map_char);
				
				free(cubfile);
				return (1);
			}
		}
		//east path if
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		{
			number_of_path++;
			//printf("it s the east path\n");
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			if (test_existence(&line[3]) == 1)
			{
				printf("error: file invalid\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if (cubfile->ea_path != NULL)
			{
				printf("error: there are two east path\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			if ((line[ft_strlen(line) - 1] != 'm') || (line[ft_strlen(line) - 2] != 'p') || (line[ft_strlen(line) - 3] != 'x') || (line[ft_strlen(line) - 4] != '.'))
			{
				printf("error: the east file is supposed to be a .xpm\n");
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			
			cubfile->ea_path = ft_strdup(&line[3]);
			//cubfile->ea_path = NULL;
			if (!cubfile->ea_path)
			{
				if (cubfile->floor_color)
					free(cubfile->floor_color);
				if (cubfile->ceiling_color)
					free(cubfile->ceiling_color);
				if (cubfile->ea_path)
					free(cubfile->ea_path);
				if (cubfile->no_path)
					free(cubfile->no_path);
				if (cubfile->so_path)
					free(cubfile->so_path);
				if (cubfile->we_path)
					free(cubfile->we_path);
				while (line)
				{
					free(line);
					line = get_next_line(fd, cubfile);
				}
				free(line);
				
				free(map_char);
				
				free(cubfile);
				return (1);
			}
		}
		//floor rgb if
		else if (line[0] == 'F' && line[1] == ' ')
		{
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			if (test_rgb(&line[2]) == 1)
			{
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if (put_rgb_floor(cubfile, &line[2]) == 1)
			{
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			number_of_rgb++;
			
		}
		//ceiling rgb if
		else if (line[0] == 'C' && line[1] == ' ')
		{
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			if (test_rgb(&line[2]) == 1)
			{
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			if (put_rgb_ceiling(cubfile, &line[2]) == 1)
			{
				free_files_rgb(&map_char, cubfile, &line, fd);
				return (1);
			}
			number_of_rgb++;
		}

		else if (((number_of_path == 4) && (number_of_rgb == 2)) || ((line[0] != '\n') && !map_char[0]))
		{
		
			if (does_line_have(line) == 0)
			{
				if (start_map == -1)
					start_map = co;
				if (line[strlen(line)] == '\n')
					line[strlen(line)] = '\0';
				if ((co - start_map) == 0)
				{
					map_char[0] = ft_strdup(line);
					//map_char[0] = NULL;
					if (map_char[0] == NULL)
					{
						if (cubfile->floor_color)
							free(cubfile->floor_color);
						if (cubfile->ceiling_color)
							free(cubfile->ceiling_color);
						if (cubfile->ea_path)
							free(cubfile->ea_path);
						if (cubfile->no_path)
							free(cubfile->no_path);
						if (cubfile->so_path)
							free(cubfile->so_path);
						if (cubfile->we_path)
							free(cubfile->we_path);
						while (line)
						{
							free(line);
							line = get_next_line(fd, cubfile);
						}
						free(line);
						
						free(map_char);
						
						free(cubfile);
					
					
					
						exit (0);
					}
				}
				else
				{
				
				
					/*int cop = 0;
					while (map_char[cop])
					{
					
						printf("{%s}\n",map_char[cop]);
						cop++;
					}*/
				
				
					if (updates_char(&map_char, line))
					{
						//updates_env(&map_char, "\n");
						free_cub_file(cubfile);
						
						
						int co = 0;
						while (map_char[co])
						{
							free(map_char[co]);
							co++;
						}
						free(map_char);
						
						while (line)
						{
							free(line);
							line = get_next_line(fd, cubfile);
						}
						free(line);

						exit(0);
					}
				}
			}
			else if (number_of_path == 4 && number_of_rgb == 2)
			{
				printf("error: map: invalid caracter, the only allowed caracters are '1', '0', ' ', 'N', 'S', 'E', 'W'\n");

				
				while (line)
				{
					free(line);
					line = get_next_line(fd, cubfile);
				}
				free(line);
				
				
				int co = 0;
				while (map_char[co] != NULL)
				{
					free(map_char[co]);
					co++;
				}
				free(map_char);
				return (1);
			}
		}
		free(line);
		co++;
	}
	return (0);
}

///////////////////////////////////////////////


int	ft_strcmp(const char *s1, const char *s2)
{
	int	n;

	n = ft_strlen(s1);
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int file_exists(const char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
		return (0);
	close(fd);
	return (1);
}

int is_valid_cub_file(const char *filename)
{
    size_t len;

    len = ft_strlen(filename);
    if (len < 4 || !filename)
        return (0);
    return (ft_strcmp(&filename[len - 4], ".cub") == 0);
}

int error_usage(int argc, char **argv)
{
	if(argc != 2)
		return (1);
	if(!file_exists(argv[1]))
	{
		printf("Error: The file does not exist \n");
		return (1);
	}
	if(!is_valid_cub_file(argv[1]))
	{
		printf("Error: the file must have a '.cub' extension \n");
		return (1);
	}
	return (0);
}

// --------------- Pont de la structure de victor vers la structure principal -----------------////

void transfer_cubfile_to_data(t_data *data, t_cubfile *cubfile)
{
    data->texinfo.north = ft_strdup(cubfile->no_path);
    data->texinfo.south = ft_strdup(cubfile->so_path);
    data->texinfo.west = ft_strdup(cubfile->we_path);
    data->texinfo.east = ft_strdup(cubfile->ea_path);

    printf("Textures:\n");
    printf("North: %s\nSouth: %s\nWest: %s\nEast: %s\n",
           data->texinfo.north, data->texinfo.south,
           data->texinfo.west, data->texinfo.east);

    data->texinfo.floor = cubfile->floor_color;
    data->texinfo.ceiling = cubfile->ceiling_color;

    printf("Floor color: %d, %d, %d\n",
           data->texinfo.floor[0], data->texinfo.floor[1], data->texinfo.floor[2]);
    printf("Ceiling color: %d, %d, %d\n",
           data->texinfo.ceiling[0], data->texinfo.ceiling[1], data->texinfo.ceiling[2]);

	data->texinfo.hexfloor = ((cubfile->floor_color[0] & 0xFF) << 16) |
                              ((cubfile->floor_color[1] & 0xFF) << 8) |
                              (cubfile->floor_color[2] & 0xFF);

    data->texinfo.hexceiling = ((cubfile->ceiling_color[0] & 0xFF) << 16) |
                                ((cubfile->ceiling_color[1] & 0xFF) << 8) |
                                (cubfile->ceiling_color[2] & 0xFF);

    data->mapinfo.width = cubfile->row_length;
    data->mapinfo.height = cubfile->column_length;

    printf("Map dimensions: Width = %d, Height = %d\n",
           data->mapinfo.width, data->mapinfo.height);

    data->map = (char **)malloc(sizeof(char *) * (data->mapinfo.height + 1));
    if (!data->map)
        clean_exit(data, 1);

    for (int i = 0; i < data->mapinfo.height; i++)
    {
        data->map[i] = (char *)malloc(sizeof(char) * (data->mapinfo.width + 1));
        if (!data->map[i])
            clean_exit(data, 1);

        for (int j = 0; j < data->mapinfo.width; j++)
        {
            if (cubfile->map[i][j] == 0)
                data->map[i][j] = '0';
            else if (cubfile->map[i][j] == 1)
                data->map[i][j] = '1';
            else
                data->map[i][j] = ' ';
        }
        data->map[i][data->mapinfo.width] = '\0';
    }
    data->map[data->mapinfo.height] = NULL;

    printf("Map:\n");
    for (int i = 0; i < data->mapinfo.height; i++)
        printf("%s\n", data->map[i]);

    data->player.pos_x = cubfile->player_x + 0.5;
    data->player.pos_y = cubfile->player_y + 0.5;

    if (cubfile->player_orientation == 'N')
        data->player.dir = 'N';
    else if (cubfile->player_orientation == 'S')
        data->player.dir = 'S';
    else if (cubfile->player_orientation == 'E')
        data->player.dir = 'E';
    else if (cubfile->player_orientation == 'W')
        data->player.dir = 'W';

    printf("Player position: x = %f, y = %f, direction = %c\n",
           data->player.pos_x, data->player.pos_y, data->player.dir);
}


int parse_args(t_data *data, char **av)
{
    t_cubfile *cubfile;

    cubfile = init_cubfile();
    if (!cubfile)
        return (1);
    if (verif(av[1], cubfile) != 0)
    {
        free_cub_file(cubfile);
        return (1);
    }
    transfer_cubfile_to_data(data, cubfile);
    free_cub_file(cubfile);
    return (0);
}


int	main(int argc, char **argv)
{
	t_data	data;

	if(error_usage(argc, argv) == 1)
	{
		printf("rappel usage: \n ./cub3D <example.cub> \n");
		return (1);
	}
	init_data(&data);
	if (parse_args(&data, argv) != 0)
		return (1);
	init_player_direction(&data);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	ft_event(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
