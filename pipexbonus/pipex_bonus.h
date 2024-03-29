/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:52:23 by gschwart          #+#    #+#             */
/*   Updated: 2024/02/23 16:33:14 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <assert.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

size_t		ft_count_chr(char const *s, char c);
void		ft_malloc_error(char **dest, size_t n);
void		ft_fre(char **patch);
void		ft_error(int n, const char *str);
void		ft_exe(char **patch, int t, char *argv, char **env);
void		ft_un(int *pipe_fd, char **argv, char **env);
void		ft_family(char *argv, char **env, int *pipe_fd);
void		ft_last(int argc, char **argv, char **env, int *pipe_fd);
char		**ft_testpath(char **result, char *argv);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		**ft_path(char **env);
char		*ft_strcpyy(char *env, char *dest, char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_nbparts(char const *s, char c);
int			ft_strncmp(char *env, char *str, int nb);
int			ft_strlenn(char *env, char *str);
int			main(int argc, char **argv, char **env);
int			ft_strlen(char *env);
void		ft_gnl(char *str);
int			ft_heredoc(char **argv, char **env);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);

#endif
