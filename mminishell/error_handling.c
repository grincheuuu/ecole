/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:46:36 by tlegendr          #+#    #+#             */
/*   Updated: 2024/06/30 19:33:38 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	pipe_usage_error(char *line)
{
	if (*line == '|')
	{
		line++;
		while (if_whitespace(*line))
			line++;
		if (*line == '|' || !*line)
		{
			putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
			return (1);
		}
	}
	return (0);
}

int	redirection_error(char *line)
{
	if (*line == '>' || *line == '<')
	{
		if (*(line + 1) == *line)
			line++;
		line++;
		while (if_whitespace(*line))
			line++;
		if (*line == '>' || *line == '<' || *line == '|' || !*line)
		{
			putstr_fd("minishell: syntax error near unexpected token `newline'\n",
				2);
			return (1);
		}
	}
	return (0);
}

int	is_in_quote(char c, int *is_in_quote)
{
	if (c == '\'' && *is_in_quote != 2)
	{
		if (*is_in_quote == 0)
			*is_in_quote = 1;
		else
			*is_in_quote = 0;
	}
	if (c == '\"' && *is_in_quote != 1)
	{
		if (*is_in_quote == 0)
			*is_in_quote = 2;
		else
			*is_in_quote = 0;
	}
	return (*is_in_quote);
}

int	check_for_errors(char *line)
{
	int in_quote = 0;

	while (if_whitespace(*line))
		line++;
	if (!*line)
		return (1);
	if (*line == '|')
	{
		putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	while (*line)
	{
		if (*line == '|' && in_quote == 0)
		{
			if (pipe_usage_error(line))
				return (1);
		}
		if ((*line == '>' || *line == '<') && in_quote == 0)
		{
			if (redirection_error(line))
				return (1);
		}
		if ((*line == '\'' || *line == '\"' ))
			in_quote = is_in_quote(*line, &in_quote);
		line++;
	}
	if (in_quote)
	{
		putstr_fd("minishell: quote error\n", 2);
		return (1);
	}
	return (0);
}