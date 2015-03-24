/*
 * p512 -- code/ecf/signal2.c
 *
 * 这个程序是 signal1.c 的改进版本，它能够正确解决信号会阻塞和不会排队等待的情况。
 *
 * 修复 signal1.c 的缺陷的一个思路是：存在一个待处理的信号只是暗示自进程最后一次
 * 收到一个信号以来，至少已经有一个这种类型的信号被发送了。所以我们必须修改
 * SIGCHLD 处理程序，使得每次 SIGCHLD 处理程序被调用时，回收尽可能多的僵死子进程。
 *
 * 然而，它没有考虑系统调用被中断的可能性。
 *
 * 在一个较老版本的 Solaris 系统中，在从键盘上进行输入之前，被阻塞的 read 系统调
 * 用就提前返回一个错误。出现这个问题是因为在特定的 Solaris 系统上，诸如 read 这
 * 样的慢速系统调用在被信号发送中断后，是不会自动重启的。相反，和 Linux 系统自动
 * 重启被中断的系统调用不同，它们会提前返回给调用应用程序一个错误条件。
 *
 * $ gcc -I../../common signal2.c ../../common/csapp.c -lpthread
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

        if (signal(SIGCHLD, handler2) == SIG_ERR)
                unix_error("signal error");

        /* Parent creates children */
        for (i = 0; i < 3; i++) {
                if (Fork() == 0) {
                        printf("Hello from child %d\n", (int)getpid());
                        Sleep(1);
                        exit(0);
                }
        }

        /* Parent waits for terminal input and then processes it */
        if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
                unix_error("read");

        printf("Parent processing input\n");
        while (1)
                ;

        exit(0);
}
