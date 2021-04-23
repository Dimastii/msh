//
// Created by Cloyster Veeta on 3/20/21.
//
#include "minishell.h"

void	child_proc_(t_cmd cmd, char	*path, int fd_out, int *pipefd)
{
	dup2(fd_out, 0);
	if (cmd.fd_write == 1)
		dup2(pipefd[1], 1);
	else
		dup2(cmd.fd_write, 1);
	close(pipefd[0]);
	if (ft_strncmp(cmd.tkn[0], "echo", ft_strlen(cmd.tkn[0])) == 0)
		exec_echo(&cmd);
	else if (ft_strncmp(cmd.tkn[0], "pwd", ft_strlen(cmd.tkn[0])) == 0)
		exec_pwd();
	else
		execve(path, cmd.tkn, g_envp);
}

int	exec_pepe(t_cmd cmd, int fd_out)
{
	int		pipefd[2];
	pid_t	pid;
	char	*path;

	pid = 1;
	path = NULL;
	pipe(pipefd);
	check_cmd(&cmd, &path, &pid);
	if (pid == 0)
	{
		child_proc_(cmd, path, fd_out, pipefd);
	}
	else
		close(pipefd[1]);
	if (path)
		free(path);
	return (pipefd[0]);
}
