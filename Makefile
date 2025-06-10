NAME	= miniRT

CC		= cc

CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
# CFLAGS	= -Wextra -Wall -Werror -g -lm

OBJ_DIR	= objs

SRC_DIR	= srcs

INC_DIR	= includes

PARSER	= parser.c assign_scene.c check_scene.c check_shape.c assign_shape.c \
			addback_shape.c free_shape.c free.c

OBJECTS	= trace_light.c sphere.c plane.c cylinder.c normal.c shadow_check.c cylinder_intersect.c

UTILS	= vector_cal_01.c vector_cal_02.c utils.c

SOURCE	= main.c  key_hook.c \
			$(addprefix parser/, $(PARSER))\
			$(addprefix objects/, $(OBJECTS))\
			$(addprefix utils/, $(UTILS))

LIB_FT	= ./lib/libft

LIBFT	= ${LIB_FT}/libft.a

LIB_MLX	= ./lib/MLX42

LIBS	= ${LIB_MLX}/build/libmlx42.a -ldl -lglfw -pthread -lm

HEADER	= -I${INC_DIR} -I${LIB_FT} -I${LIB_MLX}/include

OBJS	= ${SOURCE:%.c=${OBJ_DIR}/%.o}

all:	${NAME}

${LIBFT}:
	${MAKE} -C ${LIB_FT}

${NAME}: ${OBJS} ${LIBFT}
	cmake $(LIB_MLX) -B $(LIB_MLX)/build && make -C $(LIB_MLX)/build -j4
	${CC} ${OBJS} ${CFLAGS} ${LIBS} ${LIBFT} ${HEADER} -o ${NAME}
	@echo "\033[0;36mminiRT Compiled\n\033[0m"

${OBJS}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c Makefile ./includes/miniRT.h
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} ${HEADER} -c $< -o $@

clean:
	rm -rfv ${OBJ_DIR}
	@rm -rfv $(LIB_MLX)/build
	@${MAKE} -C ${LIB_FT} clean
	@echo "\033[31mMLX Clean Completed\n\033[0m"

fclean: clean
	rm -rfv ${NAME}
	@${MAKE} -C ${LIB_FT} fclean
	@echo "\033[31mminiRT Clean Completed\n\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
