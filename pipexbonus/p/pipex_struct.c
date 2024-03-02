/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:00:43 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/01 19:20:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_initialiser(t_pip **lst, t_pip *new)
{
	t_pip	first;

	first = ft_new(pid, fd);
}

t_pip	*ft_new(pid_t pid, int fd)
{
	t_pip	*new_node;

	new_node = (t_pip *)malloc(sizeof(t_pip));
	if (new_node == NULL)
		return (NULL);
	new_node->pid = pid;
	new_node->fd = fd;
	new_node->status = status;
	new_node->next = NULL;
	return (new_node);
}
