/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_ajout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:59:35 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/16 15:59:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error_deux(int n, const char *str, t_file_fd *t_file)
{
	(void)t_file;
	if (n == -1)
	{
		perror(str);
		return (1);
	}
	return (0);
}

void	ft_free_last(char **patch)
{
	ft_fre(patch);
	write(2, " command not found last", 23);
}

void	ft_absolut_path(char **argv, char **com, char **env)
{
	(void)com;
	if ((access(argv[0], F_OK | X_OK) == 0))
	{
		execve(argv[0], argv, env);
	}
}

int	ft_arg_exit(char **argv, int status)
{
	int	i;

	i = 0;
	if (argv[1] != NULL && argv[1][0] != 0 && argv[2] != NULL)
	{
		write(1, "exit\n", 5);
		while (argv[i++] != NULL)
		{
			if (ft_atol_test(argv[1]) != 0)
				break ;
			else
			{
				write(2, "minishell: exit: too many arguments\n", 36);
				return (1);
			}
		}
	}
	else
		status = ft_cmd_exit(argv, status);
	return (status);
}

void	ft_close_exit_success(t_pointer **pointera, t_pointer_cmd **pointerB,
		t_file_fd *t_file, char **argv)
{
	ft_lstclear_bis(&(*pointera)->first);
	free(*pointera);
	ft_fre(argv);
	ft_lstclear_node(&(*pointerB)->first);
	free(*pointerB);
	free(t_file);
	rl_clear_history();
	exit(0);
}
