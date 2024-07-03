/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_plus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:08:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/10 16:49:07 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strlen(const char *env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return (0);
	while (env[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_exe(char **patch, int t, char **argv, char **env)
{
	if (patch == NULL)
	{
		ft_thor(argv);
		return ;
	}
	while (patch[t] != NULL)
	{
		if ((access(argv[0], F_OK | X_OK) == 0))
			execve(argv[0], argv, env);
		if ((access(patch[t], F_OK | X_OK) == 0) && (argv[0][0] != '.'
			&& argv[0][0] != '\0' && argv[0][1] != '/'))
		{
			execve(patch[t], argv, env);
		}
		t++;
	}
}

void	ft_thor(char **argv)
{
	if ((access(argv[0], F_OK | X_OK) == 0))
	{
		execve(argv[0], argv, NULL);
	}
}

char	*ft_arg(char *argv)
{
	char	*dest;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	dest = NULL;
	l = ft_strlen(argv);
	while ((l - j) > 0 && argv[l - j] != '/')
		j++;
	dest = malloc((j + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = l - j;
	j = 0;
	while (argv[i + j] != '\0')
	{
		dest[j] = argv[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_atol_test(char *gv)
{
	int	i;

	i = 0;
	while ((gv[i] > 8 && gv[i] < 14) || gv[i] == 32)
		i++;
	if (gv[i] == 45 || gv[i] == 43)
		i++;
	if (!(gv[i] > 47 && gv[i] < 58))
	{
		write(2, "minishell: exit: ", 17);
		ft_putstr_fd(gv, 2);
		write(2, ": numeric argument required\n", 28);
		return (2);
	}
	while (gv[i] > 47 && gv[i] < 58)
		i++;
	if (gv[i] == '\0')
		return (0);
	else
	{
		write(2, "minishell: exit: ", 17);
		ft_putstr_fd(gv, 2);
		write(2, ": numeric argument required\n", 28);
		return (2);
	}
}
