#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

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
void    ft_pipeline(char **tab, char **env);
int ft_wait(t_list *list);
void    ft_last(char **dest, char **env, char **tab, t_list **list);
void    ft_mid(char **dest, char **env, char **tab, t_list **list);
void    ft_un(char **dest, char **env, char **tab, t_list **list);
t_list  *ft_maillon(t_list *list);
void    ft_lstclear(t_list **list);
t_list  *ft_new(void);
void    ft_one(char **tab, char **env);
int ft_cd(char *dest);
void    ft_fre(char **tab);
int ft_searchpipe(char **tab);


int ft_strlen(const char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while(str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *str)
{
    int i;
    int j;
    char    *dest;

    j = 0;
    i = ft_strlen(str);
    dest = malloc((i + 1) * sizeof(char));
    if (dest == NULL)
        return (NULL);
    while (j < i)
    {
        dest[j] = str[j];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

int ft_searchpipe(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        if (strncmp(tab[i], "|", 1) == 0)
            return (1);
        i++;
    }
    return (0);
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
    tab = NULL;
}

int ft_cd(char *dest)
{
    int i;

    i = 30;
    i = chdir(dest);
    if (i == 0)
        write (2, "ok", 2);
    else if (i == -1)
        write (2, "cd error" , 8);
    return (0);
}

int ft_wait(t_list *list)
{
    t_list  *temp;

    temp = list;
    while(temp != NULL)
    {
        close(list->pipe_fd[0]);
        waitpid(list->pid, &list->status, 0);
        temp = temp->next;
    }
    return (1);
}

int main(int argc, char **argv, char **env)
{
    int i;
    int j;
    int t;
    char    **tab;

    i = 1;
    tab = NULL;
    if (argc == 1)
    {
        write(2, "bad arg\n", 8);
        exit (EXIT_FAILURE);
    }
    while (argv[i] != NULL)
    {
        t = i;
        j = 0;
        while (argv[t] != NULL && argv[t][0] != ';')
            t++;
        tab = malloc((t + 1) * sizeof(char *));
        if (tab == NULL)
            return (1);
        while (argv[i] != NULL && argv[i][0] != ';')
        {
            tab[j] = ft_strdup(argv[i]);
            i++;
            j++;
        }
        tab[j] = NULL;
        if (ft_searchpipe(tab) == 0)
            ft_one(tab, env);
        else
            ft_pipeline(tab, env);
        if (argv[i] != NULL)
            i++;
    }
    return (0);
}

