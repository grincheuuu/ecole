/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:41:24 by gschwart          #+#    #+#             */
/*   Updated: 2023/11/07 13:56:29 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_exec(int argc, char **argv, t_pointer **pointera, t_pointer_cmd *pointerB)
{
	char    **env_tab;
    int i;
    int j;

    (void)argv;
    (void)argc;
    i = 0;
    j = 0;
//    temp = pointerB->first;
    env_tab = ft_transform_env_list(pointera);
	ft_printlist_cmd(pointerB);
    write(1, "\n", 2);
    write(1, "\n", 2);
    ft_pipex_start(i, env_tab, pointera, pointerB);
	ft_lstclear_node(&pointerB->first);
    ft_fre(env_tab);
	free(pointerB);
}

void    ft_test_dir(void)
{
    struct stat file;
    char    path[] = "cmd_echo.c";

    if (stat(path, &file) == 0)
    {
        if (S_ISDIR(file.st_mode))
        {
            write (2, "bash: ./", 9);
            ft_putstr_fd(path, 2);
            write (2, ": No such file or directory\n", 29);
        }
        else
            ft_putstr_fd("fichier", 2);
    }
}
