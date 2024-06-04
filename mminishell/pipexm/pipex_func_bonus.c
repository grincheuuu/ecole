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
	dprintf(2, "\n1wait");
	while (temp->next != NULL)
	{
		close(temp->pipe_fd[0]);
		waitpid(temp->pid, &temp->status, 0);
		temp = temp->next;
		dprintf(2, "\n1caaa");
	}
	waitpid(temp->pid, &temp->status, 0);
	return (temp->status);
}

void	ft_clean_all(char **patch, t_listp **listp)
{
	ft_fre(patch);
	ft_lstclear(listp);
}
/*
void	ft_clean_final(t_pointer_p *pointer, int j)
{
	(void)j;
	ft_lstclear(&pointer->first);
	free(pointer);
//	if (j == 1)
//		exit(EXIT_FAILURE);
}*/


void	ft_clean_final(t_listp *list, int j)
{
	(void)j;
	ft_lstclear(&list);
//	if (j == 1)
//		exit(EXIT_FAILURE);
}