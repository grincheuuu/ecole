# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 01:42:44 by tguerran          #+#    #+#              #
#    Updated: 2024/12/18 06:08:02 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME	= cub3D

CC		= cc
CFLAGS	= -Werror -Wextra -Wall -g3

SRC_DIR		= ./sources/
OBJ_DIR		= ./objects/
INC_DIR		= ./includes/

LIBFT_PATH	= ./Libft/
LIBFT		= $(LIBFT_PATH)libft.a

MLX_PATH	= ./minilibx-linux
MLX			= $(MLX_PATH)libmlx.a
MLX_FLAGS	= -L $(MLX_PATH) -lmlx -lXext -lX11 -lm

SRC_FILES	= main.c \
				init/init_data.c \
				init/init_mlx.c \
				init/init_textures.c \
				player/ft_event.c \
				player/player_dir.c \
				player/player_pos.c \
				player/player_move.c \
				player/player_rotate.c \
				raycasting/raycasting.c \
				raycasting/render.c \
				raycasting/texture.c \
				raycasting/image_utils.c \
				exit/exit.c \
				exit/ft_free.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INC			= -I $(INC_DIR) -I $(LIBFT_PATH) -I $(MLX_PATH)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)init
	@mkdir -p $(OBJ_DIR)player
	@mkdir -p $(OBJ_DIR)raycasting
	@mkdir -p $(OBJ_DIR)exit

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
