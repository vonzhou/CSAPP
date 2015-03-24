/*
 * 练习题 8.8 下面这个程序的输出是什么？
 *
 * 这个程序打印“213”，这是卡尔基梅隆大学 CS:APP 课程的缩写名
 */

#include <stdio.h>              /* printf() fflush() */
#include <stdlib.h>             /* exit() */

#include <sys/types.h>          /* pid_t */
#include <sys/wait.h>           /* waitpid() */
#include <signal.h>             /* kill() signal() */
#include <unistd.h>             /* fork() */

pid_t pid;
int counter = 2;

void handler1(int sig)
{
        counter = counter - 1;
        printf("%d", counter);
        fflush(stdout);
        exit(0);
}

int main()
{
        signal(SIGUSR1, handler1);

        printf("%d", counter);
        fflush(stdout);

        if ((pid = fork()) == 0) {    /* child */
                while (1) {};
        }
        kill(pid, SIGUSR1);
        waitpid(-1, NULL, 0);
        counter = counter + 1;
        printf("%d", counter);
        exit(0);
}
