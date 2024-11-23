/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:13:32 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/31 15:42:51 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_format(va_list *args, const char *str)
{
	int	len;

	len = 0;
	if (*(str + 1) == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (*(str + 1) == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (*(str + 1) == 'p')
		len += ft_putptr(va_arg(*args, void *));
	else if (*(str + 1) == 'u')
		len += ft_putunbr(va_arg(*args, int));
	else if (*(str + 1) == 'x')
		len += ft_puthex_l(va_arg(*args, int));
	else if (*(str + 1) == 'X')
		len += ft_puthex_u(va_arg(*args, int));
	else if (*(str + 1) == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			len = len + ft_format(&args, format);
			format += 2;
		}
		else
		{
			len = len + ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (len);
}

//int main()
//{
	// char str = '5';
	// int 	*ptr;
	// char str2[] = "salut comment ca va";
	// int x = 123454;
	// int valuehex = 42;
	// ft_printf("je dois afficher ce caractere ==== %c \n", str);
	// ft_printf("je dois afficher cette phrase === %s \n", str2);
	// ft_printf("je dois afficher ce numero === %d \n", x);
	// ft_printf("%c %s %%\n", str, str2);

	//printf("|%d| \n", printf(" %d ", INT_MIN));
	//ft_printf("|%d| \n", ft_printf(" %d %d ", INT_MIN, INT_MAX));
	//printf("|%x| \n", valuehex);
	//ft_printf("|%x| \n", valuehex);
	//printf("|%X| \n", valuehex);
	//ft_printf("|%X| \n", valuehex);
	// printf("|%u| \n",x );
	// ft_printf("|%u| \n", x);
	// printf("|%i| \n",valuehex );
	// ft_printf("|%i| \n", valuehex);
	// printf("|%p| \n", &ptr);
	// ft_printf("|%p| \n ", &ptr);

	//return (0);
//}
