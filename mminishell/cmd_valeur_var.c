/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_valeur_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:52 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/07 15:54:56 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_valeur_var(char *var, t_pointer *pointera)
{
    char    *valeur;
    t_list	*temp;

    valeur = ft_search_var_deux(pointera, var + 1);
    temp = pointera->first;
/*	while(temp != NULL)
	{
		if (ft_strncmp(var + 1, temp->str, ft_strlen(var)) == 0)
			write (1, temp->str, ft_strlen(str) - 1);
		temp = temp->next;
    }*/
    return (temp->str);
}

char	*ft_search_var_deux(t_pointer *pointera, char *var)
{
	t_list	*temp;
	int	i;
	int	j;
	int	len_var;

	i = 0;
	j = 0;
	len_var = 0;
	temp = pointera->first;
	while (var[j++] != '=' && var[j++] != '\0')
		len_var += 1;
	while(temp != NULL)
	{
        write (1, "A\n\n\n\n\n\n", 1);
		if (ft_strncmp(var, temp->str, len_var) == 0)
		{
			write (1, "B\n\n\n\n\n\n", 1);
            write (1, temp->str, ft_strlen(temp->str));
			return (temp->str);
		}
		temp = temp->next;
		i++;
	}
	return (NULL);
}
