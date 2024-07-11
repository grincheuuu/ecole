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

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_transform_env_list(t_pointer *pointera)
{
	t_list	*temp;
	char	**env_tab;
	int		i;

	i = 0;
	env_tab = NULL;
	temp = pointera->first;
//	ft_printlist(pointera);
//	printf("\n\n\n\n");
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	env_tab = malloc((i + 1) * sizeof(char*));
	if (env_tab == NULL)
		return (NULL);
	temp = pointera->first;
	i = 0;
	while (temp != NULL)
	{
		env_tab[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	env_tab[i] = NULL;
//	ft_lstclear(&env_list);
//	free(pointera);
//    ft_print_tab(env_tab);
	return (env_tab);
}

void	ft_print_env(t_pointer *pointerA)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (pointerA == NULL)
	{
		return ;
	}
	temp = pointerA->first;
	while (temp != NULL)
	{
		write (1, temp->str, ft_strlen(temp->str));
		write (1, "\n", 1);
		temp = temp->next;
		i++;
	}
}

void	ft_printlist(t_pointer *pointerA)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
//	printf("\n");
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
/*	temp = pointerA->end;
	while (i > 0)
	{
		printf("%d", temp->str);
		temp = temp->before;
		i--;
	}*/
}
