ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRC = ft_malloc.c\
		main.c\

INC_FILE = libft_malloc.h

OBJ = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -fPIC -g

LIBFT = ./libft/libft.a


NAME = libft_malloc_$(HOSTTYPE).so

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -shared -o $(NAME) $(OBJ) $(LIBFT)
	mkdir -p exec_lien_symbolique
	ln -sf ../$(NAME) exec/libft_malloc.so
	
$(LIBFT):
	$(MAKE) -C ./libft

%.o : %.c
	$(CC) $(CCFLAGS) -I. -c $< -o $@

clean :
	rm -rf $(OBJ)
	make -C ./libft clean

fclean : clean
	rm -rf $(NAME) $(LIBFT)
	make -C ./libft fclean
	echo clean complete

re: fclean all

.phony: clean fclean all re