/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:06:57 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/13 14:27:26 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_str(char *s)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if (s == NULL)
	{
		write (STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write (STDOUT_FILENO, &s[i], 1);
		i++;
	}
	return (i);
}
