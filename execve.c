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
	if (stat(cmd, &buff) == 0) {
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
				return (path);
			}
			fre = path;
			path = str;//лик
			free(fre);
		}
//		free(fre_str);
	}
	else
	{
		printf(" А где PATH то?\n");
	}
	return NULL;
}
void sighandler(int signum) {
	printf("Caught signal %d, coming out...\n", signum);
}
void		stdexec(t_cmd *cmd, char ***envp, int fd_out)
{
	pid_t pid;
	char *path;
	struct stat buff;

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

	signal(SIGINT, sighandler);
	if (pid == 0) {

		dup2(fd_out, 0);
		if (ft_strncmp(cmd->tokens[0], "echo", ft_strlen(cmd->tokens[0])) == 0)
		{
			exec_echo(cmd);
		}
		else {
			execve(path, cmd->tokens, *envp);
		}
	}
	else if (pid < 0)
	{
		//принт еррор
	}
	else
	{
		if (fd_out != 0) {
			close(fd_out);
		}
	}
	wait(0);
}

int 		exec_pepe(char **str, t_cmd cmd, int fd_out, char ***envp, int fd_arr[])
{
	int pipefd[2];
	pid_t pid;
	char *path;
	static int i;


	pid = 1;

	pipe(pipefd);
	fd_arr[i] = pipefd[0];
	if (ft_strncmp(cmd.tokens[0], "echo", ft_strlen(cmd.tokens[0])) == 0 || (path = findbin(cmd.tokens[0], *envp)))
	{
		pid = fork();
	}
	else
		printf(" А где бинарник то?:%s \n", path);

	if (pid == 0) {
		dup2(fd_out, 0);

		dup2(pipefd[1], 1);
		close(pipefd[0]);
		if (ft_strncmp(cmd.tokens[0], "echo", ft_strlen(cmd.tokens[0])) == 0)
		{
			printf("qwe\n\n\n\n\n\n\n");
			exec_echo(&cmd);
		}
		else
			execve(path, cmd.tokens, *envp);
	}
	else
	{
//		if (fd_out != 0) {
//			waitpid(pid, NULL, 0);
//			close(fd_out);
//		}
//		waitpid(pid, NULL, 0);
		close(pipefd[1]);
	}
	++i;
//	wait(NULL);
	return(pipefd[0]);
}








void lets_exec(int pepeout[2], int pepein[2], char *file, char **argv, char **envp, int mode){
    int	status;
    char *text = malloc(100);
    int pid;
    int fd = open("/Users/cveeta/CLionProjects/minishell/qqq.txt", O_CREAT | O_WRONLY, 0777);
    pid = fork();

    if (pid == 0) {
        if (mode) {
            dup2(pepeout[0], 0);
        }
        else {
        }
        dup2(pepein[1], 1);
        status = execve(file, argv, envp);
    }
    else if (pid < 0)
    {
        //принт еррор
    }
    else
    {
        wait(NULL);
    }
}

