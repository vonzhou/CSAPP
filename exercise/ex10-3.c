/*
 * 10.3
 *
 * 就像前面 10.2 那样，假设磁盘文件 foobar.txt 由 6 个 ASCII 码字符“foobar”组成。
 * 那么下列程序的输出是什么？
 *
 * $ echo "foobar" > foobar.txt
 * $ cc -I../common ../common/csapp.c ex10-3.c -lpthread
 */

#include "csapp.h"

int main()
{
        int fd;
        char c;

        fd = Open("foobar.txt", O_RDONLY, 0);
        if (Fork() == 0) {      /* child */
                Read(fd, &c, 1);
                exit(0);
        }

        /* parent */
        Wait(NULL);
        Read(fd, &c, 1);
        printf("c = %c\n", c);
        exit(0);
}
