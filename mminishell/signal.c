/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:26:36 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/02 18:08:03 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

void	sig_readline(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_signal = SIGINT;
	}
}

void	sig_cmd(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		g_signal = SIGINT;
	}
	if (sig == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
}

void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_signal = SIGINT;
	}
	if (sig == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
}

void	sig_exit_code(t_pointer **arg)
{
	if (g_signal)
	{
		(*arg)->status = 130;
		g_signal = 0;
	}
}

void	change_signal(int param)
{
	struct sigaction	sig_int;
	struct sigaction	sig_quit;

	ft_bzero(&sig_int, sizeof(sig_int));
	ft_bzero(&sig_quit, sizeof(sig_quit));
	sig_int.sa_flags = SA_RESTART;
	sig_quit.sa_flags = SA_RESTART;
	if (param == 0)
	{
		sig_int.sa_handler = &sig_readline;
		sig_quit.sa_handler = SIG_IGN;
	}
	else if (param == 1)
	{
		sig_int.sa_handler = &sig_cmd;
		sig_quit.sa_handler = &sig_cmd;
	}
	else
	{
		sig_int.sa_handler = &sig_heredoc;
		sig_quit.sa_handler = &sig_heredoc;
		sig_int.sa_flags = 0;
	}
	sigemptyset(&sig_int.sa_mask);
	sigemptyset(&sig_quit.sa_mask);
	sigaction(SIGINT, &sig_int, NULL);
	sigaction(SIGQUIT, &sig_quit, NULL);
}
