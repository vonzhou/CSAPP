/*
 * 8.21
 *
 * mofaph@gmail.com
 *
 * 下面程序可能的输出序列是什么？
 *
 * unix> cc ex8-21.c
 * unix> ./a.out
 *
 * 1. fork 失败： bc
 * 2. fork 成功
 *     2.1 子进程先运行： abc
 *     2.2 父进程先运行： bac
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
        if (fork() == 0) {
                printf("a");
                exit(0);
        } else {
                printf("b");
                waitpid(-1, NULL, 0);
        }
        printf("c");
        exit(0);
}
