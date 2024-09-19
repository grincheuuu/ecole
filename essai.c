#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

typedef struct  s_listp
{
    int pid;
    int pipe_fd[2];
    int status;
    struct s_listp  *next;
    struct s_listp  *before;
}   t_listp;

typedef struct  s_pointer
{
    t_listp *first;
}   t_pointer;

t_listp *ft_new(void);
int ft_pipeline(int argc, char **argv, char **env, char **temp);
void    ft_un(char *argv, t_listp **listp, t_pointer *pointera, char **env, char **temp);
void    ft_mid(char *argv, t_listp **listp, t_pointer *pointera, char **temp);
t_listp  *ft_maillon(t_listp *listp, t_pointer *pointera);
void    ft_fre(char **com);
void    ft_lstclear(t_listp **listp);
void    ft_last(char *argv, t_listp **listp, t_pointer *pointera, char **env, char **temp);
int ft_wait(t_pointer *pointera);
char    **split(char *str, char del);
int ft_one(char *argv, char **env, char **temp);
int search_pipe(char *temp);

int main(int argc, char **argv, char **env)
{
    int status;
    int i;
    char    *str;
    char    **temp;
    char    **pi;

    status = 0;
    i = 1;
    temp = NULL;
    pi = NULL;
    str = strdup("");
    if (argc == 1)
    {
        write (2, "please enter a command or list of command separated bye | or ;\n", 63);
        free(str);
        exit (EXIT_FAILURE);
    }
    while (argv[i] != NULL)
    {
        printf(" ");
        str = strcat(str, argv[i]);
        i++;
    }
//    printf("str %s \n", str);
    temp = split(str, ';');
    free(str);
    i = 0;
    while (temp[i] != NULL)
    {
//        printf("AA temp %s\n", temp[i]);
        if (search_pipe(temp[i]) == 1)
        {
//            printf("B temp[i] %s\n\n", temp[i]);
            status = ft_one(temp[i], env, temp);
        }
        else
        {
//            printf("A temp[i] %s\n\n", temp[i]);
            pi = split(temp[i], '|');
            status = ft_pipeline(argc, pi, env, temp);
            pi = NULL;
        }
        i++;
    }
    ft_fre(temp);
    exit (status);
    return (0);
}

int search_pipe(char *temp)
{
    int i;

    i = 0;
    while (temp[i] != '\0')
    {
        if (temp[i] == '|')
            return (0);
        i++;
    }
    return (1);
}

int ft_one(char *argv, char **env, char **temp)
{
    int status;
    int pipe_fd[2];
    int pid;
    char    **com;

    com = NULL;
    pid = fork();
    if (pid == 0)
    {
        com = split(argv, ' ');
        if (access(com[0], F_OK | X_OK) == 0)
        {
            execve(com[0], com, env);
        }
        ft_fre(com);
        ft_fre(temp);
        write(2, "error", 5);
        exit(EXIT_FAILURE);
    }
    waitpid(pid, &status, 0);
    return (status); 
}

t_listp *ft_new(void)
{
    t_listp *new_node;

    new_node = (t_listp *)malloc(sizeof(t_listp));
    if (new_node == NULL)
        return (NULL);
    new_node->pid = 0;
    new_node->status = 0;
    new_node->next = NULL;
    new_node->before = NULL;
    return (new_node);
}

int ft_pipeline(int argc, char **argv, char **env, char **temp)
{
    int i;
    int j;
    int status;
    t_listp  *listp;
    t_pointer   *pointera;
    char    **str;

    i = 0;
    j = 0;
    str == NULL;
    status = 0;
    listp = ft_new();
//    printf(" pi %s j %d\n", argv[j], j);
    while (argv[j] != NULL)
    {
        j++;
//        printf(" pi %s j %d\n", argv[j], j);
    }
    pointera = (t_pointer *)malloc(sizeof(t_pointer));
    if (pointera == NULL)
        return (0);
    pointera->first = listp;
    while (argv[i] != NULL)
    {
        pipe(listp->pipe_fd);
        listp->pid = fork();
        if (i == (j - 1))
            ft_last(argv[i], &listp, pointera, env, temp);
        else if (i == 0)
            ft_un(argv[i], &listp, pointera, env, temp);
        else
            ft_mid(argv[i], &listp, pointera, temp);
        i++;
    }
    status = ft_wait(pointera);
    ft_lstclear(&pointera->first);
    free(pointera);
    return (status);
}

