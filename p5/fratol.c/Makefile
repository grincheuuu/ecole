NAME	= fractol
CFLAGS  = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	= minilibx-linux
NAME_BONUS = $(NAME)_bonus
HEADERS	= -I ./include -I $(LIBMLX)
LIBS	= $(LIBMLX)/libmlx.a -lX11 -lXext -lm

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






	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)  && printf "Compiling: $(notdir $<)"
ChatGPT

Cela semble être une règle de compilation dans un Makefile. Explorons-le :

    @$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) : Cette partie est la commande de compilation. Voici ce qu'elle fait :
        @$(CC): Appelle le compilateur défini par CC.
        $(CFLAGS): Inclut les options de compilation définies par CFLAGS.
        -c $< -o $@: Indique au compilateur de générer un fichier objet (-c) à partir du fichier source spécifié ($<) et de le sauvegarder sous le nom de fichier objet spécifié ($@).
        $(HEADERS): Inclut les répertoires d'en-tête spécifiés dans la variable HEADERS.

    && printf "Compiling: $(notdir $<)" : Cette partie est une commande shell qui affiche un message après la compilation réussie du fichier source. Voici ce qu'elle fait :
        &&: Cette partie est un opérateur de contrôle de flux qui signifie "exécuter la commande suivante uniquement si la commande précédente réussit".
        printf "Compiling: $(notdir $<)" : Cette commande shell utilise printf pour afficher le message "Compiling: [nom du fichier source]".
            $(notdir $<) : C'est une fonction de substitution de texte dans GNU Make qui extrait le nom du fichier source ($<) sans son chemin d'accès.

En résumé, cette règle compile un fichier source en fichier objet, puis affiche un message indiquant que le fichier source a été compilé avec succès.
User
@$
ChatGPT

L'@ devant la commande dans un Makefile est une convention pour supprimer l'affichage de la commande elle-même. Cela signifie que la commande ne sera pas affichée dans la sortie standard lorsqu'elle est exécutée. C'est utile pour rendre la sortie du Makefile plus propre en n'affichant que les messages d'erreur ou de succès, plutôt que chaque commande exécutée.
