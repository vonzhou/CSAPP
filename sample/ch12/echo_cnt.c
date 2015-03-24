/*
 * p675 -- code/conc/echo_cnt.c
 *
 * 从客户端接收的所有字节计数
 *
 * 下面的代码展示了一个从线程例程调用的初始化程序包的一般技术。
 */

#include "csapp.h"

static int byte_cnt;            /* Byte counter */
static sem_t mutex;             /* and the mutex that protects it */

static void init_echo_cnt(void)
{
        Sem_init(&mutex, 0, 1);
        byte_cnt = 0;
}

void echo_cnt(int connfd)
{
        int n;
        char buf[MAXLINE];
        rio_t rio;
        static pthread_once_t once = PTHREAD_ONCE_INIT;

        Pthread_once(&once, init_echo_cnt);
        Rio_readinitb(&rio, connfd);
        while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
                P(&mutex);
                byte_cnt += n;
                printf("thread %d receive %d (%d total) bytes on fd %d\n",
                       (int)pthread_self(), n, byte_cnt, connfd);
                V(&mutex);
                Rio_writen(connfd, buf, n);
        }
}
