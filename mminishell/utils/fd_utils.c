/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:35:27 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/03 11:57:56 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) < 0)
			break ;
		i++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write(fd, s, l);
}

void	putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		putstr_fd("-2147483648", fd);
		return ;
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
			return ;
	}
}

void	handle_redirlow_part(t_lexing **tmp, char *line, t_parsing **par)
{
	char	*heredoc_file;

	(*par)->i++;
	while (line[(*par)->i] && is_blank(line[(*par)->i]))
		(*par)->i++;
	heredoc_file = extract_next_word(line, &(*par)->i, par);
	*tmp = add_to_list(*tmp, heredoc_file, bstructtok(2, 1, &(*par)->token),
			bstruct((*par)->old_i, ft_strlen(heredoc_file), 1));
	free(heredoc_file);
}

void	handle_special_cases(t_parsing **par, char *line, char **value)
{
	char	*substr;
	char	*value_deux;

	while (line[(*par)->i] && !is_blank(line[(*par)->i])
		&& handle_special_case(*par))
	{
		substr = ft_substr(line, (*par)->i++, 1);
		value_deux = *value;
		*value = ft_strjoin(value_deux, substr);
		free(substr);
		substr = NULL;
		free(value_deux);
	}
}
