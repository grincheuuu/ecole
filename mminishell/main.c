/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:08:34 by tlegendr          #+#    #+#             */
/*   Updated: 2024/06/30 19:36:33 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) < 0)
			break;
		i++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}



void putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		putstr_fd("-2147483648", fd);
		return;
	}
	if (n < 0)
	{
		putstr_fd("-", fd);
		n = -n;
	}
	if (n >= 10)
	{
		putnbr_fd(n / 10, fd);
		putnbr_fd(n % 10, fd);
	}
	else
	{
		n = n + '0';
		if (write(fd, &n, 1) < 0)
			return;
	}
}


char    *ft_search_home(t_pointer *pointera, char *var)
{
	t_list	*temp;
	char	*home;

	home = NULL;
	temp = pointera->first;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, 4) == 0)
		{
			home = ft_strdup(temp->str + 5);
			return (home);
		}
		temp = temp->next;
	}
	return (NULL);
}

char *ft_search_env_var(t_pointer *pointera, char *var)
{
	t_list	*temp;
	char	*home;

	home = NULL;
	temp = pointera->first;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var) - 1) == 0)
		{
			home = ft_strdup(temp->str + ft_strlen(var));
			return (home);
		}
		temp = temp->next;
	}
	return (NULL);
}

char	*ft_prompt(t_pointer *pointera)
{
	char	*buffer;
	char	*prompt;
	char	*temp;
	char	*home;
	size_t	size;

	size = 1024;
	prompt = NULL;
	temp = NULL;
	home = NULL;
	buffer = malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (getcwd(buffer, size) == NULL)
	{
		write(2, "Cannot get current working directory path\n", 43);
		free(buffer);
		return (NULL);
	}
	home = ft_search_home(pointera, "HOME=");
	if (home == NULL)
		return (NULL);
	if (ft_strncmp(buffer, home, ft_strlen(buffer)) == 0)
		prompt = ft_strdup("minishell:~$ ");	
	if (ft_strncmp(buffer, "/home", ft_strlen(buffer)) == 0)
		prompt = ft_strdup("minishell:/home$ ");
	if (ft_strncmp(buffer, "/", ft_strlen(buffer)) == 0)
		prompt = ft_strdup("minishell:/$ ");
	else
	{
		if (ft_strncmp(buffer, home, ft_strlen(home) - 1) == 0)
		{
			temp = ft_strjoin("minishell:~", buffer + ft_strlen(home));
			prompt = ft_strjoin(temp, "$ ");
		}
		else
		{
			temp = ft_strjoin("minishell:", buffer);
			prompt = ft_strjoin(temp, "$ ");
		}
		free(temp);
	}
	free(home);
	free(buffer);
	return (prompt);
}

int prompt(t_pointer **pointera)
{
	int status;

	status = 0;
	t_garbage	*garbage = malloc(sizeof(t_garbage));

	garbage->prompt = ft_prompt(*pointera);
	change_signal(0);
	garbage->line = readline(garbage->prompt);
	if (!garbage->line)
	{
		ft_putstr_fd("exit\n", 2);
		free(garbage->prompt);
		rl_clear_history();
		free(garbage);
		status = (*pointera)->status;
		ft_lstclear_bis(&(*pointera)->first);
		free(*pointera);
		exit (status);
	}
	if (garbage->line != NULL || garbage->line[0] != '\0')
		add_history(garbage->line);
	sig_exit_code(pointera);
	change_signal(1);
	int error = check_for_errors(garbage->line);
	if (!garbage->line || error == 1)
	{
		free(garbage->prompt);
		free(garbage->line);
		free(garbage);
		return (0);
	}
	if (error == 1)
	{
		free(garbage->prompt);
		free(garbage->line);
		free(garbage);
		(*pointera)->status = 1;
		return (1);
	}
	(*pointera)->garbage = garbage;
	status = parse_line(garbage->line, pointera);
	(*pointera)->status = status;
	return (status);
}

t_lexing *add_to_list(t_lexing *tmp, char *cmd, int token, int next_token, int *token_var, int index, int full_len, int special_token)
{
	//printf("add to list callled with cmd: %s token: %d next_token: %d index: %d full_len: %d special_token: %d\n", cmd, token, next_token, index, full_len, special_token);
	tmp->cmd = ft_strdup(cmd);
	tmp->token = token;
	tmp->special_token = special_token;
	tmp->full_len = full_len;
	tmp->index = index;
	
	if (token_var != NULL)
		*token_var = next_token;

	t_lexing *new_node = (t_lexing *)malloc(sizeof(t_lexing));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->cmd = NULL; 
	new_node->token = 0;
	new_node->special_token = 0;
	new_node->full_len = 0;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = tmp;
	tmp->next = new_node;
	return new_node;
}

void clean_table(t_lexing *cmd)
{
	t_lexing *tmp;

	while (cmd && cmd->prev != NULL)
		cmd = cmd->prev;
	while (cmd != NULL) {
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->cmd != NULL) {
			free(tmp->cmd);
			tmp->cmd = NULL; 
		}
		tmp->next = NULL; 
		tmp->prev = NULL;
		free(tmp);
	}
}


void print_list(t_lexing *cmd)
{
	while (cmd->prev)
		cmd = cmd->prev;
	/*    putstr_fd("List\n", 1);
	while (cmd) {
		putstr_fd("cmd: ", 1);
		putstr_fd(cmd->cmd, 1);
		putstr_fd("\n", 1);
		putstr_fd("Token: ", 1);
		putnbr_fd(cmd->token, 1);
		putstr_fd("\n", 1);
		putstr_fd("Special Token: ", 1);
		putnbr_fd(cmd->special_token, 1);
		putstr_fd("\n", 1);
		cmd = cmd->next;
	}*/
}


