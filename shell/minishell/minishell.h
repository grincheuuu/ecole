/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:48:28 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/25 16:56:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list_cmd
{
	char	*cmd;
	char	*type;
	struct s_list_cmd	*before;
	struct s_list_cmd	*next;
}	t_cmd;

typedef struct	s_control_cmd
{
	struct s_list_cmd	*first;
	struct s_list_cmd	*end;
}	t_pointer_cmd;

typedef struct	s_list
{
	char	*str;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

typedef struct	s_control
{
	struct s_list	*first;
	struct s_list	*end;
}	t_pointer;

void	ft_printlist(t_pointer *pointerA);
int		main(int argc, char **argv, char **env);
int		ft_test_var(char *var, t_pointer *pointera, char ***tab);
int		ft_search_var(t_pointer *pointera, char *var);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_init_maillon_cmd(char **argv);
void	ft_init(t_pointer *pointerA);
void	ft_affect(t_list *pile_a, t_pointer *pointera);
void	ft_lstadd_back(t_list **chaine, t_list *new);
void	ft_lstclear(t_list **chaine);
int		ft_export(char *str, t_list *env_list, t_pointer *pointera);
void	ft_maillon_change(t_pointer *pointera, int i, char *var);
void	ft_malloc_error(char **dest, size_t n);
void	ft_fre(char **patch);
void	ft_putstr_fd(char *s, int fd);
void	ft_unset(t_pointer *pointera, char *var);
void    ft_unset_error(char *var, t_list *env_list, t_pointer *pointera);
void    ft_free_maillon(t_pointer *pointera, int i);
void	ft_export_error(char *var, t_list *env_list, t_pointer *pointera, char ***tab);
void	ft_analyse_arg(int argc, char **argv, t_list *env_list, t_pointer *pointera);
void    ft_pwd(t_list *env_list, t_pointer *pointera);
void    ft_failure(t_list *env_list, t_pointer *pointera);
void	ft_putstr_fd(char *s, int fd);
void	ft_cd(char *str, t_list *env_list, t_pointer *pointera, int argc);
void    ft_exit_success(t_pointer *pointera);
void	ft_only_cd(t_pointer *pointera, char *var, int argc);
void    ft_cmd_exit(char *gv, char *next, t_pointer *pointera);
void	ft_atol_test(char *gv, t_pointer *pointera);
void    ft_exit_failure(t_pointer *pointera, unsigned int n);
void    ft_free_node_cmd(t_cmd *node);
void	ft_lstclear_node(t_cmd **chaine);
void	ft_printlist_cmd(t_pointer_cmd *pointerB);
void	ft_lstadd_back_cmd(t_cmd **chaine, t_cmd *new);
void    ft_print_tab(char **env_tab);
void	ft_export_only(t_pointer *pointera);
void    sigint_handler(int signal);
void    set_signal(void);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *str);
int 	ft_init_maillon_cmd(char **argv);
long	ft_atol(const char *nptr);
t_list	*ft_maillonlist(char **env);
t_list	*ft_lstnew(char *str);
t_cmd	*ft_maillonlist_cmd(char **argv);
t_cmd	*ft_lstnew_cmd(char ***str);
size_t	ft_nbparts(char const *s, char c);
size_t	ft_count_chr(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, const char *src);
char    *ft_search_home(t_pointer *pointera, char *var);
char    *ft_prompt(t_list *env_list, t_pointer *pointera);
char	*ft_initialize_shell(t_list *env_list, t_pointer *pointera);
char	**ft_transform_env_list(t_pointer *pointera);
char	*ft_valeur_var(char *var, t_pointer *pointera);
char	*ft_search_var_deux(t_pointer *pointera, char *var);

#endif