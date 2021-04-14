//
// Created by Cloyster Veeta on 3/27/21.
//

#include "minishell.h"

void pepe(char **argv, char **envp)
{
    char *text = malloc(100);
    char **ar = (char **)malloc(sizeof (char *)*4);
    ar[0] = strdup("/bin/ls");
    ar[1] = strdup("/usr/bin/wc");
    ar[2] = strdup("/usr/bin/wc");
    ar[3] = strdup("/usr/bin/wc");
    ar[4] = NULL;

    int pepeout[2];
    int pepetemp[2];
    int pepein[2];

    pipe(pepeout);
    pipe(pepein);
    int i = 0;
    int mode = 0;
    while (i < 3)
    {
        close(pepeout[1]);
        lets_exec(pepeout, pepein,ar[i] ,argv, envp, mode);
        mode = 1;
        pepetemp[0] = pepein[0];
        pepetemp[1] = pepein[1];
        pepeout[0] = pepetemp[0];
        pepeout[1] = pepetemp[1];
        pepein[0] = pepeout[0];
        pepein[1] = pepeout[1];
        pipe(pepein);
        i++;
    }
    read(pepeout[0], text, 100);
    write(1, text, 100);
    close(pepeout[1]);
}