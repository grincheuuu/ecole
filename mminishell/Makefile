# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:14:59 by tlegendr          #+#    #+#              #
#    Updated: 2024/06/30 15:40:24 by tlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c signal.c ft_split.c error_handling.c  cmd_env.c list.c cmd_export.c fonction.c cmd_unset.c cmd_pwd.c cmd_cd.c ft_exec.c cmd_exit.c init_chaine_cmd.c signaux.c pipexm/pipex_bonus.c pipexm/pipex_projet_bonus.c pipexm/pipex_utils_bonus.c pipexm/pipex_func_bonus.c pipexm/pipex_plus_bonus.c pipexm/pipex_gnl_bonus.c pipexm/pipex_pipes_bonus.c pipexm/pipex_heredoc_bonus.c pipexm/pipex_struct_bonus.c pipexm/pipex_utils_second.c pipexm/pipex_bonus_ajout.c cmd_echo.c ft_itoa.c  pipexm/pipex_addition_one.c pipexm/pipex_attribut.c pipexm/pipex_minishell_ajout.c pipexm/pipex_minishell_generate_argv.c pipexm/pipex_minishell_generate.c pipexm/pipex_pipes_ome.c pipexm/pipex_plus_plus_pipe.c pipexm/pipex_minishell_pipe.c pipexm/pipex_mini_ajout.c
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
