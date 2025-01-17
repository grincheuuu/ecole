/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_return_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:20:13 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:20:45 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	finalize(char ***envp, char **new_envp, char *new_var, int i)
{
	*envp = new_envp;
	(*envp)[i] = new_var;
	(*envp)[i + 1] = NULL;
}

void	print_messages(void)
{
	printf("Error\n");
	printf("malloc failed\n");
}

int	updates_char(char ***envp, const char *line)
{
	char	*new_var;
	char	**new_envp;
	int		i;

	i = 0;
	new_var = (char *)malloc ((ft_strlen(line) + 1) * sizeof(char));
	if (!new_var)
	{
		print_messages();
		return (1);
	}
	while (line[i] != '\0')
	{
		new_var[i] = line[i];
		i++;
	}
	new_var[i] = '\0';
	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = ft_realloc(*envp, sizeof(char *) * (i + 2));
	if (!new_envp)
		return (free_updates_char(&new_var));
	finalize(envp, new_envp, new_var, i);
	return (0);
}
