NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra 
CC = clang

SRC =	check_flags.c \
		check_hashtag.c \
		ft_printf.c \
		init_struct.c \
		print_num.c \
		print_str.c \
		print_type.c \
		print_width.c \
		printf_utils_num.c \
		printf_utils.c \
		utils_base.c \

OBJ =	$(SRC:.c=.o)

REMOVE = rm -rf 

all: $(NAME)

$(NAME): $(OBJ) 
	ar -rcs $(NAME) $(OBJ)

bonus: all

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	$(REMOVE) $(OBJ)

fclean: clean 
	$(REMOVE) $(NAME)

re: fclean all 