/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:30:43 by tguerran          #+#    #+#             */
/*   Updated: 2023/11/14 12:16:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compteur(int x)
{
	size_t	i;

	i = 1;
	while (((x / 10) < 0) || ((x / 10) >= 1))
	{
		x = x / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long int	num;

	num = n;
	i = ft_compteur(n);
	if (n < 0)
	{
		num *= -1;
		i++;
	}
	str = (char *)malloc(sizeof(char ) * (i + 1));
	if (str == NULL)
		return (NULL);
	*(str + i) = 0;
	while (i--)
	{
		*(str + i) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}

// int main()
// {
// 	int i;

// 	i = -125;
// 	printf("%s \n", ft_itoa(i));
// }
