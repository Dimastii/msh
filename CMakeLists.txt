cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(libft-main)
link_directories(./)


add_executable(minishell main.c
        libft-main/ft_strjoin.c
        libft-main/ft_strlen.c
        libft-main/ft_strncmp.c
        libft-main/ft_strdup.c
        libft-main/ft_calloc.c
        libft-main/ft_bzero.c
        libft-main/ft_substr.c
        libft-main/ft_strchr.c
        libft-main/ft_strnstr.c
        f.c main.h realized_f.c execve.c perser.c pepe.c libft-main/ft_free.c ft_init.c libft-main/ft_isolating.c libft-main/ft_lastcoldel.c utils.c)