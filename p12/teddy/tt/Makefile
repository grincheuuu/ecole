# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 16:45:45 by tguerran          #+#    #+#              #
#    Updated: 2024/11/05 00:55:56 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra -Ofast -g

OBJDIR = obj
LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = main.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c \
		utils/gnl.c \
		cub3d_events.c \
		cub3d_init.c \
		cub3d_render.c \
		cub3d.c \
		distance.c

MLX_PATH = ./minilibx-linux
MLX_LIB = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
MLX_INC = -I$(MLX_PATH)

OFILES = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

DIRS = $(sort $(dir $(OFILES)))

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DIRS):
	mkdir -p $(DIRS)

$(OBJDIR)/%.o: %.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_INC) -I$(LIBFT_PATH)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(MLX_LIB) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT_PATH)
	rm -f $(OFILES)
	rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean $(NAME)
