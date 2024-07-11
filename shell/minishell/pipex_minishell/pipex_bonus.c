/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/16 19:07:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_result(char **result, char *temp)
{
	char	**testpatch;
	int		t;
	int		i;

	i = 0;
	t = 0;
	testpatch = NULL;
	if (result == NULL)
	{
		free(temp);
		return (testpatch);
	}
	while (result[t] != NULL)
		t++;
	testpatch = ft_testpatch_suite(t, i, result, temp);
	ft_fre(result);
	free(temp);
	return (testpatch);
}

char	**ft_testpatch_suite(int t, int i, char **result, char *temp)
{
	char	**testpatch;

	testpatch = malloc((t + 1) * sizeof(char *));
	if (testpatch == NULL)
		return (NULL);
	while (i < t)
	{
		testpatch[i] = ft_strjoin(result[i], temp);
		i++;
	}
	testpatch[i] = NULL;
	return (testpatch);
}

char	**ft_testpath(char **result, char *argv)
{
	char	**testpatch;
	char	*temp;
	int		l;
	int		i;
	int		t;

	i = 0;
	t = 0;
	l = 1 + ft_strlen(argv);
	temp = malloc((l + 1) * sizeof(char));
	if (temp == NULL)
	{
		ft_fre(result);
		return (NULL);
	}
	temp[i] = '/';
	while (argv[i] != '\0')
	{
		temp[i + 1] = argv[i];
		i++;
	}
	temp[i + 1] = '\0';
	testpatch = ft_result(result, temp);
	return (testpatch);
}

void	ft_execve_error(int n, const char *str, char ***thor, char ***com)
{
	if (n == -1)
	{
		perror(str);
		ft_fre(*thor);
		ft_fre(*com);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	status;

	i = 2;
	status = 0;
	if (argc >= 5)
	{
		if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
			status = ft_heredoc(argv, env);
		else
		{
			status = ft_pipeline(argc, argv, env, i);
		}
		if (status != 0)
			exit(status);
		exit(EXIT_SUCCESS);
	}
	write (2, "arguments faux", 9);
	exit(EXIT_FAILURE);
}
