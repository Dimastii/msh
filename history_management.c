#include "minishell.h"

void	sort_history(int fd, t_dlist **lst)
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
		line = NULL;
		if (!ret_gnl)
			break ;
	}
}

void	init_list(t_dlist **list, char *str)
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
		*list = tmp;
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

char	*return_line(struct termios	*term, int fd, char *line)
{
	termcap_switcher(term, 1);
	if (*line != '\0')
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	write(1, "\n", 1);
	return (line);
}

void	search_keys(char *fd_str, struct termios *term, char **line, t_dlist **tmp)
{
	if (!ft_strcmp(fd_str, "\4"))
		ctrl_d(**line, term);
//	else if (!ft_strcmp(fd_str, "\e[A"))
//		arrow_up(tmp);
	else if (!ft_strcmp(fd_str, "\e[B"))
		arrow_down(tmp);
}
