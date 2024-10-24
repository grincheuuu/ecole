NAME	= CUB3D
CFLAGS  = -Wextra -Wall -Werror -Ofast -g
LIBMLX	= minilibx-linux
LIBS	= $(LIBMLX)/libmlx.a -lX11 -lXext -lm
HEADERS	= -I ./include -I $(LIBMLX)
CC = cc
MAKE = make

SRCS = src/cub3d src/get_next_line_utils src/get_next_line src/cub3d_render src/cub3d_init src/cub3d_events src/gnl src/distance

INC_FILES = fractol.h

SRC = $(addsuffix .c,$(SRCS))
OBJS = $(addsuffix .o,$(SRCS))

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)  && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(CFLAGS) -o $(NAME)

$(LIBS):
	@$(MAKE) -C $(LIBMLX)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
