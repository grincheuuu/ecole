/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:49:40 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/06 20:09:29 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_env_variable(char **tmp_cmd, t_parsing **par,
		t_pointer **pointera, int *len)
{
	int		start_index;
	char	*tmp_var;
	char	*var;
	char	*value;
	char	*joined_cmd;

	(*par)->i++;
	start_index = (*par)->i;
	while ((*par)->line[(*par)->i] && !is_blank((*par)->line[(*par)->i])
		&& is_authorized_for_env_char((*par)->line[(*par)->i]))
		(*par)->i++;
	tmp_var = ft_substr((*par)->line, start_index, (*par)->i - start_index);
	*len += ft_strlen(tmp_var) + 1;
	var = ft_strjoin(tmp_var, "=");
	value = ft_search_env_var(*pointera, var);
	if (value == NULL)
		value = ft_strdup("");
	joined_cmd = ft_strjoin(*tmp_cmd, value);
	free(*tmp_cmd);
	free(tmp_var);
	*tmp_cmd = joined_cmd;
	free(var);
	free(value);
}

void	handle_status_variable(char **tmp_cmd, int *i, t_pointer **pointera,
		int *len)
{
	char	*status_number;
	char	*temp_deux;

	temp_deux = NULL;
	status_number = ft_itoa((*pointera)->status);
	temp_deux = *tmp_cmd;
	*tmp_cmd = ft_strjoin(temp_deux, status_number);
	*len += ft_strlen(status_number);
	free(status_number);
	free(temp_deux);
	(*i) += 2;
}

void	handle_else_part(char **tmp_cmd, t_parsing **par, int *len)
{
	char	*tmp_var;
	char	*temp;
	char	*line;
	int		*i;

	line = (*par)->line;
	i = &(*par)->i;
	tmp_var = ft_substr(line, *i, 1);
	temp = ft_strjoin(*tmp_cmd, tmp_var);
	free(*tmp_cmd);
	free(tmp_var);
	*tmp_cmd = temp;
	(*i)++;
	(*len)++;
}

void	handle_quote_add(t_lexing **tmp, t_parsing **par,
	t_pointer **poina, int len)
{
	char	to_catch;
	char	*tmp_cmd;
	int		index;

	to_catch = (*par)->line[(*par)->i];
	index = (*par)->i;
	(*par)->old_i = ++(*par)->i;
	tmp_cmd = ft_strdup("");
	while ((*par)->line[(*par)->i] && (*par)->line[(*par)->i] != to_catch)
	{
		if ((*par)->line[(*par)->i] == '$' && to_catch == '\"'
			&& is_authorized_for_env_char((*par)->line[(*par)->i + 1]))
			handle_env_variable(&tmp_cmd, par, poina, &len);
		else if ((*par)->line[(*par)->i] == '$' && to_catch == '\"'
			&& (*par)->line[(*par)->i + 1] == '?')
			handle_status_variable(&tmp_cmd, &(*par)->i, poina, &len);
		else
			handle_else_part(&tmp_cmd, par, &len);
	}
	*tmp = add_to_list(*tmp, tmp_cmd, bstructtok((*par)->token, 0, NULL),
			bstruct(index, len + 2, 0));
	free(tmp_cmd);
	(*par)->i++;
}
