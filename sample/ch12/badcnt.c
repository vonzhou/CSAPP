/*
 * p664 -- code/conc/badcnt.c
 *
 * 下面的代码展示了多线程程序中的共享变量的同步错误问题。它创建两个线程，每个线程
 * 都对共享计数变量 cnt 加 1.因为每个线程都对计数器增加了 niters 次，我们预计它的
 * 最终值是 2×niters。这看上去简单而直接。然后，在 Linux 系统上运行这个程序时，
 * 我们不仅得到错误的答案，而且每次得到的答案都还不相同。
 *
 * 在类 UNIX 系统中编译和运行：
 *
 * unix> make badcnt
 * unix> ./badcnt
 */

#include "csapp.h"

void *thread(void *vargp);      /* Thread routine prototype */

/* Global shared variable */
volatile int cnt = 0;           /* Counter */

int main(int argc, char **argv)
{
        int niters;
        pthread_t tid1, tid2;

        /* Check input argument */
        if (argc != 2) {
                printf("usage: %s <niters>\n", argv[0]);
                exit(0);
        }
        niters = atoi(argv[1]);

        /* Created threads and wait for them to finish */
        Pthread_create(&tid1, NULL, thread, &niters);
        Pthread_create(&tid2, NULL, thread, &niters);
        Pthread_join(tid1, NULL);
        Pthread_join(tid2, NULL);

        /* Check result */
        if (cnt != (2 * niters))
                printf("BOOM! cnt=%d\n", cnt);
        else
                printf("OK cnt=%d\n", cnt);
        exit(0);
}

/* Thread routine */
void *thread(void *vargp)
{
        int i, niters = *((int *)vargp);
        for (i = 0; i < niters; i++)
                cnt++;
        return NULL;
}
