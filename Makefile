NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

SRC = ft_printf.c

OBJ = ${SRC:.c=.o}



all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all