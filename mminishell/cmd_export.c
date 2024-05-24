/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:46:42 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/29 18:02:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_only(t_pointer *pointera)
{
	t_list	*temp;
	char	*copy;

	temp = pointera->first;
	copy = NULL;
	while (temp != NULL)
	{
		copy = ft_strjoin("declare -x ", temp->str);
		free(temp->str);
		temp->str = ft_strdup(copy);
		free(copy);
		write (1, temp->str, ft_strlen(temp->str));
		write (1, "\n", 1);
		temp = temp->next;
	}
	ft_print_env(&pointera);
}

int	ft_export(char *str, t_pointer **pointera)
{
	t_list	*new;
	t_list	*env_list;

	new = NULL;
	env_list = (*pointera)->first;
	if (str == NULL)
	{
		ft_export_only(*pointera);
		return (0);
	}
	printf("\n8888%s8888\n", str);
	if (ft_test_var(str, pointera) == 0)
	{
		dprintf(2, "\n\nAAAAAAAAAAAAAAAAAAA\n\n");
		new = ft_lstnew_bis(str);
		if (new == NULL)
			return (1); //status = 1
		ft_lstadd_back_bis_pointer(pointera, new);
	}
	write (2, "\n\n\n\n", 5);
//	ft_print_env(pointera);
	return (0); // status=0
}

void	ft_lstadd_back_bis_pointer(t_pointer **pointera, t_list *new)
{
	t_list	*temp;
	t_list	*chaine;
	int	i;

	i = 0;
	chaine = (*pointera)->first;
	temp = chaine;
	if (chaine == NULL)
		chaine = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->before = temp;
		new->next = NULL;
	}
	ft_print_env(pointera);
}

int	ft_test_var(char *var, t_pointer **pointera)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = -1;
	t = 1;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
	{
		ft_export_error(var, pointera);
		return (1);
	}
	while (var[i] != '\0' && var[i] != '=')
	{
		if (ft_isalpha(var[i]) == 0 && ft_isdigit(var[i]) == 0 && var[i] != '_' && var[i] != '=')
		{
			ft_export_error(var, pointera);
			return (1);
		}
		i++;
	}
	if (var[i] == '=')
		t = 0;
	while (var[i] != '\0')
	{
		if ((var[i] >= 0 && var[i] <= 31) && var[i] == 127)
		{
			ft_export_error(var, pointera);
			return (1);
		}
		i++;
	}
	if (t == 0)
	{
		j = ft_search_var(*pointera, var);
		if (j < 0)
			return (0);
		if (j >= 0)
		{
			dprintf(2, "22222222222222");
			ft_maillon_change(pointera, j, var);
		}
	}
	return (1);
}

int	ft_search_var(t_pointer *pointera, char *var)
{
	t_list	*temp;
	int	i;
	int	j;
	int	len_var;

	i = -1;
	j = 0;
	len_var = 1;
	temp = pointera->first;
	while (var[j++] != '\0' && var[j] != '=')
		len_var += 1;
	while(temp != NULL)
	{
		i++;
		if (ft_strncmp(var, temp->str, len_var) == 0)
		{
			printf("\n55555%s  %dj  55555\n", temp->str, i);
			return (i);
		}
		temp = temp->next;
	}
	return (-1);
}

void	ft_maillon_change(t_pointer **pointera, int i, char *var)
{
	t_list	*temp;
	t_list	*new;
	int	j;

	j = 0;
	temp = (*pointera)->first;
	while (temp != NULL && j < i)
	{
		temp = temp->next;
		j++;
	}
	new = ft_lstnew_bis(var);
	if (new == NULL)
	{
//		ft_lstclear_bis(&pointera->first);
		return ;
	}
	if (temp->next != NULL)
		temp->next->before = new;
	else
		(*pointera)->end = new;
	if (temp->before != NULL)
		temp->before->next = new;
	else
		(*pointera)->first = new;
	new->next = temp->next;
	new->before = temp->before;
	free(temp->str);
	free(temp);
}

void	ft_export_error(char *var, t_pointer **pointera)
{
	int	i;

	i = 0;
	(void)pointera;
	write (2, "bash: export: '", 16);
	ft_putstr_fd(var, 2);
	write (2, "': not a valid identifier\n", 27);
//	ft_lstclear_bis(&env_list);
//	free(pointera);
//	ft_fre(*tab);
//	exit(EXIT_FAILURE);
}
