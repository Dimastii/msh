#include "minishell.h"

void			exec_pwd()
{
	char	*line;

	line = getcwd(NULL, -1);
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
	free(line);
	exit (0);
}
