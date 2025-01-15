NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c
OBJ = ${SRC:.c=.o}

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	ar rcs ${NAME} ${OBJ} ${LIBFT}

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	rm -f ${OBJ}
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all