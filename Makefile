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

FILES =	./source/ft_printf.c\
		./source/ft_tratament.c\
		./source/ft_string.c\
		./source/ft_utils.c\
		./source/ft_pointer.c\
		./source/ft_char.c\
		./source/ft_flags.c\
		./source/ft_integer.c\
		./source/ft_flag_u.c\
		./source/ft_flag_x.c\

OBJ = $(patsubst ./source/%.c, ./objs/%.o, $(FILES))

NAME = libftprintf.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

bonus: all

$(NAME):	$(OBJ)
	make -C libft_printf
	cp libft_printf/libft.a $(NAME)
	mv libft_printf/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

./objs/%.o:	./source/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -I. -I/libft_printf -c $< -o $@
clean: 
	make clean -C ./libft_printf
	$(RM) ./objs $(OBJ_BONUS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re