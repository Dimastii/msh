#include "minishell.h"

static void	argv_error(char **argv)
{
	write(1, BASH_NAME, 10);
	write(1, &argv[1][0], ft_strlen(&argv[1][0]));
	write(1, ": No such file or directory", 27);
}

int	main(int ac, char **argv, char **envp)
{
	char			*pars_str;
	char			*fre;
	int				fd;
	t_dlist			*lst;

	if (ac == 1)
	{
		g_envp = ft_coldup(envp);
		lst = NULL;
		fd = open(HISTORY_FILE, O_CREAT | O_RDWR | O_APPEND, 0644);
		while (1)
		{
			sort_history(fd, &lst);
			pars_str = termcap_processing_2(fd, &lst);
			fre = pars_str;
			if (*pars_str)
			{
				lets_pars(&pars_str);
				free(fre);
			}
		}
	}
	argv_error(argv);
	return (0);
}
