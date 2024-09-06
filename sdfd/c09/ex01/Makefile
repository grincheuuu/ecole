# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschwart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 11:29:47 by gschwart          #+#    #+#              #
#    Updated: 2023/08/29 20:27:24 by gschwart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a.

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
