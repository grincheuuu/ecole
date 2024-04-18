NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= minilibx-linux
NAME_BONUS := $(NAME)_bonus
HEADERS	:= -I ./include -I $(LIBMLX)
LIBS	:= $(LIBMLX)/libmlx.a -lX11 -lXext -lm

SRCS = src/fractol src/fractol_event src/fractol_init src/fractol_render

SRCS_BONUS = bonus/fractol_bonus bonus/fractol_event_bonus bonus/fractol_init_bonus bonus/fractol_render_bonus

INC_FILES = fractol.h

INC_FILES_BONUS = fractol_bonus.h

SRC = $(addsuffix .c,$(SRCS))
SRC_BONUS = $(addsuffix .c,$(SRCS_BONUS))
OBJS = $(addsuffix .o,$(SRCS))
OBJS_BONUS = $(addsuffix .o,$(SRCS_BONUS))

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
