/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:39:42 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/06 20:13:15 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_heredoc_input(int fd, char *delimiter)
{
	char	*line;

	while (1)
	{
		change_signal(2);
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (g_signal == SIGINT)
		{
			g_signal = 0;
			free(line);
			return (-1);
		}
		if (line == NULL)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	return (0);
}

void	handle_dollar(char *line, t_parsing **par, t_lexing **tmp,
		t_pointer **pointera)
{
	if (line[(*par)->i + 1] == '?')
		handle_get_status(tmp, pointera, &(*par)->i, &(*par)->token);
	else if (is_authorized_for_env_char(line[(*par)->i + 1]))
		handle_get_envvar(tmp, line, par, pointera);
	else
	{
		*tmp = add_to_list(*tmp, "$", bstructtok(1, 1, &(*par)->token),
				bstruct((*par)->i, 1, 0));
		(*par)->i++;
	}
}

int	process_line_chars(char *line, t_parsing **par, t_lexing **tmp,
		t_pointer **pointera)
{
	int	status;

	status = 0;
	while (line[(*par)->i] && status != -1)
	{
		if (is_blank(line[(*par)->i]))
			(*par)->i++;
		else if (line[(*par)->i] == '\'' || line[(*par)->i] == '\"')
			handle_quote_add(tmp, par, pointera, 0);
		else if (line[(*par)->i] == '|')
			*tmp = add_to_list(*tmp, "|", bstructtok(2, 1, &(*par)->token),
					bstruct((*par)->i++, 1, 5));
		else if (line[(*par)->i] == '>')
			handle_redir_upper(tmp, line, par);
		else if (line[(*par)->i] == '<')
			status = handle_redir_lower(tmp, line, par);
		else if (line[(*par)->i] == '$')
			handle_dollar(line, par, tmp, pointera);
		else if (line[(*par)->i])
			handle_standard_char_add(tmp, par);
		else
			(*par)->i++;
	}
	return (status);
}

int	handle_input(t_pointer **pointera, t_garbage **garbage)
{
	int	status;

	*garbage = malloc(sizeof(t_garbage));
	(*garbage)->prompt = ft_prompt(*pointera);
	change_signal(0);
	(*garbage)->line = readline((*garbage)->prompt);
	if (!(*garbage)->line)
	{
		ft_putstr_fd("exit\n", 2);
		rl_clear_history();
		clear_garbage(garbage);
		status = (*pointera)->status;
		ft_lstclear_bis(&(*pointera)->first);
		free(*pointera);
		exit(status);
	}
	if ((*garbage)->line != NULL || (*garbage)->line[0] != '\0')
		add_history((*garbage)->line);
	sig_exit_code(pointera);
	change_signal(1);
	return (0);
}

char	*get_prompt_home(t_pointer *pointera, char *buffer)
{
	char	*prompt;
	char	*temp;
	char	*home;

	home = ft_search_home(pointera, "HOME=");
	if (home == NULL)
		return (NULL);
	if (ft_strncmp(buffer, home, ft_strlen(buffer)) == 0)
		prompt = ft_strdup("minishell:~$ ");
	else if (ft_strncmp(buffer, "/home", ft_strlen(buffer)) == 0)
		prompt = ft_strdup("minishell:/home$ ");
	else if (ft_strncmp(buffer, "/", ft_strlen(buffer)) == 0)
		prompt = ft_strdup("minishell:/$ ");
	else
	{
		if (ft_strncmp(buffer, home, ft_strlen(home) - 1) == 0)
			temp = ft_strjoin("minishell:~", buffer + ft_strlen(home));
		else
			temp = ft_strjoin("minishell:", buffer);
		prompt = ft_strjoin(temp, "$ ");
		free(temp);
	}
	free(home);
	return (prompt);
}
