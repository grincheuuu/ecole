# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 01:42:44 by tguerran          #+#    #+#              #
#    Updated: 2024/12/19 16:01:52 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
CFLAGS  = -Wextra -Wall -Werror -Ofast -g
LIBMLX	= ./minilibx-linux
LIBS	= $(LIBMLX)/libmlx.a -lX11 -lXext -lm
HEADERS	= -I ./include -I $(LIBMLX)
CC = cc
MAKE = make

LIBFT_PATH	= ./Libft/
LIBFT		= $(LIBFT_PATH)libft.a

SRCS	= sources/main \
				sources/main2 \
				sources/init/init_data \
				sources/init/init_mlx \
				sources/init/init_textures \
				sources/parsing/parsing \
				sources/parsing/parsing_init_free \
				sources/parsing/parsing_free \
				sources/parsing/parsing_map \
				sources/parsing/parsing_map_2 \
				sources/parsing/parsing_player \
				sources/parsing/parsing_return_path \
				sources/parsing/parsing_utils_1 \
				sources/parsing/parsing_utils_2 \
				sources/parsing/parsing_utils_3 \
				sources/parsing/parsing_utils_4 \
				sources/parsing/parsing_free_2 \
				sources/parsing/parsing_handle \
				sources/parsing/parsing_handle_2 \
				sources/parsing/pars_rand \
				sources/parsing/spaces \
				sources/parsing/spaces2 \
				sources/parsing/put_test_rgb \
				sources/parsing/fail_map \
				sources/parsing/process_file \
				sources/parsing/updates_char \
				sources/parsing/lines_analysis \
				sources/player/ft_event \
				sources/player/player_dir \
				sources/player/player_pos \
				sources/player/player_move \
				sources/player/player_move2 \
				sources/player/player_rotate \
				sources/raycasting/raycasting \
				sources/raycasting/render \
				sources/raycasting/texture \
				sources/raycasting/image_utils \
				sources/exit/exit \
				sources/exit/ft_free

SRC = $(addsuffix .c,$(SRCS))
OBJS = $(addsuffix .o,$(SRCS))

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)  && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(CFLAGS) -o $(NAME) $(LIBFT)

$(LIBS):
	@$(MAKE) -C $(LIBMLX)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
