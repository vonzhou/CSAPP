/*
 * p674 -- code/conc/echoservert_pre.c
 *
 * 基于预线程化的并发服务器
 *
 * 服务器是由一个主线程和一组工作者线程构成的。主线程不断地接受来自客户端的连接请
 * 求，并将得到的连接描述福放在一个有限缓冲区中。每一个工作者线程反复地从共享缓冲
 * 区中取出描述符，为客户端服务，然后等待下一个描述符。
 *
 * 在类 UNIX 系统下编译和运行这个程序：
 *
 * unix> make echoserver_pre
 * unix> ./echoserver_pre 8192 # server
 *
 * # client 1
 * unix> telnet 127.0.0.1 8192
 * unix> hello # press return, and see what server output
 */

#include "csapp.h"
#include "sbuf.h"

#define NTHREADS 4
#define SBUFSIZE 16

void echo_cnt(int connfd);
void *thread(void *vargp);

sbuf_t sbuf;                    /* Shared buffer of connected descriptors */

int main(int argc, char **argv)
{
        int i, listenfd, connfd, port;
        socklen_t clientlen = sizeof(struct sockaddr_in);
        struct sockaddr_in clientaddr;
        pthread_t tid;

        if (argc != 2) {
                fprintf(stderr, "usage: %s <port>\n", argv[0]);
                exit(0);
        }
        port = atoi(argv[1]);
        sbuf_init(&sbuf, SBUFSIZE);
        listenfd = Open_listenfd(port);

        for (i = 0; i < NTHREADS; i++) /* Create worker threads */
                Pthread_create(&tid, NULL, thread, NULL);

        while (1) {
                connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
                sbuf_insert(&sbuf, connfd); /* Insert connfd in buffer */
        }

        return 0;               /* fixed compiler warning */
}

void *thread(void *vargp)
{
        Pthread_detach(pthread_self());
        while (1) {
                int connfd = sbuf_remove(&sbuf); /* Remove connfd from buffer */
                echo_cnt(connfd);                /* Service client */
                Close(connfd);
        }
}
