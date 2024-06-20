/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:41:24 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/07 13:56:29 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(t_pointer **pointera, t_pointer_cmd *pointerB)
{
	int		status;
	int		i;
	char	*var;
	char	*op;

	status = 0;
	i = -1;
	var = NULL;
	op = NULL;
	i = ft_search_var(*pointera, "SHLVL=");
	if (i < 0)
		ft_export_plus(pointera);
	else if (i >= 0)
	{
		op = ft_export_moin(pointera, i);
		var = ft_strjoin("SHLVL=", op);
		free(op);
		ft_maillon_change(pointera, i, var);
		free(var);
	}
	status = ft_pipex_start(pointera, pointerB, status);
	ft_lstclear_node(&pointerB->first);
	free(pointerB);
	return (status);
}
void	ft_export_plus(t_pointer **pointera)
{
	char	**op;

	op = malloc(3 * sizeof(char *));
	if (op== NULL)
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

	j = 0;
	op = NULL;
	nbchar = NULL;
	temp = (*pointera)->first;
	while (temp != NULL && j++ < i)
		temp = temp->next;
	op = ft_strdup(temp->str + 6);
	if (ft_atoi_test(op) == 2)
	{
		free(op);
		op = ft_strdup("1");
	}
	else
	{
		j = 1 + ft_atoi(op);
		free (op);
		nbchar = ft_itoa(j);
		op = ft_strdup(nbchar);
		free(nbchar);
	}
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
