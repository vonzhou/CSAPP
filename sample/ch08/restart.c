/*
 * p523 -- code/ecf/restart.c
 *
 * 非本地跳转的另一个重要应用是使一个信号处理程序分支到一个特殊的代码位置，而不是
 * 返回到被信号到达中断了的指令的位置。
 *
 * 这个示例程序，在一个用户键入 ctrl-c 时，使用非本地跳转来重启到它自身
 *
 * 在程序第一次启动时，对 sigsetjmp() 的初始调用保存调用环境和信号的上下文（包括
 * 待处理的和被阻塞的信号向量）。随后，主函数进入一个无限处理循环。当用户键入
 * ctrl-c 时，外壳发送一个 SIGINT 信号给这个进程，该进程捕获这个信号。不是从信号
 * 处理程序返回，如果是这样信号处理程序会将控制返回给被中断的处理循环，反之，处理
 * 程序执行一个非本地跳转，回到主函数的开始处。
 *
 * unix> gcc -I../../common restart.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

sigjmp_buf buf;

void handler(int sig)
{
        siglongjmp(buf, 1);
}

int main()
{
        Signal(SIGINT, handler);

        if (!sigsetjmp(buf, 1))
                printf("starting\n");
        else
                printf("restarting\n");

        while (1) {
                Sleep(1);
                printf("processing...\n");
        }
        exit(0);
}
