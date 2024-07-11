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

SRCS = pipex_bonus.c pipex_projet_bonus.c pipex_utils_bonus.c pipex_func_bonus.c pipex_plus_bonus.c pipex_gnl_bonus.c pipex_pipes_bonus.c pipex_heredoc_bonus.c pipex_struct_bonus.c pipex_utils_second.c pipex_bonus_ajout.c

INC_FILES = pipex_bonus.h

OBJS = pipex_bonus.o pipex_projet_bonus.o pipex_utils_bonus.o pipex_func_bonus.o pipex_plus_bonus.o pipex_gnl_bonus.o pipex_pipes_bonus.o pipex_heredoc_bonus.o pipex_struct_bonus.o pipex_utils_second.o pipex_bonus_ajout.o

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