int ft_wait(t_pointer *pointera)
{
    t_listp *temp;
    int status;

    temp = pointera->first;
    status = 0;
    while (temp != NULL)
    {
        close(temp->pipe_fd[0]);
        waitpid(temp->pid, &temp->status, 0);
        status = temp->status;
        temp = temp->next;
    }
    return (status);
}

void    ft_un(char *argv, t_listp **listp, t_pointer *pointera, char **env, char **temp)
{
    char    **com;

//    printf(" un %s \n", argv);
    com = split(argv, ' ');
    if ((*listp)->pid == 0)
    {
        dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
        close((*listp)->pipe_fd[0]);
        close((*listp)->pipe_fd[1]);
        if (access(com[0], F_OK | X_OK) == 0)
            execve(com[0], com, env);
        ft_fre(com);
        ft_fre(temp);
        ft_lstclear(&pointera->first);
        free(pointera);
        write (2, "error commande 1\n", 17);
        exit (EXIT_FAILURE);
    }
    else
    {
        close((*listp)->pipe_fd[1]);
        *listp = ft_maillon(*listp, pointera);
    }

}

void    ft_mid(char *argv, t_listp **listp, t_pointer *pointera, char **temp)
{
    char    **com;
    
//    printf(" mid \n");
    com = split(argv, ' ');
    if((*listp)->pid == 0)
    {
        dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
        close((*listp)->before->pipe_fd[0]);
        dup2((*listp)->pipe_fd[1], STDOUT_FILENO);
        close((*listp)->pipe_fd[0]);
        close((*listp)->pipe_fd[1]);
        if (access(com[0], F_OK | X_OK) == 0)
            execve(com[0], com, NULL);
        ft_fre(com);
        ft_fre(temp);
        ft_lstclear(&pointera->first);
        free(pointera);
        write (2, "error commande ?\n", 17);
        exit (EXIT_FAILURE);
    }
    else
    {
        close((*listp)->before->pipe_fd[0]);
        close((*listp)->pipe_fd[1]);
        *listp = ft_maillon(*listp, pointera);
    }
}

void    ft_last(char *argv, t_listp **listp, t_pointer *pointera, char **env, char **temp)
{
    char    **com;

    printf(" last %s \n", argv);
    close((*listp)->pipe_fd[0]);
    close((*listp)->pipe_fd[1]);
    com = split(argv, ' ');
    if ((*listp)->pid == 0)
    {
        dup2((*listp)->before->pipe_fd[0], STDIN_FILENO);
        close((*listp)->before->pipe_fd[0]);
        if (access(com[0], F_OK | X_OK) == 0)
            execve(com[0], com, env);
        ft_fre(temp);
        ft_lstclear(&pointera->first);
        free(pointera);
        write (2, "error commande final\n", 22);
        exit (EXIT_FAILURE);
    }
    else
    {
        close((*listp)->before->pipe_fd[0]);
    }
    
}

t_listp  *ft_maillon(t_listp *listp, t_pointer *pointera)
{
    t_listp *new;
    t_listp *temp;

    temp = listp;
    new = ft_new();
    if (new == NULL)
    {
        ft_lstclear(&pointera->first);
        return (NULL);
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->before = temp;
    new->next = NULL;
    listp = listp->next;
    return (listp);
}

void    ft_fre(char **com)
{
    int i;

    if (com == NULL)
        return ;
    while (com[i] != NULL)
    {
        free(com[i]);
        i++;
    }
    free(com);
}

void    ft_lstclear(t_listp **listp)
{
    t_listp *current;
    t_listp *second;

    current = *listp;
    if (current == NULL)
        return;
    while (current != NULL)
    {
        second = current->next;
        free(current);
        current = second;
    }
    *listp = NULL;
}

char    **split(char *str, char del)
{
    int i;
    int g;
    int j;
    int v;
    int z;
    char    **dest;

    i = 0;
    j = 0;
    g = 0;
    v = 0;
    dest = NULL;
    if (str == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        if(str[i] == del)
        {
            while (str[i] != '\0' && str[i] == del)
                i++;
            j++;
        }
        i++;
    }
    dest = (char **)malloc((j + 1 + 1) * sizeof(char *));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (g <= j)
    {
        v = 0;
        while (str[i] != '\0' && str[i] == del)
            i++;
        z = i;
        while (str[i] != '\0' && str[i] != del)
            i++;
        dest[g] = malloc((i - z + 1) * sizeof(char));
        if (dest[g] == NULL)
            return (NULL);
        while (z < i)
        {
            dest[g][v] = str[z];
            v++;
            z++;
        }
        dest[g][v] = '\0';
        g++;
    }
    dest[g] = NULL;
    return (dest);
}