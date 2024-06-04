/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_plus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:08:05 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/23 18:44:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		write(2, "\n", 1);
		return (1);
//		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_strlen(char *env)
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
	dprintf(2, "444\n");
	ft_print_tab(patch);
	if (patch == NULL)
	{
		ft_thor(argv);
		return ;
	}
	while (patch[t] != NULL)
	{
		if ((access(argv[0], F_OK | X_OK) == 0))
			execve(argv[0], argv, env);
		if ((access(patch[t], F_OK | X_OK) == 0))
		{
			dprintf(2, "\nexceve %s execve\n", patch[t]);
			execve(patch[t], argv, env);
		}
		free(patch[t]);
		t++;
	}
	free(patch);
}

void	ft_thor(char **argv)
{
//	char	**com;
//	char	*dest;
//	int		k;

//	k = 0;
//	com = NULL;
//	dest = NULL;
//	dest = ft_arg(argv);
//	com = ft_split(dest, ' ');
/*	while (com[k] != NULL)
	{
		dprintf(2, "\nW5s");
		k++;
	}*/
	write (2, "\n", 1);
//	free(dest);
	if ((access(argv[0], F_OK | X_OK) == 0))
	{
		execve(argv[0], argv, NULL);
	}
//	ft_fre(com);
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
