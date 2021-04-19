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

t_dlist			*init_list(t_dlist *lst, char *str)
{
	t_dlist	*tmp;
	t_dlist	*cur;

	tmp = NULL;
	tmp = (t_dlist *)malloc(sizeof(t_dlist));
	if (!tmp)
		error("malloc error");
	tmp->str = str;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!lst)
	{
		lst = tmp;
		return (lst);
	}
	else
	{
		cur = lst;
		while (cur->next)
			cur = cur->next;
		cur->next = tmp;
		tmp->prev = cur;
	}
	return (lst);
}

t_dlist			*sort_history(int fd, t_dlist *lst)
{
	char		*line;
	int			ret_gnl;

	while (1)
	{
		ret_gnl = get_next_line(fd, &line);
		if (*line != '\0')
			lst = init_list(lst, line);
		free(line);
		if (!ret_gnl)
			break;
	}
	while (lst->next)
		lst = lst->next;
	return (lst);
}

char		*termcap_processing(int fd, t_dlist *lst)
{
	char			*line;
	struct	termios	term;
	char			*term_type = "xterm-256color";
	int				i;
	char			str[2000];
	char			*fre;
	t_dlist			*tmp;

	line = ft_strdup("");
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ISIG);
	if (tcsetattr(0, TCSANOW, &term) < 0)
		error("Couldn't get terminal database for some reason!");
	if (tgetent(0, term_type) < 0)
		error("Couldn't get terminal database for some reason!");
	tputs(save_cursor, 1, ft_putchar);
	write(1, "POLUPOKER:", 10);
	//TODO добавлять в историю сразу и стрелки вправо/влево
	while (1)
	{
		str[0] = '\0';
		i = read(0, &str, 100);
		str[i] = '\0';
		if (!ft_strcmp(str, "\4"))//ctrl + D
		{
			if (*line == '\0')
			{
				write(1, "exit\n", 5);
				exit(0);
			}
			continue ;
		}
		else if (!ft_strcmp(str, "\3"))//ctrl + C
		{
			write(1, "\nPOLUPOKER:", 11);
			ft_bzero(line, ft_strlen(line));
			continue ;
		}
		else if ((int)str[0] == 28 || !ft_strcmp(str, "\t")
		|| !ft_strcmp(str, "\e[C") || !ft_strcmp(str, "\e[D"))//(ctrl + \) tab arrow right arrow left
			continue ;
		else if (!ft_strcmp(str, "\e[A"))//arrow up
		{
			tputs(tigetstr("cr"), 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			fre = line;
			line = ft_strdup(tmp->str);//leak
			free(fre);
			write(1, "POLUPOKER:", 10);
			write(1, line, ft_strlen(line));
//			tmp->next = init_list(tmp, str);
//			tmp->next->prev = tmp;
			if (tmp->prev)
				tmp = tmp->prev;
		}
		else if (!ft_strcmp(str, "\e[B"))//arrow down
		{
			tputs(tigetstr("rc"), 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			if (tmp->next)
				tmp = tmp->next;
			fre = line;
			line = ft_strdup(tmp->str);
			free(fre);
			write(1, "POLUPOKER:", 10);
			write(1, line, ft_strlen(line));
		}
		else if (!ft_strcmp(str, "\177"))//delete
		{
			if (ft_strlen(line) > 0)
			{
				tputs(cursor_left, 1, ft_putchar);
				tputs(tgetstr("dc", 0), 1, ft_putchar);
				line[ft_strlen(line) - 1] = '\0';
			}
			else
				continue ;
		}
		else if (ft_strcmp(str, "\n"))
		{
			fre = line;
			line = ft_strjoin(line, str);
			free(fre);
			write(1, &str, i);
		}
		if (!ft_strcmp(str, "\n"))
		{
			if (*line != '\0')
			{
				write(fd, line, ft_strlen(line));
				write(fd, "\n", 1);
				tmp = init_list(tmp, ft_strdup(line));
				tmp->next->prev = tmp;
				tmp = tmp->next;
				lst = tmp;
			}
			term.c_lflag |= (ECHO);
			term.c_lflag |= (ICANON);
			term.c_lflag |= (ISIG);
			tcsetattr(0, TCSANOW, &term);
			return (line);
		}
	}
}
