//
// Created by Cloyster Veeta on 3/18/21.
//

#ifndef MINISHELL_MAIN_H


#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "libft-main/libft.h"

#include <fcntl.h>
#include <termcap.h>

#include <sys/types.h>
#include <sys/stat.h>

typedef struct  s_cmd{
	int create;
	int mode;
	char **tokens;
	void (*cmd) (char *file, char **argv, char **envp);
}               t_cmd;

char *pwd();
void cd(char *path);
void lets_exec(int pepeout[2], int pepein[2], char *file, char **argv, char **envp, int mode);
void lets_pars(char *str_original, t_cmd **cmds);
void pepe(char **argv, char **envp);
void exec_ls(char *file, char **argv, char **envp);
char	*ft_strjoins(char const *s1, char s2);
void		init_cnd(t_cmd *cmd);
void		init_cmds(t_cmd **cmds);
#define MINISHELL_MAIN_H

#endif //MINISHELL_MAIN_H
