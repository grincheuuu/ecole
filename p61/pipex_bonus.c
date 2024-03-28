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
	int		len;
	int		t;
	int		i;

	len = 0;
	i = 0;
	t = 0;
	while (result[t] != NULL)
		t++;
	testpatch = malloc((t + 1) * sizeof(char *));
	if (testpatch == NULL)
		return (NULL);
	while (i < t)
	{
		len = ft_strlen(result[i]) + ft_strlen(temp);
		testpatch[i] = ft_strjoin(result[i], temp);
		i++;
	}
	testpatch[i] = NULL;
	ft_fre(result);
	free(temp);
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

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	file_fdfinal;
	int	file_fd;

	i = 2;
	if (argc >= 5)
	{
		if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
			ft_heredoc(argv, env);
		else
		{
			file_fdfinal = open(argv[argc - 1], O_WRONLY
					| O_TRUNC | O_CREAT, 0644);
			ft_error(file_fdfinal, "file_fdfinal");
			close(file_fdfinal);
			ft_error((file_fd = open(argv[1], O_RDONLY, 0644)), "file_fd");
			close(file_fd);
			ft_pipeline(argc, argv, env, i);
		}
		exit(EXIT_SUCCESS);
	}
	write (2, "argc faux", 9);
	exit(EXIT_FAILURE);
}
