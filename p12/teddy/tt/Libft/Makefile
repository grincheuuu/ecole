# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 10:51:41 by tguerran          #+#    #+#              #
#    Updated: 2024/06/05 16:19:54 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
DEPS = libft.h
SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_strdup.c	\
		ft_substr.c \
		ft_strjoin.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_striteri.c \
		ft_split.c \
		ft_printf.c \
		ft_putchar.c \
		ft_puthex_l.c \
		ft_puthex_u.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_atof.c \
		ft_strtoll.c \
		ft_strcat.c


SRCB = 	ft_lstnew.c	 \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OFILES = $(SRC:.c=.o)

OFILESB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	
bonus: $(OFILESB)
	ar rcs $(NAME) $(OFILESB)

clean:
	rm -f $(OFILES) $(OFILESB)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)
