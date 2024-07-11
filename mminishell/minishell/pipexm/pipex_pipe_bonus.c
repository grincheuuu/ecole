/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:27:04 by gschwart          #+#    #+#             */
/*   Updated: 2024/07/02 17:27:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_fre_listp(t_listp **listp, char **argv)
{
	t_listp	*temp;

	temp = NULL;
	if (argv == NULL || argv[0] == NULL)
	{
		while (*listp != NULL)
		{
			temp = *listp;
			*listp = (*listp)->before;
		}
		ft_lstclear(&temp);
		return (1);
	}
	return (0);
}

void	ft_unlink(t_pointer_cmd **pointerB)
{
	t_lexing	*tempdeux;

	tempdeux = (*pointerB)->first;
	while (tempdeux != NULL)
	{
		if (tempdeux->special_token == 2)
		{
			if (access(tempdeux->cmd, F_OK) == 0)
				unlink(tempdeux->cmd);
		}
		tempdeux = tempdeux->next;
	}
}
