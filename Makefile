#NAME		= minishell
#
#CC			= gcc
#
#SRCS		= main.c
#
#HEADER		= minishell.h
#
#LIB_HEADER	= libft/libft.h
#
#OBJS_DIR	= ./obj/
#
#OBJS		= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
#
#LIBFT		= make all -C libft
#
#FLAGS		= -ltermcap
#
#RM			= rm -rf
#
#all:	${NAME}
#
#$(OBJS_DIR):
#	@mkdir -p $(OBJ_DIR)
#
#${OBJS}: $(OBJS_DIR)%.o: %.c $(HEADER)
#		@mkdir ${OBJS_DIR}
#		${LIBFT}
#		${CC} ${FLAGS} -I. -c $< -o $@
#
#${NAME}:	${OBJS_DIR} ${OBJS} ${HEADER}
#			${CC} ${FLAGS} ${OBJS} -o ${NAME} -L. -I. libft/libft.a
#
#clean:
#			${RM} ${OBJS}
#			${RM} ${OBJS_DIR}
#			make clean -C libft
#
#fclean:		clean
#					${RM} ${NAME}
#					${RM} ${OBJS_DIR}
#					make fclean -C libft
#
#re:			fclean all
#
#.PHONY:		re all clean fclean

NAME		= minishell

SRC			= main.c \
			libft/get_next_line.c \
			termcaps.c \
			parser.c \
			ft_init.c \
			utils.c \
			libft/ft_free.c \
			libft/ft_lastcoldel.c \
			libft/ft_isolating.c \
			echo.c \
			pwd.c \
			detect_token.c \
			detect_spec.c \
			quote.c \
			not_quote.c \
			search_glob.c \
			pipe_exec.c \
			findbin.c \
			stdexec.c \
			export.c

HEADER		= minishell.h

OBJS		= ${SRC:.c=.o}

LIBFT		= make all -C libft

FLAGS		= -ltermcap

RM			= rm -f

all:	${NAME}

.c.o:
		gcc ${FLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${HEADER}
		${LIBFT}
		gcc ${FLAGS} ${OBJS} -o ${NAME} -I. libft/libft.a

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft
re:		fclean all

.PHONY:		re all clean fclean