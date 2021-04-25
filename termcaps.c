#include "minishell.h"

void	termcap_switcher(struct termios	*term ,int	switcher)
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

//char	*termcap_processing_2(int fd, t_dlist **lst)
//{
//	struct termios	term;
//	size_t			i;
//	char			str[2000];
//	t_dlist			*tmp;
//
//	pre_term_preps(&term);
//	tmp = *lst;
//	init_list(&tmp, "");
//	while (1)
//	{
//		str[0] = '\0';
//		i = read(0, &str, 100);
//		str[i] = '\0';
//		search_keys(str, &term, &tmp->str, &tmp);
//		if (!ft_strcmp(str, "\177"))
//		{
//			if (ft_strlen(tmp->str) > 0)
//			{
//				tputs(cursor_left, 1, ft_putchar);
//				tputs(tgetstr("dc", 0), 1, ft_putchar);
//				tmp->str[ft_strlen(tmp->str - 1)] = '\0';
//			}
//			else
//				continue ;
//		}
//		else if (!ft_strcmp(str, "\3"))
//		{
//			ctrl_c(&tmp->str);
//			continue ;
//		}
//		else if (exclude_ascii(str))
//			continue ;
//		else if (ft_strcmp(str, "\n"))
//		{
//			tmp->str = ft_freeline(tmp->str, ft_strjoin(tmp->str, str));
//			write(1, str, i);
//		}
//		if (!ft_strcmp(str, "\n"))
//		{
//			*lst = tmp;
//			return (return_line(&term, fd, tmp->str));
//		}
//	}
//}

char		*termcap_processing_2(int fd, t_dlist **lst)
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
		str[0] = '\0';
		i = read(0, &str, 100);
		str[i] = '\0';
		search_keys(str, &term, &tmp->str, &tmp);
		if (!ft_strcmp(str, "\177"))//delete
		{
			if (ft_strlen(tmp->str) > 0)
			{
				tputs(cursor_left, 1, ft_putchar);
				tputs(tgetstr("dc", 0), 1, ft_putchar);
				tmp->str[ft_strlen(tmp->str) - 1] = '\0';
			}
			else
				continue ;
		}
		else if (((int)str[0] == 12))
			ctrl_l();
		else if (!ft_strcmp(str, "\e[A"))//arrow up
			arrow_up(&tmp);
		else if (!ft_strcmp(str, "\3"))//ctrl + C
		{
			ctrl_c(&tmp->str);
			continue ;
		}
		else if (exclude_ascii(str))
			continue ;
		else if (ft_strcmp(str, "\n"))
		{
			tmp->str = ft_freeline(tmp->str, ft_strjoin(tmp->str, str));
			write(1, &str, i);
		}
		if (!ft_strcmp(str, "\n"))
		{
			termcap_switcher(&term, 1);
			if (*tmp->str != '\0')
			{
				write(fd, tmp->str, ft_strlen(tmp->str));
				write(fd, "\n", 1);
			}
			*lst = tmp;
			write(0, "\n", 1);
			return (tmp->str);
		}
	}
}