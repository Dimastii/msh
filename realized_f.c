//
// Created by Cloyster Veeta on 3/20/21.
//
#include "main.h"

char *pwd()
{
    char *dir = malloc(1000000);
    getcwd(dir, 1000000);
    printf("%s\n", dir);
    return (dir);
}

void cd(char *path)
{
    if (chdir(path) == -1)
        printf("bash: cd: %s: No such file or directory\n", path);
}

