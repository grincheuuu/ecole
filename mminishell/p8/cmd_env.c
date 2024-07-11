/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:42:27 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/25 16:44:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init( t_pointer *pointerA)
{
	pointerA->first = NULL;
	pointerA->end = NULL;
}

char	**ft_transform_env_list(t_pointer **pointera)
{
	t_list	*temp;
	char	**env_tab;
	int		i;

	i = 0;
	env_tab = NULL;
	temp = (*pointera)->first;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	env_tab = malloc((i + 1) * sizeof(char*));
	if (env_tab == NULL)
		return (NULL);
	temp = (*pointera)->first;
	i = 0;
	while (temp != NULL)
	{
		env_tab[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

int	ft_print_env(t_pointer **pointerA)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (*pointerA == NULL)
	{
		return (1);
	}
	temp = (*pointerA)->first;
	while (temp != NULL)
	{
		write (1, temp->str, ft_strlen(temp->str));
		write (1, "\n", 1);
		temp = temp->next;
		i++;
	}
	return (0);
}

void	ft_printlist(t_pointer *pointerA)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (pointerA == NULL)
	{
		write (1, "NULL", 4);
		return ;
	}
	temp = pointerA->first;
	while (temp != NULL)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
		i++;
	}
}
