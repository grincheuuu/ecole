/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:35:12 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/01 14:37:02 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_pointer *pointera, char *var)
{
    t_list	*temp;
	int	i;
    int j;

	i = 0;
    j = 0;
	temp = pointera->first;
    if (ft_isalpha(var[j]) == 0 && var[j] != '_')
		ft_unset_error(var, pointera->first, pointera);
    while (var[j] != '\0')
	{
		if (ft_isalpha(var[j]) == 0 && ft_isdigit(var[j]) == 0 && var[j] != '_' && var[j] != '=')
			ft_unset_error(var, pointera->first, pointera);
		if (var[j] == '=')
			ft_unset_error(var, pointera->first, pointera);
		j++;
	}
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var)) == 0)
			ft_free_maillon(pointera, i);
		temp = temp->next;
		i++;
    }
}

void    ft_unset_error(char *var, t_list *env_list, t_pointer *pointera)
{
    write (2, "bash: unset: '", 15);
    ft_putstr_fd(var, 2);
    write (2, "': not a valid identifier\n", 27);
    ft_lstclear(&env_list);
    free(pointera);
    exit(EXIT_FAILURE);
}

void    ft_free_maillon(t_pointer *pointera, int i)
{
    t_list  *temp;
    t_list  *supr;
    int j;

    j = 0;
    supr = NULL;
    temp = pointera->first;
    while (temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
    if (temp == NULL)
        return;
    supr = temp;
    if (temp->next != NULL)
        temp->next->before = temp->before;
    else
        pointera->end =temp->before;
    if (temp->before != NULL)
        temp->before->next = temp->next;
    else
        pointera->first = temp->next;
    free(supr->str);
    free(supr);
    ft_exit_success(pointera);
}
void    ft_exit_success(t_pointer *pointera)
{
    ft_printlist(pointera);
    ft_lstclear(&pointera->first);
    free(pointera);
    exit(EXIT_SUCCESS);
}
