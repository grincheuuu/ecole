/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/23 19:04:48 by gschwart         ###   ########.fr       */
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

int	ft_gnl(char *str)
{
	char	*line;
	int		file_fd;

	line = NULL;
	file_fd = open("text.tmp", O_RDWR | O_TRUNC | O_CREAT, 0644);
	ft_error(file_fd, "file_fd");
	while (get_next_line(0) != NULL)
	{
		line = get_next_line(0);
		if (strncmp(line, str, ft_strlen(str)))
			break ;
		write (file_fd, line, ft_strlen(line));
		free(line);
	}
	return (file_fd);
}

int	main(int argc, char **argv, char **env)
{
	int	file_fd;
	int	file_fi;
	int	i;
	int	pipe_fd[2];

	i = argc - 2;
	if (argc >= 5)
	{
		if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			file_fd = ft_gnl(argv[2]);
			file_fi = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
			ft_error(file_fdfi, "file_fdfinal");
			ft_error(pipe(pipe_fd), "pipe_fd");
			while (i > 2)
			{
				if (i == argc - 2)
					ft_last(file_fi, argv[i], env, pipe_fd);
				else if (i == 3)
					ft_un(file_fd, pipe_fd, argv[i], env);
				else
					ft_family(argv[i], env, pipe_fd);
				i--;
			}
		}
		else
		{
			ft_error((file_fd = open(argv[1], O_RDONLY, 0644)), "file_fd");
			file_fi = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
			ft_error(file_fi, "file_fdfinal");
			ft_error(pipe(pipe_fd), "pipe_fd");
			while (i > 1)
			{
				if (i == argc - 2)
					ft_last(file_fi, argv[i], env, pipe_fd);
				else if (i == 2)
					ft_un(file_fd, pipe_fd, argv[i], env);
				else
					ft_family(argv[i], env, pipe_fd);
				i--;
			}
		}
		exit(EXIT_SUCCESS);
	}
	write (2, "argc faux", 9);
	exit(EXIT_FAILURE);
}
