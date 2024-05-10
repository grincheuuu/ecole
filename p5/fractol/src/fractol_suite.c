/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:31:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/19 19:37:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_analyse_argjulia(char **argv)
{
	ft_atof_test(argv[2]);
	ft_atof_test(argv[3]);
}

void	ft_atof_test(const char *nptr)
{
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
		nptr++;
	if (!(*nptr > 47 && *nptr < 58))
		ft_error_julia();
	while (*nptr > 47 && *nptr < 58)
		nptr++;
	if (*nptr == '.')
		nptr++;
	else if (*nptr == '\0')
		return ;
	else
		ft_error_julia();
	if (!(*nptr > 47 && *nptr < 58))
		ft_error_julia();
	while (*nptr > 47 && *nptr < 58)
		nptr++;
	if (*nptr != '\0')
		ft_error_julia();
}

void	ft_error_julia(void)
{
	write(2, "for Julia <x> <y> are two numbers\n", 34);
	write(2, "put only one signe '-' or '+'", 29);
	exit(EXIT_FAILURE);
}
