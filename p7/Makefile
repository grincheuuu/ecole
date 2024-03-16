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
NAME = push_swap

SRCS = push_swap.c push_swap_init.c push_swap_mouv.c push_swap_mouvement.c push_swap_util.c push_swap_algorithm.c push_swap_suite.c push_swap_air.c push_swap_freya.c

INC_FILES = push_swap.h

OBJS = push_swap.o push_swap_init.o push_swap_mouv.o push_swap_mouvement.o push_swap_util.o push_swap_algorithm.o push_swap_suite.o push_swap_air.o push_swap_freya.o

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
