/*
 * 12.22
 *
 * mofaph@gmail.com
 * 2013-8-17
 *
 * 使用 I/O 多路复用的 echo 服务器。服务器使用 select 等待监听描述符上的连接请求
 * 和标准输入上的命令。
 *
 * unix> cc -Wall -I../common ../common/csapp.c ex12-22.c -lpthread -o ex12-22
 * unix> ./ex12-22
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096
#define LISTENQ 1024            /* second argument to listen() */

void echo(int connfd)
{
        char buf[MAXLINE];
        int n = read(connfd, buf, sizeof(buf));
        if (n < 0) {
                perror("read");
                exit(EXIT_FAILURE);
        }
        if (n > 0) {
                printf("server received %d bytes\n", (int)n);
                int out = write(connfd, buf, n);
                if (out != n) {
                        fprintf(stderr, "write error\n");
                        exit(EXIT_FAILURE);
                }
        }
}

void command(void)
{
        char buf[MAXLINE];
        char *ret = fgets(buf, MAXLINE, stdin);
        if (ret == NULL) {
                if (feof(stdin)) { /* EOF */
                        exit(EXIT_SUCCESS);
                }
                if (ferror(stdin)) {
                        perror("fgets");
                        exit(EXIT_FAILURE);
                }
        }
        printf("%s", buf);      /* Process the input command */
}

/* token from common/csapp.c */
int open_listenfd(int port)
{
        int listenfd, optval=1;
        struct sockaddr_in serveraddr;

        /* Create a socket descriptor */
        if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
                return -1;

        /* Eliminates "Address already in use" error from bind. */
        if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
                       (const void *)&optval , sizeof(int)) < 0)
                return -1;

        /* Listenfd will be an endpoint for all requests to port
           on any IP address for this host */
        memset((char *) &serveraddr, 0, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons((unsigned short)port);
        if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
                return -1;

        /* Make it a listening socket ready to accept connection requests */
        if (listen(listenfd, LISTENQ) < 0)
                return -1;
        return listenfd;
}

/* token from common/csapp.c */
int Open_listenfd(int port)
{
        int rc = open_listenfd(port);
        if (rc < 0) {
                perror("Open_listenfd error");
                exit(EXIT_FAILURE);
        }
        return rc;
}

/* token from common/csapp.c */
int Select(int  n, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout)
{
    int rc = select(n, readfds, writefds, exceptfds, timeout);
    if (rc < 0) {
            perror("Select error");
            exit(EXIT_FAILURE);
    }
    return rc;
}

/* token from common/csapp.c */
int Accept(int s, struct sockaddr *addr, socklen_t *addrlen)
{
    int rc = accept(s, addr, addrlen);
    if (rc < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
    }
    return rc;
}

/* token from common/csapp.c */
void Close(int fd)
{
        int rc = close(fd);
        if (rc < 0) {
                perror("Close error");
                exit(EXIT_FAILURE);
        }
}

int main(int argc, char **argv)
{
        int listenfd, connfd, port;
        socklen_t clientlen = sizeof(struct sockaddr_in);
        struct sockaddr_in clientaddr;
        fd_set read_set, ready_set;

        if (argc != 2) {
                fprintf(stderr, "usage: %s <port>\n", argv[0]);
                exit(0);
        }
        port = atoi(argv[1]);
        listenfd = Open_listenfd(port);

        FD_ZERO(&read_set);     /* Clear read set */
        FD_SET(STDIN_FILENO, &read_set); /* Add stdin to read set */
        FD_SET(listenfd, &read_set);

        while (1) {
                ready_set = read_set;
                Select(listenfd+1, &ready_set, NULL, NULL, NULL);
                if (FD_ISSET(STDIN_FILENO, &ready_set))
                        command(); /* Read command line from stdin */
                if (FD_ISSET(listenfd, &ready_set)) {
                        connfd = Accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
                        echo(connfd); /* Echo client one line or nothing(EOF) */
                        Close(connfd);
                }
        }

        return 0;               /* Avoid compiler warning */
}