t_lexing *merge_and_add(t_lexing *tmp2, t_lexing *cmd, t_lexing **updated_cmd)
{
    char *new_cmd = NULL;
    char *tmp_cmd = NULL;

    new_cmd = ft_strjoin(cmd->cmd, cmd->next->cmd);
    cmd = cmd->next;
    while (cmd->index + cmd->full_len == cmd->next->index) {
        tmp_cmd = new_cmd;
        new_cmd = ft_strjoin(new_cmd, cmd->next->cmd);
        free(tmp_cmd);
        cmd = cmd->next;
    }
    tmp2 = add_to_list(tmp2, new_cmd, 0, 0, NULL, 0, ft_strlen(new_cmd), 0);
    free(new_cmd);
    *updated_cmd = cmd;
    return tmp2;
}


t_lexing *merge_nearby_word(t_lexing *cmd)
{
	//printf("merge nearby word called\n");
    t_lexing *tmp2;

    tmp2 = malloc(sizeof(t_lexing));
    if (tmp2 == NULL)
        exit(EXIT_FAILURE);
    tmp2->prev = NULL;
    tmp2->next = NULL;
    while (cmd->prev)
        cmd = cmd->prev;
    while (cmd->next) {
        if (cmd->token != 2 && cmd->next->token != 2) {
            if (cmd->index + cmd->full_len == cmd->next->index)
                tmp2 = merge_and_add(tmp2, cmd, &cmd);
            else
                tmp2 = add_to_list(tmp2, cmd->cmd, cmd->token, 0, NULL, cmd->index, cmd->full_len, cmd->special_token);
        } else {
            tmp2 = add_to_list(tmp2, cmd->cmd, cmd->token, 0, NULL, cmd->index, cmd->full_len, cmd->special_token);
        }
        cmd = cmd->next;
    }
    cmd->next = NULL;
    while (cmd->prev)
        cmd = cmd->prev;
    return tmp2;
}

char *process_heredoc(char *delimiter)
{
	int fd;
	char *line;

	fd = open("/tmp/heredoc_ft", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		putstr_fd("Error: cannot create heredoc file\n", 2);
		return NULL;
	}
	while (1)
	{
		change_signal(2);
		line = readline("heredoc> ");
		if (line == NULL)
			break;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break;
		}
		if (g_signal == SIGINT)
			break;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	change_signal(0);
	return "/tmp/heredoc_ft";
}

int is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return 1;
	return 0;
}

int ft_isalnum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int is_authorized_for_env_char(char c)
{
	if (c == '_' || ft_isalnum(c))
		return 1;
	return 0;
}



