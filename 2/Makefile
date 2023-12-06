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
NAME = libftprintf.a

SRCS = ft_print_char.c ft_printf.c ft_print_hex.c ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_unsigned.c

INC_FILES = includes/ft_printf.h

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS) $(INC_FILES)
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re libft
