/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:01:36 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 03:17:09 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	*free_strjoin2(char **s1, t_cubfile *cubfile)
{
	free(*s1);
	cubfile->failed = 1;
	printf("Error\n");
	printf("error :malloc failed\n");
	return (NULL);
}

void	*free_strjoin1(t_cubfile *cubfile)
{
	cubfile->failed = 1;
	printf("Error\n");
	printf("error :malloc failed\n");
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2, t_cubfile *cubfile)
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
