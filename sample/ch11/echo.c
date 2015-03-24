/*
 * p632
 *
 * 读和回送文本行的 echo 函数
 *
 * unix> cc -I../../common ../../common/csapp.c echoserveri.c echo.c -lpthread -o echod
 */

#include "csapp.h"

void echo(int connfd)
{
        size_t n;
        char buf[MAXLINE];
        rio_t rio;

        Rio_readinitb(&rio, connfd);
        while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
                printf("server received %d bytes\n", (int)n);
                Rio_writen(connfd, buf, n);
        }
}
