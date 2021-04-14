//
// Created by Cloyster Veeta on 3/20/21.
//

#include "minishell.h"

void exec_ls(char *file, char **argv, char ***envp)
{
	execve(file, argv, *envp);
}

char		*findbin(char *cmd, char **envp)
{
	char *path;
	char *str;
	char *fre;
	char *fre_str;
	path = NULL;
//	cmd[ft_strlen(cmd)] = '\0';
	struct stat buff;
	if ((str = ft_strdup(check_glob("PATH", envp)))) {
		fre_str = str;
		path = str;
//		printf("1 |%s \n", path);
		while ((str = ft_strchr(str, ':'))) {
			*str = '\0';
			str++;
			path = ft_strjoins(path, '/');
			fre = path;
			path = ft_strjoin(path, cmd);
			free(fre);
			if (stat(path, &buff) == 0) {
//				printf("0 |%s \n", path);
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

void		stdexec(t_cmd *cmd, char ***envp, int fd_out)
{
	int pid = fork();
	char *path;
	if (ft_strncmp(cmd->tokens[0], "exit", ft_strlen(cmd->tokens[0])) == 0)
	{
		exit(0);
	}
	if (pid == 0) {
//		dup2(fd_out, 1);
		if ((path = findbin(cmd->tokens[0], *envp))) {
			printf("~exec path:%s \n", path);
			execve(path, cmd->tokens, *envp);
		}
		else
			printf(" А где бинарник то?:%s \n", path);
	}
	else if (pid < 0)
	{
		//принт еррор
	}
	else
	{
		if (fd_out != 1)
			close(fd_out);
		wait(NULL);
	}
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