void handle_quote_add(t_lexing **tmp, char *line, int *i, int *old_i, int *token, t_pointer **pointera)
{
	//printf("handle_quote_add called with line: %s i: %d old_i: %d token: %d\n", line, *i, *old_i, *token);
	char to_catch = line[*i];
	char *tmp_cmd;
	int index = *i;
	int start_index = 0;
	int len = 0;
	(*i)++;
	*old_i = *i;
	tmp_cmd = ft_strdup("");
	while (line[*i] && line[*i] != to_catch)
	{
		if (line[*i] == '$' && to_catch == '\"' && is_authorized_for_env_char(line[*i + 1]))
		{
			(*i)++;
			start_index = *i;
			while (line[*i] && !is_blank(line[*i]) && is_authorized_for_env_char(line[*i]))
				(*i)++;
			char *tmp_var = ft_substr(line, start_index, *i - start_index);
			len += ft_strlen(tmp_var) + 1;
			char *var = ft_strjoin(tmp_var, "=");
			char *value = ft_search_env_var(*pointera, var);
			if (value == NULL)
				value = ft_strdup("");
			char *joined_cmd = ft_strjoin(tmp_cmd, value);
			free(tmp_cmd);
			free(tmp_var);
			tmp_cmd = joined_cmd;
			//printf("tmp_cmd: %s\n", tmp_cmd);
			free(var);
			free(value);
		}
		else if (line[*i] == '$' && to_catch == '\"' && line[*i + 1] == '?')
		{
			char *statusNumber = ft_itoa((*pointera)->status);
			tmp_cmd = ft_strjoin(tmp_cmd, statusNumber);
			len += ft_strlen(statusNumber);
			free(statusNumber);
			(*i)+=2;
		}
		else
		{
			char *tmp2 = ft_substr(line, *i, 1);
			char *temp = ft_strjoin(tmp_cmd, tmp2);
			free(tmp_cmd);
			free(tmp2);
			tmp_cmd = temp;
			//printf("tmp_cmd: %s and to_catch: %c\n", tmp_cmd, to_catch);
			(*i)++;
			len++;
		}
	}
	*tmp = add_to_list(*tmp, tmp_cmd, *token, 0, token, index, len+2, 0);
	free(tmp_cmd);
}



char *extract_next_word(char *line, int *i)
{
	int old_i = 0;
	char to_catch;
	
	if (line[*i] == '\'' || line[*i] == '\"')
	{
		to_catch = line[*i];
		(*i)++;
		old_i = *i;
		while (line[*i] && line[*i] != to_catch)
			(*i)++;
		return ft_substr(line, old_i, *i - old_i);
	}
	old_i = *i;
	while (line[*i] && !is_blank(line[*i]))
		(*i)++;
	return ft_substr(line, old_i, *i - old_i);
}

