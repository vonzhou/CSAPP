/*
 * p515 -- code/ecf/signal3.c
 *
 * 这个程序是 signal2.c 的改进版本，它正确地解决了系统调用可能被中断的可能性。
 *
 * 为了编写可移植的信号处理代码，我们必须考虑系统调用过早返回的可能性，然后当它发
 * 生时手动重启它们。
 *
 * $ gcc -I../../common signal3.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

void handler2(int sig)
{
        pid_t pid;

        while ((pid = waitpid(-1, NULL, 0)) > 0)
                printf("Handler reaped child %d\n", (int)pid);
        if (errno != ECHILD)
                unix_error("waitpid error");
        Sleep(2);
        return;
}

int main()
{
        int i, n;
        char buf[MAXBUF];
        pid_t pid;

        if (signal(SIGCHLD, handler2) == SIG_ERR)
                unix_error("signal error");

        /* Parent creates children */
        for (i = 0; i < 3; i++) {
                pid = Fork();
                if (pid == 0) {
                        printf("Hello from child %d\n", (int)getpid());
                        Sleep(1);
                        exit(0);
                }
        }

        /* Manually restart the read call if it is interrupted */
        while ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
                if (errno != EINTR)
                        unix_error("read");

        printf("Parent processing input\n");
        while (1)
                ;

        exit(0);
}
