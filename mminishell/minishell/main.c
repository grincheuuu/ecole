/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:08:34 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/08 15:31:41 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(t_pointer *pointera)
{
	char	*buffer;
	char	*prompt;
	size_t	size;

	size = 1024;
	prompt = NULL;
	buffer = malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (getcwd(buffer, size) == NULL)
	{
		write(2, "Cannot get current working directory path\n", 43);
		free(buffer);
		return (NULL);
	}
	prompt = get_prompt_home(pointera, buffer);
	free(buffer);
	return (prompt);
}

int	prompt(t_pointer **pointera)
{
	int			status;
	int			error;
	t_garbage	*garbage;

	status = handle_input(pointera, &garbage);
	if (status != 0)
		return (status);
	error = check_for_errors(garbage->line);
	if (error == 1 && garbage->line[0] == '\0')
	{
		clear_garbage(&garbage);
		(*pointera)->status = 0;
		return (0);
	}
	if (error == 1 && garbage->line[0] != '\0')
	{
		clear_garbage(&garbage);
		(*pointera)->status = 1;
		return (1);
	}
	(*pointera)->garbage = garbage;
	status = parse_line(garbage->line, pointera);
	(*pointera)->status = status;
	return (status);
}

char	*process_heredoc(char *delimiter, int index)
{
	int		fd;
	char	*indexstr;
	char	*heredoc_file;

	indexstr = ft_itoa(index);
	heredoc_file = ft_strjoin("/tmp/heredoc_", indexstr);
	free(indexstr);
	fd = open(heredoc_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		putstr_fd("Error: cannot create heredoc file\n", 2);
		return (NULL);
	}
	if (handle_heredoc_input(fd, delimiter) == -1)
	{
		free(heredoc_file);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (heredoc_file);
}

int	parse_line(char *line, t_pointer **pointera)
{
	int			status;
	t_parsing	*parsing;
	t_lexing	*cmd;
	t_lexing	*tmp;

	status = 0;
	parsing = malloc(sizeof(t_parsing));
	parsing->token = 1;
	parsing->line = line;
	cmd = init_tmp(NULL);
	tmp = cmd;
	tmp->cmd = NULL;
	parsing->i = 0;
	parsing->old_i = 0;
	status = process_line_chars(line, &parsing, &tmp, pointera);
	free(parsing);
	tmp->next = NULL;
	if (status == 0 || check_if_heredoc_valid(tmp) == 1)
		status = merge_and_run(cmd, pointera);
	else
		return (handling_sigint_handler(pointera, cmd));
	return (status);
}

int	main(int argc, char **argv, char **env)
{
	t_pointer	*pointera;
	t_list		*env_list;
	int			status;

	(void)env;
	(void)argv;
	status = 0;
	rl_outstream = stderr;
	pointera = malloc(sizeof(t_pointer));
	if (pointera == NULL)
		return (1);
	ft_init(pointera);
	env_list = ft_maillonlist(env);
	if (env_list == NULL)
		return (1);
	ft_affect(env_list, pointera);
	ft_shlvl(&pointera);
	if (argc == 1)
		while (1)
			status = prompt(&pointera);
	else
		putstr_fd("Error: too many arguments\n", 2);
	ft_lstclear_bis(&pointera->first);
	free(pointera);
	return (status);
}
