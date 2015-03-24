/*
 * p510 -- code/ecf/sigint1.c
 *
 * 这个程序捕获用户在键盘上输入 Ctrl-C 时外壳发送的 SIGINT 信号。SIGINT 的默认行
 * 为是立刻终止该进程。在这个示例中，我们将默认行为修改为捕获信号，输出一条信息，
 * 然后终止该进程
 *
 * $ gcc -I../../common sigint1.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

void handler(int sig)           /* SIGINT handler */
{
        printf("Caught SIGINT\n");
        exit(0);
}

int main()
{
        /* Install the SIGINT handler */
        if (signal(SIGINT, handler) == SIG_ERR)
                unix_error("signal error");

        pause();                /* Wait for the receipt of a signal */

        exit(0);
}
