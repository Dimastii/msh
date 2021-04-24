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

/* @hviva
 * @hnewman
 * @fngoc
 * @lphoenix
 * @mdenys
 * @Melisha
 * @trachell
 * @jkamala рыжик
 * @Smyriell Maria
 * @mhumfrey
 * @keuclide
 */

int	main(int ac, char **argv, char **envp)
{
	char			*pars_str;
	char			*fre;
	int				fd;
	t_dlist			*lst;
	t_dlist			*listik;


	g_envp = ft_coldup(envp);
	lst = NULL;
	fd = open(HISTORY_FILE, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		error("couldn't open history file");

	char *line = strdup("ls");
	char *lin = line;

//	line = strdup("export r=qwe    qwe=");
//	ft_printcol(g_envp);
//	while (1)
//	{
//		sort_history(fd, &lst);
//		pars_str = termcap_processing_2(fd, &lst);
//		fre = pars_str;
//		listik = lst;
//		write(1, "\n", 1);
//		if (*pars_str)
//		{
			lets_pars(&line);
//			ft_printcol(g_envp);

			free(lin);
//		}
//	}
	char *r;
	while (read(0, &r, 1))
	{

	}
}
