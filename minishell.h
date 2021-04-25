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
# define HISTORY_FILE "./minishell_history"
# define BASH_NAME "POLUPOKER:"

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

char		**g_envp;

void		ctrl_l();
char		*return_line(struct termios	*term, int fd, char *line);
char		*ft_freeline(char *fre, char *str);
int			exclude_ascii(char *str);
void		search_keys(char *fd_str, struct termios *term, char **line, t_dlist **tmp);
int			ft_strcmp(const char *s1, const char *s2);
char		*save_history(char *line, int fd);
void		ctrl_c(char **line);
int			back_space(char **line);
void		ctrl_d(char symbol, struct termios *term);
void		termcap_switcher(struct termios *term ,int switcher);
void		arrow_down(t_dlist **tmp);
void		arrow_up(t_dlist **tmp);
int			ft_putchar(int c);
void		detect_token(char **str, t_cmd *cmd);
void		detect_spec(char **str, t_cmd *cmd);
void		search_glob(char **str, char **tocken, char const *tmp, char **envp);
void 		this_not_quote(char **str, char **tocken, int *redir, char **tmp);
void 		this_quote(char **str, char **tocken, char **tmp);
void		exec_pwd();
int 		isspec(int c);
int			ft_isspace(int c);
char	*findbin(char *cmd);
void		stdexec(t_cmd *cmd, int fd_out);
char		*ft_strchrifnepred(const char *string, int symbol, int flag);
void		lets_pars(char **str);
char		*ft_strjoins(char const *s1, char s2);
void		init_cnd(t_cmd *cmd);
void		sort_history(int fd, t_dlist **lst);
void		init_list(t_dlist **list, char *str);
char		*termcap_processing_2(int fd, t_dlist **lst);
char		*check_glob(char *glob);
int			exec_pepe(t_cmd cmd, int fd_out);
void		exec_echo(t_cmd	*cmd);
void		check_cmd(t_cmd *cmd, char	**path, pid_t *pid);
void		error(char *str);
char	**ret_glob(char *arg);
void		exec_export(t_cmd *cmd);
void 	exec_cd(t_cmd cmd);

#endif