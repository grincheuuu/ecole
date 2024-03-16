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
	char	c;
	
	i = 2;
	c = 0;
	if (argc >= 5)
	{
		if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
			ft_heredoc(argv, env);
		else
		{
			ft_pipeline(argc, argv, env, i);
/*			while (i < argc - 1)
			{	
				if (i == argc - 2)
				{
					ft_last(argc, argv, env, listp);
				}
				else if (i == 2)
				{
					ft_un(argv, env, pointp);
					write (1, "\n", 1);
					c = file_fd + '0';
					write (1, &c, 1);
					if(file_fd != 0)
						perror("file_fda");
				}
				else
				{
					ft_mid(argv[i], env, listp);
					if (file_fd != 0)
						perror("file_fd1b");
				}
				i++;
			}
			while (j < argc - 3)
			{
				write(1, "4", 1);
				wait(NULL);
				write(1, "5", 1);					
				j++;
			}*/
		}
		exit(EXIT_SUCCESS);
	}
	write (2, "argc faux", 9);
	exit(EXIT_FAILURE);
}
