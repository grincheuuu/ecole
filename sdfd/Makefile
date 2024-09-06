NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJ = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INCDIR = includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
