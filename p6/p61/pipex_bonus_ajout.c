/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_ajout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:59:35 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/16 15:59:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error_deux(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		return (1);
	}
	return (0);
}

void	ft_free_last(char **patch)
{
	free(patch);
	write (2, " command not found last", 23);
}
