/*
 * 10.2
 *
 * mofaph@gmail.com
 *
 * 假设磁盘文件 foobar.txt 由 6 个 ASCII 码字符“foobar”组成。那么，下列程序的输
 * 出是什么？
 *
 * $ echo "foobar" > foobar.txt
 * $ cc -I../common ../common/csapp.c ex10-2.c -lpthread
 */

#include "csapp.h"

int main()
{
        int fd1, fd2;
        char c;

        fd1 = Open("foobar.txt", O_RDONLY, 0);
        fd2 = Open("foobar.txt", O_RDONLY, 0);
        Read(fd1, &c, 1);
        Read(fd2, &c, 1);
        printf("c = %c\n", c);
        exit(0);
}
