/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:19:07 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/01 17:51:47 by tlegendr         ###   ########.fr       */
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
