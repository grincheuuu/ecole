/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:33:36 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/23 15:42:21 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

void	ft_swap(char *a, char *b)
{
	char	stock;

	stock = *a;
	*a = *b;
	*b = stock;
}

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstrg(int argc, char **argv)
{
	int	j;
	int	k;
	int	lens;

	lens = argc;
	while (lens > 1)
	{
		j = 0;
		k = 1;
		while (k < lens)
		{
			if (ft_strcmp(argv[j], argv[k]) > 0)
				ft_swap(argv[j], argv[k]);
			j++;
			k++;
		}
		lens--;
	}
	k = 1;
	while (k < argc)
	{
		ft_putchar(argv[k]);
		ft_putchar("\n");
		k++;
	}
}

int	main(int argc, char **argv)
{
	ft_putstrg(argc, argv);
	return (0);
}
