/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/10 20:03:43 by tlegendr         ###   ########.fr       */
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

char	**ft_testpath(char **result, char **argv)
{
	char	**testpatch;
	char	*temp;
	int		l;
	int		i;

	i = 0;
	l = 1 + ft_strlen(argv[0]);
	temp = malloc((l + 1) * sizeof(char));
	if (temp == NULL)
	{
		ft_fre(result);
		return (NULL);
	}
	temp[i] = '/';
	while (argv[0][i] != '\0')
	{
		temp[i + 1] = argv[0][i];
		i++;
	}
	temp[i + 1] = '\0';
	testpatch = ft_result(result, temp);
	return (testpatch);
}

int	ft_pipex_start(t_pointer **pointera, t_pointer_cmd *pointerB, int status)
{
	if (ft_search_pipe(pointerB) == 1)
		return (ft_realize_cmd(&pointerB, pointera, status));
	else
	{
		status = ft_pipeline(pointerB, pointera, status);
	}
	return (status);
}

char	**ft_generate_argv_deux(t_pointer_cmd **pointerB, int t)
{
	char		**argv;
	t_lexing	*temp;
	t_lexing	*zoro;
	int			i;

	argv = NULL;
	i = 0;
	temp = (*pointerB)->first;
	zoro = (*pointerB)->first;
	temp = ft_temp(temp, t);
	while (temp != NULL)
	{
		if (temp->special_token != 5)
			return (NULL);
		if (temp->special_token == 0)
			i++;
		temp = temp->next;
	}
	argv = ft_generate_argv_un(zoro, t, i);
	return (argv);
}
