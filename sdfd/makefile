# Nom de la bibliothèque
NAME = libft.a

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Dossiers sources et includes
SRC_DIR = srcs
INC_DIR = includes

# Liste des fichiers sources
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Fichiers objets
OBJ_DIR = objs
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Fichiers headers
HEADER = $(INC_DIR)/ft.h

# Règle par défaut
all: $(NAME)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

# Création de la bibliothèque
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) créée avec succès!"

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)

# Suppression de la bibliothèque et des fichiers objets
fclean: clean
	@rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Spécifie les règles ne créant pas de fichiers portant le nom de règle
.PHONY: all clean fclean re

