

#include "main.h"


int main(int ac,char **argv, char **envp)
{
    t_cmd *cmds;

    cmds = malloc(sizeof(t_cmd) * 3);
	init_cmds(&cmds);

    printf("Welcome to the fShell!\n");

    char *line = strdup("   ls -la -ll   ;  ls -lll ffff;   ls;        ");
    lets_pars(line, &cmds);
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "123");
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "1234");
//	cmds[0].tokens = ft_coljoins(cmds[0].tokens, "12345");
	ft_printcol(cmds[0].tokens);
	return 0;
}
