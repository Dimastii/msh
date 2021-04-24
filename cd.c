#include "minishell.h"

void 	exec_cd(t_cmd cmd)
{
	char **old;
	char **pwd;

	old = ret_glob("OLDPWD");
	*old = ft_freeline(*old, ft_strdup("OLDPWD="));
	*old = ft_freeline(*old, ft_strjoin(*old , getcwd(NULL, -1)));
	printf("%s\n", getcwd(NULL, -1));
	chdir(cmd.tkn[1]);
	printf("%s\n", getcwd(NULL, -1));
	pwd = ret_glob("PWD");
	*pwd = ft_freeline(*pwd, ft_strdup("PWD="));
	*pwd = ft_freeline(*pwd, ft_strjoin(*pwd , getcwd(NULL, -1)));
}