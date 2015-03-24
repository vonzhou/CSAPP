/*
 * 8.2
 *
 * A. 子进程的输出是什么？
 * B. 父进程的输出是什么？
 */

#include "csapp.h"

int main()
{
    pid_t pid;
    int x = 1;

    pid = Fork();
    if (pid == 0) {             /* child */
        printf("child: x=%d\n", ++x);
        exit(0);
    }

    /* parent */
    printf("parent: x=%d\n", --x);
    exit(0);
}
