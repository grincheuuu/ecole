# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:14:59 by tlegendr          #+#    #+#              #
#    Updated: 2024/07/03 13:43:08 by tlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c signal.c ft_split.c error_handling.c  cmd_env.c list.c cmd_export.c fonction.c cmd_unset.c cmd_pwd.c cmd_cd.c ft_exec.c cmd_exit.c init_chaine_cmd.c signaux.c \
pipexm/pipex_bonus.c pipexm/pipex_projet_bonus.c pipexm/pipex_utils_bonus.c pipexm/pipex_func_bonus.c pipexm/pipex_plus_bonus.c pipexm/pipex_gnl_bonus.c pipexm/pipex_pipes_bonus.c pipexm/pipex_heredoc_bonus.c pipexm/pipex_struct_bonus.c pipexm/pipex_utils_second.c pipexm/pipex_bonus_ajout.c cmd_echo.c ft_itoa.c  pipexm/pipex_addition_one.c pipexm/pipex_attribut.c pipexm/pipex_minishell_ajout.c pipexm/pipex_minishell_generate_argv.c pipexm/pipex_minishell_generate.c pipexm/pipex_pipes_ome.c pipexm/pipex_plus_plus_pipe.c pipexm/pipex_minishell_pipe.c pipexm/pipex_mini_ajout.c \
utils/clean_utils.c utils/handle_utils.c utils/is_check.c utils/fd_utils.c utils/list_utils.c utils/list_utils_2.c utils/var_env_utils.c utils/handle_split.c utils/main_utils.c pipexm/pipex_add_deux.c pipexm/pipex_pipe_bonus.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I/usr/include 
LDFLAGS = -lm -lz -lreadline

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
