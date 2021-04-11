#include "main.h"

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
	t_dlist	*tmp = NULL;
	t_dlist	*cur;

	tmp = (t_dlist *)malloc(sizeof(t_dlist));
	if (!tmp)
		error("malloc error");
	tmp->str = str;
//	printf("LIST STR: %s\n", tmp->str);
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
		lst = init_list(lst, line);
		if (!ret_gnl)
			break ;
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
	t_dlist			*tmp;

	line = ft_strdup("");
	tmp = lst;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	if (tcsetattr(0, TCSANOW, &term) < 0)
		error("Couldn't get terminal database for some reason!");
	if (tgetent(0, term_type) < 0)
		error("Couldn't get terminal database for some reason!");
	tputs(save_cursor, 1, ft_putchar);
	i = 0;
	tmp = init_list(tmp, ft_strdup(""));
	tmp = tmp->next;
	//TODO надо что-то сделать со строкой чтобы ее можно было редактировать
	while (1)
	{
		i += read(0, &str, 100);
		str[i] = '\0';
		if (!ft_strcmp(str, "\4"))
		{
			if (i == 1)
			{
				write(1, "exit", 4);
				exit(0);
			}
			continue ;
		}
		else if (!ft_strcmp(str, "\e[A"))
		{
			tputs(tigetstr("cr"), 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, tmp->str, ft_strlen(tmp->str));
			if (tmp->prev)
				tmp = tmp->prev;
		}
		else if (!ft_strcmp(str, "\e[B"))
		{
			tputs(tigetstr("rc"), 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			if (tmp->next)
				tmp = tmp->next;
			write(1, tmp->str, ft_strlen(tmp->str));
		}
		else if (!ft_strcmp(str, "\177"))
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
		}
		else if (!ft_strcmp(str, "\e[C") || !ft_strcmp(str, "\e[D"))
			continue ;
		else
		{
			line = ft_strjoin(line, str);
			write(1, &str, i);
		}
		if (!ft_strcmp(str, "\n"))
		{
			write(fd, line, ft_strlen(line));
			close (fd);
			return (line);
		}
	}
//	write(fd, line, ft_strlen(line));
//	return (line);
}

//int		main(int argc, char **argv, char **envp)
//{
//	char			*pars_str;
//	int				fd;
//	t_dlist			*lst = NULL;
//
//	fd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND , 0644);
//	lst = sort_history(fd, lst);
////	printf("list: %s", lst->str);
//	pars_str = termcap_processing(fd, lst);
//	close (fd);
//	printf("%s", pars_str);
//	return (0);
//}
