#include "main.h"


int main(int ac, char **argv, char **envp)
{
    t_cmd			*cmds;
	char			*pars_str;
	int				fd;
	t_dlist			*lst = NULL;

	pars_str = ft_strdup("1");//потом очистить
	cmds = ft_calloc(3, sizeof(t_cmd));///m h

	fd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND , 0644);
	lst = sort_history(fd, lst);

//	printf("pars_str: |%s|\n", pars_str);

	char *line = strdup("qwe | qwe");
	while (1) {
		write(1, "POLUPOKER:", 10);
//		pars_str = termcap_processing(fd, lst);
//		printf("pars_str: |%s|-|%d|\n", pars_str, ft_strncmp(pars_str, "exit", ft_strlen(pars_str)));
//		if (*pars_str) {
			lets_pars(line, &cmds, &envp);
//		}///
	}


	return (0);
}
