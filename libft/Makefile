# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 15:38:53 by cveeta            #+#    #+#              #
#    Updated: 2020/11/06 19:16:20 by cveeta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f
SRCS	=			ft_isalnum.c ft_memcmp.c  ft_putchar_fd.c  \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_coldup.c ft_coljoins.c
OBJ	= $(SRCS:.c=.o)
BONUS	=	ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c\
            ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ	= $(BONUS:.c=.o)
all:	$(NAME)
$(NAME):$(OBJ)
		ar rc $(NAME) $(OBJ) libft.h
clean:
		$(RM) $(OBJ) $(BONUS_OBJ)
fclean:	clean
		$(RM) $(NAME)
re:		fclean $(NAME)
bonus:	$(OBJ) $(BONUS_OBJ)
		ar rc $(NAME) $(OBJ) $(BONUS_OBJ) libft.h