/*
 * p658 -- code/conc/hello.c
 *
 * 下面的代码展示了一个简单的 Pthreads 程序。主线程创建一个对等线程，然后等待它的
 * 终止。对等线程输出“Hello, world\n”并且终止。当主线程检测到对等线程终止后，它
 * 就通过调用 exit() 终止该进程。
 *
 * unix> cc -Wall -I../../common hello.c ../../common/csapp.c -lpthread -o hello
 * unix> ./hello
 */

#include "csapp.h"

void *thread(void *argvp);

int main()
{
        pthread_t tid;
        Pthread_create(&tid, NULL, thread, NULL);
        Pthread_join(tid, NULL);
        exit(0);
}

void *thread(void *argvp)       /* Thread routine */
{
        printf("Hello, world!\n");
        return NULL;
}
