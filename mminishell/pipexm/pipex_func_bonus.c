/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:32:00 by gschwart          #+#    #+#             */
/*   Updated: 2024/06/30 16:06:59 by tlegendr         ###   ########.fr       */
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
	rl_clear_history();
}

void	ft_clean_final(t_listp **listp, t_pointer **pointera,
		t_pointer_cmd **pointerB, t_file_fd *t_file)
{
	t_listp	*temp;

	temp = NULL;
	if (t_file != NULL)
	{
		free(t_file);
	}
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
	rl_clear_history();
}

void	ft_clean_argv_pipe(char **argv, int status)
{
	ft_fre(argv);
	ft_signaux_annul(1);
	exit(status);
}
