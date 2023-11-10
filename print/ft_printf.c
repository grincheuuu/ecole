/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:57:09 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/10 15:36:58 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static int	ft_print_arg(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == '%')
		return (count += ft_print_char('%'));
	else if (type == 'c')
		return (count += ft_print_char(va_arg(args, int)));
	else if (type == 's')
		return (count += ft_print_str(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (count += ft_print_int(va_arg(args, int)));
	else if (type == 'x')
		return (count += ft_print_hex(va_arg(args, unsigned int), 0));
	else if (type == 'X')
		return (count += ft_print_hex(va_arg(args, unsigned int), 1));
	else if (type == 'u')
		return (count += ft_print_unsigned(va_arg(args, unsigned int)));
	else if (type == 'p')
		return (count += ft_print_ptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		countprint;

	countprint = 0;
	va_start(args, format);
	i = 0;
	if (*format == '\0' || format == NULL)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			countprint += ft_print_arg(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			countprint += 1;
			i++;
		}
	}
	return (countprint);
}
/*
int	main(void)
{
	char	c;
	int	d;
	char	s[] = "hello world";

	c = 'A';
	d = 42;
	ft_printf("charctere %c, int %d, string %s", c, d, s);
	return(0);
}*/
