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
			history_management.c \
			key_actions.c \
			utils_2.c \
			export.c \
			libft/ft_coljoins.c \
			libft/ft_coldup.c \
			cd.c

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