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
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = pipex.c pipex_projet.c pipex_utils.c pipex_func.c pipex_plus.c pipex_suite.c

SRCS_BONUS = pipex_bonus.c pipex_projet_bonus.c pipex_utils_bonus.c pipex_func_bonus.c pipex_plus_bonus.c pipex_gnl_bonus.c pipex_pipes_bonus.c pipex_heredoc_bonus.c pipex_struct_bonus.c pipex_utils_second.c pipex_bonus_ajout.c


INC_FILES = pipex.h

INC_FILES_BONUS = pipex_bonus.h

OBJS = pipex.o pipex_projet.o pipex_utils.o pipex_func.o pipex_plus.o pipex_suite.o

OBJS_BONUS = pipex_bonus.o pipex_projet_bonus.o pipex_utils_bonus.o pipex_func_bonus.o pipex_plus_bonus.o pipex_gnl_bonus.o pipex_pipes_bonus.o pipex_heredoc_bonus.o pipex_struct_bonus.o pipex_utils_second.o pipex_bonus_ajout.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
re: fclean all bonus

.PHONY: all clean fclean re
