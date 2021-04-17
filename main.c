#include "minishell.h"

int	main(int ac, char **argv, char **envp)
{
	t_cmd			*cmds;
	char			*pars_str;
	int				fd;
	t_dlist			*lst = NULL;

	pars_str = ft_strdup("1");//потом очистить
	cmds = ft_calloc(3, sizeof(t_cmd));

	fd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND , 0644);
	lst = sort_history(fd, lst);
//	printf("pars_str: |%s|\n", pars_str);

	char *line = strdup("ls | wc");
	struct stat buff;
//	write(1, "1\n", 1);
//	printf(")%d", stat("./minishell", &buff));
//	execve("./minishell", NULL, envp);
	//хехе хфхф
	while (1)
	{
		pars_str = termcap_processing(fd, lst);
		write(1, "\n", 1);
//		printf("pars_str: |%s|-|%d|\n", pars_str, ft_strncmp(pars_str, "exit", ft_strlen(pars_str)));
		if (*pars_str) {
			lets_pars(&pars_str, &envp);
		}
	}
	return (0);
}
