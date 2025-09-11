/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:34:39 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 13:49:00 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[j] != '\0')
		j++;
	j--;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}

static int	size(long int nbr)
{
	int	j;

	j = 0;
	if (nbr == 0)
		j++;
	while (nbr > 0)
	{
		nbr /= 10;
		j++;
	}
	return (j);
}

static char	*convert(char *str, long int nbr, int signe)
{
	int	i;

	i = 0;
	if (nbr == 0)
		str[i++] = 48;
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
		i++;
	}
	if (signe > 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa(int c)
{
	char		*str;
	int			signe;
	long int	nbr;

	nbr = c;
	signe = 0;
	if (nbr < 0)
	{
		signe++;
		nbr *= -1;
	}
	str = malloc(sizeof(char) * (size(nbr) + 1 + signe));
	if (str == NULL)
		return (0);
	return (convert(str, nbr, signe));
}
