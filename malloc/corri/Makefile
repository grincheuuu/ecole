ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRC = ft_malloc.c\
		ft_free.c\
		ft_realloc.c\
		ft_show.c\
		ft_utils.c\

INC_FILE = libft_malloc.h

OBJ = $(SRC:.c=.o)

CC = cc -pthread
CCFLAGS = -Wall -Wextra -Werror -fPIC -g

LIBFT = ./libft/libft.a


NAME = libft_malloc_$(HOSTTYPE).so

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -shared -o $(NAME) $(OBJ) $(LIBFT)
	ln -sf $(NAME) libft_malloc.so

%.o : %.c
	$(CC) $(CCFLAGS) -I. -c $< -o $@

clean :
	rm -rf $(OBJ)
	make -C ./libft clean

fclean : clean
	rm -rf $(NAME) $(LIBFT) libft_malloc.so
	make -C ./libft fclean
	echo clean complete

re: fclean all

.phony: clean fclean all re