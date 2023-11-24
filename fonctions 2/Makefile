SRCS = ft_strlcat ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memset ft_strchr ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_tolower ft_toupper ft_calloc ft_memmove ft_strdup ft_strrchr ft_substr ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_itoa ft_split

BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

/*SRCS et BONUS : Ce sont les variables qui définissent les fichiers source à compiler pour créer votre bibliothèque. "SRCS" contient les fichiers source principaux que vous souhaitez compiler, et "BONUS" contient les fichiers source supplémentaires liés aux bonus.*/

INC_FILES = libft.h

/*INC_FILES : Cette variable contient le nom du fichier d'en-tête que vous souhaitez inclure lors de la création de la bibliothèque. Cela garantit que l'en-tête est bien inclus dans votre bibliothèque pour être utilisé par d'autres programmes.*/

SRC = $(addsuffix .c,$(SRCS))
SRC_B = $(addsuffix .c,$(BONUS))
OBJ = $(addsuffix .o,$(SRCS))
OBJ_B = $(addsuffix .o,$(BONUS))

/*SRC et SRC_B : Ces variables génèrent la liste complète des fichiers source en ajoutant l'extension ".c" à la fin de chaque nom de fichier dans les variables SRCS et BONUS.*/
/*OBJ et OBJ_B : Ce sont les fichiers d'objet correspondants aux fichiers source dans SRC et SRC_B. Ils sont générés à partir des fichiers source en remplaçant l'extension ".c" par ".o".*/

CC = cc
CCFLAGS = -Wall -Wextra -Werror

/*CC : C'est le compilateur que vous utiliserez pour compiler vos fichiers source en fichiers objet. Par défaut, vous utilisez "cc", qui est un compilateur C.*/
/*CCFLAGS : Ces sont les drapeaux (flags) que vous souhaitez passer au compilateur. Dans votre cas, vous avez activé les avertissements (-Wall), les avertissements supplémentaires (-Wextra), et les erreurs (-Werror).*/

NAME = libft.a

/*NAME : C'est le nom de la bibliothèque que vous allez créer. Dans votre cas, c'est "libft.a".*/

all: $(NAME)

/*all : Cible "all" qui est la cible par défaut. Lorsque vous exécutez "make" sans argument, il construit la bibliothèque.*/

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ) $(INC_FILES)

/*$(NAME) : Règle pour créer la bibliothèque. Il utilise la commande "ar" pour créer la bibliothèque à partir des fichiers objets générés à partir des fichiers source.*/

bonus: $(OBJ_B)
	ar -rcs $(NAME) $(OBJ_B)

/*bonus : Cible "bonus" pour compiler des fichiers bonus supplémentaires et les ajouter à la bibliothèque.*/

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

/*%.o: %.c : Cette règle de construction indique comment générer un fichier objet à partir d'un fichier source. Il utilise le compilateur (CC) pour compiler le fichier source en fichier objet.construire un .o à partir d'un .c)*/compiler tous les fichiers sources, possédant l’extension .c, en fichiers objets correspondant,*/

clean :
	rm -rf $(OBJ) $(OBJ_B)
	
/*clean : Cible pour supprimer les fichiers objets générés.*/

fclean : clean
	rm -rf $(NAME)
	
/*fclean : Cible pour supprimer à la fois les fichiers objets et la bibliothèque créée.*/

re : fclean all

/*re : Cible pour nettoyer (fclean) et reconstruire (all) la bibliothèque.*/

.PHONY : all re clean fclean

/*.PHONY : Il s'agit d'une directive spéciale pour indiquer à Make que ces cibles ne sont pas des fichiers réels, mais des cibles personnalisées. Cela garantit que les cibles seront exécutées même s'il existe des fichiers réels portant les mêmes noms.  commande .PHONY. Elle permet de définir une cible particulière. C’est juste un nom de fichier fictif pour les commandes qui seront exécutées quand vous lancez une requête explicite. Cela permet d’éviter des conflits avec un fichier du même nom et d’améliorer les performances du Makefile.*/

La ligne SRC = $(addsuffix .c,$(SRCS)) dans le Makefile est une directive Makefile qui utilise des variables et des fonctions Makefile pour générer une liste de fichiers source en ajoutant l'extension ".c" à chaque nom de fichier dans la variable SRCS.

