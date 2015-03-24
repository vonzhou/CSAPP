/*
 * p509 -- code/ecf/alarm.c
 *
 * 使用 alarm() 函数来调度周期性事件
 *
 * 这个程序安排自己被 SIGALRM 信号在 5 秒内每秒中断一次。当传送第 6 个 SIGALRM 信
 * 号时，它就终止。
 *
 * 注意：这里设置了一个信号处理函数，只要进程收到一个 SIGALRM 信号，就异步地调用
 *     该函数，中断 main 程序中的无限 while 循环
 *
 * $ gcc -I../../common alarm.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

void handler(int sig)
{
        static int beeps = 0;

        printf("BEEP\n");
        if (++beeps < 5)
                Alarm(1);       /* Next SIGALRM will be delivered in 1 second */
        else {
                printf("BOMP!\n");
                exit(0);
        }
}

int main()
{
        Signal(SIGALRM, handler); /* Install SIGALRM handler */
        Alarm(1);                 /* Next SIGALRM will be delivered in 1s */

        while (1) {
                ;            /* Signal handler returns control here each time */
        }
        exit(0);
}
