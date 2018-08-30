# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 09:02:05 by nbelpois          #+#    #+#              #
#    Updated: 2018/06/13 09:17:07 by nbelpois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c -I
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar
ARFLAGS = rc
SRC_P = ./srcs/
HEADER = ./includes/
SRC = $(SRC_P)ft_putchar.c $(SRC_P)ft_putstr.c $(SRC_P)ft_swap.c $(SRC_P)ft_strlen.c $(SRC_P)ft_strcmp.c
OBJ = ft_putchar.o ft_putstr.o ft_swap.o ft_strcmp.o ft_strlen.o

all: $(NAME)

$(NAME):
	$(CC) $(HEADER) $(CFLAGS) $(SRC)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

.PHONY: clean fclean re

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
