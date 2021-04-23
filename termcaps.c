#include "minishell.h"

void		error(char *str)
{
	printf("%s\n", str);
	exit (0);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	if (!ss1 || !ss2)
		return (-1);
	while (ss1[i] != '\0' && ss2[j] != '\0')
	{
		if (ss1[i] != ss2[j])
			return (ss1[i] - ss2[j]);
		j++;
		i++;
	}
	return (ss1[i] - ss2[j]);
}

int			ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void			init_list(t_dlist **list, char *str)
{
	t_dlist	*tmp;
	t_dlist	*cur;

	cur = NULL;
	tmp = NULL;
	tmp = malloc(sizeof(t_dlist));
	if (!tmp)
		error("malloc error");
	tmp->str = ft_strdup(str);
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!(*list))
	{
		*list = tmp;
		write(1, "lol\n", 4);
	}
	else
	{
		cur = *list;
		while (cur->next)
			cur = cur->next;
		cur->next = tmp;
		tmp->prev = cur;
		*list = tmp;
	}
}

void			sort_history(int fd, t_dlist **lst)
{
	char		*line;
	int			ret_gnl;

	while (1)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl < 0)
			error("history file problem");
		if (*line != '\0')
			init_list(lst, line);
		free(line);
		if (!ret_gnl)
			break;
	}
}

char		*termcap_processing_2(int fd, t_dlist **lst)
{
	struct termios	term;
	size_t			i;
	char			str[2000];
	char			*fre;
	t_dlist			*tmp;
	t_dlist			*temp;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ISIG);
	if (tcsetattr(0, TCSANOW, &term) < 0)
		error("Couldn't get terminal database for some reason!");
	if (tgetent(0, "xterm-256color") < 0)
		error("Couldn't get terminal database for some reason!");
	tputs(save_cursor, 1, ft_putchar);
	tmp = *lst;
	init_list(&tmp, ft_strdup(""));
//	write(1, "::::", 4);
//	write(1, tmp->str, ft_strlen(tmp->str));
//	write(1, "::::", 4);
//	write(1, "\n", 1);
//	temp = tmp;
//	while (temp->prev)
//	{
//		write(1, "before termcap: ", 16);
//		write(1, temp->str, ft_strlen(temp->str));
//		write(1, "\n", 1);
//		temp = temp->prev;
//	}
	write(1, BASH_NAME, 10);
	while (1)
	{
		str[0] = '\0';
		i = read(0, &str, 100);
		str[i] = '\0';
		if (!ft_strcmp(str, "\4"))//ctrl + D
		{
			if (*tmp->str == '\0')
			{
				write(1, "exit\n", 5);
				term.c_lflag |= (ECHO);
				term.c_lflag |= (ICANON);
				term.c_lflag |= (ISIG);
				tcsetattr(0, TCSANOW, &term);
				exit(0);
			}
			continue ;
		}
		else if (!ft_strcmp(str, "\177"))//delete
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
		else if (!ft_strcmp(str, "\e[A"))//arrow up
		{
			tputs(tigetstr("cr"), 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, BASH_NAME, 10);
			if (tmp->prev && tmp->prev->str )
				tmp = tmp->prev;
			write(1, tmp->str, ft_strlen(tmp->str));
		}
		else if (!ft_strcmp(str, "\e[B"))//arrow down
		{
			tputs(tigetstr("rc"), 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			if (tmp->next)
				tmp = tmp->next;
			write(1, BASH_NAME, 10);
			write(1, tmp->str, ft_strlen(tmp->str));
		}
		else if (!ft_strcmp(str, "\3"))//ctrl + C
		{
			write(1, "\n", 1);
			write(1, BASH_NAME, 10);
			ft_bzero(tmp->str, ft_strlen(tmp->str));
			continue ;
		}
		else if ((int)str[0] == 28 || !ft_strcmp(str, "\t")
				 || !ft_strcmp(str, "\e[C") || !ft_strcmp(str, "\e[D"))//(ctrl + \) tab arrow right arrow left
			continue ;
		else if (ft_strcmp(str, "\n"))
		{
			tmp->str = ft_strjoin(tmp->str, str);
			write(1, &str, i);
		}
		if (!ft_strcmp(str, "\n"))
		{
			term.c_lflag |= (ECHO);
			term.c_lflag |= (ICANON);
			term.c_lflag |= (ISIG);
			tcsetattr(0, TCSANOW, &term);
			if (*tmp->str != '\0')
			{
				write(fd, tmp->str, ft_strlen(tmp->str));
				write(fd, "\n", 1);
			}
			*lst = tmp;
			return (tmp->str);
		}
	}
}
