/*
 * 8.6 -- p502
 *
 * 编写一个叫做 myecho 的程序，它打印出它的命令行参数和环境变量
 *
 * unix> cc ex8-6.c -o myecho
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
        int i;

        printf("Command line arguments:\n");
        for (i = 0; i < argc; i++)
                printf("\targv[%d]: %s\n", i, argv[i]);
        printf("\n");

        printf("Environment variables:\n");
        extern char **environ;
        for (i = 0; environ[i] != NULL; i++)
                printf("\tenvp[%2d]: %s\n", i, environ[i]);

        return 0;
}
