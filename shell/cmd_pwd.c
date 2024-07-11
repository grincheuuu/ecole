/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:57:00 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/01 16:58:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_pwd(t_list *env_list, t_pointer *pointera)
{
    char    *buffer;
    size_t  size;

    size = 1024;
    if (size <= 0)
    {
        ft_failure(env_list, pointera);
    }
    buffer = malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
    {
        ft_failure(env_list, pointera);
    }
    if (getcwd(buffer, size) == NULL)
    {
        write (2, "Cannot get current working directory path\n", 43);
        free(buffer);
        ft_failure(env_list, pointera);
    }
    ft_putstr_fd(buffer, 1);
    write(1, "\n", 1);
    free(buffer);
    return ;
}

void    ft_failure(t_list *env_list, t_pointer *pointera)
{
    ft_lstclear(&env_list);
	free(pointera);
    exit(EXIT_FAILURE);
}
