# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschwart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 17:39:44 by gschwart          #+#    #+#              #
#    Updated: 2023/10/30 17:39:48 by gschwart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlcat ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memset ft_strchr ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_tolower ft_toupper ft_calloc ft_memmove ft_strdup ft_strrchr ft_substr ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_itoa ft_split

BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

INC_FILES = libft.h

SRC = $(addsuffix .c,$(SRCS))
SRC_B = $(addsuffix .c,$(BONUS))
OBJ = $(addsuffix .o,$(SRCS))
OBJ_B = $(addsuffix .o,$(BONUS))

CC = cc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ) $(INC_FILES)

bonus: $(OBJ_B)
	ar -rcs $(NAME) $(OBJ_B)

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
