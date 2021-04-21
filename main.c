#include "minishell.h"



int	main(int ac, char **argv, char **envp) {
	char *pars_str;
	char *fre;
	int fd;
	t_dlist *lst = NULL;

//	pars_str = ft_strdup("1");//потом очистить

	fd = open("minishell_history", O_CREAT | O_RDWR | O_APPEND, 0644);
//	lst = sort_history(fd, lst);

	char *line = strdup("ls > c");
//	while (1) {
//		pars_str = termcap_processing(fd, lst);
//		fre = pars_str;
//		write(1, "\n", 1);
//		if (*pars_str) {
			lets_pars(&line, &envp);
//			free(fre);
//		}
//	}
//	char *r;
//	while (read(0, &r, 1))
//	{
//	}
}
