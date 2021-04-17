#include "minishell.h"



int	main(int ac, char **argv, char **envp)
{
	char			*pars_str;
	int				fd;
	t_dlist			*lst = NULL;

	pars_str = ft_strdup("1");//потом очистить

	fd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND , 0644);
	lst = sort_history(fd, lst);

	char *line = strdup("ls | wc");


//	while(1) {
//		printf("Going to sleep for a second...\n");
//		sleep(1);
//	}


	while (1)
	{
		pars_str = termcap_processing(fd, lst);
		write(1, "\n", 1);
		if (*pars_str) {
			lets_pars(&pars_str, &envp);
		}
	}
}
