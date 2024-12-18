NAME	= cub3D
CFLAGS  = -Wextra -Wall -Ofast -g
LIBMLX	= minilibx-linux
LIBS	= -L$(LIBMLX) -lmlx -lX11 -lXext -lm
HEADERS	= -I ./include -I $(LIBMLX)
CC      = cc
MAKE    = make

SRCS = src/main \
		src/utils/get_next_line_utils \
		src/utils/get_next_line \
		src/texture \
		src/init/ft_init \
		src/event/ft_event \
		src/utils/gnl \
		src/raycasting/distance

SRC = $(addsuffix .c,$(SRCS))
OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBMLX)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
