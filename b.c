#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct  s_list
{
    int pid;
    int status;
    int pipe_fd[2];
    struct s_list   *next;
    struct s_list   *before;
}   t_list;

int ft_strlen(const char *str);
char    *ft_strdup(const char *str);
void    ft_fre(char **tab);
int ft_cd(char **tab);
int ft_one(char **tab, char **env);
t_list  *ft_new(void);
void    ft_lstclear(t_list **list);
t_list  *ft_maillon(t_list  *list);
void    ft_un(char **dest, char **env, char **tab, t_list **list, t_list *pointera);
void    ft_mid(char **dest, char **env, char **tab, t_list **list, t_list *pointera);
void    ft_last(char **dest, char **env, char **tab, t_list **list, t_list *pointera);
int ft_wait(t_list *list);
int ft_pipeline(char **tab, char **env);
int ft_searchpipe(char **tab);

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
    int j;
    char    *dest;

    i = ft_strlen(str);
    j = 0;
    dest = malloc((i + 1) * sizeof(char));
    while (j < i)
    {
        dest[j] = str[j];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

void    ft_fre(char **tab)
{
    int i;

    i = 0;
    while(tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int ft_cd(char **tab)
{
    int i;

    i = 0;
    if (tab[1] == NULL || tab[1][0] == '\0' || tab[2] != NULL)
    {
        write (2, "err\n", 4);
        return (1);
    }
    i = chdir(tab[1]);
    if (i == -1)
    {
        write (2, "er\n", 3);
        return (1);
    }
    return (0);
}

int ft_one(char **tab, char **env)
{
    int pid;
    int status;

    status = 0;
    if (strncmp(tab[0], "cd", 2) == 0)
    {
        status = ft_cd(tab);
        return (status);
    }
    pid = fork();
    if (pid == 0)
    {
        execve(tab[0], tab, env);
        ft_fre(tab);
        write (2, "erreur\n", 7);
        exit (EXIT_FAILURE);
    }
    waitpid(pid, &status, 0);
    return (status);
}

t_list  *ft_new(void)
{
    t_list  *new;

    new = malloc((sizeof(t_list)));
    new->pid = 0;
    new->status = 0;
    new->next = NULL;
    new->before = NULL;
    return (new);
}

void    ft_lstclear(t_list **list)
{
    t_list  *temp;
    t_list  *curent;

    temp = *list;
    curent = NULL;
    while (temp != NULL)
    {
        curent = temp;
        temp = temp ->next;
        free(curent);
    }
    *list = NULL;
}

t_list  *ft_maillon(t_list  *list)
{
    t_list  *temp;
    t_list  *new;

    temp = list;
    new = ft_new();
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->before = temp;
    return (list);
}

void    ft_un(char **dest, char **env, char **tab, t_list **list, t_list *pointera)
{
    if((*list)->pid == 0)
    {
        dup2((*list)->pipe_fd[1], STDOUT_FILENO);
        close((*list)->pipe_fd[0]);
        close((*list)->pipe_fd[1]);
        execve(dest[0], dest, env);
        write (2, "erreur\n", 7);
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
    if((*list)->pid == 0)
    {
        dup2((*list)->before->pipe_fd[0], STDIN_FILENO);
        close((*list)->before->pipe_fd[0]);
        dup2((*list)->pipe_fd[1], STDOUT_FILENO);
        close((*list)->pipe_fd[0]);
        close((*list)->pipe_fd[1]);
        execve(dest[0], dest, env);
        write (2, "erreur\n", 7);
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
    if((*list)->pid == 0)
    {
        dup2((*list)->before->pipe_fd[0], STDIN_FILENO);
        close((*list)->before->pipe_fd[0]);
        execve(dest[0], dest, env);
        write (2, "erreur\n", 7);
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

    temp = list;
    while (temp != NULL)
    {
        close(list->pipe_fd[0]);
        waitpid(list->pid, &list->status, 0);
        temp = temp->next;
    }
    return (list->status);
}

int ft_pipeline(char **tab, char **env)
{
    t_list  *list;
    t_list  *pointera;
    int i;
    int j;
    int status;
    int n;
    char    **dest;

    i = 0;
    j = 0;
    n = 0;
    status = 0;
    list = ft_new();
    dest = NULL;
    pointera = list;
    while (tab[i] != NULL)
    {
        j = i;
        while(tab[j] != NULL && tab[j][0] != '|')
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
        pipe(list->pipe_fd);
        list->pid = fork();
        if (n == 0)
            ft_un(dest, env , tab, &list, pointera);
        else if (tab[i] == NULL)
            ft_last(dest, env, tab, &list, pointera);
        else
            ft_mid(dest, env, tab, &list, pointera);
        if (tab[i] != NULL && tab[i][0] == '|')
            i++;
        ft_fre(dest);
        dest = NULL;
        n++;
    }
    status = ft_wait(pointera);
    ft_lstclear(&pointera);
    return (WEXITSTATUS(status));
}

int ft_searchpipe(char **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(tab[i] != NULL)
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

int main(int argc, char **argv, char **env)
{
    int i;
    int j;
    int t;
    int status;
    char    **tab;

    i = 1;
    j = 0;
    t = 0;
    (void)env;
    status = 0;
    tab = NULL;
    if (argc == 1)
        return (1);
    while (argv[i] != NULL)
    {
        while (argv[i] != NULL && argv[i][0] == ';' && argv[i][1] == '\0')
            i++;
        t = i;
        while(argv[t] != NULL)
        {
            if (argv[t][0] == ';' && argv[t][1] == '\0')
                break;
            t++;
        }
//        printf("t %d i %d\n", t, i);
        tab = malloc((t - i + 1) * sizeof(char *));
        j = 0;
        while (argv[i] != NULL)
        {
            if (argv[i][0] == ';' && argv[i][1] == '\0')
                break;
            tab[j] = ft_strdup(argv[i]);
//            printf("tab %s j %d i %d \n", tab[j], j, i);
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