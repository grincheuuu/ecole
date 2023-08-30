# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschwart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 10:38:46 by gschwart          #+#    #+#              #
#    Updated: 2023/08/29 20:26:06 by gschwart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

ar -rc libft.a. ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
