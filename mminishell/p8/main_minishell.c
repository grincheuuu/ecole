/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:53:39 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/23 15:58:58 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
char    *ft_search_home(t_pointer *pointera, char *var)
{
    t_list	*temp;
	char	*home;

	home = NULL;
	temp = pointera->first;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var)) == 0)
		{
			home = ft_strdup(temp->str + 5);
			return (home);
		}
		temp = temp->next;
	}
	return (NULL);
}

char    *ft_prompt(t_list *env_list, t_pointer *pointera)
{
    char    *buffer;
    char    *prompt;
    char    *temp;
    char    *home;
    size_t  size;

    size = 1024;
    prompt = NULL;
    temp = NULL;
    home = NULL;
    (void)env_list;
    buffer = malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
        ft_failure(&pointera);
    if (getcwd(buffer, size) == NULL)
    {
        write (2, "Cannot get current working directory path\n", 43);
        free(buffer);
//        ft_failure(&pointera);
    }
    home = ft_search_home(pointera, "HOME=");
    if (home == NULL)
        return(NULL);
    if (ft_strncmp(home, buffer, ft_strlen(home)))
    {
        free(home);
        prompt = malloc((17 + 1) * sizeof(char));
        if (prompt == NULL)
            return(NULL);
        prompt = ft_strcpy(prompt, "minishell:~$ ");
    }
    else
    {
        temp = ft_strjoin("minishell:~", buffer + ft_strlen(home));
        prompt = ft_strjoin(temp, "$ ");
        free(temp);
        free(home);
    }
    free(buffer);
    return (prompt);
}*/
/*
char	*ft_initialize_shell(t_list *env_list, t_pointer *pointera)
{
    char    *line;
    char    *prompt;

    prompt = ft_prompt(env_list, pointera);
    line = readline(prompt);
    free(prompt);
    return (line);
}*/

int	main(int argc, char **argv, char **env)
{
    t_pointer   *pointera;
    t_pointer_cmd   *pointerb;
    t_list      *env_list;

    pointera = NULL;
    pointerb = NULL;
    env_list = NULL;
    (void)argc;
	pointera = malloc(sizeof(t_pointer));
	if (pointera == NULL)
		return (1);
    ft_init(pointera);
    env_list = ft_maillonlist(env);
	if (env_list == NULL)
		return (1);
    ft_affect(env_list, pointera);
/*    while (1)
    {
        ft_initialize_shell(env_list, pointera);
    }*/
    pointerb = ft_init_maillon_cmd(argv + 1);
    ft_exec(&pointera, pointerb);
//	ft_printlist(pointera);
	ft_lstclear_bis(&pointera->first);
	free(pointera);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}

void    ft_print_tab(char **env_tab)
{
    int i;

    i = 0;
    while (env_tab[i] != NULL)
    {
        printf("\n%s\n", env_tab[i]);
        i++;
    }
    printf("\nprinttab\n");
}
