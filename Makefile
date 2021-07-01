# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 17:49:17 by rarodrig          #+#    #+#              #
#    Updated: 2021/06/29 17:49:17 by rarodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_printf.c\

OBJ = $(FILES:.c=.o)

NAME = ft_printf.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):	$(FILES)
	$(CC) $(CFLAGS) -c $(FILES)

clean: 
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re