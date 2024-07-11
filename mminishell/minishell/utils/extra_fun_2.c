/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:14:40 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/08 17:18:09 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_next_word(char *line, int *i, t_parsing **par, int hd_case)
{
	char	*word;
	char	*tmp;
	char	*tmp2;

	word = ft_strdup("");
	while (line[*i] && is_blank(line[*i]))
		(*i)++;
	while (line[*i] && handle_special_case(*par, hd_case) != 0)
	{
		(*par)->old_i = *i;
		if (line[(*par)->i] == '\'' || line[(*par)->i] == '\"')
		{
			ft_extract_next_word_deux(par, line, &i);
			tmp = ft_substr(line, (*par)->old_i, (*par)->i - (*par)->old_i);
			tmp2 = ft_strjoin(word, tmp);
			free(word);
			word = tmp2;
			free(tmp);
			(*par)->i++;
		}
		ft_extract_next_word_quatre(par, line, &i, hd_case);
		tmp = ft_substr(line, (*par)->old_i, (*par)->i - (*par)->old_i);
		word = ft_extract_next_word_trois(&word, &tmp, &tmp2);
	}
	return (word);
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

t_lexing	*merge_escapenull(t_lexing *tmp2, t_lexing *cmd,
		t_lexing **updated_cmd)
{
	char	*new_cmd;
	char	*tmp_cmd;

	ft_cmdcmd(&new_cmd, &tmp_cmd, &cmd);
	if (cmd->next->cmd == NULL)
		cmd->next->cmd = ft_strdup("");
	new_cmd = ft_strjoin(cmd->cmd, cmd->next->cmd);
	cmd = cmd->next;
	while (cmd->index + cmd->full_len == cmd->next->index)
	{
		tmp_cmd = new_cmd;
		if (cmd->next->cmd == NULL)
			cmd->next->cmd = ft_strdup("");
		if (cmd->cmd == NULL)
			cmd->cmd = ft_strdup("");
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

int	redir_replace(t_lexing *cmd, t_pointer **pointera)
{
	(void)pointera;
	while (cmd->prev)
		cmd = cmd->prev;
	if (cmd->cmd == NULL)
		return (1);
	while (cmd->next != NULL)
	{
		if (cmd->special_token == 3 || cmd->special_token == 4
			|| cmd->special_token == 1)
		{
			free(cmd->cmd);
			if (cmd->next->cmd == NULL)
			{
				cmd->cmd = ft_strdup("");
				return (1);
			}
			cmd->cmd = ft_strdup(cmd->next->cmd);
			free(cmd->next->cmd);
			cmd->next = cmd->next->next;
			free(cmd->next->prev);
			cmd->next->prev = cmd;
		}
		cmd = cmd->next;
	}
	return (0);
}
