/*
 * p498 -- code/ecf/waitpid1.c
 *
 * 使用 waitpid 函数不按照特定的顺序回收僵死子进程
 */

#include "csapp.h"
#define N 2

int main(void)
{
        int status, i;
        pid_t pid;

        /* Parent creates N children */
        for (i = 0; i < N; i++)
                if ((pid = Fork()) == 0) /* Child */
                        exit(100+i);

        /* Parent reaps N children in no particular order */
        while ((pid = waitpid(-1, &status, 0)) > 0) {
                if (WIFEXITED(status))
                        printf("child %d terminated normally with exit status=%d\n",
                               pid, WEXITSTATUS(status));
                else
                        printf("child %d terminated abnormally\n", pid);
        }

        /* The normal termination is if there are no more children */
        if (errno != ECHILD)
                unix_error("waitpid error");

        exit(0);
}
