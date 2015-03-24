/*
 * 8.24
 *
 * mofaph@gmail.com
 *
 * unix> cc -I../common ex8-24.c ../common/csapp.c -lpthread
 */

#include "csapp.h"
#define N 2

int main(void)
{
        int status, i;
        pid_t pid;

        /* Parent creates N children */
        for (i = 0; i < N; i++)
                if ((pid = Fork()) == 0) { /* Child */
                        int *p = NULL;
                        *p = 0; /* write to invalid address */
                        exit(100+i);
                }

        /* Parent reaps N children in no particular order */
        while ((pid = waitpid(-1, &status, 0)) > 0) {
                if (WIFEXITED(status)) {
                        printf("child %d terminated normally with exit status=%d\n",
                               pid, WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                        int signo = WTERMSIG(status);
                        char str[1024];
                        snprintf(str, sizeof(str), "child %d terminated by signal %d", pid, signo);
                        psignal(signo, str);
                } else {
                        printf("child %d terminated abnormally\n", pid);
                }
        }

        /* The normal termination is if there are no more children */
        if (errno != ECHILD)
                unix_error("waitpid error");

        exit(0);
}
