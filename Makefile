SRC_NAME = get_next_line.c get_next_line_utils.c

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_BONUS = $(SRC_NAME:.c=.o)

CFLAG = -Wall -Wextra -Werror

NAME = gnl.a

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ_NAME}
	gcc -c ${CFLAG} ${SRC_NAME}
	ar -rc $(NAME) $(OBJ_NAME)

bonus: ${NAME} ${OBJ_BONUS}
	gcc -c ${CFLAG} ${SRC_BONUS}
	ar -rc ${NAME} ${OBJ_NAME} ${OBJ_BONUS}

clean:
	rm -rf ${OBJ_NAME} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all