/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:39:33 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/03 11:57:12 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_next_word(char *line, int *i, t_parsing **par)
{
	char	to_catch;

	(*par)->old_i = 0;
	if (line[*i] == '\'' || line[*i] == '\"')
	{
		to_catch = line[*i];
		(*i)++;
		(*par)->old_i = *i;
		while (line[*i] && line[*i] != to_catch)
			(*i)++;
		return (ft_substr(line, (*par)->old_i, *i - (*par)->old_i));
	}
	(*par)->old_i = *i;
	if (par == NULL)
	{
		while (line[*i] && !is_blank(line[*i]))
			(*i)++;
	}
	else
	{
		while (line[*i] && !is_blank(line[*i])
			&& handle_special_case(*par) == 1)
			(*i)++;
	}
	return (ft_substr(line, (*par)->old_i, *i - (*par)->old_i));
}

t_lexing	*merge_and_add(t_lexing *tmp2, t_lexing *cmd,
		t_lexing **updated_cmd)
{
	char	*new_cmd;
	char	*tmp_cmd;

	new_cmd = NULL;
	tmp_cmd = NULL;
	new_cmd = ft_strjoin(cmd->cmd, cmd->next->cmd);
	cmd = cmd->next;
	while (cmd->index + cmd->full_len == cmd->next->index)
	{
		tmp_cmd = new_cmd;
		new_cmd = ft_strjoin(new_cmd, cmd->next->cmd);
		free(tmp_cmd);
		cmd = cmd->next;
	}
	tmp2 = add_to_list(tmp2, new_cmd, bstructtok(0, 0, NULL), bstruct(0,
				ft_strlen(new_cmd), 0));
	free(new_cmd);
	*updated_cmd = cmd;
	return (tmp2);
}

int	merge_and_run(t_lexing *cmd, t_pointer **pointera)
{
	t_lexing		*tmp2;
	t_pointer_cmd	*control;
	int				status;

	tmp2 = merge_nearby_word(cmd);
	control = malloc(sizeof(t_pointer_cmd));
	clean_table(cmd);
	clear_garbage(&(*pointera)->garbage);
	while (tmp2->prev)
		tmp2 = tmp2->prev;
	control->first = tmp2;
	control->end = NULL;
	while (tmp2 != NULL)
	{
		if (tmp2->next->cmd == NULL)
		{
			free(tmp2->next);
			tmp2->next = NULL;
		}
		tmp2 = tmp2->next;
	}
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
	tmp->prev = NULL;
	tmp->next = NULL;
	while (cmd->prev)
		cmd = cmd->prev;
	return (tmp);
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
				tmp2 = merge_and_add(tmp2, cmd, &cmd);
			else
				tmp2 = add_to_list(tmp2, cmd->cmd, bstructtok(cmd->token, 0,
							NULL), bstruct(cmd->index, cmd->full_len,
							cmd->special_token));
		}
		else
			tmp2 = add_to_list(tmp2, cmd->cmd, bstructtok(cmd->token, 0, NULL),
					bstruct(cmd->index, cmd->full_len, cmd->special_token));
		cmd = cmd->next;
	}
	cmd->next = NULL;
	while (cmd->prev)
		cmd = cmd->prev;
	return (tmp2);
}
