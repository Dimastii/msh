#include "main.h"


int main(int ac, char **argv, char **envp)
{
    t_cmd			*cmds;
	char			*pars_str;
	int				fd;
	t_dlist			*lst = NULL;

	fd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND , 0644);
	lst = sort_history(fd, lst);
	pars_str = termcap_processing(fd, lst);
    cmds = ft_calloc(3, sizeof(t_cmd));

	char **str = malloc(sizeof(char **) * 3);
	str[0] = strdup("ls");
	str[1] = strdup("-la");
	str[2] = NULL;

//	ft_printcol(str);

	char *line = strdup(" $PWD ");
	printf("pars_str: %s\n", pars_str);
	lets_pars(pars_str, &cmds, &envp);

//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "123");
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "1234");
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "12345");

	return (0);
}
