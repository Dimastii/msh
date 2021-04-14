cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(libft)
link_directories(msh)

set(CMAKE_C_FLAGS "-ltermcap")

add_executable(minishell
        main.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strncmp.c
        libft/ft_strdup.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        libft/ft_substr.c
        libft/ft_strchr.c
        libft/ft_strnstr.c
        termcaps.c
        libft/get_next_line.c
        f.c minishell.h realized_f.c execve.c perser.c pepe.c libft/ft_free.c ft_init.c libft/ft_isolating.c libft/ft_lastcoldel.c utils.c)