/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:02:06 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/03 18:02:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cmd_exit(char *gv, char *next, t_pointer *pointera)
{
    unsigned int    code;
    long    nb;

    code = 0;
    write (1, "exit\n", 5);
    if (gv == NULL || (gv[0] == 0 && gv[1] == '\0'))
        ft_exit_success(pointera);
    nb = ft_atol(gv);
    if (gv != NULL && next != NULL)
    {
        write (2, "bash: exit: too many arguments\n", 32);
        return ;
    }
    ft_atol_test(gv, pointera);
    if (nb < 0 || nb > 2147483647)
        ft_exit_failure(pointera, 255);
    if (nb > 255)
        ft_exit_failure(pointera, nb % 255);
    if (nb > 0 && nb <= 255)
        ft_exit_failure(pointera, nb);
}

long	ft_atol(const char *nptr)
{
	long	resultat;
	int		signe;

	signe = 1;
	resultat = 0;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			signe = signe * -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		resultat *= 10;
		resultat += *nptr - '0';
		nptr++;
	}
	return (resultat * signe);
}

void	ft_atol_test(char *gv, t_pointer *pointera)
{
	while ((*gv > 8 && *gv < 14) || *gv == 32)
		gv++;
	if (*gv == 45 || *gv == 43)
		gv++;
	if (!(*gv > 47 && *gv < 58))
	{
        write (2, "bash: exit: ", 13);
        ft_putstr_fd(gv, 2);
        write (2, ": numeric argument required\n", 29);
        ft_exit_failure(pointera, 2);
    }
	while (*gv > 47 && *gv < 58)
		gv++;
    if (*gv == '\0')
		return ;
    else
    {
        write (2, "bash: exit: ", 13);
        ft_putstr_fd(gv, 2);
        write (2, ": numeric argument required\n", 29);
        ft_exit_failure(pointera, 2);
    }
}

void    ft_exit_failure(t_pointer *pointera, unsigned int n)
{
    ft_lstclear(&pointera->first);
    free(pointera);
    exit(n);
}
