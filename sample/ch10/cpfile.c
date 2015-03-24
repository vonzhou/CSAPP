/*
 * p602
 *
 * 使用 RIO 函数一次一行地从标准输入拷贝一个文本文件到标准输出
 *
 * unix> cc -I../../common ../../common/csapp.c cpfile.c -lpthread
 */

#include "csapp.h"

int main(int argc, char *argv[])
{
        int n;
        rio_t rio;
        char buf[MAXLINE];

        Rio_readinitb(&rio, STDIN_FILENO);
        while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
                Rio_writen(STDOUT_FILENO, buf, n);
}
