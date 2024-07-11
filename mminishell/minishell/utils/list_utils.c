/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:39:33 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/08 17:18:19 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	merge_and_run(t_lexing *cmd, t_pointer **pointera)
{
	t_lexing		*tmp2;
	t_pointer_cmd	*control;
	int				status;

	tmp2 = merge_nearby_word(cmd);
	control = malloc(sizeof(t_pointer_cmd));
	clean_table(cmd);
	clear_garbage(&(*pointera)->garbage);
	redir_replace(tmp2, pointera);
	while (tmp2->prev)
		tmp2 = tmp2->prev;
	if (tmp2->cmd == NULL)
	{
		free(tmp2);
		tmp2 = NULL;
	}
	control->first = tmp2;
	control->end = NULL;
	ft_tmp2(&tmp2);
	status = ft_exec(pointera, control);
	(*pointera)->status = status;
	clean_table(tmp2);
	return (status);
}

t_lexing	*init_tmp(t_lexing *cmd)
{
	t_lexing	*tmp;

	tmp = malloc(sizeof(t_lexing));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->cmd = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (cmd == NULL)
		return (tmp);
	while (cmd->prev)
		cmd = cmd->prev;
	return (tmp);
}

t_lexing	*add_list(t_lexing *cmd, t_lexing *tmp2)
{
	tmp2 = add_to_list(tmp2, cmd->cmd, bstructtok(cmd->token, 0, NULL),
			bstruct(cmd->index, cmd->full_len, cmd->special_token));
	return (tmp2);
}

t_lexing	*add_list_if_not_null(t_lexing *cmd, t_lexing *tmp2)
{
	if (cmd->cmd != NULL)
	{
		tmp2 = add_list(cmd, tmp2);
	}
	return (tmp2);
}

t_lexing	*merge_nearby_word(t_lexing *cmd)
{
	t_lexing	*tmp2;

	tmp2 = init_tmp(cmd);
	while (cmd->next)
	{
		if (cmd->token != 2 && cmd->next->token != 2)
		{
			if (cmd->index + cmd->full_len == cmd->next->index)
			{
				if (cmd->cmd != NULL && cmd->next->cmd != NULL)
					tmp2 = merge_and_add(tmp2, cmd, &cmd);
				else if (cmd->cmd == NULL || cmd->next->cmd == NULL)
					tmp2 = merge_escapenull(tmp2, cmd, &cmd);
			}
			else
			{
				tmp2 = add_list_if_not_null(cmd, tmp2);
			}
		}
		else if (cmd->cmd != NULL)
			tmp2 = add_list(cmd, tmp2);
		cmd = cmd->next;
	}
	cmd->next = NULL;
	return (tmp2);
}
