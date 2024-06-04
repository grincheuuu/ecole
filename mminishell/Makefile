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

SRCS = cmd_env list cmd_export fonction splitt cmd_unset cmd_pwd cmd_cd ft_exec cmd_exit main_minishell init_chaine_cmd cmd_valeur_var signaux pipexm/pipex_bonus pipexm/pipex_projet_bonus pipexm/pipex_utils_bonus pipexm/pipex_func_bonus pipexm/pipex_plus_bonus pipexm/pipex_gnl_bonus pipexm/pipex_pipes_bonus pipexm/pipex_heredoc_bonus pipexm/pipex_struct_bonus pipexm/pipex_utils_second pipexm/pipex_bonus_ajout cmd_echo ft_itoa

INC_FILES = minishell.h pipex/pipex_bonus.h

SRC = $(addsuffix .c,$(SRCS))
SRC_BONUS = $(addsuffix .c,$(SRCS_BONUS))
OBJS = $(addsuffix .o,$(SRCS))
OBJS_BONUS = $(addsuffix .o,$(SRCS_BONUS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
