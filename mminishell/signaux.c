/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:18:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/06 20:18:53 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
	}
}

void	ft_signaux_pipeline(int n)
{
	struct sigaction	sig_int_pipe;
	struct sigaction	sig_quit_pipe;

	ft_bzero(&sig_int_pipe, sizeof(&sig_int_pipe));
	ft_bzero(&sig_quit_pipe, sizeof(&sig_quit_pipe));
	sig_int_pipe.sa_flags = SA_RESTART;
	sig_quit_pipe.sa_flags = SA_RESTART;
	if (n == 0)
	{
		sig_int_pipe.sa_handler = SIG_IGN;
		sig_quit_pipe.sa_handler = SIG_IGN;
	}
	else
	{
		sig_int_pipe.sa_handler = SIG_DFL;
		sig_quit_pipe.sa_handler = SIG_DFL;
	}
	sigemptyset(&sig_int_pipe.sa_mask);
	sigemptyset(&sig_quit_pipe.sa_mask);
	if (sigaction(SIGQUIT, &sig_quit_pipe, NULL) == -1)
		perror("sigaction: SIGQUIT");
	if (sigaction(SIGINT, &sig_int_pipe, NULL) == -1)
		perror("sigaction: SIGINT");
}

int	ft_search_var(t_pointer *pointera, char *var)
{
	t_list	*temp;
	int		i;
	int		j;
	int		len_var;

	i = -1;
	j = 0;
	len_var = 1;
	temp = pointera->first;
	while (var[j++] != '\0' && var[j] != '=')
		len_var += 1;
	while (temp != NULL)
	{
		i++;
		if (ft_strncmp(var, temp->str, len_var) == 0)
			return (i);
		temp = temp->next;
	}
	return (-1);
}

void	ft_maillon_change(t_pointer **pointera, int i, char *var)
{
	t_list	*temp;
	t_list	*new;
	int		j;

	j = 0;
	temp = (*pointera)->first;
	while (temp != NULL && j < i)
	{
		temp = temp->next;
		j++;
	}
	new = ft_lstnew_bis(var);
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

void	ft_export_error(char *var)
{
	write(2, "bash: export: '", 16);
	ft_putstr_fd(var, 2);
	write(2, "': not a valid identifier\n", 27);
}
