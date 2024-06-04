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

void    ft_cmd_exit(char **argv, t_pointer **pointera, t_pointer_cmd *pointerB)
{
    long    nb;
    char    **env;

    write (1, "exit\n", 5);
    env = ft_transform_env_list(pointera);
    if (argv[1] == NULL || (argv[1][0] == 0 && argv[1][0] == '\0'))
        ft_exit_success(pointera, pointerB, argv, env);
    if (argv[2] != NULL)
    {
        write (2, "bash: exit: too many arguments\n", 32);
        return ;
    }
    nb = ft_atol(argv[1]);
    ft_atol_test(argv[1], pointera, pointerB, argv);
    if (nb < 0 || nb > 2147483647)
        ft_exit_failure(pointera, pointerB, 255, argv);
    if (nb > 255)
        ft_exit_failure(pointera, pointerB, nb % 255, argv);
    if (nb > 0 && nb <= 255)
        ft_exit_failure(pointera, pointerB, nb, argv);
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

void	ft_atol_test(char *gv, t_pointer **pointera, t_pointer_cmd *pointerB, char **str)
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
        ft_exit_failure(pointera, pointerB, 2, str);
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
        ft_exit_failure(pointera, pointerB, 2, str);
    }
}

void    ft_exit_failure(t_pointer **pointera, t_pointer_cmd *pointerB, unsigned int n, char **str)
{
    ft_lstclear_bis_pointera(pointera);
    free(pointera);
    ft_lstclear_node(&pointerB->first);
	free(pointerB);
    ft_fre(str);
//    ft_fre(env_tab);
    exit(n);
}
