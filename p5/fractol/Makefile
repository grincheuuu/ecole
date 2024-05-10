NAME	= fractol
CFLAGS  = -Wextra -Wall -Werror -Ofast
LIBMLX	= minilibx-linux
NAME_BONUS = $(NAME)_bonus
LIBS	= $(LIBMLX)/libmlx.a -lX11 -lXext -lm
HEADERS	= -I ./include -I $(LIBMLX)
CC = cc
MAKE = make

SRCS = src/fractol src/fractol_event src/fractol_init src/fractol_render src/fractol_suite

SRCS_BONUS = bonus/fractol_bonus bonus/fractol_event_bonus bonus/fractol_init_bonus bonus/fractol_render_bonus bonus/fractol_suite_bonus

INC_FILES = fractol.h

INC_FILES_BONUS = fractol_bonus.h

SRC = $(addsuffix .c,$(SRCS))
SRC_BONUS = $(addsuffix .c,$(SRCS_BONUS))
OBJS = $(addsuffix .o,$(SRCS))
OBJS_BONUS = $(addsuffix .o,$(SRCS_BONUS))

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)  && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(CFLAGS) -o $(NAME)

$(LIBS):
	@$(MAKE) -C $(LIBMLX)

 bonus: $(OBJS_BONUS) $(LIBS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
