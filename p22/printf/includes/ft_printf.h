/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:40:12 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/13 16:34:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_print_char(char c, int fd);
int	ft_printf(const char *format, ...);
int	ft_print_hex(unsigned int n, int a);
int	ft_print_int(int n);
int	ft_print_ptr(unsigned char *p);
int	ft_print_str(char *s);
int	ft_print_unsigned(unsigned int a);

#endif
