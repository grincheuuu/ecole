/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:12:51 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/08 17:16:32 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_extract_next_word_deux(t_parsing **par, char *line, int **i)
{
	char	to_catch;

	to_catch = line[(*par)->i];
	(*par)->i++;
	(*par)->old_i = **i;
	while (line[(*par)->i] && line[(*par)->i] != to_catch)
		(*par)->i++;
}

char	*ft_extract_next_word_trois(char **word, char **tmp, char **tmp2)
{
	*tmp2 = ft_strjoin(*word, *tmp);
	free(*word);
	free(*tmp);
	*word = *tmp2;
	return (*word);
}

void	ft_extract_next_word_quatre(t_parsing **par, char *line, int **i,
		int hd_case)
{
	(*par)->old_i = **i;
	while (line[(*par)->i] && !is_blank(line[(*par)->i])
		&& handle_special_case(*par, hd_case) == 1)
		(*par)->i++;
}

void	ft_cmdcmd(char **new_cmd, char **tmp_cmd, t_lexing **cmd)
{
	*new_cmd = NULL;
	*tmp_cmd = NULL;
	if ((*cmd)->cmd == NULL)
		(*cmd)->cmd = ft_strdup("");
}

void	ft_tmp2(t_lexing **tmp2)
{
	while (*tmp2 != NULL)
	{
		if ((*tmp2)->next->cmd == NULL)
		{
			free((*tmp2)->next);
			(*tmp2)->next = NULL;
		}
		(*tmp2) = (*tmp2)->next;
	}
}
