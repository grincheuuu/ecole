/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:28:23 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/30 14:20:25 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *ray, const char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		ray[i] = src[i];
		i++;
	}
	ray[i] = '\0';
	return (ray);
}

char	*ft_strcat(char *ray, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src == NULL)
		return (NULL);
	while (ray[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		ray[i + j] = src[j];
		j++;
	}
	ray[i + j] = '\0';
	return (ray);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ray;
	size_t	l;

	l = 0;
	ray = NULL;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	ray = malloc((l + 1) * sizeof(char));
	if (ray == NULL)
		return (NULL);
	ft_strcpy(ray, s1);
	ft_strcat(ray, s2);
	free(s1);
	return (ray);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			p = s;
			return ((char *)p);
		}
		s++;
	}
	if (*s == (char)c)
	{
		p = s;
		return ((char *)p);
	}
	return (NULL);
}