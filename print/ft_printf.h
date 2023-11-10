/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:40:12 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/10 14:46:25 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_printf(const char *format, ...);
int	ft_print_hex(int n, int a);
int	ft_print_int(int n);
int	ft_print_ptr(void *p);
int	ft_print_str(char *s);
int	ft_print_unsigned(unsigned int a);

#endif
