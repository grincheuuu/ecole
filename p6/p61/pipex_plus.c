/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:08:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/20 16:14:35 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int	ft_strlen(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_exe(char **patch, int t, char *argv, char **env)
{
	char	**com;
	char	**thor;

	com = NULL;
	thor = NULL;
	if (patch == NULL)
	{
		ft_thor(argv);
		return ;
	}
	while (patch[t] != NULL)
	{
		thor = ft_split(patch[t], ' ');
		free(patch[t]);
		com = ft_split(argv, ' ');
		if ((access(thor[0], F_OK | X_OK) == 0))
		{
			execve(thor[0], com, env);
		}
		ft_fre(thor);
		ft_fre(com);
		t++;
	}
}

void	ft_thor(char *argv)
{
	char	**thor;
	char	**com;
	char	*dest;
	int		i;
	int		t;

	i = 0;
	t = 0;
	com = NULL;
	dest = NULL;
	thor = ft_split(argv, ' ');
	dest = ft_arg(argv);
	com = ft_split(dest, ' ');
	free(dest);
	if ((access(thor[0], F_OK | X_OK) == 0))
	{
		ft_execve_error(execve(thor[0], com, NULL), "execve", &thor, &com);
	}
	ft_fre(thor);
	ft_fre(com);
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
