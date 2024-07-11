/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:19:07 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/06 16:21:13 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_table(t_lexing *cmd)
{
	t_lexing	*tmp;

	while (cmd && cmd->prev != NULL)
		cmd = cmd->prev;
	while (cmd != NULL)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->cmd != NULL)
		{
			free(tmp->cmd);
			tmp->cmd = NULL;
		}
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
	}
}

void	clear_garbage(t_garbage **garbage)
{
	if ((*garbage)->prompt)
		free((*garbage)->prompt);
	if ((*garbage)->line)
		free((*garbage)->line);
	free(*garbage);
}

int	handling_sigint_handler(t_pointer **pointera, t_lexing *cmd)
{
	if (cmd != NULL)
		clean_table(cmd);
	if ((*pointera)->garbage != NULL)
		clear_garbage(&(*pointera)->garbage);
	return (130);
}

int	check_if_heredoc_valid(t_lexing *tmp)
{
	t_lexing	*tmp2;

	tmp2 = tmp;
	while (tmp2->prev)
		tmp2 = tmp2->prev;
	while (tmp2->cmd)
	{
		if (tmp2->special_token == 2)
			if (tmp2->cmd == NULL)
				return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}
