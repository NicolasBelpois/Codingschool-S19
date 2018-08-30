# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 09:38:19 by nbelpois          #+#    #+#              #
#    Updated: 2018/07/26 09:53:03 by nbelpois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c
CFLAGS = -Wall -Werror -Wextra

_GREEN	=	\033[1;32m
_RED	=	\033[1;31m

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_strcat.c ft_strcmp.c ft_strcpy.c \
	  ft_strdup.c  ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	  ft_strstr.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strlcat.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_memcpy_rev.c ft_putchar.c ft_memalloc.c \
	  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_isspace.c ft_islower.c ft_isupper.c ft_strnlen.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs

HEADER = -I includes

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

RM = /bin/rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(_GREEN)$(NAME)... Compiled *"

.PHONY: clean fclean re

clean: 
	@echo "$(_RED)Deleting Libft objects X"
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(_RED)Deleting Libft executable X"
	@$(RM) $(NAME)

re: fclean all

