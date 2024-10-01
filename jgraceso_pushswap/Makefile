NAME		= push_swap
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I ./includes

OBJ_DIR		= obj/
SRC_DIR		= src/push_swap

SRC			= cost.c\
				sort.c\
				do_move.c\
				sort_position.c\
				input_check.c\
				stack_utils.c\
				input_check_utils.c\
				stack_values_initialization.c\
				main.c\
				swap.c\
				push.c\
				tiny_sort.c\
				reverse_rotate.c\
				utils.c\
				rotate.c\

SRCS		= $(addprefix ${SRC_DIR}, ${SRC})
OBJ 		= ${SRC:.c=.o}
OBJS		= ${addprefix ${OBJ_DIR}, ${OBJ}}

all: ${OBJ_DIR} ${NAME}

${OBJ_DIR}%.o: ${SRC_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
		@${MAKE} -C ./libft fclean
		@${RM} ${OBJ_DIR}

fclean: clean
		@rm -f ${NAME}

re:	fclean all
