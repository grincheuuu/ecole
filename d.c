#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

typedef struct  s_list
{
    int pid;
    int pipe_fd[2];
    int status;
    struct s_list   *next;
    struct s_list   *before;
}   t_list;

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *str)
{
    int i;
    char    *dest;

    i = ft_strlen(str);
    dest = malloc((i + 1) * sizeof(char));
    i = 0;
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void    ft_fre(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int ft_searchpipe(char **tab)
{
    int i;
    int j;

    i = 0;
    while (tab[i] != NULL)
    {
        j = 0;
        while (tab[i][j] != '\0')
        {
            if (tab[i][j] == '|')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_cd(char **tab)
{
    int i;

    i = 0;
    if (tab[1] == NULL || tab[1][0] == '\0' || tab[2] != NULL)
    {
        write (2, "error: cd; bad arguments\n", 25);
        return (1);
    }
    i = chdir(tab[1]);
    if (i == -1)
    {
        write (2, "cd erreur\n", 10);
        return (1);
    }
    return (0);
}

int ft_one(char **tab, char **env)
{
    int status;
    int pid;

    status = 0;
    if (strncmp(tab[0], "cd", 3) == 0)
    {
        status = ft_cd(tab);
        return (status);
    }
    pid = fork();
    if (pid == -1)
    {
        write (2, "error fatal\n", 12);
        exit (EXIT_FAILURE);
    }
    if (pid == 0)
    {
        execve(tab[0], tab, env);
        write (2, "erreur\n", 7);
        ft_fre(tab);
        exit (EXIT_FAILURE);
    }
    waitpid(pid, &status, 0);
    return (WEXITSTATUS(status));
}

t_list  *ft_new(void)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    new->pid = 0;
    new->status = 0;
    new->next = NULL;
    new->before = NULL;
    return (new);
}

void    ft_lstclear(t_list **list)
{
    t_list  *temp;
    t_list  *current;

    temp = *list;
    current = *list;
    while(temp != NULL)
    {
        current = temp;
        temp = temp->next;
        free(current);
    }
    *list = NULL;
}

t_list  *ft_maillon(t_list *list)
{
    t_list  *new;
    t_list  *temp;

    new = ft_new();
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->before = temp;
    return (list);
}

void    ft_un(char **dest, char **env, char **tab, t_list **list, t_list *pointera)
{
    if ((*list)->pid == 0)
    {
        dup2((*list)->pipe_fd[1], STDOUT_FILENO);
        close((*list)->pipe_fd[0]);
        close((*list)->pipe_fd[1]);
        execve(dest[0], dest, env);
        write (2, "child\n", 6);
        ft_fre(dest);
        ft_fre(tab);
        ft_lstclear(&pointera);
        exit (EXIT_FAILURE);
    }
    else
    {
        close((*list)->pipe_fd[1]);
        *list = ft_maillon(*list);
        *list = (*list)->next;
    }
}

void    ft_mid(char **dest, char **env, char **tab, t_list **list, t_list *pointera)
{
    if ((*list)->pid == 0)
    {
        dup2((*list)->before->pipe_fd[0], STDIN_FILENO);
        close((*list)->before->pipe_fd[0]);
        dup2((*list)->pipe_fd[1], STDOUT_FILENO);
        close((*list)->pipe_fd[0]);
        close((*list)->pipe_fd[1]);
        execve(dest[0], dest, env);
        write (2, "child\n", 6);
        ft_fre(dest);
        ft_fre(tab);
        ft_lstclear(&pointera);
        exit (EXIT_FAILURE);
    }
    else
    {
        close((*list)->before->pipe_fd[0]);
        close((*list)->pipe_fd[1]);
        *list = ft_maillon(*list);
        *list = (*list)->next;
    }
}

void    ft_last(char **dest, char **env, char **tab, t_list **list, t_list *pointera)
{
    close((*list)->pipe_fd[0]);
    close((*list)->pipe_fd[1]);
    if ((*list)->pid == 0)
    {
        dup2((*list)->before->pipe_fd[0], STDIN_FILENO);
        close((*list)->before->pipe_fd[0]);
        execve(dest[0], dest, env);
        write (2, "child\n", 6);
        ft_fre(dest);
        ft_fre(tab);
        ft_lstclear(&pointera);
        exit (EXIT_FAILURE);
    }
    else
    {
        close((*list)->before->pipe_fd[0]);
    }
}

int ft_wait(t_list *list)
{
    t_list  *temp;
    int status;

    temp = list;
    status = 0;
    while (temp != NULL)
    {
        close(list->pipe_fd[0]);
        waitpid(list->pid, &list->status, 0);
        status = list->status;
        temp = temp->next;
    }
    return (WEXITSTATUS(status));
}

int ft_pipeline(char **tab, char **env)
{
    t_list  *list;
    t_list  *pointera;
    int i;
    int j;
    int n;
    int status;
    char **dest;

    i = 0;
    j = 0;
    n = 0;
    status = 0;
    dest = NULL;
    list = ft_new();
    pointera = list;
    while (tab[i] != NULL)
    {
        j = i;
        while (tab[j] != NULL && tab[j][0] != '|')
            j++;
        dest = malloc((j - i + 1) * sizeof(char *));
        j = 0;
        while (tab[i] != NULL && tab[i][0] != '|')
        {
            dest[j] = ft_strdup(tab[i]);
            j++;
            i++;
        }
        dest[j] = NULL;
        j = 0;
        j = pipe(list->pipe_fd);
        if (j == -1)
        {
            write (2, "error tal\n", 10);
            ft_fre(dest);
            ft_fre(tab);
            exit (EXIT_FAILURE);
        }
        list->pid = fork();
        if (list->pid == -1)
        {
            write (2, "error\n", 6);
            exit (EXIT_FAILURE);
        }
        if (n == 0)
            ft_un(dest, env, tab, &list, pointera);
        else if (tab[i] == NULL)
            ft_last(dest, env, tab, &list, pointera);
        else
            ft_mid(dest, env, tab, &list, pointera);
        ft_fre(dest);
        dest = NULL;
        if (tab[i] != NULL && tab[i][0] == '|')
            i++;
        n++;
    }
    status = ft_wait(pointera);
    ft_lstclear(&pointera);
    return (status);
}

int main(int argc, char **argv, char **env)
{
    int i;
    int j;
    int t;
    int status;
    char **tab;

    i = 1;
    j = 0;
    t = 0;
    status = 0;
    tab= NULL;
    if (argc == 1)
        return (0);
    while (argv[i] != NULL)
    {
        while (argv[i] != NULL && argv[i][0] == ';' && argv[i][1] == '\0')
            i++;
        t = i;
        while (argv[t] != NULL)
        {
            if (argv[t][0] == ';' && argv[t][1] == '\0')
                break;
            t++;
        }
        tab = malloc((t + 1 - i) * sizeof(char *));
        j = 0;
        while (argv[i] != NULL)
        {
            if (argv[i][0] == ';' && argv[i][1] == '\0')
                break;
            tab[j] = ft_strdup(argv[i]);
            j++;
            i++;
        }
        tab[j] = NULL;
        if (ft_searchpipe(tab) == 0)
            status = ft_one(tab, env);
        else
            status = ft_pipeline(tab, env);
        ft_fre(tab);
        tab = NULL;
    }
    return (status);
}