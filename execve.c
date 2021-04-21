//
// Created by Cloyster Veeta on 3/20/21.
//
#include "minishell.h"

char		*findbin(char *cmd, char **envp)
{
	char *path;
	char *str;
	char *fre;
	char *fre_str;
	path = NULL;
	struct stat buff;
	if (stat(cmd, &buff) == 0)
	{
		return (cmd);
	}
	if ((str = ft_strdup(check_glob("PATH", envp)))) {
		fre_str = str;
		path = str;
		while ((str = ft_strchr(str, ':'))) {
			*str = '\0';
			str++;
			path = ft_strjoins(path, '/');
			fre = path;
			path = ft_strjoin(path, cmd);
			free(fre);
			if (stat(path, &buff) == 0) {
				free(fre_str);
				return (path);
			}
			fre = path;
			path = str;
			free(fre);
		}
		free(fre_str);
	}
	else
	{
		printf(" А где PATH то?\n");
	}
	return NULL;
}

void	sighandler(int signum)
{
	write(1, "\n", 1);
//	printf("Caught signal %d, coming out...\n", signum);
}
void		stdexec(t_cmd *cmd, char ***envp, int fd_out)
{
	pid_t		pid;
	char		*path;

	path = NULL;
	pid = 1;
	if (ft_strncmp(cmd->tokens[0], "exit", ft_strlen(cmd->tokens[0])) == 0)
	{
		exit(0);
	}
	if (ft_strncmp(cmd->tokens[0], "echo", ft_strlen(cmd->tokens[0])) == 0 || (path = findbin(cmd->tokens[0], *envp)))
	{
		pid = fork();
	}
	else
		printf(" А где бинарник то?:%s \n", path);
	if (pid == 0)
	{
		///pid == 0 - сигнал отправляется всем членам группы
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
			execve(path, cmd->tokens, *envp);
		}
	}
	else if (pid < 0)
	{
		///pid < -1 - сигнал отправляется группе с номером -pid
	}
	else
	{
		///pid > 0 - сигнал отправляется конкретному процессу
		if (fd_out != 0) {
			close(fd_out);
		}
	}
//	signal(SIGINT, ft_quit);///SIGINT code:2 Term Interrupt from keyboard
//	signal(SIGQUIT, ft_quit);///SIGQUIT code:3 Core Quit from keyboard
	if (path)
		free(path);
	wait(0);
}

int			exec_pepe(char **str, t_cmd cmd, int fd_out, char ***envp)
{
	int pipefd[2];
	pid_t pid;
	char *path;


	pid = 1;
	path = NULL;
	pipe(pipefd);
	if (ft_strncmp(cmd.tokens[0], "echo", ft_strlen(cmd.tokens[0])) == 0 || (path = findbin(cmd.tokens[0], *envp)))
	{
		pid = fork();
	}
	else
		printf(" А где бинарник то?:%s \n", path);


	if (pid == 0) {
		dup2(fd_out, 0);
		if (cmd.fd_write == 1)
			dup2(pipefd[1], 1);
		else
			dup2(cmd.fd_write, 1);
		close(pipefd[0]);
		if (ft_strncmp(cmd.tokens[0], "echo", ft_strlen(cmd.tokens[0])) == 0)
		{
			exec_echo(&cmd);
		}
		else
			execve(path, cmd.tokens, *envp);
	}
	else
	{
		close(pipefd[1]);
	}

	if (path)
		free(path);
	return(pipefd[0]);
}
