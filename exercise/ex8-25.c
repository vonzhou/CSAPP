/*
 * 8.25
 *
 * mofaph@gmail.com
 *
 * 编写 fgets 函数的一个版本，叫做 tfgets，它 5 秒中后会超时。tfgets 函数接收和
 * fgets 相同的输入。如果用户在 5 秒内不键入一个输入行，tfgets 返回 NULL。否则，
 * 它返回一个指向输入行的指针。
 *
 * unix> cc ex8-25.c t8-25.c
 */

#include <stdio.h>
#include <setjmp.h>

#include <unistd.h>
#include <signal.h>

static sigjmp_buf env;

void signal_handler(int signo)
{
        const int TIME_OUT = 1;

        if (signo == SIGALRM)
                siglongjmp(env, TIME_OUT);
}

char *tfgets(char *s, int size, FILE *stream)
{
        /* The following code was token from common/csapp.c, Signal() implemation */
        struct sigaction action, old_action;
        action.sa_handler = signal_handler;
        sigemptyset(&action.sa_mask); /* block sigs of type being handled */
        action.sa_flags = SA_RESTART; /* restart syscalls if possible */
        if (sigaction(SIGALRM, &action, &old_action) < 0) {
                perror("sigaction");
                return NULL;
        }

        unsigned int max_waiting = 5; /* seconds */
        alarm(max_waiting);

        int rc;
        rc = sigsetjmp(env, 1); /* saving signal mask in env */
        if (rc == 0) {
                return fgets(s, size, stream);
        } else {                /* time out */
                return NULL;
        }
}
