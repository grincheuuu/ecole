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

int	ft_cmd_exit(char **argv, int status)
{
	long	nb;

	if (argv[1] == NULL)
	{
		ft_only_exit(status);
		return (status);
	}
	write(1, "exit\n", 5);
	if (argv[1][0] == '\0' || (((argv[1][0] == 0 && argv[1][1] == '\0')
				&& argv[2] == NULL)))
		return (0);
	if (argv[1] == NULL || (((argv[1][0] == '-' || argv[1][0] == '+')
		&& argv[1][1] == 0) && argv[1][2] == '\0' && argv[2] == NULL))
		return (0);
	nb = ft_atol(argv[1]);
	if (ft_int(nb, argv) == 2)
		return (2);
	if (nb < 0 && nb > -257)
		return (256 + nb);
	if (nb > 255 || nb < -256)
		return (nb % 255);
	if (nb > 0 && nb <= 255)
		return (nb);
	return (0);
}

void	ft_only_exit(int status)
{
	char	**temp;
	char	*str;

	str = NULL;
	temp = malloc((3) * sizeof(char *));
	if (temp == NULL)
		return ;
	temp[0] = ft_strdup("exit");
	str = ft_itoa(status);
	temp[1] = ft_strdup(str);
	temp[2] = NULL;
	ft_cmd_exit(temp, status);
	free(str);
	ft_fre(temp);
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

void	ft_exit_failure(t_pointer **pointera, t_pointer_cmd *pointerB,
		unsigned int n, char **str)
{
	ft_lstclear_bis_pointera(pointera);
	free(pointera);
	ft_lstclear_node(&pointerB->first);
	free(pointerB);
	ft_fre(str);
	exit(n);
}

void	ft_exit_success(t_pointer **pointera, t_pointer_cmd *pointerB,
		char **str)
{
	ft_lstclear_bis_pointera(pointera);
	free(*pointera);
	ft_lstclear_node(&pointerB->first);
	free(pointerB);
	ft_fre(str);
	exit(EXIT_SUCCESS);
}
