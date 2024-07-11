/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:21:22 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/08 16:45:36 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_redir_upper(t_lexing **tmp, char *line, t_parsing **par)
{
	int		type;

	if (line[(*par)->i + 1] == '>')
		type = 2;
	else
		type = 1;
	(*par)->old_i = (*par)->i;
	(*par)->i += type;
	*tmp = add_to_list(*tmp, "upper_to", bstructtok(2, 1, &(*par)->token),
			bstruct((*par)->old_i, type, 2 + type));
}

int	handle_redir_lower(t_lexing **tmp, char *line, t_parsing **par)
{
	char	*delimiter;
	char	*heredoc_file;
	char	*hereo;

	(*par)->old_i = (*par)->i;
	if (line[(*par)->i + 1] == '<')
	{
		(*par)->i += 2;
		while (line[(*par)->i] && is_blank(line[(*par)->i]))
			(*par)->i++;
		delimiter = extract_next_word(line, &(*par)->i, par, 1);
		hereo = ft_strjoin(delimiter, "\n");
		heredoc_file = process_heredoc(hereo, (*par)->i);
		free(delimiter);
		free(hereo);
		if (heredoc_file == NULL)
			return (-1);
		change_signal(0);
		*tmp = add_to_list(*tmp, heredoc_file, bstructtok(2, 1, &(*par)->token),
				bstruct((*par)->old_i, ft_strlen(heredoc_file), 2));
		free(heredoc_file);
	}
	else
		handle_redirlow_part(tmp, par);
	return (0);
}

void	handle_standard_char_add(t_lexing **tmp, t_parsing **parsing)
{
	char	*tmp_cmd;

	(*parsing)->old_i = (*parsing)->i;
	while ((*parsing)->line[(*parsing)->i]
		&& handle_special_case(*parsing, 0) == 1
		&& (*parsing)->line[(*parsing)->i] != '\n')
		(*parsing)->i++;
	if ((*parsing)->old_i != (*parsing)->i)
	{
		tmp_cmd = ft_substr_parsing(*parsing);
		*tmp = add_to_list(*tmp, tmp_cmd,
				bstructtok((*parsing)->token, 0, &(*parsing)->token),
				bstruct((*parsing)->old_i,
					(*parsing)->i - (*parsing)->old_i, 0));
		free(tmp_cmd);
	}
}

void	handle_get_status(t_lexing **tmp, t_pointer **pointera, int *i,
		int *token)
{
	char	*status_number;

	status_number = ft_itoa((*pointera)->status);
	*tmp = add_to_list(*tmp, status_number,
			bstructtok(1, 1, token), bstruct(*i, 2, 0));
	free(status_number);
	(*i) += 2;
}

void	handle_get_envvar(t_lexing **tmp, char *line, t_parsing **par,
		t_pointer **pointera)
{
	char	*tmp_cmd;
	char	*var;
	char	*value;

	(*par)->old_i = ++(*par)->i;
	while (line[(*par)->i] && !is_blank(line[(*par)->i])
		&& is_authorized_for_env_char(line[(*par)->i]))
	{
		(*par)->i++;
	}
	tmp_cmd = ft_substr(line, (*par)->old_i, (*par)->i - (*par)->old_i);
	var = ft_strjoin(tmp_cmd, "=");
	value = ft_search_env_var(*pointera, var);
	*tmp = add_to_list(*tmp, value, bstructtok(1, 1, &(*par)->token),
			bstruct((*par)->old_i - 1, ft_strlen(tmp_cmd) + 1, 0));
	free(tmp_cmd);
	free(var);
	free(value);
}
