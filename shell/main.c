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
    buffer = malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
        ft_failure(env_list, pointera);
    if (getcwd(buffer, size) == NULL)
    {
        write (2, "Cannot get current working directory path\n", 43);
        free(buffer);
        ft_failure(env_list, pointera);
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
}

char	*ft_initialize_shell(t_list *env_list, t_pointer *pointera)
{
    char    *line;
    char    *prompt;

    prompt = ft_prompt(env_list, pointera);
    line = readline(prompt);
    free(prompt);
    return (line);
}

void	ft_analyse_arg(int argc, char **argv, t_list *env_list, t_pointer *pointera)
{;
	if (argc >= 2 && ft_strncmp(argv[1], "export", 6) == 0)
		ft_export(argv[2], env_list, pointera);
	if (argc >= 2 && ft_strncmp(argv[1], "unset", 5) == 0)
		ft_unset(pointera, argv[2]);
	if (argc == 2 && ft_strncmp(argv[1], "pwd", 3) == 0)
		ft_pwd(env_list, pointera);
	if (argc >= 2 && ft_strncmp(argv[1], "cd", 2) == 0)
		ft_cd(argv[2], env_list, pointera, argc);
	if (argc >= 2 && ft_strncmp(argv[1], "exit", 4) == 0)
		ft_cmd_exit(argv[2], argv[3], pointera);
    if (argc >= 2 && ft_strncmp(argv[1], "$", 1) == 0)
    {
        printf("a revoir");
		ft_valeur_var(argv[1], pointera);
    }
}

int	main(int argc, char **argv, char **env)
{
    t_pointer   *pointera;
    t_list      *env_list;
    char    *line;
    char    **env_tab;

    pointera = NULL;
    env_list = NULL;
    line =  NULL;
    env_tab = NULL;
    (void)argc;
    (void)argv;
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
        line = ft_initialize_shell(env_list, pointera);
        ft_analyze_line(line);
    }*/
	ft_analyse_arg(argc, argv, env_list, pointera);
//    ft_init_maillon_cmd(argc, argv + 1);
    env_tab = ft_transform_env_list(pointera);
//	ft_printlist(pointera);
    ft_fre(env_tab);
	ft_lstclear(&env_list);
	free(pointera);
	return (0);
}

void    ft_print_tab(char **env_tab)
{
    int i;

    i = 0;
    while (env_tab[i] != NULL)
    {
        printf("%s\n", env_tab[i]);
        i++;
    }
}
/*
void    ft_check_arg(int argc, char **argv, t_pointer *pointera, t_list *env_list)
{
    char    **_pop;

    pop = NULL;
    while (i < (argc - 1))
    {
        pop = ft_split(argv[i], ' ');
        if (access(pop[0], F_OK | X_OK | R_OK) == 0)
            commande;
        if (ft_builtins(argv[i], pointera, env_list, argc))
            commande_builtins;
        if (argv[i] == "PIPE")
            return ;
        else
        {

        }
        free(pop);
    }
}

int ft_builtins(char argv, t_pointer *pointera, t_list *env_list, int argc)
{
    if (ft_strncmp(argv, "echo", 4))
        return ();
    if (ft_strncmp(argv, "export", 6) == 0)
		ft_export(argv[], env_list, pointera);
	if (t_strncmp(argv[1], "unset", 5) == 0)
		ft_unset(pointera, argv[2]);
	if (ft_strncmp(argv, "pwd", 3) == 0)
		ft_pwd(env_list, pointera);
	if (ft_strncmp(argv, "cd", 2) == 0)
		ft_cd(argv[2], env_list, pointera, argc);
	if (ft_strncmp(argv, "exit", 4) == 0)
		ft_cmd_exit(argv[2], argv[3], pointera);
    if (ft_strncmp(argv, "$", 1) == 0)
        ft_valeur_var(argv[1], pointera);
    if (ft_strncmp(argv, "env", 1) == 0)
        ft_print_env(argv[1], pointera);
    return (0);
}*/