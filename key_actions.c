#include "minishell.h"

void	arrow_up(t_dlist **tmp)
{
	tputs(tigetstr("rc"), 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	write(1, BASH_NAME, 10);
	if ((*tmp)->prev && (*tmp)->prev->str)
		*tmp = (*tmp)->prev;
	write(1, (*tmp)->str, ft_strlen((*tmp)->str));
}

void	arrow_down(t_dlist **tmp)
{
	tputs(tigetstr("rc"), 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if ((*tmp)->next)
		*tmp = (*tmp)->next;
	write(1, BASH_NAME, 10);
	write(1, (*tmp)->str, ft_strlen((*tmp)->str));
}

void	ctrl_d(char symbol, struct termios *term)
{
	if (symbol == '\0')
	{
		write(1, "exit\n", 5);
		termcap_switcher(term, 1);
		exit(0);
	}
}

void	ctrl_c(char **line)
{
	write(1, "\n", 1);
	write(1, BASH_NAME, 10);
	ft_bzero(*line, ft_strlen(*line));
}

int	exclude_ascii(char *str)
{
	if (!ft_strcmp(str, "\t")
		|| !ft_strcmp(str, "\e[C") || !ft_strcmp(str, "\e[D")
		|| ((int)str[0] > 4 && (int)str[0] < 10)
		|| ((int)str[0] > 11 && (int)str[0] < 32)
		|| ((int)str[0] >= 0 && (int)str[0] < 3))
		return (1);
	return (0);
}
