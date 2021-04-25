#include "minishell.h"

void	termcap_switcher(struct	termios *term, int switcher)
{
	if (!switcher)
	{
		term->c_lflag &= ~(ECHO);
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ISIG);
		if (tcsetattr(0, TCSANOW, term) < 0)
			error("Couldn't get terminal database for some reason!");
	}
	else
	{
		term->c_lflag |= (ECHO);
		term->c_lflag |= (ICANON);
		term->c_lflag |= (ISIG);
		if (tcsetattr(0, TCSANOW, term) < 0)
			error("Couldn't get terminal database for some reason!");
	}
}

static void	pre_term_preps(struct termios *term)
{
	if (tcgetattr(0, term) < 0)
		error("Couldn't get terminal database for some reason!");
	termcap_switcher(term, 0);
	if (tgetent(0, getenv("TERM")) < 0)
		if (tgetent(0, "xterm-256color") < 0)
			error("Couldn't get terminal database for some reason!");
	tputs(save_cursor, 1, ft_putchar);
	write(1, BASH_NAME, 10);
}

static int	ctrl_c_and_ascii(char *fd_str, char **line, size_t i)
{
	if (!ft_strcmp(fd_str, "\3"))
	{
		ctrl_c(line);
		return (1);
	}
	else if (exclude_ascii(fd_str))
		return (1);
	else if (ft_strcmp(fd_str, "\n"))
	{
		*line = ft_freeline(*line, ft_strjoin(*line, fd_str));
		write(1, fd_str, i);
	}
	return (0);
}

static int	backspace(t_dlist **tmp)
{
	if (ft_strlen((*tmp)->str) > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		(*tmp)->str[ft_strlen((*tmp)->str) - 1] = '\0';
		return (1);
	}
	else
		return (0);
}

char	*termcap_processing_2(int fd, t_dlist **lst)
{
	struct termios	term;
	size_t			i;
	char			str[2000];
	t_dlist			*tmp;

	pre_term_preps(&term);
	tmp = *lst;
	init_list(&tmp, "");
	while (1)
	{
		i = read(0, &str, 100);
		str[i] = '\0';
		search_keys(str, &term, &tmp->str, &tmp);
		if (!ft_strcmp(str, "\177"))
			backspace(&tmp);
		else if (ctrl_c_and_ascii(str, &tmp->str, i))
			continue ;
		if (!ft_strcmp(str, "\n"))
		{
			new_line_press(&term, fd, tmp->str);
			*lst = tmp;
			return (tmp->str);
		}
	}
}
