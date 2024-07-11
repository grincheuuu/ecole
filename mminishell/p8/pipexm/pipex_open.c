/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:30:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/15 19:17:51 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char    **ft_create_tab(t_pointer_cmd *pointerB)
{
    t_cmd	*temp;
	char	**argv;
	char	*copy;

	temp = pointerB->first;
	argv = NULL;
	copy = ft_strdup("");
	while (temp != NULL)
	{
        while (ft_strncmp(temp->type, "word", 5) == 0))
		if (ft_strncmp(temp->type, "word", 5) == 0)
		{
			argv[i] = ft_strjoin(copy, temp->cmd);
			free(copy);
			copy = argv[i];
            argv[i] = ft_strjoin(copy, " ");
            free(copy);
            copy = argv[i];
//			printf("\n9%s9\n", temp->cmd);
		}
		temp = temp->next;
	}
//	printf("%s", argv);
	return (argv);
}

int ft_realize_cmd(t_pointer_cmd *pointerB, char **env, t_pointer **pointera)
{
	char	*argv;
	pid_t	a_pid;
	int		pipe_fd[2];
	int		status;
	t_file_fd	*t_file;

	argv = NULL;
	t_file = NULL;
	status = 0;
	t_file = ft_realize_filefd(pointerB);
	if (t_file == NULL)
		return (1);
	argv = ft_create_argv(pointerB);
	printf("\naa%saa\n", argv);
	if (argv == NULL || *argv == '\0')
	{
		printf("BB");
		free(argv);
		free(t_file);
		return (0);
	}
	if (ft_analyse_arg_buildin(argv, pointera, pointerB, env) == 0)
	{
		free(argv);
		free(t_file);
		return (status);
	}
/*	if (ft_strncmp("./minishell", argv, 11) == 0)
		ft_level(pointera, "SHLVL=");*/
	ft_error(pipe(pipe_fd), "pipe_fd");
	ft_error((a_pid = fork()), "a_pid");
	if (a_pid == 0)
		ft_childun(pipe_fd, argv, env, t_file);
	else
		close(pipe_fd[1]);
	waitpid(a_pid, &status, 0);
	if (access("text.tmp", F_OK) == 0)
		unlink("text.tmp");
	free(argv);
	free(t_file);
	printf("D");
	return (status);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}
