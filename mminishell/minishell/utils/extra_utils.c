/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:56:38 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/03 16:58:52 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_signal_handlers_for_heredoc(struct sigaction *sig_int,
		struct sigaction *sig_quit)
{
	sig_int->sa_handler = &sig_heredoc;
	sig_quit->sa_handler = &sig_heredoc;
	sig_int->sa_flags = 0;
}

int	check_syntax_errors(char *line, int *in_quote)
{
	while (*line)
	{
		if (*line == '|' && *in_quote == 0)
		{
			if (pipe_usage_error(line))
				return (1);
		}
		if ((*line == '>' || *line == '<') && *in_quote == 0)
		{
			if (redirection_error(line))
				return (1);
		}
		if ((*line == '\'' || *line == '\"'))
			*in_quote = is_in_quote(*line, in_quote);
		line++;
	}
	return (0);
}
