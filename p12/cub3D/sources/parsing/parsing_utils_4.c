/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:08:29 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:05:29 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_split2(char **str)
{
	int	co;

	co = 0;
	while (str[co])
	{
		free(str[co]);
		co++;
	}
	free(str);
}

char	**ft_realloc(char **old_envp, size_t new_size)
{
	char		**new_envp;
	size_t		i;

	new_envp = (char **)malloc(new_size);
	if (!new_envp)
	{
		printf("Error\n");
		printf("error :malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (old_envp[i] != NULL)
	{
		new_envp[i] = old_envp[i];
		i++;
	}
	new_envp[i] = NULL;
	free(old_envp);
	return (new_envp);
}
