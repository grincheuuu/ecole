SRCS_L =	libft/ft_atoi.c\
			libft/ft_bzero.c\
			libft/ft_calloc.c\
			libft/ft_isalnum.c\
			libft/ft_isalpha.c\
			libft/ft_isascii.c\
			libft/ft_isdigit.c\
			libft/ft_isprint.c\
			libft/ft_itoa.c\
			libft/ft_lstadd_back.c\
			libft/ft_lstadd_front.c\
			libft/ft_lstclear.c\
			libft/ft_lstdelone.c\
			libft/ft_lstiter.c\
			libft/ft_lstlast.c\
			libft/ft_lstmap.c\
			libft/ft_lstnew.c\
			libft/ft_lstsize.c\
			libft/ft_memccpy.c\
			libft/ft_memchr.c\
			libft/ft_memcmp.c\
			libft/ft_memcpy.c\
			libft/ft_memmove.c\
			libft/ft_memset.c\
			libft/ft_putchar_fd.c\
			libft/ft_putendl_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_split.c\
			libft/ft_strchr.c\
			libft/ft_strdup.c\
			libft/ft_striteri.c\
			libft/ft_strjoin.c\
			libft/ft_strlcat.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_strmapi.c\
			libft/ft_strncmp.c\
			libft/ft_strnstr.c\
			libft/ft_strrchr.c\
			libft/ft_strtrim.c\
			libft/ft_substr.c\
			libft/ft_tolower.c\
			libft/ft_toupper.c\
			libft/ft_tab_size.c\
			libft/ft_free_tab.c\

FUNC =	src/get_next_line.c\
		src/lem-in.c\
		src/parsing.c\
		src/parsing_utils.c\
		src/utils.c\
		src/abre.c\
		src/init.c\

FUNC_BONUS_VIZU =	src/get_next_line.c\
					src_bonus/parsing_bonus.c\
					src/parsing_utils.c\
					src_bonus/vizu-hex.c\
					src/utils.c\
					src_bonus/make_background.c\
					src_bonus/vizu-hex_utils.c\

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

# Normal
NAME = lem-in
NAME_BONUS_VIZU = vizu-hex


OBJ = $(patsubst srcs/%.c, obj/%.o, $(FUNC))
OBJ_BONUS_VIZU = $(patsubst srcs_bonus_vizu/%.c, obj_bonus_vizu/%.o, $(FUNC_BONUS_VIZU))


# Mlx
MLX_PATH = ./mlx/
MLX_FLAGS = -lX11 -lXext -lm
MLX_LIB = mlx/libmlx_Linux.a

HEADER_LIB = libft/libft.h
HEADER = include/lem-in.h
HEADER_BONUS = include/vizu_hex.h
# Compil
all: 	${NAME}

bonus: ${NAME} ${NAME_BONUS_VIZU}


$(OBJ): ${HEADER} $(HEADER_LIB)

$(OBJ_BONUS_VIZU): ${HEADER} ${HEADER_BONUS} $(HEADER_LIB)




${NAME}: $(LIBFT) ${OBJ}
	${CC} ${OBJ} $(LIBFT) $(CFLAGS) -o $(NAME)

${NAME_BONUS_VIZU}: $(LIBFT) ${OBJ_BONUS_VIZU}
	make -C $(MLX_PATH) --no-print-directory
	${CC} ${OBJ_BONUS_VIZU} $(LIBFT) $(MLX_LIB) $(CFLAGS) $(MLX_FLAGS) -o $(NAME_BONUS_VIZU)


$(LIBFT): $(HEADER_LIB) $(SRCS_L)
	@echo "\n==> Making LIBFT"
	make -C ./libft


obj_bonus/%.o: src_bonus/%.c
	@mkdir -p obj_bonus/
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c $< -o $@


clean:	
	rm -rf obj
	rm -rf obj_bonus
	rm -rf obj_bonus_vizu
	@make -C ./libft clean
	@make clean -C ${MLX_PATH} --no-print-directory

fclean:	clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}
	rm -f ${NAME_BONUS_VIZU}
	@make -C ./libft fclean
	@make clean -C ${MLX_PATH} --no-print-directory

re:	fclean all

.PHONY: all clean fclean re bonus
