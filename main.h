//
// Created by Cloyster Veeta on 3/18/21.
//

#ifndef MINISHELL_MAIN_H
# define MINISHELL_MAIN_H

# include <stdio.h>
# include <stdlib.h>

# include <unistd.h>
# include "libft-main/libft.h"

# include <fcntl.h>
# include <termcap.h>

# include <sys/types.h>
# include <sys/stat.h>

# include <curses.h>
# include <term.h>

typedef struct		s_dlist
{
	char			*str;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;


typedef struct	s_cmd
{
	int		create;
	int		mode;
	char	**tokens;
}				t_cmd;

char		*pwd();
char		*findbin(char *cmd, char **envp);
void		cd(char *path);
void		stdexec(t_cmd *cmd, char ***envp, int fd_out);
char		*ft_strchrifnepred(const char *string, int symbol, int flag);
void		lets_exec(int pepeout[2], int pepein[2], char *file, char **argv, char **envp, int mode);
void lets_pars(char **str, char ***envp);
void		pepe(char **argv, char **envp);
void		exec_ls(char *file, char **argv, char ***envp);
char		*ft_strjoins(char const *s1, char s2);
void		init_cnd(t_cmd *cmd);
void		init_cmds(t_cmd **cmds);
t_dlist		*sort_history(int fd, t_dlist *lst);
t_dlist		*init_list(t_dlist *lst, char *str);
char		*termcap_processing(int fd, t_dlist *lst);
char	*check_glob(char *glob, char **envp);

#endif //MINISHELL_MAIN_H
