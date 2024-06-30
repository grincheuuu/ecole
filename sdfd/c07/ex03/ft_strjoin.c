/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:34:01 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/28 12:39:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

int	return_lenght(int size, char **strs, int size_sep)
{
	int	i;
	int	len;

	if (size == 0)
		return (0);
	len = size_sep * (size - 1);
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		++i;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *) malloc(1);
		*res = '\0';
		return (res);
	}
	len = return_lenght(size, strs, ft_strlen(sep));
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if (i < size - 1)
			res = ft_strcpy(res, sep);
		++i;
	}
	*res = '\0';
	return (res - len);
}
/*
int main(void)
{
	char	*strs [] = {"hello", "world", "this"};
	int	size = 3;
	char	*sep = " ";
	
	char	*resulat = ft_strjoin(size, strs, sep);
	printf("%s", resulat);
	free(resulat);
	return (0);
}*/
