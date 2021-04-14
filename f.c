#include "minishell.h"







void open_write_in_file(char *name_file, int fd_pred)
{
    int fd;
    char *text = malloc(10);
    fd = open(name_file, O_WRONLY);

    read(fd_pred, &text, 9);
    text[9] = '\0';
    write(fd, text, ft_strlen(text));
    close(fd);
    write(0, text, ft_strlen(text));
}

void pepe1()
{
    int pepe[2];
    char *text;

    if (!pipe(pepe))
    {
        text = pwd();

        write(pepe[1], &text, ft_strlen(text)); //положили в пайп

        ///foo() //функция распределения пайпов по функциям или fd

        open_write_in_file("/Users/cveeta/CLionProjects/minishell/qqq.txt", pepe[0]);
    }
    else{/*pipe error*/}

}
