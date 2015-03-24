/*
 * p650 -- code/conc/echoserverp.c
 *
 * 基于进程的并发 echo 服务器。父进程派生一个子进程来处理每个新的连接请求
 *
 * 在 UNIX 系统下编译和运行这个程序：
 *
 * unix> make echoserverp
 * unix> ./echoserverp 16384
 */

#include "csapp.h"

void echo(int connfd);

void sigchld_handler(int sig)
{
        while (waitpid(-1, 0, WNOHANG) > 0)
                ;
        return;
}

int main(int argc, char **argv)
{
        int listenfd, connfd, port;
        socklen_t clientlen = sizeof(struct sockaddr_in);
        struct sockaddr_in clientaddr;

        if (argc != 2) {
                fprintf(stderr, "usage: %s <port>\n", argv[0]);
                exit(0);
        }
        port = atoi(argv[1]);

        Signal(SIGCHLD, sigchld_handler);
        listenfd = Open_listenfd(port);
        while (1) {
                connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
                if (Fork() == 0) {
                        Close(listenfd); /* Child closes its listening socket */
                        echo(connfd);    /* Child services client */
                        Close(connfd);   /* Child closes connection with client */
                        exit(0);
                }
                Close(connfd);  /* Parent closes connected socket (important!) */
        }

        return 0;               /* Avoid compiler warning */
}