int parse_line(char *line, t_pointer **pointera)
{
	int i = 0;
	int old_i = 0;
	int token = 1;
	t_lexing *cmd = NULL;
	t_lexing *tmp = NULL;

	cmd = (t_lexing *)malloc(sizeof(t_lexing));
	if (cmd == NULL)
		exit(EXIT_FAILURE);
	cmd->prev = NULL;
	cmd->next = NULL;
	tmp = cmd;
	while (line[i])
	{
		if (line[i])
		{
			old_i = i;
			while (line[i] && line[i] != '\t' && line[i] != ' ' && line[i] != '\'' && line[i] != '\"' && line[i] != '|' && line[i] != '>' && line[i] != '<' && line[i] != '$')
				i++;
			if (old_i != i)
			{
				char *tmp_cmd = ft_substr(line, old_i, i - old_i);
				tmp = add_to_list(tmp, tmp_cmd, token, 0, &token, old_i, i-old_i, 0);
				free(tmp_cmd);
			}
		}
		if (line[i] == '\'' || line[i] == '\"')
			handle_quote_add(&tmp, line, &i, &old_i, &token, pointera);
		if (line[i] == '|')
			tmp = add_to_list(tmp, "|", 2, 1, &token, 0, 1, 5);
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				old_i = i;
				i += 2;
				while (line[i] && is_blank(line[i]))
					i++;
				char *filen = extract_next_word(line, &i);
				tmp = add_to_list(tmp, filen, 2, 1, &token, old_i, ft_strlen(filen), 4);
				free(filen);
				i++;
			}
			else
			{
				old_i = i;
				i++;
				while (line[i] && is_blank(line[i]))
					i++;
				char *filen = extract_next_word(line, &i);
				tmp = add_to_list(tmp, filen, 2, 1, &token, old_i, ft_strlen(filen), 3 );
				free(filen);
			}
		}
		if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				char *delimiter;

				old_i = i;	
				i += 2;
				while (line[i] && is_blank(line[i]))
					i++;
				delimiter = extract_next_word(line, &i);
				char *heredoc_file = process_heredoc(delimiter);
				free(delimiter);
				tmp = add_to_list(tmp, heredoc_file, 2, 1, &token, old_i, ft_strlen(heredoc_file), 2);
			}
			else 
			{
				i++;
				while (line[i] && is_blank(line[i]))
					i++;
				char *filen = extract_next_word(line, &i);
				tmp = add_to_list(tmp, filen, 2, 1, &token, 0, 1, 1);
				free(filen);
			}
		}

		if (line[i] == '$')
		{
			if (line[i + 1] == '?')
			{
				char *statusNumber = ft_itoa((*pointera)->status);
				tmp = add_to_list(tmp, statusNumber, 1, 1, &token, i, 2, 0);
				free(statusNumber);
				i++;
			}
			else if (is_authorized_for_env_char(line[i + 1]))
			{
				i++;
				old_i = i;
				while (line[i] && !is_blank(line[i]) && is_authorized_for_env_char(line[i]))
					i++;
				char *tmp_cmd = ft_substr(line, old_i, i - old_i);
				char *var = ft_strjoin(tmp_cmd, "=");
				char *value = ft_search_env_var(*pointera, var);
				if (value == NULL)
					value = ft_strdup("");
				while (line[i] && !is_blank(line[i]) && line[i] != '\'' && line[i] != '\"' && line[i] != '|' && line[i] != '>' && line[i] != '<' && line[i] != '$')
				{
					char *tmp = value;
					value = ft_strjoin(value, ft_substr(line, i, 1));
					i++;
					free(tmp);
				}
				tmp = add_to_list(tmp, value, 1, 1, &token, old_i-1, ft_strlen(tmp_cmd) + 1, 0);
				i--;
				free(tmp_cmd);
				free(var);
				free(value);
			}
			else
				tmp = add_to_list(tmp, "$", 1, 1, &token, i, 1, 0);
		}
		if (line[i])
			i++;
	}
	tmp->next = NULL;
	t_lexing *tmp2 = merge_nearby_word(cmd);
	clean_table(cmd);  
	free((*pointera)->garbage->line);
	free((*pointera)->garbage->prompt);
	free((*pointera)->garbage);
	(*pointera)->garbage = NULL;

	t_pointer_cmd *control = malloc(sizeof(t_pointer_cmd));
	while (tmp2->prev)
		tmp2 = tmp2->prev;
	control->first = tmp2;
	control->end = NULL;
	while (tmp2 != NULL)
	{
		if (tmp2->next-> cmd == NULL)
		{
			free(tmp2->next);
			tmp2->next = NULL;
		}
		tmp2 = tmp2->next;
	}
	(void)pointera;
	int status = ft_exec(pointera, control);
	(*pointera)->status = status;
	clean_table(tmp2); 
	return (status);
}

int		main(int argc, char **argv, char **env)
{
	(void)env;
	(void)argv;
	t_pointer   *pointera;
	t_list      *env_list;
	int	status;

	pointera = NULL;
	env_list = NULL;
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

void	ft_shlvl(t_pointer **pointera)
{
	char	*var;
	char	*op;
	int	i;

	var = NULL;
	op = NULL;
	i = -1;
	i = ft_search_var(*pointera, "SHLVL=");
	if (i < 0)
		ft_export_plus(pointera);
	else
	{
		op = ft_export_moin(pointera, i);
		var = ft_strjoin("SHLVL=", op);
		free(op);
		ft_maillon_change(pointera, i, var);
		free(var);
	}
}
