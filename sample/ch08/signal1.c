/*
 * p512 -- code/ecf/signal1.c
 *
 * 这个程序的基本结构是一个父进程创建一些子进程，这些子进程独立运行一会儿，然后终
 * 止。父进程必须回收子进程，以避免在系统中留下僵死进程。父进程在子进程运行时可以
 * 自由地做其他工作。
 *
 * 这个程序是有缺陷的，因为它无法处理信号阻塞、信号不排队等待和系统调用被中断这些
 * 情况
 *
 * 哪里出错了呢？问题在于我们的代码没有解决信号可以阻塞和不会排队等待这样的情况。
 * 发生的情况是：父进程接受并捕获了第一个信号。当处理程序还在处理第一个信号时，第
 * 二个信号就传送并添加到了待处理信号集合里。然而，因为 SIGCHLD 信号被 SIGCHLD 处
 * 理程序阻塞了，所以第二个信号就不会被接收。此后不久，就在处理程序还在处理第一个
 * 信号时，第三个信号到达了。因为已经有了一个待处理的 SIGCHLD，第三个 SIGCHLD 信
 * 号会被丢弃。一段时间之后，处理程序返回，内核注意到有一个待处理的 SIGCHLD 信号，
 * 就迫使父进程接收这个信号。父进程捕获这个信号，并第二次执行处理程序。在处理程序
 * 完成对第二个信号的处理之后，已经没有待处理的 SIGCHLD 信号了，而且也绝不会有，
 * 因为第三个 SIGCHLD 的所有信息都已经丢失了。
 *
 * 由此得到的重要教训是，不可以用信号来对其他进程中发生的事件计数
 *
 * $ gcc -I../../common signal1.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

void handler1(int sig)
{
        pid_t pid;

        if ((pid = waitpid(-1, NULL, 0)) < 0)
                unix_error("waitpid error");
        printf("Handler reaped child %d\n", (int)pid);
        Sleep(2);
        return;
}

int main()
{
        int i, n;
        char buf[MAXBUF];

        if (signal(SIGCHLD, handler1) == SIG_ERR)
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
