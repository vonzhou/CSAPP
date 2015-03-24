/*
 * p661 -- code/conc/echoservert.c
 *
 * 在 UNIX 系统下编译和运行这段代码：
 *
 * unix> make echoservert
 * unix> ./echoservert 8192
 */

#include "csapp.h"

void echo(int connfd);
void *thread(void *vargp);

int main(int argc, char **argv)
{
        int listenfd, *connfdp, port;
        socklen_t clientlen = sizeof(struct sockaddr_in);
        struct sockaddr_in clientaddr;
        pthread_t tid;

        if (argc != 2) {
                fprintf(stderr, "usage: %s <port>\n", argv[0]);
                exit(0);
        }
        port = atoi(argv[1]);
        listenfd = Open_listenfd(port);
        while (1) {
                connfdp = Malloc(sizeof(int));
                *connfdp = Accept(listenfd, (SA *) &clientaddr, &clientlen);
                Pthread_create(&tid, NULL, thread, connfdp);
        }
}

/* Thread routine */
void *thread(void *vargp)
{
        int connfd = *((int *)vargp);
        Pthread_detach(pthread_self());
        Free(vargp);
        echo(connfd);
        Close(connfd);
        return NULL;
}
