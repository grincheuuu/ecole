/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_attribut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:26:54 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/26 17:26:58 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_child_last_deux(t_pointer_cmd **pointerB, t_pointer **pointera,
		t_file_fd *t_file, t_listp **listp)
{
	char	**argv;

	argv = NULL;
	close(t_file->stdin_fd);
	close(t_file->stdout_fd);
	ft_signaux_pipeline(1);
	if (ft_generate_infile(pointerB, t_file, pointera, listp) == 0)
		dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
	close((*listp)->before->pipe_fd[0]);
	ft_generate_outfile(pointerB, t_file, pointera, listp);
	argv = ft_generate_argv(pointerB, t_file->t);
	return (argv);
}

void	ft_restore_fd(t_file_fd *t_file)
{
	if (t_file != NULL)
	{
		dup2(t_file->stdin_fd, STDIN_FILENO);
		close(t_file->stdin_fd);
		dup2(t_file->stdout_fd, STDOUT_FILENO);
		close(t_file->stdout_fd);
	}
}

int	ft_arg_buildin(char **argv)
{
	if (argv == NULL || argv[0] == NULL)
		return (1);
	if (argv[0][0] >= '0' && argv[0][0] <= '9')
		return (1);
	if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (0);
	else
		return (1);
}

int	ft_search_pipe(t_pointer_cmd *pointerB)
{
	t_lexing	*temp;

	temp = pointerB->first;
	while (temp != NULL)
	{
		if (temp->special_token == 5)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_signaux_annul(int n)
{
	struct sigaction	sa_ignore;
	struct sigaction	sa_default;

	if (n == 0)
	{
		ft_bzero(&sa_ignore, sizeof(sa_ignore));
		sa_ignore.sa_handler = SIG_IGN;
		sa_ignore.sa_flags = 0;
		sigemptyset(&sa_ignore.sa_mask);
		if (sigaction(SIGPIPE, &sa_ignore, NULL) == -1)
			perror("sigaction");
	}
	else
	{
		ft_bzero(&sa_default, sizeof(sa_default));
		sa_default.sa_handler = SIG_DFL;
		sa_default.sa_flags = 0;
		sigemptyset(&sa_default.sa_mask);
		if (sigaction(SIGPIPE, &sa_default, NULL) == -1)
			perror("sigaction");
	}
}
