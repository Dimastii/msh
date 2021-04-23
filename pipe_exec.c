//
// Created by Cloyster Veeta on 3/20/21.
//
#include "minishell.h"

int			exec_pepe(t_cmd cmd, int fd_out, char ***envp)
{
	int pipefd[2];
	pid_t pid;
	char *path;

	pid = 1;
	path = NULL;
	pipe(pipefd);
	if (ft_strncmp(cmd.tkn[0], "echo", ft_strlen(cmd.tkn[0])) == 0 || (path = findbin(cmd.tkn[0], *envp)))
	{
		pid = fork();
	}
	else
		printf(" А где бинарник то?:%s \n", path);
	if (pid == 0)
	{
		dup2(fd_out, 0);
		if (cmd.fd_write == 1)
			dup2(pipefd[1], 1);
		else
			dup2(cmd.fd_write, 1);
		close(pipefd[0]);
		if (ft_strncmp(cmd.tkn[0], "echo", ft_strlen(cmd.tkn[0])) == 0)
		{
			exec_echo(&cmd);
		}
		else
			execve(path, cmd.tkn, *envp);
	}
	else
		close(pipefd[1]);
	if (path)
		free(path);
	return(pipefd[0]);
}
