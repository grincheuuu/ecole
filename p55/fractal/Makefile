NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= minilibx-linux

HEADERS	:= -I ./include -I $(LIBMLX)
LIBS	:= $(LIBMLX)/libmlx.a -lX11 -lXext -lm
SRCS	:= $(shell find src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

BONUS	:= $(shell find bonus -iname "*_bonus.c")
OBJS_BONUS	:= ${BONUS:.c=.o}
NAME_BONUS := $(NAME)_bonus

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

 bonus: libmlx $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
