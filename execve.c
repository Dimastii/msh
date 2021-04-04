//
// Created by Cloyster Veeta on 3/20/21.
//

#include "main.h"

void exec_ls(char *file, char **argv, char **envp)
{
	execve(file, argv, envp);
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

