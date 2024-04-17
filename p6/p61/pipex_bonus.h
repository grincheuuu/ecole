/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:52:23 by gschwart          #+#    #+#             */
/*   Updated: 2024/03/20 14:31:10 by gschwart         ###   ########.fr       */
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
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

typedef struct s_listpipe
{
	int					file_fd;
	int					pid;
	int					pipe_fd[2];
	int					status;
	struct s_listpipe	*before;
	struct s_listpipe	*next;
}	t_listp;

typedef struct s_cont
{
	t_listp	*first;
	t_listp	*end;
}	t_pointer;

size_t		ft_count_chr(char const *s, char c);
void		ft_malloc_error(char **dest, size_t n);
void		ft_fre(char **patch);
void		ft_error(int n, const char *str);
void		ft_exe(char **patch, int t, char *argv, char **env);
void		ft_un(char **argv, char **env,
				t_listp **listp, t_pointer *pointer);
void		ft_mid(char *argv, char **env,
				t_listp **listp, t_pointer *pointer);
int			ft_last(int argc, char **argv, char **env, t_listp **listp);
void		ft_lstclear(t_listp **chaine);
void		ft_lstadd_back(t_listp **chaine, t_listp *new);
int			ft_pipeline(int argc, char **argv, char **env, int i);
int			ft_wait(t_pointer *pointerA);
void		ft_clean_all(char **patch, t_pointer *pointer);
void		ft_clean_final(t_pointer *pointer, int j);
char		**ft_testpath(char **result, char *argv);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		**ft_path(char **env);
char		*ft_after(char *save);
char		*ft_tronc(char *save);
char		*ft_read_and_save(int fd, char *save);
char		*ft_strcpyy(char *env, char *dest, char *str);
char		*ft_arg(char *argv);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_nbparts(char const *s, char c);
int			ft_strncmp(char *env, char *str, int nb);
int			ft_strlenn(char *env, char *str);
int			main(int argc, char **argv, char **env);
int			ft_strlen(char *env);
int			ft_file(char *argv);
int			ft_error_deux(int n, const char *str);
void		ft_test_file_fd(char *argv, t_pointer *pointer);
void		ft_gnl(char *str);
void		ft_thor(char *argv);
void		ft_execve_error(int n, const char *str, char ***thor, char ***com);
void		ft_free_last(char **patch);
int			ft_heredoc(char **argv, char **env);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strjoined(char *s1, char *s2);
char		**ft_testpatch_suite(int t, int i, char **result, char *temp);
t_listp		*ft_lstnew(void);
t_listp		*ft_maillon(t_listp *listp, t_pointer *pointerA);
t_listp		*ft_parent_un(t_listp **listp, t_pointer *pointer);
t_pointer	*ft_pointer_init(t_listp *listp);

#endif
