/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:39:15 by gschwart          #+#    #+#             */
/*   Updated: 2024/07/08 17:18:31 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "pipexm/pipex_bonus.h"
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

extern int		g_signal;

void			putstr_fd(char *str, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				parse_line(char *line, t_pointer **pointera);
int				ft_strlen(const char *string);
char			*ft_substr_parsing(t_parsing *parsing);
int				check_for_errors(char *line);

void			ft_printlist(t_pointer *pointerA);
int				ft_test_var(char *var, t_pointer **pointera);
int				ft_search_var(t_pointer *pointera, char *var);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			ft_init(t_pointer *pointerA);
void			ft_affect(t_list *pile_a, t_pointer *pointera);
void			ft_lstadd_back_bis(t_list **chaine, t_list *new);
void			ft_maillon_change(t_pointer **pointera, int i, char *var);
int				ft_unset_error(char *var);
int				ft_unset_deux(char *var, t_list *temp, t_pointer **pointera);
void			ft_free_maillon(t_pointer **pointera, int i);
void			ft_export_error(char *var);
void			ft_failure(t_pointer **pointera);
void			ft_exit_success(t_pointer **pointera, t_pointer_cmd *pointerB,
					char **str);
void			ft_only_cd(t_pointer **pointera, char *var);
void			ft_exit_failure(t_pointer **pointera, t_pointer_cmd *pointerB,
					unsigned int n, char **str);
void			ft_free_node_cmd(t_lexing *node);
void			ft_lstadd_back_cmd(t_cmd **chaine, t_cmd *new);
int				ft_export_only(t_pointer *pointera);
void			sigint_handler(int signal);
void			set_signal(void);
void			ft_bzero(void *s, size_t n);
int				ft_exec(t_pointer **pointera, t_pointer_cmd *pointerB);
void			ft_realize_oldpwd(char *old_pwd, t_pointer **pointera);
void			ft_lstadd_back_bis_pointer(t_pointer **pointera, t_list *new);
void			ft_lstclear_bis_pointera(t_pointer **pointera);
int				ft_dollar(char *option, t_pointer **pointera, int status);
void			ft_space(char **option);
char			*ft_itoa(int n);
char			*ft_old_pwd(void);
int				ft_search_option_echo(char **option);
int				ft_cd_moin(t_pointer **pointera);
long			ft_atol(const char *nptr);
t_pointer_cmd	*ft_init_maillon_cmd(char **argv);
t_list			*ft_maillonlist(char **env);
t_list			*ft_lstnew_bis(char *str);
t_cmd			*ft_maillonlist_cmd(char **argv);
t_cmd			*ft_lstnew_cmd(char ***str);
char			*ft_search_home(t_pointer *pointera, char *var);
char			*ft_initialize_shell(t_list *env_list, t_pointer *pointera);
char			**ft_create_pipex(t_pointer_cmd *pointerb);
void			ft_putstr_fd(char *s, int fd);
char			*ft_prompt(t_pointer *pointera);
int				ft_atoi_test(char *gv);
char			*ft_export_moin(t_pointer **pointera, int i);
void			ft_export_plus(t_pointer **pointera);
int				ft_atoi(const char *nptr);
int				ft_cd_tilde(t_pointer **pointera, char *str);
void			ft_chdir_error(char *str, char *old_pwd);
void			ft_chdir_success(char *old_pwd, t_pointer **pointera);
void			ft_unset_trois(char *var, t_list *temp, t_pointer **pointera);
int				ft_test_var_deux(char *var, int i, int t, t_pointer **pointera);
void			ft_shlvl(t_pointer **pointera);

void			sig_exit_code(t_pointer **arg);

void			clean_table(t_lexing *cmd);
void			clear_garbage(t_garbage **garbage);
int				handling_sigint_handler(t_pointer **pointera, t_lexing *cmd);

void			putstr_fd(char *str, int fd);
void			ft_putstr_fd(char *s, int fd);
void			putnbr_fd(int n, int fd);

void			handle_redir_upper(t_lexing **tmp, char *line, t_parsing **par);
int				handle_redir_lower(t_lexing **tmp, char *line, t_parsing **par);
void			handle_standard_char_add(t_lexing **tmp, t_parsing **parsing);
void			handle_get_status(t_lexing **tmp, t_pointer **pointera, int *i,
					int *token);
void			handle_get_envvar(t_lexing **tmp, char *line,
					t_parsing **parsing, t_pointer **pointera);

int				is_blank(char c);
int				ft_isalnum(char c);
int				is_authorized_for_env_char(char c);

t_lexing		*add_to_list(t_lexing *tmp, char *cmd,
					t_addlist_token *addlist_token, t_addlist *addlist);
void			handle_quote_add(t_lexing **tmp, t_parsing **par,
					t_pointer **poina, int len);
char			*extract_next_word(char *line, int *i, t_parsing **parsing,
					int hd_case);
t_lexing		*merge_and_add(t_lexing *tmp2, t_lexing *cmd,
					t_lexing **updated_cmd);
int				merge_and_run(t_lexing *cmd, t_pointer **pointera);
t_lexing		*merge_nearby_word(t_lexing *cmd);

char			*ft_search_home(t_pointer *pointera, char *var);
char			*ft_search_env_var(t_pointer *pointera, char *var);
void			ft_shlvl(t_pointer **pointera);

char			*ft_prompt(t_pointer *pointera);
int				prompt(t_pointer **pointera);
char			*process_heredoc(char *delimiter, int index);

int				handle_special_case(t_parsing *parsing, int is_hd);

t_addlist		*bstruct(int index, int full_len, int special_token);
t_addlist_token	*bstructtok(int token, int next_token, int *token_var);

void			handle_env_variable(char **tmp_cmd, t_parsing **par,
					t_pointer **pointera, int *len);
void			handle_status_variable(char **tmp_cmd, int *i,
					t_pointer **pointera, int *len);
void			handle_else_part(char **tmp_cmd, t_parsing **par, int *len);
void			handle_quote_add(t_lexing **tmp, t_parsing **par,
					t_pointer **poina, int len);

void			handle_special_cases(t_parsing **par, char *line, char **value);
void			handle_redirlow_part(t_lexing **tmp, t_parsing **par);

int				handle_heredoc_input(int fd, char *delimiter);
void			handle_dollar(char *line, t_parsing **par, t_lexing **tmp,
					t_pointer **pointera);
int				process_line_chars(char *line, t_parsing **par, t_lexing **tmp,
					t_pointer **pointera);
int				handle_input(t_pointer **pointera, t_garbage **garbage);
char			*get_prompt_home(t_pointer *pointera, char *buffer);

int				check_if_heredoc_valid(t_lexing *tmp);

void			set_signal_handlers_for_heredoc(struct sigaction *sig_int,
					struct sigaction *sig_quit);
int				check_syntax_errors(char *line, int *in_quote);

void			sig_readline(int sig);
void			sig_cmd(int sig);
void			sig_heredoc(int sig);
void			sig_exit_code(t_pointer **arg);
void			change_signal(int param);

int				if_whitespace(char c);
int				pipe_usage_error(char *line);
int				redirection_error(char *line);
int				is_in_quote(char c, int *is_in_quote);
int				check_for_errors(char *line);

t_lexing		*init_tmp(t_lexing *cmd);
void			ft_tmp2(t_lexing **tmp2);
void			ft_cmdcmd(char **new_cmd, char **tmp_cmd, t_lexing **cmd);
void			ft_extract_next_word_deux(t_parsing **par, char *line, int **i);
char			*ft_extract_next_word_trois(char **word, char **tmp,
					char **tmp2);
void			ft_extract_next_word_quatre(t_parsing **par, char *line,
					int **i, int hd_case);

void			ft_extract_next_word_deux(t_parsing **par, char *line, int **i);
char			*ft_extract_next_word_trois(char **word, char **tmp,
					char **tmp2);
void			ft_extract_next_word_quatre(t_parsing **par, char *line,
					int **i, int hd_case);
void			ft_cmdcmd(char **new_cmd, char **tmp_cmd, t_lexing **cmd);
void			ft_tmp2(t_lexing **tmp2);

char			*extract_next_word(char *line, int *i, t_parsing **par,
					int hd_case);
t_lexing		*merge_and_add(t_lexing *tmp2, t_lexing *cmd,
					t_lexing **updated_cmd);
t_lexing		*merge_escapenull(t_lexing *tmp2, t_lexing *cmd,
					t_lexing **updated_cmd);
int				redir_replace(t_lexing *cmd, t_pointer **pointera);

#endif
