/*
 * 8.20
 *
 * mofaph@gmail.com
 *
 * 使用 execve 编写一个叫做 myls 的程序，该程序的行为和 /bin/ls 程序的一样。你的
 * 程序应该接受相同的命令行参数，解释同样的环境变量，并产生相同的输出。
 *
 * ls 程序从 COLUMNS 环境变量中获得屏幕的宽度。如果没有设置 COLUMNS，那么 ls 会假
 * 设屏幕宽 80 列。因此，你可以通过把 COLUMNS 环境设置小于 80，来检查你对环境变量
 * 的处理：
 *
 * unix> cc ex8-20.c -o myls
 * unix> setenv COLUMNS 40
 * ...output is 40 column wide
 * unix> ./myls
 * unix> unsetenv COLUMNS
 * unix> ./myls
 * ...output is now 80 columns wide
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <wait.h>

extern char *environ[];

int main(int argc, char *argv[])
{
        pid_t pid;

        pid = fork();
        if (pid < 0) {
                perror("fork");
                exit(1);
        }

        /* child */
        else if (pid == 0) {
                execve("/bin/ls", argv, environ);
                /* Never reach here */
                perror("execve");
                exit(2);
        }

        /* parent */
        else {
                int status, ret;
                ret = waitpid(pid, &status, 0);

                /* error */
                if (ret < 0) {
                        perror("waitpid");
                        exit(3);
                }

                /* nothing */
        }

        return 0;
}
