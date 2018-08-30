# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 10:26:38 by nbelpois          #+#    #+#              #
#    Updated: 2018/08/30 12:16:20 by nbelpois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

CC = gcc
CCFLAGS = -Wall -Werror -Wextra


SRC = main.c\
	  algo.c\
	  map_manage.c\
	  read_tetri.c\
	  tetri.c

_GREEN 	= 		\033[1;32m
_RED 	=		\033[1;31m


LIBFT = libft.a

OBJ = $(SRC:.c=.o)

RM = /bin/rm -rf

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT)
	@$(CC) $(CCFLAGS) -I./libft -c $(SRC)
	@$(CC) $(CCFLAGS) $(OBJ) -I./libft -Llibft -lft -o $(NAME)
	@echo "$(_GREEN)$(NAME)... Compiled *"

.PHONY: clean fclean re

clean:
	@echo "$(_RED)Deleting Fillit's object X"
	@$(RM) $(OBJ)
	@make -C libft fclean

fclean: clean
	@echo "$(_RED)Deleting Fillit executable X"
	@$(RM) $(NAME)

re: fclean all
