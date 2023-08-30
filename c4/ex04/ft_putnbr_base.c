/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:29:02 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/22 18:37:07 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	if(!base || base[0] == '\0'
}

void	ft_putnbr_base(int nbr, char *base)
{
	int basevalue;

	basevallue = 0;

	while(base[basevalue] != '\0')
	{
		if (base[basevalue] == '+' || base[basevalue] == '-')
			return (0);
		basevalue++;
	}
	if (basevalue < 2)
		return (0);
	if (doublechar(base))
		return (0);
	printnbr(nbr, basevalue, base);
}

int doublechar(char * symbols)
{
	int	i;
	int	j;

	i = 0;
	while (*(symbols + i))
	{
		j = i +1;
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return 1;
			jj++;
		}
		i++
	}
	return 0;
}

void printnbr(int n, int basevalue, char *symbols)
{
	long	nlong;

	nlong = n;
	if (nlong < 0) // signe moin
	{
		nlong = -nlong;
		ft_putchar('-');
	}
	if (nlong >= basevalue) // recurssivite
		printnbr(nlong / basevalue, basevalue, symbols);
		ft_putchar(symbols[nlong % basevalue]);

}

int	main(void)
{
	int	nbr;
	char	*base;

	nbr = ;
	*base = ;	
	ft_putnbr_base(nbr, base);
	return (0);
}
