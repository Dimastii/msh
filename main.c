#include "minishell.h"

void	lst_clear(t_dlist **lst, void (*del)(char *))
{
	t_dlist *temp;

	if (lst && *lst)
	{
		while (*lst)
		{
			temp = *lst;
			(*lst) = (*lst)->prev;
			del(temp->str);
			free(temp);
		}
	}
}

void		del_str(char *str)
{
	free(str);
}

int	main(int ac, char **argv, char **envp)
{
	char			*pars_str;
	char			*fre;
	int				fd;
	t_dlist			*lst;
	t_dlist			*listik;

	g_envp = envp;
	lst = NULL;
	fd = open(HISTORY_FILE, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		error("couldn't open history file");
	while (1)
	{
		sort_history(fd, &lst);
		pars_str = termcap_processing_2(fd, &lst);
		fre = pars_str;
//		listik = lst;
//		write(1, "\n", 1);
//		write(1, "|||", 3);
//		write(1, listik->str, ft_strlen(listik->str));
//		write(1, "|||", 3);
//		while (listik->prev)
//		{
//			write(1, "after termcap: ", 15);
//			write(1, listik->str, ft_strlen(listik->str));
//			write(1, "\n", 1);
//			listik = listik->prev;
//		}
		if (*pars_str)
		{
			lets_pars(&pars_str);
			free(fre);
		}
	}
}
