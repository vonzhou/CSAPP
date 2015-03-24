/*
 * p521 -- code/ecf/rfork.c
 *
 * 下面的代码包含了一个暴露竞争的简便技巧
 *
 * 像 procmask2.c 那样的竞争难以发现，因为它们依赖于内核相关的调度决策。在一次
 * fork() 调用之后，有些内核调度子进程先运行，而有些内核调度父进程先运行。如果你
 * 要在后一种系统上运行 procmask1.c 的代码，它绝不会失败，无论你测试多少遍。但是
 * 一旦在前一种系统上运行这段代码，那么竞争就会暴露出来，代码会失败。
 *
 * 下面的代码是一个 fork() 的包装函数，它随机地决定父进程和子进程执行的顺序。父进
 * 程和子进程扔一枚硬币来决定谁会休眠，因而给另一个进程被调度的机会。
 *
 * 如果我们运行这个代码多次，那么我们就有极高的概率会测试到父子进程执行的两种顺序，
 * 无论这个特定内核的调度策略是什么样子的。
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

/* Sleep for a random period between [0, MAX_SLEEP] us. */
#define MAX_SLEEP 100000

/* Macro that maps val into the range [0, RAND_MAX] */
#define CONVERT(val) (((double)val)/(double)RAND_MAX)

pid_t Fork(void)
{
        static struct timeval time;
        unsigned              bool, secs;
        pid_t                 pid;

        /* Generate a different seed each time the function is called */
        gettimeofday(&time, NULL);
        srand(time.tv_usec);

        /* Determine whether to sleep in parent of child and for how long */
        bool = (unsigned)(CONVERT(rand()) + 0.5);
        secs = (unsigned)(CONVERT(rand()) * MAX_SLEEP);

        /* Call the real fork function */
        if ((pid = fork()) < 0)
                return pid;

        /* Randomly decide to sleep in the parent or the child */
        if (pid == 0) {         /* Child */
                if (bool) {
                        usleep(secs);
                }
        }
        else {                  /* Parent */
                if (!bool) {
                        usleep(secs);
                }
        }

        /* Return the PID like a normal fork call */
        return pid;
}
