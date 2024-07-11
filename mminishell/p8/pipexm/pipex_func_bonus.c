/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:32:00 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/19 20:02:21 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	l;

	l = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}

char	*ft_strjoined(char *s1, char *s2)
{
	char	*dest;
	size_t	l;

	l = 0;
	dest = NULL;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	free(s1);
	return (dest);
}

int	ft_wait(t_listp **listp)
{
	t_listp	*temp;

	temp = *listp;
	while (*listp != NULL)
	{
		temp = *listp;
		*listp = (*listp)->before;
	}
	while (temp->next != NULL)
	{
		close(temp->pipe_fd[0]);
		waitpid(temp->pid, &temp->status, 0);
		temp = temp->next;
	}
	waitpid(temp->pid, &temp->status, 0);
	return (temp->status);
}

void	ft_clean_all(char **patch, t_listp **listp, t_pointer_cmd **pointerB,
		t_pointer **pointera)
{
	t_listp	*temp;

	temp = NULL;
	while (*listp != NULL)
	{
		temp = *listp;
		*listp = (*listp)->before;
	}
	if (patch != NULL)
		ft_fre(patch);
	ft_lstclear(&temp);
	ft_lstclear_bis(&(*pointera)->first);
	free(*pointera);
	ft_lstclear_node(&(*pointerB)->first);
	free(*pointerB);
}

void	ft_clean_final(t_listp **listp, t_pointer **pointera,
		t_pointer_cmd **pointerB, t_file_fd *t_file)
{
	t_listp	*temp;

	temp = NULL;
	free(t_file);
	if (listp != NULL)
	{
		while (*listp != NULL)
		{
			temp = *listp;
			*listp = (*listp)->before;
		}
		ft_lstclear(&temp);
	}
	ft_lstclear_bis(&(*pointera)->first);
	free(*pointera);
	ft_lstclear_node(&(*pointerB)->first);
	free(*pointerB);
}

void	ft_test_dir(char *patch)
{
	struct stat	file;

	if (stat(patch, &file) == 0)
	{
		if (S_ISDIR(file.st_mode))
		{
			write(2, "minishell: ", 11);
			ft_putstr_fd(patch, 2);
			write(2, ": Is a directory\n", 17);
		}
		else if ((access(patch, F_OK | X_OK) < 0))
		{
			write(2, "minishell: ", 11);
			ft_putstr_fd(patch, 2);
			write(2, ": Permission denied\n", 20);
		}
	}
	else if ((patch != NULL && patch[0] != '\0') && (patch[ft_strlen(patch)
			- 1] == '/' || patch[0] == '/'))
	{
		write(2, "minishell: ", 11);
		ft_putstr_fd(patch, 2);
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		write(2, "minishell: command not found: ", 30);
		ft_putstr_fd(patch, 2);
		write(2, "\n", 1);
	}
}
