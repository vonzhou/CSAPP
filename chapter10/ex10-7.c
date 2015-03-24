/*
 * P612, 习题10.7
 */

#include "csapp.h"
// 头文件中定义的MAXBUF = MAXLINE = 8192

#define MYBUF 5
#define MAXLINE 10

int main(int argc, char **argv)
{
        int n;
        rio_t rio;
        char buf[MAXLINE];
        int count = 0;          //bytes already read

        Rio_readinitb(&rio, STDIN_FILENO);
        n = Rio_readnb(&rio, buf, MAXLINE);// read a line
        while (n > 0) {
                count += n;
                if(count >= MYBUF) {
                        Rio_writen(STDOUT_FILENO, buf, MYBUF);
                        count -= MYBUF;
                        if (count > 0)
                                memmove(buf, buf + MYBUF, count);
                }
                n = Rio_readnb(&rio, buf+count, MAXLINE-count);
        }

        return 0;
}
