/*
 * 10.7
 *
 * mofaph@gmail.com
 * 2013-5-11
 *
 * $ cc -I../common ../common/csapp.c ex10-7.c -lpthread
 * # 注意，上面链接到 pthread 库不是代码必须的，是由于 csapp.c 中需要
 */

#include "csapp.h"

#undef  MAXBUF
#define MAXBUF 6

#undef  MAXLINE
#define MAXLINE 10

int main(int argc, char **argv)
{
        int n;
        rio_t rio;
        char buf[MAXLINE];
        int count = 0;          /* 记录 buf 中已经读入的字符数 */

        Rio_readinitb(&rio, STDIN_FILENO);
        n = Rio_readnb(&rio, buf, MAXLINE);
        while (n > 0) {
                count += n;
                if (count >= MAXBUF) {
                        Rio_writen(STDOUT_FILENO, buf, MAXBUF);
                        count -= MAXBUF;
                        if (count > 0)
                                memmove(buf, buf+MAXBUF, count);
                }
                n = Rio_readnb(&rio, buf+count, MAXLINE-count);
        }

        return 0;
}
