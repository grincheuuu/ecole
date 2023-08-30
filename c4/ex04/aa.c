/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:55:11 by amassias          #+#    #+#             */
/*   Updated: 2023/08/21 20:32:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

int	contains(char c, const char *str)
{
	while (*str)
		if (*str++ == c) //la base conntient pas 2 fois le meme caractere dans toute la base
			return (1);
	return (0);
}

int	ft_is_forbiden_base(const char *base)
{
	unsigned long	len;

	len = 0;
	while (base[len]) //si la base contient des plus ou des moins
	{
		if (base[len] == '+' || base[len] == '-'
			|| contains(base[len], &base[len + 1])) //base vide ou taille 1
			return (1);
		++len;
	}
	return (len <= 1);
}

void	_ft_putnbr_base(long n, long base_len, const char *base_str)
{
	if (n >= base_len)
		_ft_putnbr_base(n / base_len, base_len, base_str); 
	ft_putchar(base_str[n % base_len]);
}

void	ft_putnbr_base(int nbr, const char *base_str)
{
	long		n;
	const char	*base_str_end;

	if (ft_is_forbiden_base(base_str)) //on verifie les parametres d exclusion
		return ;
	n = (long) nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	base_str_end = base_str;
	while (*base_str_end)
		++base_str_end;
	_ft_putnbr_base(n, base_str_end - base_str, base_str);
}
