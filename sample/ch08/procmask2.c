/*
 * p520 -- code/ecf/procmask2.c
 *
 * 这个程序消除了 procmask1.c 中的竞争，用 sigprocmask() 来同步进程。
 *
 * 通过在调用 fork() 之前，阻塞 SIGCHLD 信号，然后在我们调用了 addjob() 之后就取
 * 消阻塞这些信号，我们保证了在子进程被添加到作业列表之后回收该子进程。
 *
 * 注意，子进程继承了它们父进程的被阻塞集合，所以我们必须在调用 execve() 之前，小
 * 心地解除子进程中阻塞的 SIGCHLD 信号。
 *
 * 这样，父进程保证在相应的 deletejob() 之前执行 addjob()。
 */

#include "csapp.h"

void handler(int sig)
{
        pid_t pid;
        while ((pid = waitpid(-1, NULL, 0)) > 0) /* Reap a zombie child */
                deletejob(pid); /* Delete the child from the job list */
        if (errno != ECHILD)
                unix_error("waitpid error");
}

int main(int argc, char **argv)
{
        int      pid;
        sigset_t mask;

        Signal(SIGCHLD, handler);
        initjobs();                   /* Initialize the job list */

        while (1) {
                Sigemptyset(&mask);
                Sigaddset(&mask, SIGCHLD);
                Sigprocmask(SIG_BLOCK, &mask, NULL); /* Block SIGCHLD */

                /* Child process */
                if ((pid = Fork()) == 0) {
                        Sigprocmask(SIG_UNBLOCK, &mask, NULL); /* Unblock SIGCHLD */
                        Execve("/bin/date", argv, NULL);
                }

                /* Parent process */
                addjob(pid);    /* Add the child to the job list */
                Sigprocmask(SIG_UNBLOCK, &mask, NULL); /* Unblock SIGCHLD */
        }

        exit(0);
}
