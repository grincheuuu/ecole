# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschwart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:34:06 by gschwart          #+#    #+#              #
#    Updated: 2023/11/13 18:18:27 by gschwart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = minishell

PIPEX = ./pipex_minishell/pipex

SRCS = cmd_env list cmd_export fonction splitt cmd_unset cmd_pwd cmd_cd ft_strjoin cmd_exit main init_chaine_cmd cmd_valeur_var signaux

INC_FILES_P = pipex_minishell/pipex_bonus.h
INC_FILES = minishell.h

SRC = $(addsuffix .c,$(SRCS))
SRC_BONUS = $(addsuffix .c,$(SRCS_BONUS))
OBJS = $(addsuffix .o,$(SRCS))
OBJS_BONUS = $(addsuffix .o,$(SRCS_BONUS))

all: $(NAME)

$(OBJS): $(INC_FILES) $(INC_FILES_P)

$(NAME): $(PIPEX) $(OBJS)
	$(CC) $(CFLAGS) -lreadline $(OBJS) $(PIPEX) -o $(NAME)

$(PIPEX): $(INC_FILES_P) $(SRCS_P)
	make -C ./pipex_minishell

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	$(RM) $(OBJS)
	make -C ./pipex_minishell clean
fclean: clean
	$(RM) $(NAME)
	make -C ./pipex_minishell fclean
re: fclean all

.PHONY: all clean fclean re
