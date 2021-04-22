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

	lst = NULL;
	fd = open(HISTORY_FILE, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		error("couldn't open history file");
	while (1)
	{
		sort_history(fd, &lst);
		pars_str = termcap_processing_2(fd, &lst);
		fre = pars_str;
		write(1, "\n", 1);
		if (*pars_str)
		{
			lets_pars(&pars_str, &envp);
			free(fre);
		}
	}
}
