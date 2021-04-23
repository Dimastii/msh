#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>

# include <unistd.h>
# include "libft/libft.h"

# include <fcntl.h>
# include <termcap.h>

# include <sys/types.h>
# include <sys/stat.h>

# include <curses.h>
# include <term.h>
# include <signal.h>


typedef	struct		s_dlist
{
	char			*str;
	struct	s_dlist	*next;
	struct	s_dlist	*prev;
}					t_dlist;

typedef struct	s_cmd
{
	int		fd_read;
	int		fd_write;
	char	**tkn;
}				t_cmd;

char **g_envp;

char *ft_freeline(char *fre, char *str);
void	detect_token(char **str, t_cmd *cmd);
void		detect_spec(char **str, t_cmd *cmd, char ***envp);
void	search_glob(char **str, char **tocken, char const *tmp, char **envp);
void 	this_not_quote(char **str, char **tocken, int *redir, char **tmp);
void 	this_quote(char **str, char **tocken, char **tmp);
void		exec_pwd();
int 	isspec(int c);
int		ft_isspace(int c);
char		*findbin(char *cmd, char **envp);
void		stdexec(t_cmd *cmd, int fd_out);
char		*ft_strchrifnepred(const char *string, int symbol, int flag);
void		lets_pars(char **str, char ***envp);
char		*ft_strjoins(char const *s1, char s2);
void		init_cnd(t_cmd *cmd);
t_dlist		*sort_history(int fd, t_dlist *lst);
t_dlist		*init_list(t_dlist *lst, char *str);
char		*termcap_processing(int fd, t_dlist *lst);
char		*check_glob(char *glob, char **envp);
int			exec_pepe(t_cmd cmd, int fd_out, char ***envp);
void		exec_echo(t_cmd	*cmd);

#endif