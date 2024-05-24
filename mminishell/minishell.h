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

# include "pipexm/pipex_bonus.h"
# include <stddef.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ft_printlist(t_pointer *pointerA);
int		main(int argc, char **argv, char **env);
int		ft_test_var(char *var, t_pointer **pointera);
int		ft_search_var(t_pointer *pointera, char *var);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_init(t_pointer *pointerA);
void	ft_affect(t_list *pile_a, t_pointer *pointera);
void	ft_lstadd_back_bis(t_list **chaine, t_list *new);
void	ft_lstclear_bis(t_list **chaine);
void	ft_maillon_change(t_pointer **pointera, int i, char *var);
void	ft_putstr_fd(char *s, int fd);
int     ft_unset_error(char *var);
int     ft_unset_deux(char *var, t_list *temp, t_pointer **pointera);
void    ft_free_maillon(t_pointer **pointera, int i);
void	ft_export_error(char *var, t_pointer **pointera);
void	ft_analyse_arg(int argc, char **argv, t_list *env_list, t_pointer *pointera);
void    ft_failure(t_pointer **pointera);
void	ft_putstr_fd(char *s, int fd);
void    ft_exit_success(t_pointer **pointera, t_pointer_cmd *pointerB, char **str, char **env);
void	ft_only_cd(t_pointer **pointera, char *var);
void	ft_atol_test(char *gv, t_pointer **pointera, t_pointer_cmd *pointerB, char **str);
void    ft_exit_failure(t_pointer **pointera, t_pointer_cmd *pointerB, unsigned int n, char **str);
void    ft_free_node_cmd(t_cmd *node);
void	ft_lstclear_node(t_cmd **chaine);
void	ft_printlist_cmd(t_pointer_cmd *pointerB);
void	ft_lstadd_back_cmd(t_cmd **chaine, t_cmd *new);
void    ft_print_tab(char **env_tab);
void	ft_export_only(t_pointer *pointera);
void    sigint_handler(int signal);
void    set_signal(void);
void	ft_bzero(void *s, size_t n);
void    ft_exec(int argc, char **argv, t_pointer **pointera, t_pointer_cmd *pointerB);
void    ft_test_dir(void);
void	ft_realize_oldpwd(char *old_pwd, t_pointer **pointera);
void	ft_lstadd_back_bis_pointer(t_pointer **pointera, t_list *new);
void	ft_lstclear_bis_pointera(t_pointer **pointera);
char    *ft_old_pwd(t_pointer **pointera);
int	    ft_search_option_echo(char **option);
long	ft_atol(const char *nptr);
t_pointer_cmd	*ft_init_maillon_cmd(char **argv);
t_list	*ft_maillonlist(char **env);
t_list	*ft_lstnew_bis(char *str);
t_cmd	*ft_maillonlist_cmd(char **argv);
t_cmd	*ft_lstnew_cmd(char ***str);
char    *ft_search_home(t_pointer *pointera, char *var);
char    *ft_prompt(t_list *env_list, t_pointer *pointera);
char	*ft_initialize_shell(t_list *env_list, t_pointer *pointera);
char	**ft_transform_env_list(t_pointer **pointera);
char    **ft_create_pipex(t_pointer_cmd *pointerb);
char	*ft_valeur_var(char *var, t_pointer *pointera);
char	*ft_search_var_deux(t_pointer *pointera, char *var);

#endif