Explications :

    SRCS est une variable qui contient une liste de noms de fichiers source, par exemple, "ft_strlcat", "ft_atoi", "ft_bzero", etc.

    $(addsuffix .c, $(SRCS)) est une expression Makefile qui effectue l'opération suivante :
        $(SRCS) est une référence à la variable SRCS, ce qui signifie qu'elle utilise la liste des noms de fichiers source définis dans SRCS.
        $(addsuffix .c, ...) est une fonction Makefile qui ajoute l'extension ".c" à chaque élément de la liste spécifiée.
        
        $(NAME) : $(OBJ) est une règle dans un fichier Makefile qui décrit comment générer la bibliothèque nommée $(NAME) (dans ce cas, libft.a) à partir des fichiers objets spécifiés dans $(OBJ) (c'est-à-dire les fichiers binaires compilés à partir des fichiers source).

Voici une explication plus détaillée de cette règle :

    $(NAME) : C'est la cible de la règle. Cela signifie que le résultat attendu de cette règle est la création de la bibliothèque libft.a.

    : : Ce symbole indique la dépendance entre la cible et les éléments suivants. Dans ce cas, la cible libft.a dépend des fichiers objets listés dans $(OBJ).

    $(OBJ) : C'est la liste des fichiers objets qui sont nécessaires pour créer la bibliothèque libft.a. Ces fichiers objets sont générés à partir des fichiers source (fichiers .c) lors de la compilation.

    ar -rcs $(NAME) $(OBJ) $(INC_FILES) : C'est la commande qui est exécutée pour créer la bibliothèque libft.a. Voici ce que chaque partie de la commande fait :
        ar : C'est l'utilitaire d'archive qui est utilisé pour créer une bibliothèque statique. Il combine les fichiers objets en un seul fichier de bibliothèque.
        -r : Cette option de ar indique que nous voulons remplacer ou ajouter des fichiers dans la bibliothèque existante (ou la créer si elle n'existe pas).
        -c : Cette option de ar indique que nous voulons créer une nouvelle bibliothèque s'il n'en existe pas déjà.
        $(NAME) : C'est le nom de la bibliothèque que nous voulons créer (dans ce cas, libft.a).
        $(OBJ) : Ce sont les fichiers objets que nous voulons ajouter à la bibliothèque.
        $(INC_FILES) : C'est la liste des fichiers d'en-tête (headers) qui doivent être inclus dans la bibliothèque. Les fichiers d'en-tête sont généralement nécessaires pour que d'autres programmes puissent utiliser la bibliothèque correctement.
        
        La règle bonus: $(OBJ_B) dans le Makefile est utilisée pour générer les fonctions bonus de la bibliothèque (définies dans $(BONUS)) et les ajouter à la bibliothèque principale ($(NAME)). Voici une explication plus détaillée de cette règle :

    bonus : C'est la cible de la règle. Cela signifie que cette règle sera exécutée lorsque vous invoquerez make bonus dans la ligne de commande.

    $(OBJ_B) : C'est la liste des fichiers objets (fichiers binaires) qui ont été générés à partir des fichiers source des fonctions bonus (définies dans $(BONUS)). Ces fichiers objets sont nécessaires pour créer la bibliothèque bonus.

    ar -rcs $(NAME) $(OBJ_B) : C'est la commande qui est exécutée pour créer la bibliothèque bonus et l'ajouter à la bibliothèque principale ($(NAME)). Voici ce que chaque partie de la commande fait :
        ar : C'est l'utilitaire d'archive utilisé pour créer une bibliothèque statique.
        -r : Cette option de ar indique que nous voulons remplacer ou ajouter des fichiers dans la bibliothèque existante.
        -c : Cette option de ar indique que nous voulons créer une nouvelle bibliothèque si elle n'existe pas.
        $(NAME) : C'est le nom de la bibliothèque principale à laquelle nous voulons ajouter les fonctions bonus.
        $(OBJ_B) : Ce sont les fichiers objets des fonctions bonus que nous voulons ajouter à la bibliothèque.

En résumé, lorsque vous exécutez make bonus, cette règle compile les fonctions bonus, génère les fichiers objets correspondants, et les ajoute à la bibliothèque principale libft.a, de sorte que la bibliothèque principale contiendra à la fois les fonctions principales et les fonctions bonus.
