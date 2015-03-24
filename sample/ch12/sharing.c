/*
 * p662 -- code/conc/sharing.c
 *
 * 这段代码用来说明关于多线程程序中的共享变量。下面的代码由一个创建了两个对等线程
 * 的主线程组成。主线程传递一个唯一的 ID 给每个对等线程，每个对等线程利用这个 ID
 * 输出一条个性化的信息，以及调用该线程例程的总次数。
 *
 * 在 UNIX 系统下编译和运行：
 *
 * unix> make sharing # 编译时可能会有警告，可以忽略
 * unix> ./sharing
 */

#include "csapp.h"

#define N 2

void *thread(void *vargp);

char **ptr;                     /* Global variable */

int main()
{
        int i;
        pthread_t tid;
        char *msgs[N] = {
                "Hello from foo",
                "Hello from bar"
        };

        ptr = msgs;
        for (i = 0; i < N; i++)
                Pthread_create(&tid, NULL, thread, (void *)i);
        Pthread_exit(NULL);
        return 0;
}

void *thread(void *vargp)
{
        int myid = (int)vargp;
        static int cnt = 0;
        printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt);
        return NULL;
}
