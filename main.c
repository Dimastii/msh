

#include "main.h"

//void read_line()
//{
//	char str;
//	read(1,)
//	while ()
//}

int main(int ac, char **argv, char **envp)
{
    t_cmd *cmds;

    cmds = ft_calloc(3, sizeof(t_cmd));
//	init_cmds(&cmds);

//    printf("Welcome to the fShell!\n %s", argv[2]);


	char **str = malloc(sizeof(char **) * 3);
	str[0] = strdup("ls");
	str[1] = strdup("-la");
	str[2] = NULL;

//	ft_printcol(str);

	char *line = strdup(" $PWD ");
	lets_pars(line, &cmds, &envp);

//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "123");
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "1234");
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "12345");

	return 0;
}
