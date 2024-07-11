/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:41:24 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/27 16:39:06 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(t_pointer **pointera, t_pointer_cmd *pointerB)
{
	int		status;

	status = 0;
	status = ft_pipex_start(pointera, pointerB, status);
	ft_lstclear_node(&pointerB->first);
	free(pointerB);
	return (status);
}

void	ft_export_plus(t_pointer **pointera)
{
	char	**op;

	op = malloc(3 * sizeof(char *));
	if (op == NULL)
		return ;
	op[0] = ft_strdup("export");
	op[1] = ft_strdup("SHLVL=1");
	op[2] = NULL;
	ft_export(op, pointera);
	ft_fre(op);
}

char	*ft_export_moin(t_pointer **pointera, int i)
{
	int		j;
	t_list	*temp;
	char	*op;
	char	*nbchar;
	char	*temp2;

	j = 0;
	op = NULL;
	nbchar = NULL;
	temp = (*pointera)->first;
	while (temp != NULL && j++ < i)
		temp = temp->next;
	op = ft_strdup(temp->str + 6);
	temp2 = op;
	if (ft_atoi_test(op) == 2)
		op = ft_strdup("1");
	else
	{
		j = 1 + ft_atoi(op);
		nbchar = ft_itoa(j);
		op = ft_strdup(nbchar);
		free(nbchar);
	}
	free(temp2);
	return (op);
}

int	ft_atoi_test(char *gv)
{
	int	i;

	i = 0;
	while ((gv[i] > 8 && gv[i] < 14) || gv[i] == 32)
		i++;
	if (gv[i] == 45 || gv[i] == 43)
		i++;
	if (!(gv[i] > 47 && gv[i] < 58))
		return (2);
	while (gv[i] > 47 && gv[i] < 58)
		i++;
	if (gv[i] == '\0')
		return (0);
	else
		return (2);
}

int	ft_atoi(const char *nptr)
{
	char	*endptr;
	int		signe;
	int		resultat;

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
	if (*nptr != '\0')
		endptr = (char *)nptr;
	return (resultat * signe);
}
