//
// Created by Cloyster Veeta on 4/23/21.
//
#include "minishell.h"

void	sighandler(int signum)
{
	signum = signum;
	write(1, "\0", 1);
}

void		stdexec(t_cmd *cmd, int fd_out)
{
	pid_t		pid;
	char		*path;

	path = NULL;
	pid = 1;
	if (ft_strncmp(cmd->tokens[0], "exit", ft_strlen(cmd->tokens[0])) == 0)
	{
		exit(0);
	}
	if (ft_strncmp(cmd->tokens[0], "echo", ft_strlen(cmd->tokens[0])) == 0 || (path = findbin(cmd->tokens[0], g_envp)))
	{
		pid = fork();
	}
	else
		printf(" А где бинарник то?:%s \n", path);
	if (pid == 0)
	{
		dup2(fd_out, 0);
		if (cmd->fd_write != 1)
			dup2(cmd->fd_write, 1);
		if (ft_strncmp(cmd->tokens[0], "echo", ft_strlen(cmd->tokens[0])) == 0)
		{
			exec_echo(cmd);
		}
		else if (ft_strncmp(cmd->tokens[0], "pwd", ft_strlen(cmd->tokens[0])) == 0)
		{
			exec_pwd();
		}
		else
		{
			execve(path, cmd->tokens, g_envp);
		}
	}
	else
	{
		if (fd_out != 0) {
			close(fd_out);
		}
	}
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	if (path)
		free(path);
	wait(0);
}
