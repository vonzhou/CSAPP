/*
 * p508 -- code/ecf/kill.c
 *
 * 父进程用 kill() 发送 SIGKILL 信号给它的子进程
 *
 * $ gcc -I../../common kill.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

int main()
{
        pid_t pid;

        /* Child sleeps until SIGKILL signal received, then dies */
        if ((pid = Fork()) == 0) {
                Pause();        /* Wait for a signal to arrive */
                printf("control should never reach here!\n");
                exit(0);
        }

        /* Parent sends a SIGKILL signal to a child */
        Kill(pid, SIGKILL);
        exit(0);
}
