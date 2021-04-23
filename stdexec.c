//
// Created by Cloyster Veeta on 4/23/21.
//
#include "minishell.h"

void	sighandler(int signum)
{
	signum = signum;
	write(1, "\0", 1);
}

void	check_cmd(t_cmd *cmd, char	**path, pid_t *pid)
{
	if (ft_strncmp(cmd->tkn[0], "exit", ft_strlen(cmd->tkn[0])) == 0)
	{
		exit(0);
	}
	*path = findbin(cmd->tkn[0], g_envp);
	if (ft_strncmp(cmd->tkn[0], "echo", ft_strlen(cmd->tkn[0])) == 0 ||
		ft_strncmp(cmd->tkn[0], "pwd", ft_strlen(cmd->tkn[0])) == 0 ||
		ft_strncmp(cmd->tkn[0], "export", ft_strlen(cmd->tkn[0])) == 0 ||
		ft_strncmp(cmd->tkn[0], "unset", ft_strlen(cmd->tkn[0])) == 0 ||
		ft_strncmp(cmd->tkn[0], "cd", ft_strlen(cmd->tkn[0])) == 0 ||
		 *path)
	{
		*pid = fork();
	}
	else
		printf(" А где бинарник то?:%s \n", *path);
}

void	child_proc(t_cmd *cmd, char	*path, int fd_out)
{
	int	stat;

	dup2(fd_out, 0);
	if (cmd->fd_write != 1)
		dup2(cmd->fd_write, 1);
	if (ft_strncmp(cmd->tkn[0], "echo", ft_strlen(cmd->tkn[0])) == 0)
		exec_echo(cmd);
	else if (ft_strncmp(cmd->tkn[0], "pwd", ft_strlen(cmd->tkn[0])) == 0)
		exec_pwd();
	else
	{
		stat = execve(path, cmd->tkn, g_envp);
		exit(stat);
	}
}

void	stdexec(t_cmd *cmd, int fd_out)
{
	pid_t		pid;
	char		*path;

	path = NULL;
	pid = 1;
	check_cmd(cmd, &path, &pid);
	if (pid == 0)
	{
		child_proc(cmd, path, fd_out);
	}
	else
	{
		if (fd_out != 0)
		{
			close(fd_out);
		}
	}
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	if (path)
		free(path);
	wait(0);
}
