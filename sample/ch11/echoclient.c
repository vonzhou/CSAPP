/*
 * p631
 *
 * echo 客户端的主程序
 *
 * unix> cc -I../../common ../../common/csapp.c echoclient.c -lpthread -o echoclient
 * unix> ./echoclient
 */

#include "csapp.h"

int main(int argc, char **argv)
{
        int clientfd, port;
        char *host, buf[MAXLINE];
        rio_t rio;

        if (argc != 3) {
                fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
                exit(0);
        }
        host = argv[1];
        port = atoi(argv[2]);

        clientfd = Open_clientfd(host, port);
        Rio_readinitb(&rio, clientfd);

        while (Fgets(buf, MAXLINE, stdin) != NULL) {
                Rio_writen(clientfd, buf, strlen(buf));
                Rio_readlineb(&rio, buf, MAXLINE);
                Fputs(buf, stdout);
        }

        Close(clientfd);
        exit(0);
}
